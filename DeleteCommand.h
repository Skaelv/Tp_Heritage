/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) ------
#if ! defined ( DeleteCommand_H_ )
#define DeleteCommand_H_
#include "EltGeo.h"
#include "Command.h"
#include "Modele.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DeleteCommand>
//
//
//------------------------------------------------------------------------



class DeleteCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 DeleteCommand (vector<string> fname);
     // Mode d'emploi :Constructeur
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


    virtual ~DeleteCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector<string> nomElt; //Stocke les noms des objets à supprimer
						  //Apres appel de Execute : stocke les commandes pour recréer l'objet

};

//--------------------------- Autres définitions dépendantes de <DeleteCommand>

#endif // DeleteCommand_H_
