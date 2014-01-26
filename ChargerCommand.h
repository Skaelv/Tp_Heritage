/*************************************************************************
                           ChargerCommand  -  description
                             -------------------
    d�but                : 20 d�c. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <ChargerCommand> (fichier ChargerCommand.h) ------
#if ! defined ( CHARGERCOMMAND_H_ )
#define CHARGERCOMMAND_H_

//--------------------------------------------------- Interfaces utilis�es
#include "Modele.h"
#include "Command.h"
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <ChargerCommand>
//	Modélise une commande de chargement d'un fichier dans un modèle
//
//------------------------------------------------------------------------
class Controller;

class ChargerCommand : public Command
{


//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- M�thodes publiques
	void Execute ( Modele& fmodele );
    // Mode d'emploi :
    //	Exécute une commande de chargement de fichier dans le modèle passé en paramètre
    // Contrat :
    //

    void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //	Annule une commande de chargement de fichier dans le modèle
    // Contrat :
    //

    bool IsNewModel ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

	//-------------------------------------------- Constructeurs - destructeur
	ChargerCommand( string fname, Controller * c );
	// Mode d'emploi :
    //	Construit une nouvelle commande en initialisant les attributs avec les paramètres
    // Contrat :
    //

	virtual ~ChargerCommand( void );
	// Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s
	string nomFichier;
	Controller * control;
	Modele OldModel;
};
//--------------------------- Autres d�finitions d�pendantes de <ChargerCommand>


#endif // ChargerCommand_H_

