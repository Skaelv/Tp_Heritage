/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

 void Ligne::Translater ( int dx, int dy )
// Algorithme :
// Déplace les points de la ligne et modifie sa commande
{
	commande = "";
    commande = "L " + name + p1.Translater( dx, dy ) + p2.Translater( dx, dy );
} //----- Fin de Méthode


bool Ligne::IsAgrege( )
//Algorithme
//
{
 	return false;
}


Point Ligne::GetP1( )
//Algorithme :
//
{
	return p1;
}

Point Ligne::GetP2()
//Algorithme :
{
	return p2;
}

//------------------------------------------------- Surcharge d'opérateurs
Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne ) : p1( unLigne.p1 ), p2( unLigne.p2 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne ( int x1, int y1, int x2, int y2, string fname, string fcommande ) : EltGeo( fname, fcommande ), p1( Point( x1, y1 ) ), p2( Point( x2, y2 ) )
// Algorithme :
//
{
	Translater( 0, 0 );//Réecrit la commande (Evite les nombres à virgules et les espaces multiples)
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
