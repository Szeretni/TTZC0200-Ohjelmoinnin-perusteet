/************************
Tehtävä: Harjoitus 25 (Palautus vko 50)
Tekijä: Hannu Oksman
Kuvaus:

Muuta harjoituksen 24 toiminnallisuutta niin, etta
varaat henkilötiedoille tilan dynaamisesti (max 10 hlo).
Muuta valikko alla olevan esimerkin mukaiseksi ja toteuta valikossa
näkyvät toiminnot.

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta henkilo
3 Nayta kaikki henkilot
4 Poista henkilon tiedot

Pvm: 7.12.2017
ver: 1.0 OksHa
************************/
#include <iostream>
#include <fstream>
using namespace std;
const int NIMI_PITUUS = 10;
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};
int Valikko(REK henkilorekisteri[], int vastaus);
void TulostaHenkilo(REK henkilorekisteri[], int lisatyt_henkilot, int vastaus, int mode);
void LisaaHenkilo(REK henkilorekisteri[], int *lkm, int vastaus);
int main(void)
{
	cout << "Kuinka monipaikkasen rekisterin haluat? ";
	int vastaus;
	cin >> vastaus;
	int lisatyt_henkilot = 0;
	REK *henkilorekisteri = { NULL };
	henkilorekisteri = new REK[vastaus];

	int *lkm = &lisatyt_henkilot;
	while (true)
	{
		switch (Valikko(henkilorekisteri, vastaus))
		{
		case 0:
			exit(0);
			break;
		case 1:
			if (lisatyt_henkilot == vastaus)
			{
				cout << "Rekisteri on taynna!\n";
			}
			else
			{
				LisaaHenkilo(henkilorekisteri, lkm, vastaus);
				//lisatyt_henkilot++;
			}
			break;
		case 2:
		{
			cout << "Minka henkilon tiedot haluat nahda? " << endl;
			cin >> *lkm;
			int mode = 1;
			TulostaHenkilo(henkilorekisteri, *lkm, vastaus, mode);
		}
		break;
		case 3:
		{
			int mode = 0;
			TulostaHenkilo(henkilorekisteri, lisatyt_henkilot, vastaus, mode);
			break;
		}
		case 4:
		{
			cout << "Minka henkilon tiedot haluat poistaa? " << endl;
			int poistovastaus;
			cin >> poistovastaus;
			poistovastaus--;
			//delete[] henkilorekisteri[poistovastaus];
			henkilorekisteri[poistovastaus] = { NULL };
			lisatyt_henkilot--;
		}
		break;
		}
	}
}

int Valikko(REK henkilorekisteri[], int vastaus)
{
	for (int i = 0; i < vastaus; i++)
	{
		if (henkilorekisteri)
		{
			cout << "Paikan numero: " << i << ", osoite: " << &henkilorekisteri[i] << " ja sisalto: " << henkilorekisteri[i].etunimi << endl;
		}
		else
		{
			break;
		}
	}
	int vastaus1;
	cout << "VALIKKO\n";
	cout << "0 Lopeta\n";
	cout << "1 Lisaa henkilo\n";
	cout << "2 Nayta henkilo\n";
	cout << "3 Nayta kaikki henkilot\n";
	cout << "4 Poista henkilon tiedot\n";
	cin >> vastaus1;
	return vastaus1;
}

void TulostaHenkilo(REK henkilorekisteri[], int lisatyt_henkilot, int vastaus, int mode)
{
	if (lisatyt_henkilot == 0)
	{
		cout << "\nRekisterissa ei ole henkiloita.\n\n";
	}
	else
	{
		if (mode == 1)
		{
			lisatyt_henkilot--;
			cout << endl;
			for (int i = 0; i < vastaus; i++)
			{
				if (henkilorekisteri && i == lisatyt_henkilot)
				{
					cout << "Henkilo " << i + 1 << ":" << endl;
					cout << "Nimi:       " << henkilorekisteri[i].etunimi << endl;
					cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
					cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
					cout << endl;
				}
			}
		}
		if (mode == 0)
		{
			cout << endl;
			cout << "Rekisterissa olevat henkilot:\n";
			for (int i = 0; i < vastaus; i++)
			{
				if (henkilorekisteri)
				{
					cout << "Henkilo " << i + 1 << ":" << endl;
					cout << "Nimi:       " << henkilorekisteri[i].etunimi << endl;
					cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
					cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
					cout << endl;
				}
			}
		}
	}
}

void LisaaHenkilo(REK henkilorekisteri[], int *lkm, int vastaus)
{
	for (int i = 0; i <= vastaus; i++)
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
	(*lkm)++; // *lkm++ kasvattaisi ensim lkm eli vaihtaa muistipaikkaa ja sitten * sisältöön
}