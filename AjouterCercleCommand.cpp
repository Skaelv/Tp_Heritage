
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
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "AjouterCercleCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

AjouterCercleCommand::AjouterCercleCommand (string fname, string fcommande,int fx, int fy,int fr)
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	x = fx;
	y = fy;
	r = fr;
}

void AjouterCercleCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.AjouterCercle(name,commande,x,y,r);
}


void AjouterCercleCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerObjet(name);
}



AjouterCercleCommand::~AjouterCercleCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AjouterCercleCommand>" << endl;
#endif
} //----- Fin de ~AjouterCercleCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
