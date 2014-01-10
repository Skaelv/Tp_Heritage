/*************************************************************************
                           ObjetAgrege  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ObjetAgrege> (fichier ObjetAgrege.h) ------
#if ! defined ( OBJETAGREGE_H_ )
#define OBJETAGREGE_H_

//--------------------------------------------------- Interfaces utilisées
#include "EltGeo.h"
#include <list>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ObjetAgrege>
//
//
//------------------------------------------------------------------------

class ObjetAgrege : public EltGeo
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
    //Renvoie true pour un ObjetAgrege
    // Contrat :
    //

    string DeleteElement(string objetASupprimer);
    // Mode d'emploi :
    //Verifie si le nom d'objet en parametre est dans la liste d'objet agrege
    //Le supprime si c'est le cas, et renvoie le nom des objets agreges auxquels
    //appartenait l'objet supprimé
    // Contrat :
    //

    void AddElement(EltGeo * element);
//------------------------------------------------- Surcharge d'opérateurs
    ObjetAgrege & operator = ( const ObjetAgrege & unObjetAgrege );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ObjetAgrege ( const ObjetAgrege & unObjetAgrege );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ObjetAgrege (list<EltGeo*> flistObjet,string fname="",string fcommande="" );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ObjetAgrege ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
list<EltGeo *> listObjet;
};

//--------------------------- Autres définitions dépendantes de <ObjetAgrege>

#endif // OBJETAGREGE_H_
