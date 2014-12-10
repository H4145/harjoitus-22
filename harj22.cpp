/*
Eetu Salo

Harjoitus 22 (Palautus vko 49)
Tee ohjelma, joka toimii henkilörekisterinä (max 10).
Ohjelma antaa käyttäjälle seuraavan valikon:

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta kaikki henkilot

Tallenna henkilöiden tiedot tietuetaulukkoon.
Tallennettavia tietoja ovat
etunimi (merkkijono)
koulumatka (liukuluku)
hatun koko (kokonaisluku)

Toteuta ensin koko ohjelma pääohjelmana.

Tämän jälkeen lisää seuraavat aliohjelmat:
a) int Valikko(void);

b) void TulostaHenkilo(TIEDOT );
c) void TulostaKaikkiHenkilot(TIEDOT [], int lkm);
d) void LisaaHenkilo(TIEDOT [], int *lkm);


*/



#include <iostream>
#include <cstring>
using namespace std;

struct HLO
{
	char nimi[32];
	float matka;
	int hattu;
};
const int MAX_HLO = 10;

int Valikko(void);
void TulostaKaikkiHenkilot(HLO[], int lkm);
void LisaaHenkilo(HLO[], int *lkm);
void TulostaHenkilo(HLO henkilo[]);

int main()
{
	HLO henkilo[MAX_HLO];
	int valinta=1;
	int lkm = 0;

	while (true)
	{
		valinta = Valikko();
		

		switch (valinta)
		{
			case 0:return 0;
			case 1:
				LisaaHenkilo(henkilo, &lkm);
				
				break;

			case 2:

				TulostaHenkilo(henkilo);
				break;
				
			case 3:
				
				 TulostaKaikkiHenkilot(henkilo, lkm);
				break;
		
					
		}

	}
}

int Valikko(void)
{
	int valinta;
	cout << "\nValikko\n\n";
	cout << "0. Lopetus\n";
	cout << "1. Uusi henkilo\n";
	cout << "2. Nayta henkilo\n";
	cout << "3. Nayta kaikki henkilot\n";
	cin >> valinta;
	return valinta;
}

void TulostaKaikkiHenkilot(HLO henkilo[], int lkm)
{
	
	for (int i = 0; i < lkm; i++)
	{ 
		cout << "\nNimi: " << henkilo[i].nimi << endl
		<< "Koulumatka: " << henkilo[i].matka << endl
		<< "Hatun koko: " << henkilo[i].hattu << endl << endl;
	}
}
void LisaaHenkilo(HLO p_henkilo[], int *lkm)
{
	cout << "Anna nimi: ";
	cin >> p_henkilo[*lkm].nimi;
	cout << "\nAnna koulumatka: ";
	cin >> p_henkilo[*lkm].matka;
	cout << "\nAnna hatun koko: ";
	cin >> p_henkilo[*lkm].hattu;
	(*lkm)++;
}

void TulostaHenkilo(HLO henkilo[])
{
	int nro;
	cout << "Tulostettavan henkilon numero? ";
	cin >> nro;
	if (nro > 10)
	{
		cout << " Danger: Overflow! ";
	}
	else
	{
		cout << "\n Nimi: " << henkilo[nro - 1].nimi << "\n Koulumatka: " << henkilo[nro - 1].matka << "\n Hatun koko: " << henkilo[nro - 1].hattu << endl;
	}
}