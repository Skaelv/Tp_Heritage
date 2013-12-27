/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Réalisation de la classe <Cercle> (fichier Cercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Cercle::Translater ( int dx, int dy )
// Algorithme :
//
{
        centre.Translater(dx,dy);
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Cercle & Cercle::operator = ( const Cercle & unCercle )
// Algorithme :
//
{
        return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Cercle::Cercle ( const Cercle & unCercle )
// Algorithme :
//
{
    centre=unCercle.centre;
	rayon=unCercle.rayon;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif
} //----- Fin de Cercle (constructeur de copie)


Cercle::Cercle ( string name,int fx,int fy, int frayon)
// Algorithme :
//
{
        centre=Point(fx,fy);
        rayon=frayon;

#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle


Cercle::~Cercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cercle>" << endl;
#endif
} //----- Fin de ~Cercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
