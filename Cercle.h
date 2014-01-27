/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "EltGeo.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cercle>
// Modélise un cercle
//
//------------------------------------------------------------------------

class Cercle : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Translater ( int dx, int dy );
    // Mode d'emploi :
    //	Translate le cercle par rapport au coordonnées passées en paramètre
    // Contrat :
    //

	long int GetRayon ( );
    // Mode d'emploi :
    //	Renvoie le rayon du cercle
    // Contrat :
    //

    bool IsAgrege( );
    // Mode d'emploi :
    //	Renvoie false pour un cercle
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Cercle & operator = ( const Cercle & unCercle );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Cercle ( const Cercle & unCercle );
    // Mode d'emploi (constructeur de copie) :
    //	Construit une copie d'un cercle
    // Contrat :
    //
    
    Cercle ( long int fx=0, long int fy=0, long int frayon = 0, string name="", string fcommande="" );
    // Mode d'emploi :
    //	Initialise les attributs d'un cercle avec les paramètres du constructeur
    // Contrat :
    //

    virtual ~Cercle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point centre;
	long int rayon;
};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_
