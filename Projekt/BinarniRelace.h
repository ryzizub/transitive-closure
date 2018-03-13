#pragma once
#include <string>

using namespace std;

/**
 Trida predstavujici binarni relaci
*/
class BinarniRelace
{
public:
	BinarniRelace ();
	~BinarniRelace ();
	void PridatVztah (const int x, const int y);
	void Vypsat();
	void Vycistit ();
	void NacistZeSouboru (const string name);
	void PripravitPole (const int x);
	void VypsatDoSouboru (const string name);
	int GetPocetPrvku ()const;
	bool ExistujeVztahMeziDvema (const int x, const int y)const;
	int GetPocetAktivnichVztahu ()const;
	void ZrusitVztahySamNaSebe ();
private:
	/**
	pole jednotlivych vztahu
	*/
	int** poleVztahu;

	/**
	Pocet prvku v relaci
	*/
	int pocetPrvku;

	/**
	Pocet aktivnich vztahu
	*/
	int pocetAktivnichVztahu;
};

