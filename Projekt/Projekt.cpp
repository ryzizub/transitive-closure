// Projekt.cpp: Definuje vstupní bod pro konzolovou aplikaci.
//

#include "stdafx.h"
#include "BinarniRelace.h"
#include <iostream>
#include "TranzitivniUzaver.h"

using namespace std;

/**
	Základní kostra programu
*/
int main ()
{
	string name;
	/**
	Vytvoreni objektu pro binarni relaci
	*/
	BinarniRelace* binarniRelace;
	binarniRelace = new BinarniRelace ();
	cout << "napiste jmeno souboru s ulozenou binarni relaci s priponou .txt: ";
	cin >> name;
	/**
	Nacteni binarni relace ze souboru
	*/
	binarniRelace->NacistZeSouboru (name);
	/**
	Vytvoreni objektu pro tranzitivni uzaver
	*/
	TranzitivniUzaver* tranzitivniUzaver;
	tranzitivniUzaver = new TranzitivniUzaver (binarniRelace);
	cout << "napiste jmeno souboru pro ulozeni tranzitivnihoUzaveru s priponou .txt: ";
	cin >> name;
	/**
	Vypsani tranzitivniho uzaveru do souboru
	*/
	tranzitivniUzaver->VypsatDoSouboru (name);
	cout << "HOTOVO";
	delete (tranzitivniUzaver);
	delete(binarniRelace);
	int x;
	cin >> x;
    return 0;
}