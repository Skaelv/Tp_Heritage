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
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Cercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Cercle::Translater ( int dx, int dy )
// Algorithme :
//
{
	stringstream ssr;
	ssr << rayon;
	string strr = " " + ssr.str();
	commande ="";
	commande = "C " + name  + centre.Translater(dx,dy) + strr;
} //----- Fin de Méthode


bool Cercle::IsAgrege()
//Algorithme
//
{
	return false;
}


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


Cercle::Cercle ( int fx,int fy, int frayon,string fname,string fcommande):EltGeo(fname,fcommande)
// Algorithme :
//
{
        centre=Point(fx,fy);
        rayon=frayon;
    	Translater(0,0);//Réecrit la commande (Evite les nombres à virgules et les espaces multiples)

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
