// crt_rand.c  
// This program seeds the random-number generator  
// with the time, then exercises the rand function.  
//  

#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>  
#include <iostream>
using namespace std;

void SimpleRandDemo(int n)
{
	// Print n random numbers.  
	int i;
	for (i = 0; i < n; i++)
		printf("  %6d\n", rand());
}

void RangedRandDemo(int range_min, int range_max, int n)
{
	// Generate random numbers in the half-closed interval  
	// [range_min, range_max). In other words,  
	// range_min <= random number < range_max  
	int i;
	for (i = 0; i < n; i++)
	{
		int u = rand() % 3 + 1;
		printf("  %6d\n", u);
	}
}

int main(void)
{
	// Seed the random-number generator with the current time so that  
	// the numbers will be different every time we run.  
	srand((unsigned)time(NULL));

	for (int j = 0; j < 1; j++)
	{
		//SimpleRandDemo(10);
		RangedRandDemo(1, 4, 10);
	}
	
}


/*
#include <iostream>
#include <time.h>  
using namespace std;
int main(void)
{
	for (int i = 0; i < 20; i++)
	{
		srand((unsigned)time(NULL)); //F1-helpin esimerkista
		char palikan_sijoitus;
		int palikka_arpa = (int)rand() / 1 * 4;
		switch (palikka_arpa)
		{
		case 1:
			palikan_sijoitus = 'x';
			cout << palikan_sijoitus << endl;
			break;
		case 2:
			palikan_sijoitus = 'y';
			cout << palikan_sijoitus << endl;
			break;
		case 3:
			palikan_sijoitus = 'z';
			cout << palikan_sijoitus << endl;
			break;
		}
	}
}
*/

/*
#include <iostream>
using namespace std;
int main(void)
{
	char *palikan_sijoitus = new char;
	for (int i = 0; i < 20; i++)
	{
		int palikka_arpa = srand() % 1 + 3;
		switch (palikka_arpa)
		{
		case 1:
			*palikan_sijoitus = 'x';
			break;
		case 2:
			*palikan_sijoitus = 'y';
			break;
		case 3:
			*palikan_sijoitus = 'z';
			break;
		}
		cout << *palikan_sijoitus;
	}
}
*/

/*#include <iostream> 
using namespace std;
struct TEST
{
	int pituus;
	int paino;
};
int main()
{
/*	int *luku_osoitin1 = NULL;
	int vastaus, laskuri = 0;
	cout << "\nMontako lukua varataan ? ";
	cin >> vastaus;
	luku_osoitin1 = new int[vastaus]; //dynaaminen tilanvaraus
	if (luku_osoitin1) // sama kuin (luku_osoitin1 != NULL) onnistuiko muistinvaraus
	{
		for (laskuri = 0; laskuri < vastaus; laskuri++)
		{
			cout << "\nLuku ?";
			cin >> luku_osoitin1[laskuri];
		}
		for (laskuri = 0; laskuri < vastaus; laskuri++)
		{
			cout << "\nLuku: " << luku_osoitin1[laskuri];
			cout << " osoitteessa: " << &luku_osoitin1[laskuri];
		}
	}
	else
		cout << "\nTilanvaraus epäonnistui";
	delete[] luku_osoitin1; // jos deletoi monta kertaa, niin kaatuu
	luku_osoitin1 = NULL; // nollaa lopuksi
	return 0;
	*/
	/*TEST *testipointteri = NULL;
	cout << "Kuinka monipaikkaisen structin haluat? ";
	int vastaus;
	cin >> vastaus;
	testipointteri = new TEST[vastaus];
	for (int i = 0; i < vastaus; i++)
	{
		cout << "Syötä pituus ja paino: ";
		cin >> testipointteri[i].pituus >> testipointteri[i].paino;
		cout << "Henkilo " << i << " pituus ja paino: " << testipointteri[i].pituus << " " << testipointteri[i].paino;
	}
	for (int i = 0; i < vastaus; i++)
	{
		cout << "Henkilo " << i << " pituus ja paino: " << testipointteri[i].pituus << " " << testipointteri[i].paino;
	}
}*/