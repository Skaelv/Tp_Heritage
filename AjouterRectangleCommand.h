/*************************************************************************
					AjouterRectangleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <AjouterRectangleCommand> (fichier AjouterRectangleCommand.h) ------
#if ! defined ( AJOUTERRECTANGLECOMMANDE_H_ )
#define AJOUTERRECTANGLECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AjouterRectangleCommand>
//	Modélise une commande d'ajout de rectangle
//
//------------------------------------------------------------------------

class AjouterRectangleCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 


	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //	Exécute une commande d'ajout de rectangle au modèle passé en paramètre
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //	Annule une commande d'ajout de rectangle au modèle
    // Contrat :
    //

    bool IsNewModel ();
	// Mode d'emploi :
    //
    // Contrat :
    //

    string GetCommande();
	// Mode d'emploi :
    //	Retourne la ligne de commande associée à cette commande
    // Contrat :
    //

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	AjouterRectangleCommand (string fname,string fcommande, long int fx1,long int fy1,long int fx2,long int fy2);
    // Mode d'emploi :
    //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
    // Contrat :
    //

    virtual ~AjouterRectangleCommand ( );
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
	long int x1;
	long int x2;
	long int y1;
	long int y2;
};

//--------------------------- Autres définitions dépendantes de <AjouterRectangleCommand>

#endif // AjouterRectangleCommand_H_
