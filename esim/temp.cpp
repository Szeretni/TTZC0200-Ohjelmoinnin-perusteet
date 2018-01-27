#include <iostream>
using namespace std;
int i = 0;
int kolme = 0;
int viisi = 0;
int Laskuri(int, int);
int j = 0;
int kerto = 0;
void main()
{
	for (i = 1; i <= 100; i++)
	{
		kolme = Laskuri(i, 3);
		viisi = Laskuri(i, 5);

	}
	cout << kolme << viisi << endl;
}

int Laskuri(int ind,int mul)
{
	for (j = 1; j <= 100; j++)
	{
		kerto = j * mul;
		if (kerto == ind)
		{
			break;
			return mul;
		}
		else
		{
			break;
			return 0;
		}
	}
}