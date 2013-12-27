/*
 * main.cpp
 *
 *  Created on: 22 déc. 2013
 *      Author: kevin
 */




#include "Controller.h"
using namespace std;
#include <iostream>

int main ()
{
	Controller Cont;
	string commande;
	cout << "# Entrez une commande" << endl;
	getline(cin,commande);
	cout << commande << endl;
	while (commande!="EXIT")
	{
		Cont.Validation(commande);
		cout << "Entrez une commande" << endl;
		getline(cin,commande);
	}

//
//	test = Cont.Validation("OA Name 4 5 8");
//	test = Cont.Validation("L Name 4 5 8");
//	test = Cont.Validation("L Name 4 5 4 5");
//	test = Cont.Validation("R Name 4 5 8 13.3");
//	test = Cont.Validation("PL Name 4 5 8 12 12 12 12 12 12 14 4 3");
//	test = Cont.Validation("PL Name 4 5 8 12 12 12 12 12 12 14 4 3 8");
//	test = Cont.Validation("C Name 4 5 8 10");
//	test = Cont.Validation("C Name 4 5 8");

	return 0;
}
