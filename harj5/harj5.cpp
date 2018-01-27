#include <iostream>
using namespace std;
int luku1 = 0;
int luku2 = 0;
void main()
{
	cout << "Kirjoita ensimmäinen luku: ";
	cin >> luku1;
	cout << "Kirjoita toinen luku: ";
	cin >> luku2;
	if (luku1 == luku2)
		cout << "BINGO!\n";
	else cout << "BONGO!\n";
}