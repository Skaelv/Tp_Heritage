/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Modele.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Modele::Sauvegarder ( string path )
{

	ofstream saving(path.c_str());
	if (!saving.fail())
	{
		for ( map<string,EltGeo*>::iterator iter = listeEltGeo.begin(); iter != listeEltGeo.end(); iter++)
		{
			saving << iter->second->GetCommande() << endl;
			cout << "# File saved"<< endl;
		}
	}//TODO Sauvegarde des fichiers
	else
	{
		cout << "# Saving failed"<< endl;
	}
}

bool Modele::Charger(string fichier)
// Algorithme :
{
	this->Vider();
	return true;
} //----- Fin de Méthode

bool Modele::Vider()
// Algorithme :
{
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		delete iterator->second;
	}
	listeEltGeo.clear();
	for (int i = redo.size();i>0;i--)
	{
		delete redo.back();
		redo.pop_back();
	}
	for (int i = undo.size();i>0;i--)
	{
		delete undo.back();
		undo.pop_back();
	}
	return true;
} //----- Fin de Méthode



void Modele::AjouterCercle(string name,string commande, int fx,int fy, int fr)
//Algorithme
{
	listeEltGeo[name] =  new Cercle(fx,fy,fr,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterRectangle(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	listeEltGeo[name] = new Rectangle(fx1,fy1,fx2,fy2,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterLigne(string name,string commande, int fx1,int fy1, int fx2,int fy2)
//Algorithme
{
	listeEltGeo[name] = new Ligne(fx1,fy1,fx2,fy2,name,commande);
	cout  << "# New Object : "<< name <<endl;
}

void Modele::AjouterPolyligne(string name,string commande, vector<pair<int,int> > fligne)
//Algorithme
{
	listeEltGeo[name] = new Polyligne(fligne,name,commande);
	cout << "# New Object : "<< name <<endl;
}

void Modele::AjouterObjetAgrege(string name,string commande, vector<string> nameObjet)
//Algorithme
{
	list<EltGeo *> objetAg;
	for (vector<string>::iterator iter=nameObjet.begin();iter<nameObjet.end(); iter++)
		{
		objetAg.push_back(listeEltGeo.find(iter->c_str())->second);
		}
	listeEltGeo[name] = new ObjetAgrege(objetAg,name,commande);
	cout<< "# New Object : "<< name <<endl;
}


void Modele::SupprimerCommande(map<string,string>  &nameObjet)
//Algorithme
{
	map<string,string> temp;
	for (map<string,string>::iterator iter=nameObjet.begin();iter!=nameObjet.end(); iter++)
	{
		//La commande suivante stocke la commande et la liste des objets agreges auquel l'objet appartenait
		temp[listeEltGeo.find(iter->first)->second->GetCommande()]=this->DeleteAgrege(iter->first);
		delete (listeEltGeo.find(iter->first)->second);
		listeEltGeo.erase(listeEltGeo.find(iter->first));
	}
	nameObjet = temp;//Passage par reference : renvoie le tableau des commandes
	//servant à créer les objets que l'on vient de supprimer
}

void Modele::SupprimerObjet(string name)
//Algorithme Efface dynamiquement le pointeur *EltGeo avant d'effacer
//la ligne de listeEltGeo
{
	delete (listeEltGeo.find(name)->second);
	listeEltGeo.erase(listeEltGeo.find(name));
}

string Modele::DeleteAgrege(string objetASupprimer)
//Algorithme : Envoie objetASupprimer a tous les objetAgreges pour qu'ils vérifient
//si l'objet est dans leur liste et le retirent si tel est le cas avant suppression dans la memoire
{

	string listAgrege="";
	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		if(iterator->second->IsAgrege())
		{
			listAgrege+= iterator->second->DeleteElement(objetASupprimer);
		}
	}
	return listAgrege;

}

void Modele::AddAgrege(string nameObject,string nameAgrege)
{
	listeEltGeo.find(nameAgrege)->second->AddElement(listeEltGeo.find(nameObject)->second);
}

void Modele::EnumererCommande()
//Algorithme
{

	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
	cout << iterator->second->GetCommande() << endl;
	}

}

bool Modele::ObjetExistant(string fname)
//Algorithme
{
	return (listeEltGeo.find(fname)!=listeEltGeo.end()) ? true : false;
}


void Modele::Translater(int dx,int dy, string fname)
//Algorithme
{
	listeEltGeo.find(fname)->second->Translater(dx,dy);
	cout <<"# "<< fname << " has been moved"<<endl;
}


void Modele::Undo()
//Algorithme :
{
	if (!undo.empty())
	{
		undo.back()->Undo(*this);//Execute la fonction Undo de la derniere commande stocké dans la pile
		redo.push_back(undo.back());//Copie la commande de la pile undo vers redo
		undo.back();//Supprime la commande de la pile undo

	}
	else
	{
		cout<< "# No command to execute" <<endl;
	}
}

void Modele::Redo()
//Algorithme :
{
	if (!redo.empty())
	{
		redo.back()->Execute(*this);//Execute la fonction Execute de la derniere commande stocké dans la pile
		undo.push_back(redo.back());//Copie la commande de la pile undo vers redo
		redo.pop_back();//Supprime la commande de la pile undo
	}
	else
	{
		cout<< "# No command to execute" <<endl;
	}
}

void Modele::Execute(Command *command)
//Algorithme
//*this passé par reference modifie directement le modele courant dans la fonction
{
	command->Execute(*this);
	undo.push_back(command);
}



//------------------------------------------------- Surcharge d'opérateurs
Modele & Modele::operator = ( const Modele & unModele )
// Algorithme :
//
{
	listeEltGeo.clear();
	for(map<string,EltGeo *>::const_iterator iterator = unModele.listeEltGeo.begin(); iterator != unModele.listeEltGeo.end(); iterator++)
		{
			listeEltGeo[iterator->first]=iterator->second;
		}
	redo.clear();
		for (vector<Command *>::const_iterator iter=unModele.redo.begin();iter!=unModele.redo.end(); iter++ )
		{
			redo.push_back(*iter);
		}
	undo.clear();
		for (vector<Command *>::const_iterator iter=unModele.undo.begin();iter!=unModele.undo.end(); iter++ )
		{
			undo.push_back(*iter);
		}
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Modele::Modele ( const Modele & unModele )
// Algorithme :
//
{
	listeEltGeo.clear();
	for(map<string,EltGeo *>::const_iterator iterator = unModele.listeEltGeo.begin(); iterator != unModele.listeEltGeo.end(); iterator++)
		{
			listeEltGeo[iterator->first]=iterator->second;
		}
	redo.clear();
		for (vector<Command *>::const_iterator iter=unModele.redo.begin();iter!=unModele.redo.end(); iter++ )
		{
			redo.push_back(*iter);
		}
	undo.clear();
		for (vector<Command *>::const_iterator iter=unModele.undo.begin();iter!=unModele.undo.end(); iter++ )
		{
			undo.push_back(*iter);
		}

		#ifdef MAP
    cout << "Appel au constructeur de copie de <Modele>" << endl;
#endif
} //----- Fin de Modele (constructeur de copie)


Modele::Modele ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//Suppression dynamique des Elements Geo et des commandes du modele
{

	for(map_it_type iterator = listeEltGeo.begin(); iterator != listeEltGeo.end(); iterator++)
	{
		delete iterator->second;
	}
	for (int i = redo.size();i>0;i--)
	{
		delete redo.back();
	}
	for (int i = redo.size();i>0;i--)
	{
		delete undo.back();
	}

#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
