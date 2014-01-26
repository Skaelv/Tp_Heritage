
/*************************************************************************
                           AjouterObjetAgregeCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterObjetAgregeCommand> (fichier AjouterObjetAgregeCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>
#include <set>

//------------------------------------------------------ Include personnel
#include "AjouterObjetAgregeCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AjouterObjetAgregeCommand::Execute ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.AjouterObjetAgrege( name, commande, listeObjet );
}

void AjouterObjetAgregeCommand::Undo ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.SupprimerObjet( name );
}

bool AjouterObjetAgregeCommand::IsNewModel ( )
// Algorithme :
//
{
	return false;
}


string AjouterObjetAgregeCommand::GetCommande ( )
//Algorithme :
//
{
	return commande;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

AjouterObjetAgregeCommand::AjouterObjetAgregeCommand ( set< string > flisteObjet, string fname, string fcommande )
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	listeObjet = flisteObjet;
}

AjouterObjetAgregeCommand::~AjouterObjetAgregeCommand ( )
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <AjouterObjetAgregeCommand>" << endl;
#endif
} //----- Fin de ~AjouterObjetAgregeCommand

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
