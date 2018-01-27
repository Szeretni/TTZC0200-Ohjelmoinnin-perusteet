/************************
Tehtävä: Harjoitus 8b
Tekijä: Hannu Oksman
Kuvaus:
	Harjoitus 8 (palautus vko 41)
	Tee ohjelma, joka tulostaa annetut kolme lukua suuruus-
	järjestyksessä (pienimmästä suurimpaan) näytölle
	(katso harj. 1 suunnitelma)
	a) käytä kokonaislukuja
	b) käytä liukulukuja (=reaalilukuja)
Pvm: 21.9.2017
ver: 1.0 OksHa
************************/

#include <iostream>
using namespace std;
float luku1 = 0;
float luku2 = 0;
float luku3 = 0;
void main()
{
	cout << "Anna 1. luku: ";
	cin >> luku1;
	cout << "Anna 2. luku: ";
	cin >> luku2;
	cout << "Anna 3. luku: ";
	cin >> luku3;
	if (luku1 <= luku2 && luku2 <= luku3)
	{
		cout << luku1 << ", " << luku2 << ", " << luku3 << endl;
	}
	else if (luku1 <= luku3 && luku3 <= luku2)
	{
		cout << luku1 << ", " << luku3 << ", " << luku2 << endl;
	}
	else if (luku2 <= luku1 && luku1 <= luku3)
	{
		cout << luku2 << ", " << luku1 << ", " << luku3 << endl;
	}
	else if (luku2 <= luku3 && luku3 <= luku1)
	{
		cout << luku2 << ", " << luku3 << ", " << luku1 << endl;
	}
	else if (luku3 <= luku1 && luku1 <= luku2)
	{
		cout << luku3 << ", " << luku1 << ", " << luku2 << endl;
	}
	else
	{
		cout << luku3 << ", " << luku2 << ", " << luku1 << endl;
	}
}