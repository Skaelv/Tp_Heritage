
/*************************************************************************
                           AjouterCercleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterCercleCommand> (fichier AjouterCercleCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AjouterCercleCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
AjouterCercleCommand::AjouterCercleCommand (string fname, string fcommande,long int fx, long int fy,long int fr)
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	x = fx;
	y = fy;
	r = fr;
}

//------------------------------------------------- Surcharge d'opérateurs



bool AjouterCercleCommand::IsNewModel ()
// Algorithme :
//
{
	return false;
}


string AjouterCercleCommand::GetCommande()
//Algorithme :
//
{
	return commande;
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
