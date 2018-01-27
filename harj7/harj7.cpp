#include <iostream>
using namespace std;
char nimi[20];
char osoite[20];
float pituus;
float paino;
int main()
{
	cout << "Ihannepaino:\n"
		<< endl
		<< "Ohjelma laskee ihannepainosi pituutesi perusteella.\n"
		<< endl
		<< "Anna nimesi: ";
	cin.get(nimi,20);
	cin.ignore(21, '\n');
	cout << "Anna pituutesi sentteinä: ";
	cin >> pituus;
	cout << "Anna osoitteesi: ";
	cin.get();
	cin.get(osoite, 20);
	cin.ignore(100,'\n');
	cout << "Anna painosi kiloina: ";
	cin >> paino;
	float ihannepaino = pituus - 100;
	float erotus = paino - ihannepaino;
	cout << "\nArvoisa " << nimi << endl
		<< "Osoitteesi on " << osoite << endl
		<< "Nykyinen painosi " << paino << " kg" << endl
		<< "Ihannepainosi on " << ihannepaino << " kg" << endl
		<< "Erotus " << erotus << " kg" << endl;
	return 0;
}