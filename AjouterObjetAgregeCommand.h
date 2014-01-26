/*************************************************************************
                AjouterObjetAgregeCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <AjouterObjetAgregeCommand> (fichier AjouterObjetAgregeCommand.h) ------
#if ! defined ( AJOUTEROBJETAGREGECOMMANDE_H_ )
#define AJOUTEROBJETAGREGECOMMANDE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AjouterObjetAgregeCommand>
//	Modélise une commande d'ajout d'objet agrégé
//
//------------------------------------------------------------------------

class AjouterObjetAgregeCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	
	void Execute ( Modele& fmodele );
    // Mode d'emploi :
    //	Exécute une commande d'ajout d'objet agrégé au modèle passé en paramètre
    // Contrat :
    //

    void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //	Annule une commande d'ajout d'objet agrégé dans le modèle
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
	AjouterObjetAgregeCommand ( std::set< string > flisteObjet, string fname, string fcommande );
    // Mode d'emploi :
    //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
    // Contrat :
    //

    virtual ~AjouterObjetAgregeCommand ( );
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
	std::set< string > listeObjet;
};

//--------------------------- Autres définitions dépendantes de <AjouterObjetAgregeCommand>

#endif // AjouterObjetAgregeCommand_H_
