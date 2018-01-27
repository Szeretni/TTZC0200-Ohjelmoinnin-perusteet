/************************
Tehtävä: Harjoitus 9
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 9 (Palautus vko 41)
Tee ohjelma, joka toimii laskimena.
Käyttäjältä kysytään kaksi kokonaislukua,
jonka jälkeen ohjelma antaa valikon
laskutoimituksista. Valikko nayttaa
seuraavalta:

VALIKKO
1. Summa
2. Erotus
3. Tulo
4. Osamaara
5. Jakojaannos

Lopuksi ohjelma tulostaa valitun tuloksen naytölle.
Pvm: 21.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
int luku1 = 0;
int luku2 = 0;
int valinta = 0;
int vastaus = 0;
void main()
{
	cout << "Anna kaksi kokonaislukua." << endl << "Anna 1. luku: ";
	cin >> luku1;
	cout << "Anna 2. luku: ";
	cin >> luku2;
	cout << endl << "VALIKKO"
		<< "\n1. Summa"
		<< "\n2. Erotus"
		<< "\n3. Tulo"
		<< "\n4. Osamaara"
		<< "\n5. Jakojaannos" << endl;
	cin >> valinta;
	if (valinta == 1)
	{
		vastaus = luku1 + luku2;
	}
	else if (valinta == 2)
	{
		vastaus = luku1 - luku2;
	}
	else if (valinta == 3)
	{
		vastaus = luku1 * luku2;
	}
	else if (valinta == 4)
	{
		vastaus = luku1 / luku2;
	}
	else
	{
		vastaus = luku1 % luku2;
	}
	cout << "Vastaus on: " << vastaus << endl;
}