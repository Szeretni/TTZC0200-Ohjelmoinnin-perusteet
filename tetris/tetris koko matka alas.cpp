#include <iostream>
using namespace std;
const int dimensio = 11;
void KentanTulostus(char[dimensio][dimensio]);
void PalikanLuonti(char *&);
void Liikkuminen(char *&);
int main()
{
	int sarake, rivi;
	char kentta[dimensio][dimensio] = { {NULL},{NULL} };
	char *palikan_sijoitus = NULL;
	int alkukohta = 1;
	palikan_sijoitus = &kentta[alkukohta][dimensio / 2];
	PalikanLuonti(palikan_sijoitus);
	KentanTulostus(kentta);
	char *uusi_paikka = NULL;
	for (int i = alkukohta; ; i++)
	{
		uusi_paikka = &kentta[alkukohta + i][dimensio / 2];
		if (*uusi_paikka == '-')
		{
			break;
		}
		else
		{
			*uusi_paikka = *palikan_sijoitus;
			*palikan_sijoitus = NULL;
			palikan_sijoitus = uusi_paikka;
			KentanTulostus(kentta);
		}
	}
	
	/*
	char syote;
	cin >> syote;
	switch (syote)
	{
	case 'a':
		break;
	case 'd':
		break;
	case 's':
		break;
	case 'w':
		break;
	default:
		break;
	}
	*/
	

	
}

void KentanTulostus(char kentta[dimensio][dimensio])
{
	//system("cls");
	int rivi = dimensio, sarake = dimensio;
	for (rivi = 0; rivi < dimensio; rivi++)
	{
		for (sarake = 0; sarake < dimensio; sarake++)
		{
			if (rivi == 0 || rivi == (dimensio - 1) || sarake == 0 || sarake == (dimensio - 1))
			{
				kentta[rivi][sarake] = '-';
			}
			if (sarake == (dimensio - 1))
			{
				cout << kentta[rivi][sarake] << endl;
			}
			else
			{
				cout << kentta[rivi][sarake];
			}
		}
	}
}

void PalikanLuonti(char *&palikan_sijoitus)
{
	int palikka_arpa = rand() % 1 + 3;
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
}

void Liikkuminen(char *&palikan_sijoitus)
{
	char syote;
	cin >> syote;
	switch (syote)
	{
	case 'a':
		
		break;
	case 'd':
		break;
	case 's':
		break;
	case 'w':
		break;
	default:
		break;
	}
}