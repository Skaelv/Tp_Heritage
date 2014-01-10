
/*************************************************************************
                           TranslaterCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <TranslaterCommand> (fichier TranslaterCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>
#include<vector>

//------------------------------------------------------ Include personnel
#include "TranslaterCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

TranslaterCommand::TranslaterCommand (int fdx, int fdy, string fname)
//Algorithme
//
{
	name = fname;
	dx =fdx;
	dy = fdy;
}

void TranslaterCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.Translater(dx,dy, name);
}


void TranslaterCommand::Undo (Modele& fmodele)
// Algorithme
{
	fmodele.Translater(-dx,-dy,name);
}


TranslaterCommand::~TranslaterCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TranslaterCommand>" << endl;
#endif
} //----- Fin de ~TranslaterCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
