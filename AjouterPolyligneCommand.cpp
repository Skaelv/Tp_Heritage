
/*************************************************************************
                           AjouterPolyligneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterPolyligneCommand> (fichier AjouterPolyligneCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "AjouterPolyligneCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AjouterPolyligneCommand::Execute ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.AjouterPolyligne( name, commande, lignes );
}

void AjouterPolyligneCommand::Undo ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.SupprimerObjet( name );
}

bool AjouterPolyligneCommand::IsNewModel ( )
// Algorithme :
//
{
	return false;
}

string AjouterPolyligneCommand::GetCommande( )
//Algorithme :
//
{
	return commande;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

AjouterPolyligneCommand::AjouterPolyligneCommand ( string fname, string fcommande, vector< pair< long int, long int> > fligne )
//Algorithme
//
{
	name = fname;
	commande = fcommande;
	lignes = fligne;
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
