/************************
Tehtävä: Harjoitus 10
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 10 (Palautus vko 41)

Tee ohjelma, joka laskee syötetyistä kokonaisluvuista sekä positiivisten
että negatiivisten kokonaislukujen osuuden. Lukujen syöttä lopetetaan
syöttämällä luku 0.

Tulostus:
Syötit kokonaislukuja seuraavasti:
----------------------------------
Negatiiviset 7 kpl 70.00%
Positiiviset 3 kpl 30.00%
Yhteensä 10 kpl 100.00%

Pvm: 28.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
int luku[100];
int i = 0;
int j = 0;
int pos = 0;
int neg = 0;
int yht = 0;
float osuus = 0;
float kerroin = 100;
void main()
{
	for (i = 1; ; i++)
	{
		cout << "Ohjelma päättyy kun annat luvun 0." << "\nAnna haluamasi luku:";
		cin >> luku[i];
		if (luku[i] == 0)
			break;
	}
	for (j = 1; j < i; j++)
	{
		if (luku[j] < 0)
			neg = neg + 1;
		else
			pos = pos + 1;
	}
	yht = neg + pos;
	cout << "Syötit kokonaislukuja seuraavasti:"
		<< "\n----------------------------------";
	osuus = kerroin * neg / yht;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);
	cout << "\nNegatiiviset " << neg << " kpl " << osuus << "%";
	osuus = kerroin * pos / yht;
	cout << "\nPositiiviset " << pos << " kpl " << osuus << "%";;
	cout << "\nYhteensä " << yht << " kpl " << "100.00%" << endl;
}