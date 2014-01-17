/*************************************************************************
                           AjouterCercleCommand  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- R�alisation de la classe <AjouterCercleCommand> (fichier AjouterCercleCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;

//------------------------------------------------------ Include personnel
#include "ChargerCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void ChargerCommand::Execute (Modele & fmodele)
// Algorithme :
//
{
	OldModel =fmodele;
	control->Charger(nomFichier);
}


void ChargerCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele=OldModel;
}

//------------------------------------------------- Surcharge d'op�rateurs
ChargerCommand::ChargerCommand(string fname, Controller * c) : nomFichier(fname), control(c)
{
}


ChargerCommand::~ChargerCommand(void)
{
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
