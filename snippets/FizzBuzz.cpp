#include <iostream>
using namespace std;
int Laskuri(int, int);
int indeksi, kerroin, fizz, buzz, i, j, kerto;
void Vastaus(int, int);

void main()
{
	for (i = 1; i <= 100; i++)
	{
		int buzz = Laskuri(i, 3);
		int fizz = Laskuri(i, 5);
		Vastaus(buzz, fizz);
	}
}
int Laskuri(int indeksi, int kerroin)
{
	for (j = 1; j <= 100; j++)
	{
		kerto = j * kerroin;
		if (indeksi == kerto)
		{
			return kerroin;
			break;
		}
	}
	return 0;
}
void Vastaus(int buzz,int fizz)
{
	if (buzz == 3 && fizz == 5)
	{
		cout << "FizzBuzz" << endl;
	}
	else if (buzz == 3)
	{
		cout << "Buzz" << endl;
	}
	else if (fizz == 5)
	{
		cout << "Fizz" << endl;
	}
	else
	{
		cout << i << endl;
	}
}