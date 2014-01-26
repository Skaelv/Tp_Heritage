/*************************************************************************
                           ClearCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ClearCommand> (fichier ClearCommand.h) ------
#if ! defined ( CLEARCOMMANDE_H_ )
#define CLEARCOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Modele.h"
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ClearCommand>
//	Modélise une commande d'effacement d'un modèle
//
//------------------------------------------------------------------------

class ClearCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Execute ( Modele& fmodele );
    // Mode d'emploi :
    //	Exécute une commande d'effacement du modèle passé en paramètre
    // Contrat :
    //

    void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //	Annule une commande d'effacement du modèle
    // Contrat :
    //

    bool IsNewModel ();
    // Mode d'emploi :
    //
    // Contrat :
    //

	//-------------------------------------------- Constructeurs - destructeur
	ClearCommand ();
    // Mode d'emploi :
    //	Construit une commande d'effacement d'un modèle
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
