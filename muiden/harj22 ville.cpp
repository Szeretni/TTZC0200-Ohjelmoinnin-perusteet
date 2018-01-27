#include <iostream>
#include <string>
//#include "tiedot.h"
using namespace std;

struct tiedot {
	char name[10];
	double koulumatka;
	int hatsize;
	bool active = false;
} *person;

int mode, Valikko();
int LisaaHenkilo(tiedot[], int order);
void TulostaKaikkiHenkilot(), TulostaHenkilo(), Tulosta(int);

int Valikko() {
	cout << "VALIKKO\n0.Lopeta\n1.Lisaa henkilo\n2.Nayta kaikki henkilot\n3.Nayta tietty henkilo\n";
	cin >> mode;
	return mode;
}

int LisaaHenkilo(tiedot[], int order) {

	cout << "Anna " << order + 1 << ". henkilön nimi.\n";
	cin >> person[order].name;

	cout << "Koulumatka kilometreinä\n";
	cin >> person[order].koulumatka;

	cout << "Ja hatun koko\n";
	cin >> person[order].hatsize;
	person[order].active = true;

	system("cls");
	cout << order+1 << ". henkilon nimi: " << person[order].name << "\nKoulumatka: "
		 << person[order].koulumatka << "km\nHatun koko: "
		 << person[order].hatsize << endl << endl;
	return ++order;
}

void Tulosta(int i) {
	cout << "Henkilon nimi: " << person[i].name << "\nKoulumatka: "
		<< person[i].koulumatka << "km\nHatun koko: "
		<< person[i].hatsize << endl
		<< "--------------------" << endl;
}

void TulostaKaikkiHenkilot() {
	system("cls");
	for (int i = 0; i < 10; i++) {
		if(person[i].active)
		Tulosta(i);
	}
}

void TulostaHenkilo() {
	int tulostettava;
	cout << "Anna henkilon numero.\n";
	cin >> tulostettava;
	if (person[tulostettava-1].active) Tulosta(tulostettava - 1); 
		else cout << "Henkiloa ei ole olemassa\n";
}

void main() {
	person = new tiedot[10];
    int order = 0;

	while (true) {
		mode = Valikko();
		switch (mode) {
			case 1: order = LisaaHenkilo(&person[order], order); break;
			case 2: TulostaKaikkiHenkilot(); break;
			case 3: TulostaHenkilo(); break;
			default: exit(0); break;
		}
	}
}