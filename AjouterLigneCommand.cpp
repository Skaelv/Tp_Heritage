
/*************************************************************************
                           AjouterLigneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterLigneCommand> (fichier AjouterLigneCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "AjouterLigneCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

AjouterLigneCommand::AjouterLigneCommand (string fname, string fcommande,int fx1, int fy1,int fx2,int fy2)
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

void AjouterLigneCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.AjouterLigne(name,commande,x1,y1,x2,y2);
}


void AjouterLigneCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerObjet(name);
}



AjouterLigneCommand::~AjouterLigneCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AjouterLigneCommand>" << endl;
#endif
} //----- Fin de ~AjouterLigneCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
