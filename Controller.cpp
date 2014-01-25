/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Controller.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <cassert>
using namespace std;
#include <iostream>
#include <cstdlib>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Controller::Validation ( string commande, bool load )
// Algorithme :
{
	//Decoupe la commande en parametre et ressort chaque mots dans un vecteur de string : mots
	istringstream ss(commande);
	istream_iterator<string> begin(ss), end;
	vector<string> mots(begin, end);
	if (mots.size()==0)
	{
		cout << "ERR" << endl << " #Invalid Parameters"<<endl;
		return false;
	}
	if ( (mots.size()==1) && (!load) )
	{
		if (mots[0]=="LIST")
		{
			this->EnumererObjet();
			return true;
		}
		if (mots[0]=="CLEAR")
		{
			this->ExecuterCommand(new ClearCommand());
			return true;
		}
		if (mots[0]=="UNDO")
		{
			this->Undo();
			return true;
		}
		if (mots[0]=="REDO")
		{
			this->Redo();
			return true;
		}
	}
	else if (mots[0]=="#")
	{
		return true;
	}
	else if ( (mots.size()==2) && (mots[0]=="SAVE") && (!load) )
	{
		Sauvegarder(mots[1]);
		return true;
	}
	else if ( (mots.size()==2) && (mots[0]=="LOAD") && (!load) )
	{
		this->ExecuterCommand(new ChargerCommand(mots[1],this));
		return true;
	}
	else if ( (!load) && (mots.size()==4) && (mots[0]=="MOVE") && (strtol(mots[2].c_str(),NULL,0)) && (strtol(mots[3].c_str(),NULL,0)) && (this->ObjetExistant(mots[1])) )
	{
		this->ExecuterCommand( new TranslaterCommand(strtol(mots[2].c_str(),NULL,0),strtol(mots[3].c_str(),NULL,0),mots[1].c_str() ) );
		return true;
	}
	else if ( (!load) && (mots[0]=="DELETE") && (mots.size()>1) )
	{
		unsigned int i;
		map<string,string> deleteMap;
		 //Ne supprime aucun objet si un objet n'existe pas
		for (i=1;i<mots.size();i++)
		{
			if (!this->ObjetExistant(mots[i]))
			//Si un objet n'existe pas on ne supprime rien
			{
				cout << "ERR"<< endl << "#At least one object do not exist : " << mots[i] << endl;
				return false;
			}
			deleteMap[mots[i].c_str()] = ""; //Reserve un espace pour stockage des commandes
									 //de recréation des objets avec Undo

		}//Fin du for
		this->ExecuterCommand( new DeleteCommand(deleteMap) );
		return true;
	}
	else if ( (mots[0]=="OA") && (mots.size()>2) && (!this->ObjetExistant(mots[1])) )
	{
		vector<string> agrege;
		for (unsigned int i=2; i<mots.size();i++)
		{
			agrege.push_back(mots[i]);
			if (!this->ObjetExistant(mots[i]))
			{
				cout << "ERR"<< endl << "#At least one object do not exist : " << mots[i] << endl;
				return false;
			}
		}
		if (!load)
		{
		this->ExecuterCommand( new AjouterObjetAgregeCommand(agrege,mots[1],commande));
		}
		else
		{
			modele.AjouterObjetAgrege(mots[1],commande,agrege);
		}
		return true;

	}
	else if ( (mots[0]=="C") && (mots.size()==5) && (IsaNumber(mots[2])) && (IsaNumber(mots[3])) && (IsaNumber(mots[4])) && (!this->ObjetExistant(mots[1])) )
	{
		if (!load)
		{
			this->ExecuterCommand(new AjouterCercleCommand(mots[1],commande,
																 	 atoi(mots[2].c_str()),
																 	 atoi(mots[3].c_str()),
																	 atoi(mots[4].c_str())
																));
		}
		else
		{
			modele.AjouterCercle(mots[1],commande,atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()));
		}

		return true;
	}

	else if ( (mots[0]=="R") && (mots.size()==6) && IsaNumber(mots[2]) && IsaNumber(mots[3]) && IsaNumber(mots[4]) && IsaNumber(mots[5]) && (!this->ObjetExistant(mots[1])) )
	{
		if (!load)
		{
			this->ExecuterCommand(new AjouterRectangleCommand(mots[1],commande,
					 	 	 	 	 	 	 	 	 	 	atoi(mots[2].c_str()),
					 	 	 	 	 	 	 	 	 	 	atoi(mots[3].c_str()),
					 	 	 	 	 	 	 	 	 	 	atoi(mots[4].c_str()),
					 	 	 	 	 	 	 	 	 	 	atoi(mots[5].c_str())
			));
		}
		else
		{
			modele.AjouterRectangle(mots[1],commande,atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()),atoi(mots[5].c_str()));
		}
		return true;
	}
	else if ( (mots[0]=="L") && (mots.size()==6) && IsaNumber(mots[2]) && IsaNumber(mots[3]) && IsaNumber(mots[4]) && IsaNumber(mots[5]) && (!this->ObjetExistant(mots[1])) )
	{
		if (!load)
		{
			this->ExecuterCommand(new AjouterLigneCommand(mots[1],commande,
		 	 	 	 	 	atoi(mots[2].c_str()),
		 	 	 	 	 	atoi(mots[3].c_str()),
		 	 	 	 	 	atoi(mots[4].c_str()),
		 	 	 	 	 	atoi(mots[5].c_str())
			));
		}
		else
		{
			modele.AjouterLigne(mots[1],commande,atoi(mots[2].c_str()),atoi(mots[3].c_str()),atoi(mots[4].c_str()),atoi(mots[5].c_str()));
		}
		return true;
	}
	else if ( (mots[0]=="PL") && (mots.size()>=4) && (mots.size() % 2 == 0) && (!this->ObjetExistant(mots[1])) )
	{
		unsigned int i;
		for (i=2; i<mots.size();i++)
		{
			if (!IsaNumber(mots[2])) //Test la validité des arguments integer
			{
				cout << "ERR"<< endl << " #Invalid Parameters"<<endl;
				return false;
			}
		}
		vector<pair<long int,long int> > lignes;
		pair<int,int> l;
		for (unsigned int i=3;i<mots.size(); i+=2)
			{
				l.first = atoi(mots[i-1].c_str());
				l.second = atoi(mots[i].c_str());
				lignes.push_back(l);//
			}
		this->ExecuterCommand(new AjouterPolyligneCommand(mots[1],commande,lignes));
		return true;
	}
	

	//Si aucune boucle possédant un retour True n'est rencontrée :
	cout << "ERR" << endl << " #Invalid Parameters"<<endl;
	return false;
} //----- Fin de Méthode


void Controller::ExecuterCommand(Command *command)
//Algorithme
{
	cout<< "OK"<<endl;
	ClearRedo();//Efface la liste des Commandes qui ont été annulées(undo) avant la création de la nouvelle commande
	command->Execute(modele);
	cmd.push_front(command);
	cmdIter--;

}


void Controller::Undo()
//Algorithme :
{
	if ( (!cmd.empty()) && (cmdIter!=cmd.end()) )
	{
		cout << "OK"<< endl;
		(*cmdIter)->Undo(modele);
		cmdIter++;
	}
	else
	{
		cout<< "# No command to execute" <<endl;
	}

}

void Controller::Redo()
//Algorithme :
{

	if (cmd.begin()!=cmdIter)
	{
		cout << "OK"<< endl;
		cmdIter--;
		(*cmdIter)->Execute(modele);
	}
	else
	{
		cout<< "# No command to execute" <<endl;
	}
}

bool Controller::ObjetExistant(string objet)
// Algorithme :
{
	return modele.ObjetExistant(objet);
} //----- Fin de Méthode

void Controller::EnumererObjet()
// Algorithme :
{
	modele.EnumererCommande();
} //----- Fin de Méthode


void Controller::Charger(string url)
// Algorithme :
{
	ifstream fichier(url.c_str());
	if ( !fichier.fail() )
	{
		cout << "# Loading new empty model"<< endl;
		string commande;
		while(getline(fichier,commande))
		{
			Validation(commande,true);
		}
		cout << "# Model loaded" << endl;
	}
	else
	{
		cout << "# File do not exist" << endl;
	}

} //----- Fin de Méthode

bool Controller::IsaNumber(string number)
//Algorithme
{
	 char * pEnd;
	  long int l = strtol (number.c_str(),&pEnd,10);
	  if ( (l<=2147483647)&&(l>=-2147483647) )
	  {
		  return (*pEnd=='\0');
	  }
	  else
	  {
		  return false;
	  }
}

void Controller::Sauvegarder(string url)
{
	list<Command *>::iterator it = cmdIter;
	ofstream saving(url.c_str(), std::ios::out);
	string s;
	if(!saving.fail())
	{
		while(it!=cmd.end() && !(*it)->IsNewModel() )
		{
			s.insert(0,(*it)->GetCommande()+"\n");	//Ecrit au début de la chaine
			it++;
		}
		saving<<s;
		saving.close();
		cout << "# Model saved"<< endl;
	}
	else
	{
		cout << "# Saving failed"<< endl;
	}
}

void Controller::ClearRedo()
//Algorithme :
{
	while(cmd.begin()!=cmdIter)
	{
		delete (*cmd.begin());
		cmd.pop_front();
	}
}



//------------------------------------------------- Surcharge d'opérateurs
Controller & Controller::operator = ( const Controller & unController )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Controller::Controller ( const Controller & unController )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Controller>" << endl;
#endif
} //----- Fin de Controller (constructeur de copie)


Controller::Controller ( )
// Algorithme :
//
{
	cmdIter=cmd.begin();
#ifdef MAP
    cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller


Controller::~Controller ( )
// Algorithme :
//
{
	for (list<Command *>::iterator iter=cmd.begin();iter!=cmd.end();iter++)
	{
		delete (*iter);
	}

#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
