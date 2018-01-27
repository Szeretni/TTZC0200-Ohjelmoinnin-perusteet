#include <iostream>
using namespace std;
int lukujen_maara = 0;
int luvut[100];
int i = 0;
int j = 0;
int jalkimmainen = 0;
int edellinen = 0;
void main()
{
	cout << "Syötä kuinka monta lukua haluat järjestää: ";
	cin >> lukujen_maara;
	for (i = 1; i <= lukujen_maara; i++)
	{
		cout << "Anna " << i << ". luku: ";
		cin >> luvut[i];
	}
	for (i = 1; i <= lukujen_maara; i++)
	{
		for (j = 2; j <= lukujen_maara; j++)
		{
			jalkimmainen = luvut[j];
			edellinen = luvut[j - 1];
			if (edellinen > jalkimmainen)
			{
				luvut[j] = edellinen;
				luvut[j - 1] = jalkimmainen;
			}
		}
	}
	cout << "Alla on lueteltu antamasi luvut pienimmästä suurimpaan: " << endl;
	for (i = 1; i <= lukujen_maara; i++)
	{
		cout << luvut[i] << " ";
	}
	cout << endl;
}