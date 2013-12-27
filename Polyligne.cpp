/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Polyligne::AjouterLigne (Ligne fligne )
// Algorithme :
//
{
	lignes.push_back(fligne);
	return true;
} //----- Fin de Méthode

string Polyligne::Translater ( int dx, int dy )
// Algorithme :
//
{
	//TODO Boucle sur le vecteur lignes appelant la methode translater de chaque lignes

} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Polyligne & Polyligne::operator = ( const Polyligne & unPolyligne )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unPolyligne )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne (constructeur de copie)


Polyligne::Polyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne


Polyligne::~Polyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
} //----- Fin de ~Polyligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
