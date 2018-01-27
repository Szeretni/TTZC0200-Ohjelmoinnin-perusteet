/************************
Tehtävä: Harjoitus 16
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 16 (Palautus vko 45)
Tee ohjelma, joka kysyy henkilotietosi ja tallentaa ne tietueeseen.
Tietueeseen talletetaan seuraavat tiedot:
etunimi (merkkijono; C:n merkkitaulukko)
sukunimi (merkkijono; C:n merkkitaulukko)
koulumatka (reaaliluku)
osoite (merkkijono; C:n merkkitaulukko)
postinumero (merkkijono; C:n merkkitaulukko)
kengannumero (kokonaisluku)

Ohjelma tulostaa lopuksi tietueen tiedot naytölle.

Pvm: 26.10.2017
ver: 1.0 OksHa
************************/
#include <iostream>
using namespace std;
struct TIEDOT
{
	char etunimet[100];
	char sukunimi[100];
	float koulumatka, kengannumero;
	char osoite[100];
	char postinumero[100];
};
int main(void)
{
	TIEDOT henkilo;
	cout << "Anna (kaikki) etunimesi: ";
	cin.getline(henkilo.etunimet, 100);
	cout << "Anna kengännumero: ";
	cin >> henkilo.kengannumero;
	cout << "Anna sukunimi: ";
	cin >> ws;
	cin.getline(henkilo.sukunimi, 100);
	cout << "Anna koulumatka: ";
	cin >> henkilo.koulumatka;
	cout << "Anna osoitteesi: ";
	cin >> ws;
	cin.getline(henkilo.osoite, 100);
	cout << "Anna postinumero: ";
	cin >> henkilo.postinumero;
	cout << endl << henkilo.sukunimi << " " << henkilo.etunimet << endl;
	cout << henkilo.osoite << endl;
	cout << henkilo.postinumero << endl;
	cout << henkilo.kengannumero << " " << henkilo.koulumatka << endl;
}