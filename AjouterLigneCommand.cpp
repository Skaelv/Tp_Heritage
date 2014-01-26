
/*************************************************************************
                           AjouterLigneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterLigneCommand> (fichier AjouterLigneCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "AjouterLigneCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AjouterLigneCommand::Execute ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.AjouterLigne( name, commande, x1, y1, x2, y2 );
}


void AjouterLigneCommand::Undo ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.SupprimerObjet( name );
}

bool AjouterLigneCommand::IsNewModel ( )
// Algorithme :
//
{
	return false;
}

string AjouterLigneCommand::GetCommande( )
//Algorithme :
//
{
	return commande;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AjouterLigneCommand::AjouterLigneCommand ( string fname, string fcommande, long int fx1, long int fy1, long int fx2, long int fy2 )
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
