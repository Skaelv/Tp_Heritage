/*************************************************************************
                           EltGeo  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <EltGeo> (fichier EltGeo.h) ------
#if ! defined ( ELTGEO_H_ )
#define ELTGEO_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EltGeo>
//	Modélise la super-classe d'une forme
//
//------------------------------------------------------------------------

class EltGeo
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	virtual void Translater( int dx, int dy );
    // Mode d'emploi :
    //	Translate la forme par rapport aux coordonnées passées en paramètre
    // Contrat :
    //

	string GetCommande( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	string GetName( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual bool IsAgrege( ) = 0;
    // Mode d'emploi :
    //Sert a determiner si l'objet est un objet agrege ou non
    // Contrat :
    //

	virtual string DeleteElement( string objetASupprimer );
    // Mode d'emploi :
    // Methode utile pour supprimer l'objet si il appartient a la liste de l'objet agrege
    // Contrat : Virtual mais appelé uniquement pour les Objets Agreges.
    //

	virtual void AddElement( EltGeo * objetAInserer );
    // Mode d'emploi :
    // Methode utile pour ajouterl'objet à l'element agrege courant
    // Contrat : Virtual mais appelé uniquement pour les Objets Agreges.
    //
	//------------------------------------------------- Surcharge d'opérateurs
    EltGeo & operator = ( const EltGeo & unEltGeo );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EltGeo ( const EltGeo & unEltGeo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EltGeo ( string fname = "", string fcommande = "" );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EltGeo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string name;
    string commande;
};

//--------------------------- Autres définitions dépendantes de <EltGeo>

#endif // ELTGEO_H_
