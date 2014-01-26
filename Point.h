/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//	Modélise un point
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	string Translater ( int dx, int dy );
    // Mode d'emploi :
    //Translate le point de +dx en abscisse
    //	     				+dy en ordonnée
    // Contrat : Renvoie les positions précédés d'un espace
    //

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point (int x = 0, int y = 0 );
    // Mode d'emploi :
    //Constructeur du point (x,y)
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int x;
	int y;
};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_
