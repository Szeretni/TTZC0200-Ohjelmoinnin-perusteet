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
Pvm: 28.9.2017
ver: 1.1 OksHa
************************/

#include <iostream>
using namespace std;
float luku1 = 0;
float luku2 = 0;
int valinta = 0; //switchcase tapauksen oltava kokonaisluku
float vastaus = 0;
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
	switch (valinta)
	{
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
		vastaus = luku1 / luku2;
		break;
	case 5:
		vastaus = (int)luku1 % (int)luku2; //jakojäännöksessä on käytettävä kokonaislukuja, siksi (int)
		break;
	}
	cout << "Vastaus on: " << vastaus << endl;
}