#include "tetris_koulukone.h"
int alkukohta = 1; //mihin kohtaan palikan luodaan
int perakkainoltava = 3; //montako palikkaa oltava perakkain, etta poistetaan
int pisteet = 0; //pistelaskuri
int main()
{
	srand((unsigned)time(NULL)); //F1-helpin esimerkista, random-kayttaa tietokoneen kelloa lukujonona
	HIGHSCORE huippupisteet[10];
	char kentta[dimensio][dimensio] = { { NULL },{ NULL } }; //kaksiulotteisen char-taulukon esittely ja maarittely
	while (true)
	{
		switch (Valikko()) //paavalikko
		{
		default: 
			for (int i = 0; ; i++)
			{
				char *palikan_sijoitus = NULL; //osoittimen esittely ja maarittely
				palikan_sijoitus = new char; //uuden palikan luonti
				if (palikan_sijoitus) //jos tilanvaraus onnistui
				{
					palikan_sijoitus = &kentta[alkukohta][dimensio / 2]; //osoitin osoittaa kaksiulotteisen char-taulukon keskusmuistiosoitteeseen
				}
				else
				{
					cout << "Tilanvaraus ei onnistunut.\n";
				}
				{
					PalikanLuonti(palikan_sijoitus, huippupisteet); //lahettaa taulukon sisaltavan osoittimen ja tietueen
					KentanTulostus(kentta); //lahettaa nykyisen pelitilanteen
					Liikkuminen(palikan_sijoitus, kentta); //lahettaa taulukon sisaltavan osoittimen ja //lahettaa nykyisen pelitilanteen
					PalikoidenPoistoV(kentta); //lahettaa nykyisen pelitilanteen
					PalikoidenPoistoP(kentta); //lahettaa nykyisen pelitilanteen
					pisteet++;
					PalikoidenPudotus(kentta); //lahettaa nykyisen pelitilanteen
				}
			}
			break;
		case 2:
			LuePisteet(huippupisteet);
			break;
		case 3:
			exit(0); //lopetus
			break;
		}
	}
}

void KentanTulostus(char kentta[dimensio][dimensio])
{
	system("cls"); //tyhjentaa ruudun
	int rivi = dimensio, sarake = dimensio;
	for (rivi = 0; rivi < dimensio; rivi++)
	{
		for (sarake = 0; sarake < dimensio; sarake++) //kay taulukon kaikki ruudut lapi
		{
			if (rivi == 0 || rivi == (dimensio - 1) || sarake == 0 || sarake == (dimensio - 1)) //reunoden luonti
			{
				kentta[rivi][sarake] = '-';
			}
			if (sarake == (dimensio - 1)) //ruutujen tutkiminen
			{
				cout << kentta[rivi][sarake] << endl; //viimeinen sarake, rivinvaihto
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
	if (*palikan_sijoitus == '-' || *palikan_sijoitus == 'x' || *palikan_sijoitus == 'y' || *palikan_sijoitus == 'z') //tutkii onko tilaa uudelle palikalle
	{
		cout << "Pisteesi: " << pisteet << endl; //jos ei ole, peli paattyy
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
	int palikka_arpa = rand() % 3 + 1; //arpoo arvon 1<=x<=3
	switch (palikka_arpa)
	{
	case 1:
		*palikan_sijoitus = 'x'; //osoittimen sisaltoon arvottu palikka
		break;
	case 2:
		*palikan_sijoitus = 'y';
		break;
	case 3:
		*palikan_sijoitus = 'z';
		break;
	}
}

void Liikkuminen(char *&palikan_sijoitus, char kentta[dimensio][dimensio]) //palikan sijainta ja kentan tilanne
{
	char *uusi_paikka = NULL; //osoittimen luonti
	char syote;
	int indeksi = alkukohta;
	int sivuliike = 1; //montako ruutua palikka liikku sivuttain
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
		while (j<dimensio) //k�yd��n l�pi merkkijonoa
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
		while (j<dimensio) //k�yd��n l�pi merkkijonoa
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

//void PystyTarkastelu(char *&tarkistuspointteri, char merkki, int j, int sarake, char merkkijono[dimensio + 1], char kentta[dimensio][dimensio])
void PystyTarkastelu(char *&tarkistuspointteri, char merkki, int j, int sarake, char *merkkijono, char *kentta[dimensio])
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