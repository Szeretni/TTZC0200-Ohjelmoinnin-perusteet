/************************
Tehtävä: Harjoitus 21 (Palautus vko 48)
Tekijä: Hannu Oksman
Kuvaus:
Muunna harjoitus 11 niin, etta käytät seuraavia aliohjelmia:

int KysyValinta(void);

-> KysyValinta paluttaa käyttäjän antaman valintanumeron (0-6)

double Summa(float luku1, int luku2);

-> Summa laskee yhteen annetut tiedot ja palauttaa summan pääohjelmaan
Pvm: 28.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
int luku_a = 0;
int luku_b = 0;
int valinta = 0;
float vastaus = 0;
int KysyValinta(void);
double Summa(float luku1, int luku2);
void main()
{
	cout << "Anna kaksi kokonaislukua." << endl << "Anna 1. luku: ";
	cin >> luku_a;
	cout << "Anna 2. luku: ";
	cin >> luku_b;
	while (true)
	{
		valinta = KysyValinta();
		switch (valinta)
		{
		case 0:
			exit(0);
			break;
		case 1:
			vastaus = Summa(luku_a, luku_b);
			break;
		case 2:
			vastaus = luku_a - luku_b;
			break;
		case 3:
			vastaus = luku_a * luku_b;
			break;
		case 4:
			vastaus = (float)luku_a / luku_b;
			break;
		case 5:
			vastaus = (int)luku_a % (int)luku_b;
			break;
		case 6:
			cout << "Anna kaksi kokonaislukua." << endl << "Anna 1. luku: ";
			cin >> luku_a;
			cout << "Anna 2. luku: ";
			cin >> luku_b;
			break;
		}
		cout << "Vastaus on: " << vastaus << endl;
	}
}

int KysyValinta(void)
{
	int kysy_valinta;
	cout << endl << "VALIKKO"
		<< "\n0. Lopetus"
		<< "\n1. Summa"
		<< "\n2. Erotus"
		<< "\n3. Tulo"
		<< "\n4. Osamaara"
		<< "\n5. Jakojaannos"
		<< "\n6. Syötä uudet luvut laskemista varten" << endl;
	cin >> kysy_valinta;
	return kysy_valinta;
}

double Summa(float luku1, int luku2)
{
	return(luku1 + luku2);
}