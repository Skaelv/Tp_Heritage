/*************************************************************************
                           TranslaterCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <TranslaterCommand> (fichier TranslaterCommand.h) ------
#if ! defined ( TRANSLATERCOMMAND_H_ )
#define TRANSLATERCOMMAND_H_

//--------------------------------------------------- Interfaces utilisées
#include "EltGeo.h"
#include "Command.h"
#include "Modele.h"
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TranslaterCommand>
//	Modélise une commande de translation d'un objet
//
//------------------------------------------------------------------------



class TranslaterCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //	Exécute une commande de translation sur un objet du modèle passé en paramètre
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
    //	Annule une commande de translation sur un objet du modèle
    // Contrat :
    //

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

	TranslaterCommand ( int fdx, int fdy, string fname );
    // Mode d'emploi :Constructeur
    //
    // Contrat :
    //

    virtual ~TranslaterCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	int dx;
	int dy;
	string name;
};

//--------------------------- Autres définitions dépendantes de <TranslaterCommand>

#endif // TranslaterCommand_H_
