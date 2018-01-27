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
int main()
{
	LuePisteet();
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
			pisteet++;
		}

		//välissä on uutta

		for (rivi = 0; rivi < dimensio; rivi++)
		{
			char merkkijono[dimensio+1];
			for (sarake = 0; sarake < dimensio; sarake++)
			{
				merkkijono[sarake] = kentta[rivi][sarake];
			}
			char *tarkistuspointteri = merkkijono;
			int montakosamaamerkkia = 0;
			for (int j = 0; j < dimensio; j++)
			{
				char apu = *tarkistuspointteri;
				char *poistopointteri = NULL;
				if ((*tarkistuspointteri) == 'x')
					//tarkastettava onko seuraava 'x'
				{
					montakosamaamerkkia++;
					tarkistuspointteri++;
					j++;
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
					}
					else
					{
						montakosamaamerkkia = 0;
						*tarkistuspointteri = apu;
					}
					/*if ((*tarkistuspointteri) == 'x')
					{
						montakosamaamerkkia++;
						if (montakosamaamerkkia >= perakkainoltava)
						{
							if (*(tarkistuspointteri + 1) != 'x' || *(tarkistuspointteri + 1) == '-' || *(tarkistuspointteri + 1) == NULL)
							{
								for (int k = montakosamaamerkkia; k > 0; k--)
								{
									poistopointteri = &kentta[rivi][j - montakosamaamerkkia + 1];
									*poistopointteri = NULL;
									montakosamaamerkkia--;
								}
							}
						}
					}*/
				}
				/*else if ((*tarkistuspointteri) == 'y')
				{
					montakosamaamerkkia++;
					if (montakosamaamerkkia >= perakkainoltava)
					{
						if (*(tarkistuspointteri + 1) != 'y' || *(tarkistuspointteri + 1) == '-' || *(tarkistuspointteri + 1) == NULL)
						{
							for (int k = montakosamaamerkkia; k > 0; k--)
							{
								poistopointteri = &kentta[rivi][j - montakosamaamerkkia + 1];
								*poistopointteri = NULL;
								montakosamaamerkkia--;
							}
						}
					}
				}
				else if ((*tarkistuspointteri) == 'z')
				{
					montakosamaamerkkia++;
					if (montakosamaamerkkia >= perakkainoltava)
					{
						if (*(tarkistuspointteri + 1) != 'z' || *(tarkistuspointteri + 1) == '-' || *(tarkistuspointteri + 1) == NULL)
						{
							for (int k = montakosamaamerkkia; k > 0; k--)
							{
								poistopointteri = &kentta[rivi][j - montakosamaamerkkia +1];
								*poistopointteri = NULL;
								montakosamaamerkkia--;
							}
						}
					}
				}
				*/
				tarkistuspointteri++;

				/*
				if (merkkijono[j] == 'x' && merkkijono[j + 1] == 'x'  && merkkijono[j + 2] == 'x')
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
				*/
			}
		}
	}

	//välissä on uutta

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
		*palikan_sijoitus = 'x'; //TEMP PITAA OLLA Y
		break;
	case 3:
		*palikan_sijoitus = 'x'; //TEMP PITAA OLLA Z
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