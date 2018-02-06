/*Hannu Oksman
Todo:
	-More comments
	-Input without buffer
	-dynamic list for high scores
	-diagonal match checking
	-dimensional blocks (now they occupy just one point)
*/

#include "tetris.h"
int alkukohta = 1;
int perakkainoltava = 3;
int pisteet = 0;
int main()
{
	HIGHSCORE huippupisteet[10];
	char kentta[dimensio][dimensio] = { { NULL },{ NULL } };
	while (true)
	{
		switch (Valikko())
		{
		default:
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
					PalikanLuonti(palikan_sijoitus,huippupisteet);
					KentanTulostus(kentta);
					Liikkuminen(palikan_sijoitus, kentta);
					PalikoidenPoistoV(kentta);
					PalikoidenPoistoP(kentta);
					pisteet++;
					PalikoidenPudotus(kentta);
				}
			}
			break;
		case 2:
			LuePisteet(huippupisteet);
			break;
		case 3:
			exit(0);
			break;
		}
	}
}

void KentanTulostus(char kentta[dimensio][dimensio])
{
	system("cls");
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

void PalikanLuonti(char *&palikan_sijoitus, HIGHSCORE huippupisteet[10])
{
	if (*palikan_sijoitus == '-' || *palikan_sijoitus == 'x' || *palikan_sijoitus == 'y' || *palikan_sijoitus == 'z')
	{
		cout << "Pisteesi: " << pisteet << endl;
		LuePisteet(huippupisteet);
		if (pisteet > huippupisteet[0].score)
		{
			cout << "Anna nimesi: ";
			cin.getline(huippupisteet[0].nimi, 20);
			huippupisteet[0].score = pisteet;
			char paiva[20] = __DATE__;
			cin.getline(huippupisteet[0].paiva, 13);
		}
		
		/*for (int i = 0; i < 10; i++)
		{
			if (huippupisteet[i].score < 0)
			{
				cout << "Anna nimesi: ";
				cin >> huippupisteet[i].nimi;
				huippupisteet[i].score = pisteet;
				string paiva = __DATE__;
				cin.getline(huippupisteet[i].paiva, 20);
			}
			break;
		}
		*/
		TallennaPisteet(pisteet, huippupisteet);
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
			PalikoidenPudotus(kentta);
			KentanTulostus(kentta);
			indeksi = -1;
			break;
		default:
			break;
		}
		indeksi++;
	}
}

void PalikoidenPoistoP(char kentta[dimensio][dimensio])
{
	for (int sarake = 0; sarake < dimensio; sarake++)
	{
		char merkkijono[dimensio + 1];
		for (int rivi = 0; rivi < dimensio; rivi++)
		{
			merkkijono[rivi] = kentta[rivi][sarake]; //koko sarake tallennetaan merkkijonoon
		}
		char *tarkistuspointteri = merkkijono; //osoittaa merkkijonoon
		int j = 0;
		char xmerkki = 'x';
		char ymerkki = 'y';
		char zmerkki = 'z';
		while (j<dimensio) //käydään läpi merkkijonoa
		{
			if ((*tarkistuspointteri) == xmerkki)
			{
				PystyTarkastelu(tarkistuspointteri, xmerkki, j, sarake, merkkijono, kentta);
			}
			if ((*tarkistuspointteri) == ymerkki)
			{
				PystyTarkastelu(tarkistuspointteri, ymerkki, j, sarake, merkkijono, kentta);
			}
			if ((*tarkistuspointteri) == zmerkki)
			{
				PystyTarkastelu(tarkistuspointteri, zmerkki, j, sarake, merkkijono, kentta);
			}
			tarkistuspointteri++;
			j++;
		}
	}
}

void PalikoidenPoistoV(char kentta[dimensio][dimensio])
{
	for (int rivi = 0; rivi < dimensio; rivi++)
	{
		char merkkijono[dimensio + 1];
		for (int sarake = 0; sarake < dimensio; sarake++)
		{
			merkkijono[sarake] = kentta[rivi][sarake];; //koko rivi tallennetaan merkkijonoon
		}
		char *tarkistuspointteri = merkkijono; //osoittaa merkkijonoon
		int j = 0;
		char xmerkki = 'x';
		char ymerkki = 'y';
		char zmerkki = 'z';
		while (j<dimensio) //käydään läpi merkkijonoa
		{
			if ((*tarkistuspointteri) == xmerkki)
			{
				VaakaTarkastelu(tarkistuspointteri, xmerkki, j, rivi, merkkijono, kentta);
			}
			if ((*tarkistuspointteri) == ymerkki)
			{
				VaakaTarkastelu(tarkistuspointteri, ymerkki, j, rivi, merkkijono, kentta);
			}
			if ((*tarkistuspointteri) == zmerkki)
			{
				VaakaTarkastelu(tarkistuspointteri, zmerkki, j, rivi, merkkijono, kentta);
			}
			tarkistuspointteri++;
			j++;
		}
	}
}

void PystyTarkastelu(char *&tarkistuspointteri, char merkki, int j, int sarake, char merkkijono[dimensio+1], char kentta[dimensio][dimensio])
{
	int montakosamaamerkkia = 0;
	int apu_j = j; //talteen mika kierros on
	char *poistopointteri = NULL;
	//tarkistus montako samaa on perakkain
	while ((*tarkistuspointteri) == merkki)
	{
		montakosamaamerkkia++;
		tarkistuspointteri++;
		j++;
	}
	if (montakosamaamerkkia >= perakkainoltava)
	{
		for (int k = montakosamaamerkkia; k > 0; k--)
		{
			poistopointteri = &kentta[j - montakosamaamerkkia][sarake];
			*poistopointteri = NULL;
			montakosamaamerkkia--;
		}
		j = apu_j;
		tarkistuspointteri = &merkkijono[j];
	}
	else
	{
		montakosamaamerkkia = 0;
		j = apu_j;
		tarkistuspointteri = &merkkijono[j];
	}
}

void VaakaTarkastelu(char *&tarkistuspointteri, char merkki, int j, int rivi, char merkkijono[dimensio + 1], char kentta[dimensio][dimensio])
{
	int montakosamaamerkkia = 0;
	int apu_j = j; //talteen mika kierros on
	char *poistopointteri = NULL;
	//tarkistus montako samaa on perakkain
	while ((*tarkistuspointteri) == merkki)
	{
		montakosamaamerkkia++;
		tarkistuspointteri++;
		j++;
	}
	if (montakosamaamerkkia >= perakkainoltava)
	{
		for (int k = montakosamaamerkkia; k > 0; k--)
		{
			poistopointteri = &kentta[rivi][j - montakosamaamerkkia];
			*poistopointteri = NULL;
			montakosamaamerkkia--;
		}
		j = apu_j;
		tarkistuspointteri = &merkkijono[j];
	}
	else
	{
		montakosamaamerkkia = 0;
		j = apu_j;
		tarkistuspointteri = &merkkijono[j];
	}
}

void PalikoidenPudotus(char kentta[dimensio][dimensio])
{
	int rivi, sarake;
	char *uusi_paikka = NULL;
	char *merkin_poiminta = NULL;
	int refresh = 0;
	while (refresh<dimensio)
	{
		for (rivi = 1; rivi < dimensio; rivi++)
		{
			for (sarake = 1; sarake < dimensio; sarake++)
			{
				merkin_poiminta = &kentta[rivi][sarake];
				if (*merkin_poiminta == '-')
				{
					break;
				}
				else if (*merkin_poiminta == 'x' || *merkin_poiminta == 'y' || *merkin_poiminta == 'z')
				{
					uusi_paikka = &kentta[rivi + 1][sarake];
					if (*uusi_paikka == NULL)
					{
						*uusi_paikka = *merkin_poiminta;
						*merkin_poiminta = NULL;
					}
				}
			}
		}
		refresh++;
	}
}

int Valikko()
{
	cout << "\nTetris by Hannu Oksman (c)2017\n";
	cout << "\nValikko";
	cout << "\n1) Pelaa";
	cout << "\n2) Huippupisteet";
	cout << "\n3) Lopeta\n";
	int vastaus;
	cin >> vastaus;
	return vastaus;
}