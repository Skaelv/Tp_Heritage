/*************************************************************************
                           ChargerCommand  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- R�alisation de la classe <ChargerCommand> (fichier ChargerCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;

//------------------------------------------------------ Include personnel
#include "ChargerCommand.h"
#include "Controller.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void ChargerCommand::Execute ( Modele & fmodele )
// Algorithme :
//
{
	OldModel = fmodele;
	control->Charger( nomFichier );
}


void ChargerCommand::Undo ( Modele& fmodele )
// Algorithme :
//
{
	fmodele=OldModel;
}

bool ChargerCommand::IsNewModel ( )
// Algorithme :
//
{
	return true;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

ChargerCommand::ChargerCommand( string fname, Controller * c ) : nomFichier( fname ), control( c )
{
}


ChargerCommand::~ChargerCommand()
{
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
