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
const int MAARA = 2;
const int NIMI_PITUUS = 10;
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};
int Valikko(REK henkilorekisteri[MAARA]);
void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
void LisaaHenkilo(REK henkilorekisteri[MAARA], int *lkm);
void TallennaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
int LueHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
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
		switch (Valikko(henkilorekisteri))
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
			int poistovastaus;
			cin >> poistovastaus;
			poistovastaus--;
			henkilorekisteri[poistovastaus] = { NULL };
			lisatyt_henkilot--;
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

int Valikko(REK henkilorekisteri[MAARA])
{
	for (int i = 0; i < MAARA; i++)
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
		cout << endl;
		cout << "Rekisterissa olevat henkilot:\n";
		for (int i = 0; i < MAARA; i++)
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

void LisaaHenkilo(REK henkilorekisteri[MAARA], int *lkm)
{
	for (int i = 0; i <= MAARA; i++)
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
		kirjoitus << "\"NIMI\"" << ":" << henkilorekisteri[i].etunimi << endl;
		kirjoitus << "\"KOULUMATKA\"" << ":" << henkilorekisteri[i].koulumatka << endl;
		kirjoitus << "\"HATUN_KOKO\"" << ":" << henkilorekisteri[i].hatun_koko;
	}
	kirjoitus.close();
}

int LueHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	cout << "Tuonti korvaa rekisterin tiedot! Haluatko jatkaa? k/e: ";
	char vastaus;
	cin >> vastaus;
	if (vastaus == 'e')
	{
		return lisatyt_henkilot;
	}
	else
	{
		lisatyt_henkilot = 0;
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
					haefile.getline(selite, 256, ':');
					//haefile.ignore(256, ':');
					haefile >> henkilorekisteri[i].etunimi;
					haefile >> ws;
					haefile.getline(selite, 256, ':');
					haefile >> henkilorekisteri[i].koulumatka;
					haefile >> ws;
					haefile.getline(selite, 256, ':');
					haefile >> henkilorekisteri[i].hatun_koko;
					haefile >> ws;
					lisatyt_henkilot++;
				}
			}
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
			cout << "Tallennettuja tietoja ei ole." << endl;
		}
		return lisatyt_henkilot;
	}
}