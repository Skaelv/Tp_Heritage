/*************************************************************************
                    AJouterCercleCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <AJouterCercleCommand> (fichier AJouterCercleCommand.h) ------
#if ! defined ( AJOUTERCERCLECOMMANDE_H_ )
#define AJOUTERCERCLECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AJouterCercleCommand>
//	Modélise une commande d'ajout de cercle
//
//------------------------------------------------------------------------

class AjouterCercleCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 
	void Execute ( Modele& fmodele );
    // Mode d'emploi :
    //	Exécute la commande d'ajout de cercle au modèle passé en paramètre
    // Contrat :
    //

    void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //	Annule la commande d'ajout de cercle au modèle passé en paramètre
    // Contrat :
    //

    bool IsNewModel ( );
	// Mode d'emploi :
    //	
    // Contrat :
    //

    string GetCommande( );
	// Mode d'emploi :
    //	Retourne la ligne de commande associée à cette commande
    // Contrat :
    //

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	AjouterCercleCommand ( string fname, string fcommande, long int fx, long int fy, long int fr );
     // Mode d'emploi :
     //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
     // Contrat :
     //

	virtual ~AjouterCercleCommand ( );
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
	long int x;
	long int y;
	long int r;
};

//--------------------------- Autres définitions dépendantes de <AjouterCercleCommand>

#endif // AjouterCercleCommand_H_
