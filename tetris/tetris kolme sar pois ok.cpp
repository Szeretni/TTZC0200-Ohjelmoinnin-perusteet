/*
Tetris by Hannu Oksman 2017
*/

#include <iostream>
#include <time.h> //random koneen kellosta
#include <cstring>
using namespace std;
const int dimensio = 7;
int alkukohta = 1;
int pisteet = 0;
void KentanTulostus(char[dimensio][dimensio]);
void PalikanLuonti(char *&);
void Liikkuminen(char *&, char[dimensio][dimensio]);
int main()
{
	int rivi, sarake;
	char kentta[dimensio][dimensio] = { { NULL },{ NULL } };
	for (int i = 0; ; i++)
	{
		char *palikan_sijoitus = NULL;
		palikan_sijoitus = new char;
		if (palikan_sijoitus)
		{
			palikan_sijoitus = &kentta[alkukohta][dimensio / 2];
		}
		else
		{
			cout << "Tilanvaraus ei onnistunut.\n";
		}
		{
			PalikanLuonti(palikan_sijoitus);
			KentanTulostus(kentta);
			Liikkuminen(palikan_sijoitus, kentta);
		}
		
		//v�liss� on uutta

		for (rivi = 0; rivi < dimensio; rivi++)
		{
			char *poistopointteri = NULL;
			char merkkijono[dimensio];
			for (sarake = 0; sarake < dimensio; sarake++)
			{
				merkkijono[sarake] = kentta[rivi][sarake];
			}
			for (int j = 0; j < dimensio; j++)
			{
				if (merkkijono[j] == 'x' && merkkijono[j+1] == 'x'  && merkkijono[j + 2] == 'x')
				{
					if (merkkijono[j + 3] == 'x')
					{
						cout << "Nelja vierekkaista";
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 3];
						*poistopointteri = NULL;
					}
					else
					{
						cout << "Kolme vierekkaista" << endl;
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
					}
				}
				if (merkkijono[j] == 'y' && merkkijono[j + 1] == 'y'  && merkkijono[j + 2] == 'y')
				{
					if (merkkijono[j + 3] == 'y')
					{
						cout << "Nelja vierekkaista";
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 3];
						*poistopointteri = NULL;
					}
					else
					{
						cout << "Kolme vierekkaista" << endl;
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
					}
				}
				if (merkkijono[j] == 'z' && merkkijono[j + 1] == 'z'  && merkkijono[j + 2] == 'z')
				{
					if (merkkijono[j + 3] == 'z')
					{
						cout << "Nelja vierekkaista";
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 3];
						*poistopointteri = NULL;
					}
					else
					{
						cout << "Kolme vierekkaista" << endl;
						poistopointteri = &kentta[rivi][j];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 1];
						*poistopointteri = NULL;
						poistopointteri = &kentta[rivi][j + 2];
						*poistopointteri = NULL;
					}
				}
			}
		}
	}

		//v�liss� on uutta

	pisteet++;
}

void KentanTulostus(char kentta[dimensio][dimensio])
{
	//system("cls"); temp
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
	if (*palikan_sijoitus == '-' || *palikan_sijoitus == 'x' || *palikan_sijoitus == 'y' || *palikan_sijoitus == 'z')
	{
		cout << "Pisteesi: " << pisteet << endl;
		exit(0);
	}
	srand((unsigned)time(NULL)); //F1-helpin esimerkista
	int palikka_arpa = rand() % 3 + 1;
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

void Liikkuminen(char *&palikan_sijoitus, char kentta[dimensio][dimensio])
{
	char *uusi_paikka = NULL;
	char syote;
	//for (int i = alkukohta; i < dimensio-1 ; i++)
	int indeksi = alkukohta;
	int sivuliike = 1;
	int xakseli = dimensio / 2;
	while (indeksi>0)
	{
		cin >> syote;
		switch (syote)
		{
		case 'a':
			uusi_paikka = &kentta[alkukohta + indeksi][xakseli - sivuliike];
			if (*uusi_paikka == '-' || *uusi_paikka == 'x' || *uusi_paikka == 'y' || *uusi_paikka == 'z')
			{
				indeksi = -1;
				break;
			}
			else
			{
				*uusi_paikka = *palikan_sijoitus;
				*palikan_sijoitus = NULL;
				palikan_sijoitus = uusi_paikka;
				KentanTulostus(kentta);
				xakseli--;
			}
			break;
		case 'd':
			uusi_paikka = &kentta[alkukohta + indeksi][xakseli + sivuliike];
			if (*uusi_paikka == '-' || *uusi_paikka == 'x' || *uusi_paikka == 'y' || *uusi_paikka == 'z')
			{
				indeksi = -1;
				break;
			}
			else
			{
				*uusi_paikka = *palikan_sijoitus;
				*palikan_sijoitus = NULL;
				palikan_sijoitus = uusi_paikka;
				KentanTulostus(kentta);
				xakseli++;
			}
			break;
		case 's':
			uusi_paikka = &kentta[alkukohta + indeksi][xakseli];
			if (*uusi_paikka == '-' || *uusi_paikka == 'x' || *uusi_paikka == 'y' || *uusi_paikka == 'z')
			{
				indeksi = -1;
				break;
			}
			else
			{
				*uusi_paikka = *palikan_sijoitus;
				*palikan_sijoitus = NULL;
				palikan_sijoitus = uusi_paikka;
				KentanTulostus(kentta);
			}
			break;
		case 'w':
			break;
		default:
			break;
		}
		indeksi++;
	}
}