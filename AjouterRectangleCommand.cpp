
/*************************************************************************
                           AjouterRectangleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <AjouterRectangleCommand> (fichier AjouterRectangleCommand.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<string>

using namespace std;
//------------------------------------------------------ Include personnel
#include "AjouterRectangleCommand.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AjouterRectangleCommand::Execute ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.AjouterRectangle( name, commande, x1, y1, x2, y2 );
}

void AjouterRectangleCommand::Undo ( Modele& fmodele )
// Algorithme :
//
{
	fmodele.SupprimerObjet( name );
}

bool AjouterRectangleCommand::IsNewModel ( )
// Algorithme :
//
{
	return false;
}

string AjouterRectangleCommand::GetCommande( )
//Algorithme :
//
{
	return commande;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

AjouterRectangleCommand::AjouterRectangleCommand ( string fname, string fcommande, long int fx1, long int fy1, long int fx2, long int fy2 )
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
