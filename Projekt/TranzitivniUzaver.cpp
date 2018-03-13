#include "stdafx.h"
#include "TranzitivniUzaver.h"


/**
Konstruktor tranzitivniho uzaveru
@param binarniRelace objekt binarni relace pro ktery se ma vytvorit tranzitivni uzaver
*/
TranzitivniUzaver::TranzitivniUzaver (BinarniRelace* binarniRelace)
{
	this->PripravitPole (binarniRelace->GetPocetPrvku ());
	for (int x = 0; x < this->GetPocetPrvku(); x++) {
		for (int y = 0; y < this->GetPocetPrvku(); y++) {
			if (x != y) {
				if (binarniRelace->ExistujeVztahMeziDvema (x, y)) {
					this->PridatVztah (x, y);
				}
			}
		}
	}
	for (int x = 0; x < this->GetPocetPrvku (); x++) {
		for (int y = 0; y < this->GetPocetPrvku (); y++) {
			if (x != y) {
				if ((!this->ExistujeVztahMeziDvema (y, x)) && (!this->ExistujeVztahMeziDvema(x,y))) {
					this->PridatVztah (x, y);
				}
			}
		}
	}
}
