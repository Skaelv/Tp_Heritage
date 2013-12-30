/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


 string Ligne::Translater ( int dx, int dy )
// Algorithme :
//
{
	string commande;
	commande = p1.Translater(dx,dy);
	commande += p2.Translater(dx,dy);
	return commande;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Ligne & Ligne::operator = ( const Ligne & unLigne )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne )
// Algorithme :
//
{

	p1=unLigne.p1;
	p2=unLigne.p2;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne (int x1,int y1,int x2,int y2,string name ):EltGeo(name),p1(Point(x1,y1)),p2(Point(x2,y2))
// Algorithme :
//
{
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
