
/*************************************************************************
                           AjouterObjetAgregeCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterObjetAgregeCommand> (fichier AjouterObjetAgregeCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "AjouterObjetAgregeCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

AjouterObjetAgregeCommand::AjouterObjetAgregeCommand (vector<string> flisteObjet,string fname, string fcommande)
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	listeObjet=flisteObjet;
}

void AjouterObjetAgregeCommand::Execute (Modele& fmodele)
// Algorithme :
//
{
	fmodele.AjouterObjetAgrege(name,commande,listeObjet);
}


void AjouterObjetAgregeCommand::Undo (Modele& fmodele)
// Algorithme :
//
{
	fmodele.SupprimerObjet(name);
}



AjouterObjetAgregeCommand::~AjouterObjetAgregeCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AjouterObjetAgregeCommand>" << endl;
#endif
} //----- Fin de ~AjouterObjetAgregeCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
