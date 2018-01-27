/************************
Tehtävä: Harjoitus 15
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 15 (Palautus vko 45)

Tee ohjelma, joka kysyy henkilötietosi seuraavasti:
Anna (kaikki) etunimesi (merkkijono):
Anna kengannumero (kokonaisluku):
Anna sukunimi (merkkijono):
Anna koulumatka (reaaliluku):
Anna osoitteesi:
Anna postinumero:

Ohjelma tulostaa tiedot seuraavasti:
sukunimi etunimet
osoite
postinumero
kengannumero ja koulumatka

Käytä C++:n cin- ja cout-olioita ohjelman toteuttamiseen.

Pvm: 5.10.2017
ver: 1.0 OksHa
************************/
#include <iostream>
using namespace std;
char etunimet[100], sukunimi[100], osoite[100];
int kengannumero, postinumero;
float koulumatka;
int main(void)
{
	cout << "Anna (kaikki) etunimesi: ";
	cin.getline(etunimet, 100);
	cout << "Anna kengännumero: ";
	cin >> kengannumero;
	cout << "Anna sukunimi: ";
	cin >> ws;
	cin.getline(sukunimi, 100);
	cout << "Anna koulumatka: ";
	cin >> ws >> koulumatka;
	cout << "Anna osoitteesi: ";
	cin >> ws;
	cin.getline(osoite, 100);
	cout << "Anna postinumero: ";
	cin >> postinumero;
	cout << endl << sukunimi << " " << etunimet << endl;
	cout << osoite << endl;
	cout << postinumero << endl;
	cout << kengannumero << " " << koulumatka << endl;
}