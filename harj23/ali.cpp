#include "esittely.h"
int Valikko(void)
{
	int vastaus;
	cout << "VALIKKO\n";
	cout << "0 Lopeta\n";
	cout << "1 Lisaa henkilo\n";
	cout << "2 Nayta kaikki henkilot\n";
	cin >> vastaus;
	return vastaus;
}

void TulostaHenkilo(REK henkilorekisteri[MAARA], int lisatyt_henkilot)
{
	for (int i = 0; i < lisatyt_henkilot; i++)
	{
		cout << "Henkilo " << i + 1 << ":" << endl;
		cout << "Nimi:       " << henkilorekisteri[i].etunimi << endl;
		cout << "Koulumatka: " << henkilorekisteri[i].koulumatka << endl;
		cout << "Hatun koko: " << henkilorekisteri[i].hatun_koko << endl;
		cout << endl;
	}
}

void LisaaHenkilo(REK henkilorekisteri[MAARA], int *lkm)
{
	for (int i = 0; i <= *lkm; i++)
	{
		if (i == *lkm)
		{
			cout << "Anna etunimi: ";
			cin >> ws;
			cin.getline(henkilorekisteri[i].etunimi, NIMI_PITUUS);
			cout << "Anna koulumatka: ";
			cin >> henkilorekisteri[i].koulumatka;
			cout << "Anna hatun koko: ";
			cin >> henkilorekisteri[i].hatun_koko;
		}
	}
}