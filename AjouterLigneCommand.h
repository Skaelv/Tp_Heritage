/*************************************************************************
                    AjouterLigneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <AjouterLigneCommand> (fichier AjouterLigneCommand.h) ------
#if ! defined ( AJOUTERLIGNECOMMANDE_H_ )
#define AJOUTERLIGNECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AjouterLigneCommand>
//	Modélise une commande d'ajout de ligne
//
//------------------------------------------------------------------------

class AjouterLigneCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 
	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //	Exécute la commande d'ajout de ligne au modèle passé en paramètre
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //	Annule la commande d'ajout de ligne au modèle
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

	AjouterLigneCommand ( string fname, string fcommande, long int fx1, long int fy1, long int fx2, long int fy2 );
    // Mode d'emploi :
    //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
    // Contrat :
    //

    virtual ~AjouterLigneCommand ( );
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
	int x1;
	int x2;
	int y1;
	int y2;
};

//--------------------------- Autres définitions dépendantes de <AjouterLigneCommand>

#endif // AjouterLigneCommand_H_
