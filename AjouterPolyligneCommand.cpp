
/*************************************************************************
                           AjouterPolyligneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterPolyligneCommand> (fichier AjouterPolyligneCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "AjouterPolyligneCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

AjouterPolyligneCommand::AjouterPolyligneCommand (string fname, string fcommande,vector<pair<int,int> > fligne)
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	lignes =fligne;
}

void AjouterPolyligneCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.AjouterPolyligne(name,commande,lignes);
}


void AjouterPolyligneCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerObjet(name);
}



AjouterPolyligneCommand::~AjouterPolyligneCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AjouterPolyligneCommand>" << endl;
#endif
} //----- Fin de ~AjouterPolyligneCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
