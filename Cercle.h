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
#include "EltGeo.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cercle>
//
//
//------------------------------------------------------------------------

class Cercle : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
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
    //
    // Contrat :
    //

    bool Translater ( int dx,int dy);
    // Mode d'emploi :
    //
    // Contrat :
    //
    Cercle ( string name="",int fx=0,int fy=0, int frayon = 0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point GetCentre ();
    // Mode d'emploi :
    //Renvoie le centre du cercle
    // Contrat :
    //

    int GetRayon ();
    // Mode d'emploi :
    //Renvoie le rayon du cercle
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
int rayon;
};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_
