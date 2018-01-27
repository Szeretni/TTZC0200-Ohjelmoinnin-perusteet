/************************
Tehtävä: Harjoitus 22 (Palautus vko 49)
Tekijä: Hannu Oksman
Kuvaus:
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

Pvm: 16.11.2017
ver: 1.0 OksHa
************************/
/*
//A-kohta int Valikko(void);

#include <iostream>
using namespace std;
const int MAARA = 10;
const int NIMI_PITUUS = 20;
int lisatyt_henkilot = 0;
int Valikko(void);
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};

int main(void)
{
	while(true)
	{
		int valinta = Valikko();
		REK henkilorekisteri[MAARA];
		switch (valinta)
		{
		case 0:
			exit(0);
			break;
		case 1:
			if (lisatyt_henkilot == MAARA)
			{
				cout << "Rekisteri on täynnä!\n";
			}
			else
			{
				for (int i = 0; i <= lisatyt_henkilot; i++)
				{
					if (i == lisatyt_henkilot)
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
				lisatyt_henkilot += 1;
			}
			break;
		case 2:
			for (int i = 0; i < lisatyt_henkilot; i++)
			{
				cout << "Henkilo " << i + 1 << ":" << endl;
				cout << "Nimi: " << henkilorekisteri[i].etunimi << endl;
				cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
				cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
				cout << endl;
			}
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
*/
/*
//B-kohta void TulostaHenkilo(TIEDOT );

#include <iostream>
using namespace std;
const int MAARA = 10;
const int NIMI_PITUUS = 20;
int lisatyt_henkilot = 0;
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};
int Valikko(void);
void TulostaHenkilo(REK henkilorekisteri[MAARA]);
int main(void)
{
	while (true)
	{
		int valinta = Valikko();
		REK henkilorekisteri[MAARA];
		switch (valinta)
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
				for (int i = 0; i <= lisatyt_henkilot; i++)
				{
					if (i == lisatyt_henkilot)
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
				lisatyt_henkilot += 1;
			}
			break;
		case 2:
			TulostaHenkilo(henkilorekisteri);
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

void TulostaHenkilo(REK henkilorekisteri[MAARA]) //näyttää vain ensimmäisen henkilön, koska ei lähetetty taulukon pituutta
{
	for (int i = 0; i < 1; i++)
	{
		cout << "Henkilo " << i + 1 << ":" << endl;
		cout << "Nimi: " << henkilorekisteri[i].etunimi << endl;
		cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
		cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
		cout << endl;
	}
}
*/
/*
//C-kohta void TulostaKaikkiHenkilot(TIEDOT [], int lkm);

#include <iostream>
using namespace std;
const int MAARA = 10;
const int NIMI_PITUUS = 20;
int lisatyt_henkilot = 0;
struct REK
{
	char etunimi[NIMI_PITUUS];
	float koulumatka;
	int hatun_koko;
};
int Valikko(void);
void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot);
int main(void)
{
	while (true)
	{
		int valinta = Valikko();
		REK henkilorekisteri[MAARA];
		switch (valinta)
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
				for (int i = 0; i <= lisatyt_henkilot; i++)
				{
					if (i == lisatyt_henkilot)
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
				lisatyt_henkilot += 1;
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
		cout << "Nimi: " << henkilorekisteri[i].etunimi << endl;
		cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
		cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
		cout << endl;
	}
}
*/

//D-kohta void LisaaHenkilo(TIEDOT [], int *lkm);

#include <iostream>
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
				LisaaHenkilo(henkilorekisteri,lkm);
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