/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<sstream>
//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Point::Translater (int dx, int dy)
// Algorithme :
//
{
    stringstream ssx;
    stringstream ssy;
    x += dx;y+=dy;
    ssx << x;ssy<< y;
    string strx = ssx.str();
    string stry = ssy.str();
    string str =" " + strx + " " + stry;
    return str;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
	x=unPoint.x;
	y=unPoint.y;
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme :
//
{
	this->x=unPoint.x;
	this->y=unPoint.y;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


Point::Point (int x, int y):x(x),y(y)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
