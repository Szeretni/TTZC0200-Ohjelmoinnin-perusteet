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
#include "esittely.h"
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