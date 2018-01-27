/************************
Tehtävä: Harjoitus 23 (Palautus vko 50)
Tekijä: Hannu Oksman
Kuvaus:
Jaa aiemmin esitetty henkilörekisteri-ohjelma omiin "osa-projekteihin" ja
otsikkotiedostoihin. Laita pääohjelma omaan tiedostoon (paa.cpp),
aliohjelmat omaan tiedostoon (ali.cpp) ja
esittelyt omaan otsikkotiedostoon (esittely.h).

Projekti tulee koostaa toimivaksi Visual Studio-
ympäristösssä.

Pvm: 23.11.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
const int MAARA = 10;
const int NIMI_PITUUS = 20;
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};
int Valikko(void);
void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
void LisaaHenkilo(REK henkilorekisteri[MAARA], int *lkm);
int main(void)
{
	int lisatyt_henkilot = 0;
	while (true)
	{
		REK henkilorekisteri[MAARA];
		int *lkm = &lisatyt_henkilot;
		switch (Valikko())
		{
		case 0:
			exit(0);
			break;
		case 1:
			if (lisatyt_henkilot == MAARA)
			{
				cout << "Rekisteri on taynna!\n";
			}
			else
			{
				LisaaHenkilo(henkilorekisteri, lkm);
				lisatyt_henkilot++;
			}
			break;
		case 2:
			TulostaHenkilo(henkilorekisteri, lisatyt_henkilot);
			break;
		}
	}
}

int Valikko(void)
{
	int vastaus;
	cout << "VALIKKO\n";
	cout << "0 Lopeta\n";
	cout << "1 Lisaa henkilo\n";
	cout << "2 Nayta kaikki henkilot\n";
	cin >> vastaus;
	return vastaus;
}

void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	for (int i = 0; i < lisatyt_henkilot; i++)
	{
		cout << "Henkilo " << i + 1 << ":" << endl;
		cout << "Nimi:       " << henkilorekisteri[i].etunimi << endl;
		cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
		cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
		cout << endl;
	}
}

void LisaaHenkilo(REK henkilorekisteri[MAARA], int *lkm)
{
	for (int i = 0; i <= *lkm; i++)
	{
		if (i == *lkm)
		{
			cout << "Anna etunimi: ";
			cin >> ws;
			cin.getline(henkilorekisteri[i].etunimi, NIMI_PITUUS);
			cout << "Anna koulumatka: ";
			cin >> henkilorekisteri[i].koulumatka;
			cout << "Anna hatun koko: ";
			cin >> henkilorekisteri[i].hatun_koko;
		}
	}
}