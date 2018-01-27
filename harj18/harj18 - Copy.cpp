/************************
Teht‰v‰: Harjoitus 18
Tekij‰: Hannu Oksman
Kuvaus:
Harjoitus 18 (Palautus vko 46)
Tee ohjelma, joka kysyy viiden koiran nimet ja i‰t.
Tiedot tallennetaan tietuetaulukkoon.
a) j‰rjest‰ tiedot ik‰ -kent‰n mukaan suuruusj‰rjestykseen
(pienimm‰st‰ suurimpaan). Ohjelma tulostaa lopuksi
jarjestetyn taulukon n‰yt‰lle.
b) j‰rjest‰ tiedot nimi -kent‰n mukaan aakkosj‰rjestyksess‰
Ohjelma tulostaa lopuksi jarjestetyn taulukon n‰ytolle.

Lajittelu tulee toteuttaa siten, ett‰ se toimisi samoin
my‰s 50 tai 5000 koiran tapauksessa.

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
const int MAX = 5; //muokkaamalla t‰t‰ symbolista vakiota voi valita kuinka monen koiran tiedot halutaan tallentaa
int main(void)
{
	KOIRIEN_TIEDOT koira[MAX];
	for (int i = 0; i < MAX; i++)
	{
		cout << "Anna " << i + 1 << ". koiran nimi: ";
		cin >> ws;
		cin.getline(koira[i].nimi, 100);
		cout << "Anna " << i + 1 << ". koiran ik‰: ";
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
const int MAX = 5; //muokkaamalla t‰t‰ symbolista vakiota voi valita kuinka monen koiran tiedot halutaan tallentaa
const int KIRJAIN = 0; //k‰ytet‰‰n poimimaan nimi-taulun haluttu kirjain aakkosvertailua varten 
int main(void)
{
	KOIRIEN_TIEDOT koira[MAX];
	for (int i = 0; i < MAX; i++)
	{
		cout << "Anna " << i + 1 << ". koiran nimi: ";
		cin >> ws;
		cin.getline(koira[i].nimi, 100);
		cout << "Anna " << i + 1 << ". koiran ik‰: ";
		cin >> koira[i].ika;
	}
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (koira[j].nimi[KIRJAIN] < koira[i].nimi[KIRJAIN]) //vertaa koirien nimien ensimm‰ist‰ merkki‰
			//toinen tapa tehd‰ ylempi on k‰ytt‰‰ if (strcmp(koira[j].nimi,koira[i].nimi)<0)
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