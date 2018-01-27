/************************
Teht�v�: Harjoitus 10
Tekij�: Hannu Oksman
Kuvaus:
Harjoitus 10 (Palautus vko 41)

Tee ohjelma, joka laskee sy�tetyist� kokonaisluvuista sek� positiivisten
ett� negatiivisten kokonaislukujen osuuden. Lukujen sy�tt� lopetetaan
sy�tt�m�ll� luku 0.

Tulostus:
Sy�tit kokonaislukuja seuraavasti:
----------------------------------
Negatiiviset 7 kpl 70.00%
Positiiviset 3 kpl 30.00%
Yhteens� 10 kpl 100.00%

Pvm: 21.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
#include <cstring> 
using namespace std;
int luku = 1;
int kokonainen = 0;
float pos = -1;
float neg = 0;
float yht = 0;
float osuus = 0;
float kerroin = 100;
char loppu[5];
void main()
{
	while (luku != 0)
	{
		cout << "Ohjelma p��ttyy kun annat luvun 0." << "\nAnna haluamasi luku:";
		cin >> luku;
		if (luku < 0)
		{
			neg = neg + 1;
		}
		else
		{
			pos = pos + 1;
		}
	}
	yht = neg + pos;
	cout << "Sy�tit kokonaislukuja seuraavasti:"
		<< "\n----------------------------------";
	osuus = kerroin * neg / yht;
	kokonainen = osuus;
	if (kokonainen == osuus)
	{
		char pitka[5] = ".00%";
		strcpy_s(loppu, pitka);
	}
	else
	{
		char lyhyt[5] = "%";
		strcpy_s(loppu, lyhyt);
	}
	cout.precision(4);
	cout << "\nNegatiiviset " << neg << " kpl " << osuus << loppu;
	osuus = kerroin * pos / yht;
	cout << "\nPositiiviset " << pos << " kpl " << osuus << loppu;
	cout << "\nYhteens� " << yht << " kpl " << "100.00%" << endl;
}