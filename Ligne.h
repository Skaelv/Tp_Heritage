/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( LIGNE_H_ )
#define LIGNE_H_

//--------------------------------------------------- Interfaces utilisées
#include "EltGeo.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//	Modélise une ligne
//
//------------------------------------------------------------------------

class Ligne : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Translater ( int dx, int dy );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsAgrege( );
    // Mode d'emploi :
    //Renvoie false pour une ligne
    // Contrat :
    //

    Point GetP1( );
    // Mode d'emploi :
    //retourne une copie de p1 (utilisé pour reconstituer la commande Polyligne)
    // Contrat :

    Point GetP2( );
    // Mode d'emploi :
    //retourne une copie de p2 (utilisé pour reconstituer la commande Polyligne)
    // Contrat :

//------------------------------------------------- Surcharge d'opérateurs
    Ligne & operator = ( const Ligne & unLigne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne ( int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, string name = "", string commande = "" );
    // Mode d'emploi :
    //Constructeur d'une ligne, ses extrémités lui sont passées
    //en paramètres.
    // Contrat :
    //

    virtual ~Ligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Point p1;
	Point p2;
};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // LIGNE_H_
