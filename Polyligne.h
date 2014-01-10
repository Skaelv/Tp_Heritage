/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) ------
#if ! defined ( POLYLIGNE_H_ )
#define POLYLIGNE_H_


//--------------------------------------------------- Interfaces utilisées
#include "EltGeo.h"
#include "Ligne.h"
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Polyligne>
//
//
//------------------------------------------------------------------------

class Polyligne : public EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsAgrege();
    // Mode d'emploi :
    //Renvoie false pour une polyligne
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Polyligne & operator = ( const Polyligne & unPolyligne );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( const Polyligne & unPolyligne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyligne (  vector< pair<int,int> > flignes ,string fname="",string fcommande="");
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool AjouterLigne (Ligne fligne  );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Translater ( int dx, int dy );
    // Mode d'emploi :
    //Appelle la fonction translater de ligne sur chaques lignes du vector lignes
    // Contrat :
    //

    virtual ~Polyligne ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector< Ligne > lignes;
};

//--------------------------- Autres définitions dépendantes de <Polyligne>

#endif // POLYLIGNE_H_
