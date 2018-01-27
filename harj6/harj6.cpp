#include <iostream>
using namespace std;
float lompakko = 0;
float lihapiirakka = 0;
float erotus = 0;
void Laskuri(float, float);
void main()
{
	cout << "Anna lompakossasi sisällön arvo: ";
	cin >> lompakko;
	cout << "Anna haluamasi kasvispiirakan hinta: ";
	cin >> lihapiirakka;
	Laskuri(lompakko,lihapiirakka);
}
void Laskuri(float tulo, float meno)
{
	if (tulo >= meno)
	{
		erotus = tulo - meno;
		cout.precision(2);
		cout << "Sinulla on varaa piirakkaan! Ostoksen jälkeen lompakkoosi jää " << erotus << " euroa.\n";
	}
	else cout << "Sinulla ei ole varaa piirakkaan! Ole hyvä ja paastoa.\n";
}