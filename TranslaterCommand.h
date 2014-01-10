/*************************************************************************
                           TranslaterCommand  -  description
                             -------------------
    début                : 20 déc. 2013
    copyright            : (C) 2013 par kantoine
*************************************************************************/

//---------- Interface de la classe <TranslaterCommand> (fichier TranslaterCommand.h) ------
#if ! defined ( TranslaterCommand_H_ )
#define TranslaterCommand_H_
#include "EltGeo.h"
#include "Command.h"
#include "Modele.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TranslaterCommand>
//
//
//------------------------------------------------------------------------



class TranslaterCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	 TranslaterCommand (int fdx, int fdy, string fname);
     // Mode d'emploi :Constructeur
     //
     // Contrat :
     //


	void Execute (Modele& fmodele);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo (Modele& fmodele);
    // Mode d'emploi :
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
int dx,dy;
string name;
};

//--------------------------- Autres définitions dépendantes de <TranslaterCommand>

#endif // TranslaterCommand_H_
