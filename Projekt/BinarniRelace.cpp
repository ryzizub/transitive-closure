#include "stdafx.h"
#include "BinarniRelace.h"
#include <iostream>;
#include <fstream>

using namespace std;


/**
Konstruktor binarni relace
*/
BinarniRelace::BinarniRelace ()
{
	this->poleVztahu = new int*[0];
	this->pocetPrvku = 0;
	this->pocetAktivnichVztahu = 0;
}


/**
Destruktor binarni relace
*/
BinarniRelace::~BinarniRelace ()
{
	delete (this->poleVztahu);
}


/**
Prida vzstah do pole
@param x prvni prvek
@param y druhy prvek
*/
void BinarniRelace::PridatVztah (const int x, const int y) {
	this->poleVztahu[x][y] = 1;
	this->pocetAktivnichVztahu++;
}


/**
Vypise binarni relaci na obrazovku
*/
void BinarniRelace::Vypsat () {
	for (int x = 0; x < this->pocetPrvku; x++) {
		for (int y = 0; y < this->pocetPrvku; y++) {
			if (this->poleVztahu[x][y] == 1) {
				cout << x << " " << y << endl;
			}
		}
	}
}


/**
Pripravi pole pro implementaci binarni relace za pomoci zadane kapacity
@param kapacita pocet prvku
*/
void BinarniRelace::PripravitPole (const int kapacita) {
	this->poleVztahu = new int*[kapacita];
	for (int i = 0; i < kapacita; ++i) {
		this->poleVztahu[i] = new int[kapacita];
	}
	this->pocetPrvku = kapacita;
	this->Vycistit ();
	this->ZrusitVztahySamNaSebe ();
}


/**
Vycistit cele pole v binarni relaci
*/
void BinarniRelace::Vycistit () {
	for (int x = 0; x < this->pocetPrvku; x++) {
		for (int y = 0; y < this->pocetPrvku; y++) {
			this->poleVztahu[x][y] == 0;
		}
	}
}


/**
Funkce která zrusi vsechny vztahy sam na sebe
*/
void BinarniRelace::ZrusitVztahySamNaSebe () {
	for (int x = 0; x < this->pocetPrvku; x++) {
		for (int y = 0; y < this->pocetPrvku; y++) {
			if (x == y) {
				if (this->poleVztahu[x][y] == 1) {
					this->pocetAktivnichVztahu--;
				}
				this->poleVztahu[x][y] == 2;
			}
		}
	}
}


/**
Funkce ktera nahraje binarni relaci do souboru
@param name jmeno souboru 
*/
void BinarniRelace::NacistZeSouboru (const string name) {
	ifstream soubor;
	soubor.open (name);
	if (soubor.is_open ())
	{
		int pocet;
		soubor >> pocet;
		this->PripravitPole (pocet);
		while (!soubor.eof ()) {
			int x;
			int y;
			soubor >> x >> y;
			this->PridatVztah(x, y);
		}
		soubor.close ();
	}
	else {
		cout << "Není možno otevøít soubor" << endl;
	}
}


/**
Funkce pro vypis binarni relace do souboru
@param name jmeno souboru do ktereho se nahraje binarni relace
*/
void BinarniRelace::VypsatDoSouboru (const string name) {
	ofstream soubor (name);
	soubor << this->pocetAktivnichVztahu << endl;
	for (int x = 0; x < this->pocetPrvku; x++) {
		for (int y = 0; y < this->pocetPrvku; y++) {
			if (this->poleVztahu[x][y] == 1) {
				soubor << x << " " << y << endl;
			}
		}
	}
}


/**
Vraci pocet prvku
@return value pocet prvku
*/
int BinarniRelace::GetPocetPrvku ()const {
	return this->pocetPrvku;
}


/**
Vraci odpoved na otazku zda existuje vztah mezi dvema 
@return value true nebo false
*/
bool BinarniRelace::ExistujeVztahMeziDvema (const int x, const int y)const {
	if (this->poleVztahu[x][y] == 1) {
		return true;
	}
	else {
		return false;
	}
}


/**
Funkce pro ziskani poctu aktivnich vztahu
@return value vraci pocet aktivnich vztahu
*/
int BinarniRelace::GetPocetAktivnichVztahu ()const {
	return this->pocetAktivnichVztahu;
}