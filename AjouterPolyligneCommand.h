/*************************************************************************
                    AjouterPolyligneCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <AjouterPolyligneCommand> (fichier AjouterPolyligneCommand.h) ------
#if ! defined ( AJOUTERPOLYLIGNECOMMANDE_H_ )
#define AJOUTERPOLYLIGNECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AjouterPolyligneCommand>
//	Modélise une commande d'ajout de polyligne
//
//------------------------------------------------------------------------

class AjouterPolyligneCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	
	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //	Exécute une commande d'ajout de polyligne au modèle passé en paramètre
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //	Annule une commande d'jout de polyligne au modèle
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
	AjouterPolyligneCommand (string fname,string fcommande, vector<pair<long int,long int> > fligne);
    // Mode d'emploi :
    //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
    // Contrat :
    //

    virtual ~AjouterPolyligneCommand ( );
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
	std::vector< std::pair< long int, long int > > lignes;
};

//--------------------------- Autres définitions dépendantes de <AjouterPolyligneCommand>

#endif // AjouterPolyligneCommand_H_
