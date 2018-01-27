#include "tetris.h"
void TallennaPisteet(int pisteet, HIGHSCORE huippupisteet[10])
{
	ofstream kirjoitus("tetris_score.txt");
	for (int i = 0; i < 10; i++)
	{
		kirjoitus << "\"NIMI\"" << ":" << huippupisteet[i].nimi << endl;
		kirjoitus << "\"PISTEET\"" << ":" << huippupisteet[i].score << endl;
		kirjoitus << "\"PAIVAMAARA\"" << ":" << huippupisteet[i].paiva << endl;
	}
	kirjoitus.close();
}

void LuePisteet(HIGHSCORE huippupisteet[10])
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
				haefile.getline(selite, 256, ':');
				haefile >> huippupisteet[i].nimi;
				haefile >> ws;
				haefile.getline(selite, 256, ':');
				haefile >> huippupisteet[i].score;
				haefile >> ws;
				haefile.getline(selite, 256, ':');
				haefile.getline(huippupisteet[i].paiva, 13);
				haefile >> ws;
				if (huippupisteet[i].score > 5)
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