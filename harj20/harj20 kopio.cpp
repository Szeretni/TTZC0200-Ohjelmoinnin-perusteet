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
int main(void)
{
	int nopeustaulu[KESKIARVO_MAARA] = { 0 }, nopeusmittari, nopeus_sum = 0, *osoitin = nopeustaulu, i = 0;
	while (true)
	{
		while (i < KESKIARVO_MAARA)
		{
			cout << "Anna nopeus: ";
			cin >> *osoitin;
			if (*osoitin < 0)
				break;
			for (int j = 0; j < KESKIARVO_MAARA; j++,osoitin++)
			{
				nopeus_sum += *osoitin;
			}
			nopeusmittari = nopeus_sum / KESKIARVO_MAARA;
			nopeus_sum = 0;
			cout << nopeusmittari << " km/h" << endl;
			i++,osoitin++;
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