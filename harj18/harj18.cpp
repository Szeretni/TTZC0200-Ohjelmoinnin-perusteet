/************************
Tehtävä: Harjoitus 18
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 18 (Palautus vko 46)
Tee ohjelma, joka kysyy viiden koiran nimet ja iät.
Tiedot tallennetaan tietuetaulukkoon.
a) järjestä tiedot ikä -kentän mukaan suuruusjärjestykseen
(pienimmästä suurimpaan). Ohjelma tulostaa lopuksi
jarjestetyn taulukon näytälle.
b) järjestä tiedot nimi -kentän mukaan aakkosjärjestyksessä
Ohjelma tulostaa lopuksi jarjestetyn taulukon näytolle.

Lajittelu tulee toteuttaa siten, että se toimisi samoin
myäs 50 tai 5000 koiran tapauksessa.

Pvm: 26.10.2017
ver: 1.0 OksHa
************************/

//A-kohta

/*#include <iostream>
using namespace std;
struct KOIRIEN_TIEDOT
{
	char nimi[100];
	float ika;
};
const int MAX = 5; //muokkaamalla tätä symbolista vakiota voi valita kuinka monen koiran tiedot halutaan tallentaa
int main(void)
{
	KOIRIEN_TIEDOT koira[MAX];
	for (int i = 0; i < MAX; i++)
	{
		cout << "Anna " << i + 1 << ". koiran nimi: ";
		cin >> ws;
		cin.getline(koira[i].nimi, 100);
		cout << "Anna " << i + 1 << ". koiran ikä: ";
		cin >> koira[i].ika;
	}
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (koira[j].ika < koira[i].ika)
			{
				KOIRIEN_TIEDOT temp = koira[i];
				koira[i] = koira[j];
				koira[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << koira[i].nimi << " " << koira[i].ika << endl;
	}
}
*/
//B-kohta
#include <iostream>
using namespace std;
struct KOIRIEN_TIEDOT
{
	char nimi[100];
	float ika;
};
const int MAX = 5; //muokkaamalla tätä symbolista vakiota voi valita kuinka monen koiran tiedot halutaan tallentaa
int main(void)
{
	KOIRIEN_TIEDOT koira[MAX];
	for (int i = 0; i < MAX; i++)
	{
		cout << "Anna " << i + 1 << ". koiran nimi: ";
		cin >> ws;
		cin.getline(koira[i].nimi, 100);
		cout << "Anna " << i + 1 << ". koiran ikä: ";
		cin >> koira[i].ika;
	}
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (strcmp(koira[j].nimi,koira[i].nimi)<0) //jos erotus on negatiivinen, eli edellinen on jälkimmäistä suurempi, niin käännetään
			{
				KOIRIEN_TIEDOT temp = koira[i];
				koira[i] = koira[j];
				koira[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << koira[i].nimi << " " << koira[i].ika << endl;
	}
}