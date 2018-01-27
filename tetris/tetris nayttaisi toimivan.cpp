/*
Tetris by Hannu Oksman 2017
*/

#include <iostream>
#include <time.h> //random koneen kellosta
#include <cstring>
#include <fstream>
using namespace std;
const int dimensio = 7;
int alkukohta = 1;
int perakkainoltava = 3;
int pisteet = 0;
void KentanTulostus(char[dimensio][dimensio]);
void PalikanLuonti(char *&);
void Liikkuminen(char *&, char[dimensio][dimensio]);
void TallennaPisteet(int pisteet);
void LuePisteet();
void PalikoidenPoistoV(char[dimensio][dimensio]);
void PalikoidenPoistoP(char[dimensio][dimensio]);
void PystyTarkastelu(char *&, char, int, int, char [dimensio+1], char[dimensio][dimensio]);
int main()
{
	LuePisteet();
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
			PalikoidenPoistoV(kentta);
			PalikoidenPoistoP(kentta);
			pisteet++;
		}
	}
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
		TallennaPisteet(pisteet);
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

void TallennaPisteet(int pisteet)
{
	ofstream kirjoitus("tetris_score.txt");
	cout << "Anna nimesi: ";
	char nimi[20];
	cin >> nimi;
	for (int i = 0; i < 1; i++)
	{
		kirjoitus << "\"NIMI\"" << ":" << nimi << endl;
		kirjoitus << "\"PISTEET\"" << ":" << pisteet;
	}
	kirjoitus.close();
}

void LuePisteet()
{
	ifstream haefile("tetris_score.txt");
	if (haefile.is_open())
	{
		char selite[256];
		for (int i = 0; ; i++)
		{
			if (haefile.peek() == EOF)
			{
				break;
			}

			else
			{
				char luenta[256];
				haefile.getline(selite, 256, ':');
				haefile >> luenta;
				cout << luenta << ": ";
				haefile >> ws;
				haefile.getline(selite, 256, ':');
				haefile >> luenta;
				cout << luenta;
				cout << endl;
			}
		}
		haefile.close();
	}
	else
	{
		cout << "Tallennettuja tietoja ei ole." << endl;
	}
}

void PalikoidenPoistoV(char kentta[dimensio][dimensio])
{
	for (int rivi = 0; rivi < dimensio; rivi++)
	{
		char merkkijono[dimensio + 1];
		for (int sarake = 0; sarake < dimensio; sarake++)
		{
			merkkijono[sarake] = kentta[rivi][sarake]; //koko rivi tallennetaan merkkijonoon
		}
		char *tarkistuspointteri = merkkijono; //osoittaa merkkijonoon
		int montakosamaamerkkia = 0;
		int j = 0;
		while (j<dimensio) //käydään läpi merkkijonoa
		{
			int apu_j = j; //talteen mika kierros on
			char *poistopointteri = NULL;
			if ((*tarkistuspointteri) == 'x' || (*tarkistuspointteri) == 'y' || (*tarkistuspointteri) == 'z')
			{
				//tarkistus montako samaa on perakkain
				while ((*tarkistuspointteri) == 'x')
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
				while ((*tarkistuspointteri) == 'y')
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
				while ((*tarkistuspointteri) == 'z')
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
			tarkistuspointteri++;
			j++;
		}
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