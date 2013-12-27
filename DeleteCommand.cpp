
/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>
#include<vector>

//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

DeleteCommand::DeleteCommand (vector<string> fname,Modele& fmodele)
//Algorithme
//
{
	modele = fmodele;
	nameObjet = fname;
}

void DeleteCommand::Execute ()
// Algorithme :
//
{

	modele.SupprimerCommande(nameObjet);
}


Modele DeleteCommand::GetModele ()
// Algorithme
{
	return modele;
}


void DeleteCommand::Undo ()
// Algorithme : Recréer les commandes stockées dans nameObjet
{
	//nameObjet contient les commandes à refaire
}


DeleteCommand::~DeleteCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de ~DeleteCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
