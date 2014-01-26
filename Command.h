/*************************************************************************
                           Command  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Command>
//	Modélise une commande
//
//------------------------------------------------------------------------
class Modele;

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
	virtual void Execute ( Modele& fmodele ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual string GetCommande( );
    // Mode d'emploi :
    //	Retourne la ligne de commande associée à cette commande
    // Contrat :
    //

	virtual bool IsNewModel ( );
    // Mode d'emploi :
    //	Permet de savoir si la commande sert a créer un nouveau modele.
    // Contrat :
    //

    virtual void Undo ( Modele& fmodele );
    // Mode d'emploi :
    //
    // Contrat :
    //

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	Command ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Command ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//--------------------------- Autres définitions dépendantes de <Command>

#endif // Command_H_
