/*************************************************************************
                           AjouterCercleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterCercleCommand> (fichier AjouterCercleCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "ChargerCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ChargerCommand::Execute ()
// Algorithme :
//
{
	//fmodele.AjouterCercle(name,commande,x,y,r);
	control->Charger(nomFichier);
}


void ChargerCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	//fmodele.SupprimerObjet(name);
	//TODO annuler la commande et Recharger les piles
}

//------------------------------------------------- Surcharge d'opérateurs
ChargerCommand::ChargerCommand(string fname, Controller* c) : nomFichier(fname), control(c)
{
	//TODO Sauvegarder les piles UNDO et REDO
	
}


ChargerCommand::~ChargerCommand(void)
{
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
