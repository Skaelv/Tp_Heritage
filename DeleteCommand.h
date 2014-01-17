/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) ------
#if ! defined ( DELETECOMMAND_H_ )
#define DELETECOMMAND_H_
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
	 DeleteCommand (map<string,string> fname);
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
    //Recréer l'objet supprimé tel qu'il était avant sa suppression
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
map<string,string> mapElt; //Stocke les noms des objets à supprimer
							  //et leur commandes pour recréer l'objet après destruction

};

//--------------------------- Autres définitions dépendantes de <DeleteCommand>

#endif // DeleteCommand_H_
