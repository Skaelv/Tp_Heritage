/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Main> (fichier Main.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Controller.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int main ( )
{
	Controller Cont;
	string commande;
	cout << " # Entrez une commande" << endl;
	getline(cin,commande);
	while (commande!="EXIT")
	{
		Cont.Validation(commande);
		cout << " # Entrez une commande" << endl;
		getline(cin,commande);
	}

	return 0;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
