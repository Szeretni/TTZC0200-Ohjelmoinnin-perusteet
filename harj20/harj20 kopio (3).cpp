/************************
Tehtävä: Harjoitus 20
Tekijä: Hannu Oksman
Kuvaus: Kuten harjoitus 19, mutta toteuta kayttaen taulukkoa ja osoitinta tiedon käsittelyyn

Pvm: 16.11.2017
ver: 1.0 OksHa
************************/
#include <iostream>
using namespace std;
const int KESKIARVO_MAARA = 5;
void Nopeusmittari(int nopeustaulu[KESKIARVO_MAARA]);
void main()
{
	int nopeustaulu[KESKIARVO_MAARA] = { 0 }, *osoitin = nopeustaulu, i = 0;
	while (true)
	{
		while (i < KESKIARVO_MAARA)
		{
			cout << "Anna nopeus: ";
			cin >> (*osoitin);
			if (*osoitin < 0)
				break;
			Nopeusmittari(nopeustaulu);
			i++;
			osoitin++;
			if (i == 5)
			{
				i = 0;
				osoitin = nopeustaulu;
			}
		}
		break;
	}
	cout << "Loppu" << endl;
}

void Nopeusmittari(int nopeustaulu[KESKIARVO_MAARA])
{

	int nopeus = 0;
	int *pointteri = nopeustaulu;
	for (int j = 0; j < KESKIARVO_MAARA; j++, pointteri++)
	{
		nopeus += *pointteri;
	}
	nopeus = nopeus / KESKIARVO_MAARA;
	cout << nopeus << " km/h" << endl;
}