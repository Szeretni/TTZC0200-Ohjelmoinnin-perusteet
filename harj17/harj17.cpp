/************************
Teht‰v‰: Harjoitus 17
Tekij‰: Hannu Oksman
Kuvaus:
Harjoitus 17 (Palautus vko 46)
Muokkaa edellist‰ ohjelmaa siten, ett‰ edell‰ m‰‰ritelty‰ tietuetyyppi‰
k‰ytet‰‰n my‰s kahden muun "koululaisen" tietojen tallentamiseen.
N‰iden kahden muun koululaisen tiedot alustetaan ao. muuttujien
m‰‰rittelyn yhteydess‰. Ainoastaan yhden koululaisen tiedot kysyt‰‰n
k‰ytt‰j‰lt‰ edellisen teht‰v‰n tapaan.

Tulosta kolmen koululaisen tiedot koulumatkan mukaisessa
suuruusj‰rjestyksess‰ (pienimm‰st‰ suurimpaan) n‰yt‰lle

Pvm: 26.10.2017
ver: 1.0 OksHa
************************/
#include <iostream>
using namespace std;
struct TIEDOT
{
	char etunimet[100];
	char sukunimi[100];
	float koulumatka;
	char osoite[100];
	char postinumero[100];
	int kengannumero;
};
const int MAX = 3;
int main(void)
{
	TIEDOT koululainen[10];
	koululainen[1] = { "koulu1", "lainen1", 5.7f, "osoi1", "post1", 1 };
	koululainen[2] = { "koulu2", "lainen2", 3.2f, "osoi2", "post2", 2 };
	cout << "Anna (kaikki) etunimesi: ";
	cin.getline(koululainen[0].etunimet, 100);
	cout << "Anna keng‰nnumero: ";
	cin >> koululainen[0].kengannumero;
	cout << "Anna sukunimi: ";
	cin >> ws;
	cin.getline(koululainen[0].sukunimi, 100);
	cout << "Anna koulumatka: ";
	cin >> koululainen[0].koulumatka;
	cout << "Anna osoitteesi: ";
	cin >> ws;
	cin.getline(koululainen[0].osoite, 100);
	cout << "Anna postinumero: ";
	cin >> koululainen[0].postinumero;
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (koululainen[j].koulumatka < koululainen[i].koulumatka)
			{
				TIEDOT temp = koululainen[i];
				koululainen[i] = koululainen[j];
				koululainen[j] = temp;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << endl << koululainen[i].sukunimi << " " << koululainen[i].etunimet << endl;
		cout << koululainen[i].osoite << endl;
		cout << koululainen[i].postinumero << endl;
		cout << koululainen[i].kengannumero << " " << koululainen[i].koulumatka << endl;
	}
}