/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CLEARCOMMANDE_H_ )
#define CLEARCOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Modele.h"
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cercle>
//
//
//------------------------------------------------------------------------

class ClearCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 ClearCommand ();
     // Mode d'emploi :
     //
     // Contrat :
     //


	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsNewModel ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ClearCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Modele OldModel;
};

//--------------------------- Autres définitions dépendantes de <ClearCommand>

#endif // ClearCommand_H_
