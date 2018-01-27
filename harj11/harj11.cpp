/************************
Teht�v�: Harjoitus 10
Tekij�: Hannu Oksman
Kuvaus:
Harjoitus 11 (Palautus vko 43)
Muuta teht�v�n 9 laskin-ohjelmaa niin, etta valikko nayttaa
seuraavalta:

VALIKKO
0. Lopetus
1. Summa
2. Erotus
3. Tulo
4. Osamaara
5. Jakojaannos
6. Syota uudet luvut laskemista varten

Laskimella on siis mahdollista k�sitell�
useita lukupareja k�ytt�j�n toiveiden
mukaisesti. Mita tapahtuu, jos luku2 on 0?
HUOM! goto -lauseen k�ytt� on KIELLETTY!!!!

Pvm: 28.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
float luku1 = 0;
float luku2 = 0;
int valinta = 0;
float vastaus = 0;
void main()
{
	cout << "Anna kaksi kokonaislukua." << endl << "Anna 1. luku: ";
	cin >> luku1;
	cout << "Anna 2. luku: ";
	cin >> luku2;
	while (true)
	{
		cout << endl << "VALIKKO"
			<< "\n0. Lopetus"
			<< "\n1. Summa"
			<< "\n2. Erotus"
			<< "\n3. Tulo"
			<< "\n4. Osamaara"
			<< "\n5. Jakojaannos"
			<< "\n6. Sy�t� uudet luvut laskemista varten" << endl;
		cin >> valinta;
		switch (valinta)
		{
		case 0:
			exit(0);
			break;
		case 1:
			vastaus = luku1 + luku2;
			break;
		case 2:
			vastaus = luku1 - luku2;
			break;
		case 3:
			vastaus = luku1 * luku2;
			break;
		case 4:
			vastaus = (float)luku1 / luku2;
			break;
		case 5:
			vastaus = (int)luku1 % (int)luku2; //miten t�st� tulevan 'possible loss of data'-varoituksen saisi pois?
			break;
		case 6:
			cout << "Anna kaksi kokonaislukua." << endl << "Anna 1. luku: ";
			cin >> luku1;
			cout << "Anna 2. luku: ";
			cin >> luku2;
			break;
		}
		cout << "Vastaus on: " << vastaus << endl;
	}
}