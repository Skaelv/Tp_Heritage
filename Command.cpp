/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Command> (fichier Command.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Command.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Command::Execute ( Modele& fmodele )
// Algorithme :
//
{
}

bool Command::IsNewModel ( )
// Algorithme :
//
{
	return true;
}

string Command::GetCommande ( )
//Algorithme :
//
{
	return "";
}


void Command::Undo ( Modele& fmodele )
// Algorithme :
//
{
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Command::Command ( )
//Algorithme
{
}

Command::~Command ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- Fin de ~Command

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
