
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

DeleteCommand::DeleteCommand (vector<string> fname)
//Algorithme
//
{
	nomElt = fname;
}

void DeleteCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerCommande(nomElt);
}


void DeleteCommand::Undo (Modele& fmodele)
// Algorithme : Recréer les commandes stockées dans nameObjet
{
	//TODO nameObjet contient les commandes à refaire : Pas besoin de reppasser par
	//le Controller (commandes validées), vérification dans Modele avec ObjetExistant
	//pour etre sur qu'un objet du meme nom n'as pas été recrée entre temps
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
