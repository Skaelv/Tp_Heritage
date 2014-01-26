
/*************************************************************************
                           ClearCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <ClearCommand> (fichier ClearCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<string>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ClearCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ClearCommand::Execute ( Modele& fmodele )
// Algorithme :
{
	OldModel = fmodele;
	fmodele = Modele( );//Mets un nouveau modele vide dans fmodele
	cout << "# New empty model loaded" << endl;
}


void ClearCommand::Undo ( Modele& fmodele )
// Algorithme : Met OldModel dans fmodele
//
{
	fmodele = OldModel;
	cout << "# Precedent model loaded" << endl;
}


bool ClearCommand::IsNewModel ( )
// Algorithme :
//
{
	return true;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ClearCommand::ClearCommand ( )
//Algorithme
//
{

}

ClearCommand::~ClearCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ClearCommand>" << endl;
#endif
} //----- Fin de ~ClearCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
