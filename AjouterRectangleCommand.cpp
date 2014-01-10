
/*************************************************************************
                           AjouterRectangleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterRectangleCommand> (fichier AjouterRectangleCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "AjouterRectangleCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

AjouterRectangleCommand::AjouterRectangleCommand (string fname, string fcommande,int fx1, int fy1,int fx2,int fy2)
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	x1 = fx1;
	y1 = fy1;
	x2 = fx2;
	y2 = fy2;
}

void AjouterRectangleCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.AjouterRectangle(name,commande,x1,y1,x2,y2);
}


void AjouterRectangleCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerObjet(name);
}



AjouterRectangleCommand::~AjouterRectangleCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AjouterRectangleCommand>" << endl;
#endif
} //----- Fin de ~AjouterRectangleCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées