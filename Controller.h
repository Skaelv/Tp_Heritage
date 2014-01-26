/*************************************************************************
                           Controller  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Controller> (fichier Controller.h) ------
#if ! defined ( CONTROLLER_H_ )
#define CONTROLLER_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Modele.h"
#include "Command.h"
#include "DeleteCommand.h"
#include "Command.h"
#include "TranslaterCommand.h"
#include "AjouterCercleCommand.h"
#include "AjouterRectangleCommand.h"
#include "AjouterLigneCommand.h"
#include "AjouterPolyligneCommand.h"
#include "AjouterObjetAgregeCommand.h"
#include "ClearCommand.h"
#include "ChargerCommand.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controller>
//	Modélise le controlleur de notre programme
//
//------------------------------------------------------------------------


class Controller
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	bool ObjetExistant( string objet );
    // Mode d'emploi :
    //Renvoie true si l'objet est dans le modele courant
    // Contrat :Sous traite a la methode de l'attribut modele
    //

	void ExecuterCommand ( Command *command );
    // Mode d'emploi :
    //Execute la commande passé en parametre
    // Contrat :
    //

	void Redo( );
    // Mode d'emploi :
    //Execute la dernière commande annulée
    // Contrat :
    //

	void Undo( );
    // Mode d'emploi :
    //Annule la dernière commande exécutée
    // Contrat :
    //

	void ClearRedo( );
	//Mode d'emploi :
	// Efface les commandes qui ne pourront plus être recrée car risque de conflit
	//Contrat :
	//

	void EnumererObjet( );
    // Mode d'emploi :
    //	Affiche dans la console les figures présentes actuellement dans le dessin
    // Contrat :
    //

	void Translater( Command *command );
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool Validation ( string commande, bool load=false );
	// Mode d'emploi :
    //		Retourne true, si commande passée en paramètre est valable
	//		False sinon
    // Contrat : 
    //


	bool IsaNumber( string number );
	// Mode d'emploi :
    //	Retourne true si la chaine passée en paramètre est un nombre
	//	False sinon
    // Contrat :
    //

	void Charger( string url );
	// Mode d'emploi :
    //Ajoute au modele courant les figures présentes dans le fichier passé en paramètre
    // Contrat : sous traite à la fonction vider du modele
    //

	void Sauvegarder( string url );
	// Mode d'emploi :
    //Sauvegarde le modele courant dans un nouveau fichier dont l'url est envoyé en parametre
    // Contrat : sous traite à la fonction vider du modele
    //
//------------------------------------------------- Surcharge d'opérateurs
    Controller & operator = ( const Controller & unController );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Controller ( const Controller & unController );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controller ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controller ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Modele modele;
	std::list<Command *> cmd;
	std::list<Command *>::iterator cmdIter;
};

//--------------------------- Autres définitions dépendantes de <Controller>

#endif // CONTROLLER_H_
