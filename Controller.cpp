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

bool Controller::Validation ( string commande )
// Algorithme :
//TODO	-Vérifier que l'objet que l'on souhaite -effacer existe,
//											-créer n'existe pas déja
// Grace à la méthode Controller::ObjetExistant déja implémenté
{
	istringstream ss(commande);
	istream_iterator<string> begin(ss), end;
	vector<string> mots(begin, end);
	if (mots.size()==1)
	{
		if (mots[0]=="LIST")
		{
			this->EnumererObjet();
			return true;
		}
		if (mots[0]=="CLEAR")
		{
			this->Vider();
			return true;
		}
		if (mots[0]=="UNDO")
		{
			//this.DefaireCommande();
			return true;
		}
		if (mots[0]=="REDO")
		{
			//this.RefaireCommande();
			return true;
		}
	}
	else if ( (mots.size()==2) and ( (mots[0]=="SAVE") or (mots[0]=="LOAD") ) )
	{
		return true;
	}
	else if ( (mots.size()==4) and (mots[0]=="MOVE") and (atoi(mots[2].c_str())) and (atoi(mots[3].c_str())) )
	{
		return true;
	}
	else if ( (mots[0]=="DELETE") and (mots.size()>1) )
	{
		unsigned int i;
		 //Ne supprime aucun objet si un objet n'existe pas
		for (i=1;i<mots.size();i++)
		{
			if (!this->ObjetExistant(mots[i]))
			//Si un objet n'existe pas on ne supprime rien
			{
				cout << "ERR"<< endl << "#Objet inexistant : " << mots[i] << endl;
				return false;
			}
		}//Fin du for
		this->SupprimerCommand( new DeleteCommand(mots,modele));
		cout << "OK"<< endl;
	}
	else if ( (mots[0]=="OA") and (mots.size()>2) )
	{

		cout << "OK"<< endl << "# New Object : "<< mots[1] <<endl;
		return true;
	}
	else if ( (mots[0]=="C") and (mots.size()==5) and (atoi(mots[2].c_str())) and (atoi(mots[3].c_str())) and (atoi(mots[4].c_str())) )
	{
		if (!this->ObjetExistant(mots[1]))
		{
			this->AjouterCercle(new AjouterCercleCommand(mots[1],commande,
														 	 atoi(mots[2].c_str()),
														 	 atoi(mots[3].c_str()),
															 atoi(mots[4].c_str()),
															 modele
														));


			cout << "OK"<< endl << "# New Object : "<< mots[1] <<endl;
			return true;
		}
	}

	else if ( ((mots[0]=="R")or(mots[0]=="L")) and (mots.size()==6) and (atoi(mots[2].c_str())) and (atoi(mots[3].c_str())) and (atoi(mots[4].c_str())) and (atoi(mots[5].c_str())) )
	{
		if (!this->ObjetExistant(mots[1]))
		{
//			this->AjouterRectangle(mots);
			cout << "OK"<< endl << "# New Object : "<< mots[1] <<endl;
			return true;
		}	}
	else if ( (mots[0]=="PL") and (mots.size()>=4) and (mots.size() % 2 == 0) )
	{
		unsigned int i;
		for (i=2; i<mots.size();i++)
		{
			if (!atoi(mots[i].c_str()))
			{
				cout << "ERR"<< endl << " #Invalid Parameters"<<endl;
				return false;
			}
		}
		if (!this->ObjetExistant(mots[1]))
		{
//			this->AjouterPolyligne(mots);
			cout << "OK"<< endl << "# New Object : "<< mots[1] <<endl;
			return true;
		}
	}

	//Si aucune boucle possédant un retour True n'est rencontrée :
	cout << "ERR" << endl << " #Invalid Parameters"<<endl;
	return false;
} //----- Fin de Méthode



bool Controller::ObjetExistant(string objet)
// Algorithme :
{
	return modele.ObjetExistant(objet);
} //----- Fin de Méthode

void Controller::AjouterCercle(AjouterCercleCommand *command)
// Algorithme :
{

	command->Execute();
//	undo.push(command);
} //----- Fin de Méthode

void Controller::AjouterRectangle(Command *command)
// Algorithme :
{
} //----- Fin de Méthode

void Controller::AjouterLigne(Command *command)
// Algorithme :
{
} //----- Fin de Méthode

void Controller::AjouterPolyligne(Command *command)
// Algorithme :
{
} //----- Fin de Méthode

void Controller::AjouterObjetAgrege ( Command *command )
// Algorithme :
{
} //----- Fin de Méthode

void Controller::SupprimerCommand(DeleteCommand *command)
// Algorithme :
{
	command->Execute();
	modele = command->GetModele();
} //----- Fin de Méthode

void Controller::SupprimerObjet(string name)
// Algorithme :
{
} //----- Fin de Méthode

void Controller::Translater(Command *command)
// Algorithme :
{
} //----- Fin de Méthode

void Controller::EnumererObjet()
// Algorithme :
{
	cout << "Controller::EnumererObjet" <<endl;
	modele.EnumererCommande();
} //----- Fin de Méthode

void Controller::Vider()
// Algorithme :
{
} //----- Fin de Méthode


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
#ifdef MAP
    cout << "Appel au constructeur de <Controller>" << endl;
#endif
} //----- Fin de Controller


Controller::~Controller ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
