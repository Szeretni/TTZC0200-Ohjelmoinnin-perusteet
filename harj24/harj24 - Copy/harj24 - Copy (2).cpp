/************************
Tehtävä: Harjoitus 24 (Palautus vko 17)
Tekijä: Hannu Oksman
Kuvaus:
Muuta harjoitusta 22 niin, etta valikko nayttaa seuraavalta:

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta henkilo
3 Nayta kaikki henkilot
4 Poista henkilon tiedot
5 Tallenna tiedot tiedostoon
6 Hae tiedot tiedostosta


ja toteuta valikossa näkyvät toiminnot.

Valitse haluamasi tallennusformaatti.

Pvm: 7.12.2017
ver: 1.0 OksHa
************************/
#include <iostream>
#include <fstream>
using namespace std;
const int MAARA = 2;
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
void TallennaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
int LueHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
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
				//lisatyt_henkilot++;
			}
			break;
		case 2:
		{
			cout << "Minka henkilon tiedot haluat nahda? " << endl;
			cin >> *lkm;
			TulostaHenkilo(henkilorekisteri, *lkm);
		}
			break;
		case 3:
			TulostaHenkilo(henkilorekisteri, lisatyt_henkilot);
			break;
		case 4:
			{
			cout << "Minka henkilon tiedot haluat poistaa? " << endl;
			cin >> *lkm;
			lkm = NULL;
			}
			break;
		case 5:
			TallennaHenkilo(henkilorekisteri, lisatyt_henkilot);
			break;
		case 6:
			lisatyt_henkilot = LueHenkilo(henkilorekisteri, lisatyt_henkilot);
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
	cout << "2 Nayta henkilo\n";
	cout << "3 Nayta kaikki henkilot\n";
	cout << "4 Poista henkilon tiedot\n";
	cout << "5 Tallenna tiedot tiedostoon\n";
	cout << "6 Hae tiedot tiedostosta\n";
	cin >> vastaus;
	return vastaus;
}

void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	if (lisatyt_henkilot == 0)
	{
		cout << "\nRekisterissa ei ole henkiloita.\n\n";
	}
	else
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
	(*lkm)++; // *lkm++ kasvattaisi ensim lkm eli vaihtaa muistipaikkaa ja sitten * sisältöön
}

void TallennaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	ofstream kirjoitus("harj24.txt");
	for (int i = 0; i < lisatyt_henkilot; i++)
	{
		//kirjoitus << "\"HENKILO\"" << ":" << i + 1 << endl;
		kirjoitus << "\"NIMI\"" << ":"<< henkilorekisteri[i].etunimi << endl;
		kirjoitus << "\"KOULUMATKA\"" << ":" << henkilorekisteri[i].koulumatka << endl;
		kirjoitus << "\"HATUN_KOKO\"" << ":" <<henkilorekisteri[i].hatun_koko;
	}
	kirjoitus.close();
}

int LueHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	ifstream haefile("harj24.txt");
	if (haefile.is_open())
	{
		char selite[256];
		for (int i = 0; ; i++)
		{
			if (haefile.peek() == EOF)
			{
				break;
			}

			else
			{
				cout << endl;
				haefile.getline(selite, 256, ':');
				//haefile.ignore(256, ':');
				haefile >> henkilorekisteri[i].etunimi;
				haefile >> ws;
				cout << selite << ":" << henkilorekisteri[i].etunimi << endl;
				haefile.getline(selite, 256, ':');
				haefile >> henkilorekisteri[i].koulumatka;
				haefile >> ws;
				cout << selite << ":" << henkilorekisteri[i].koulumatka << endl;
				haefile.getline(selite, 256, ':');
				haefile >> henkilorekisteri[i].hatun_koko;
				haefile >> ws;
				cout << selite << ":" << henkilorekisteri[i].hatun_koko << endl;
				lisatyt_henkilot++;
			}
		}
		cout << endl;
		/*while (haefile.peek() != EOF)
		{
			haefile >> henkilorekisteri[i].etunimi >> henkilorekisteri[i].koulumatka >> henkilorekisteri[i].hatun_koko;
			haefile.get();
			cout << henkilorekisteri[i].etunimi << henkilorekisteri[i].koulumatka << henkilorekisteri[i].hatun_koko << endl;	
		}*/
		haefile.close();
	}
	else
	{
		cout << "Tallennettuja tietoja ei ole" << endl;
	}
	return lisatyt_henkilot;
}
