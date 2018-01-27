/*
Tassa tiedostossa on ulkoisen tiedoston kirjoitus ja tulostus
*/

#include "tetris_koulukone.h" //oman otsikkotiedoston sisallytys
void TallennaPisteet(int pisteet, HIGHSCORE huippupisteet[10])
{
	ofstream kirjoitus("tetris_score.txt"); //tallentaa tiedostoon, JSON-formaatti
	for (int i = 0; i < 10; i++)
	{
		kirjoitus << "\"NIMI\"" << ":" << huippupisteet[i].nimi << endl;
		kirjoitus << "\"PISTEET\"" << ":" << huippupisteet[i].score << endl;
		kirjoitus << "\"PAIVAMAARA\"" << ":" << huippupisteet[i].paiva << endl;
	}
	kirjoitus.close(); //sulkee tiedostopuskurin
}

void LuePisteet(HIGHSCORE huippupisteet[10]) //tulostaa tiedostosta
{
	ifstream haefile("tetris_score.txt");
	if (haefile.is_open()) //tarkistaa onko tiedostoa olemassa
	{
		char selite[256]; //talla poimitaan pois tassa tapauksessa tarpeeton informaatio
		for (int i = 0; ; i++)
		{
			if (haefile.peek() == EOF) //tarkistaa onko seuraava merkki tiedoston lopetuspiste
			{
				break; //jos on, niin silmukan lopetus
			}
			else
			{
				haefile.getline(selite, 256, ':'); //lukee selite-muuttujaan 256 merkkia tai lopetusmerkin ":"
				haefile >> huippupisteet[i].nimi; //sijoitus tuotuun taulukkoo
				haefile >> ws;
				haefile.getline(selite, 256, ':');
				haefile >> huippupisteet[i].score;
				haefile >> ws;
				haefile.getline(selite, 256, ':');
				haefile.getline(huippupisteet[i].paiva, 13);
				haefile >> ws;
				if (huippupisteet[i].score > 5) //jos yli 5 pistetta, niin tulostaa tiedot
				{
					cout << huippupisteet[i].nimi << endl;
					cout << huippupisteet[i].score << endl;
					cout << huippupisteet[i].paiva << endl;
				}
			}
		}
		haefile.close();
	}
}