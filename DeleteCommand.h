/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier DeleteCommand.h) ------
#if ! defined ( DELETECOMMAND_H_ )
#define DELETECOMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "EltGeo.h"
#include "Command.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DeleteCommand>
//	Modélise une commande d'effacement d'une ou plusieurs forme
//
//------------------------------------------------------------------------


class DeleteCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 
	void Execute ( Modele& fmodele );
    // Mode d'emploi :
    //	Exécute une commande d'effacement de forme(s) du le modèle passé en paramètre
    // Contrat :
    //

    void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //Recrée l'objet supprimé tel qu'il était avant sa suppression
    // Contrat :
    //

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	DeleteCommand ( std::map< string, string > fname );
     // Mode d'emploi :Constructeur
     //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
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
	std::map< string, string > mapElt; //Stocke les noms des objets à supprimer
							  //et leur commandes pour recréer l'objet après destruction

};

//--------------------------- Autres définitions dépendantes de <DeleteCommand>

#endif // DeleteCommand_H_
