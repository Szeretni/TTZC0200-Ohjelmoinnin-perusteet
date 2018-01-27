/************************
Teht�v�: Harjoitus 19
Tekij�: Hannu Oksman
Kuvaus:
Harjoitus 19 (Palautus vko 47)
Tee ohjelma, joka toimii auton nopeusmittarina.
Periaate on seuraava: N�pp�imist� toimii
nopeusanturina ja n�ytt� mittarin n�ytt�n�.
Nopeusmittari laskee viiden viimeisen nopeuden
keskiarvon ja tulostaa sen nykyisen� nopeutena
n�yt�lle. Negatiivinen nopeus lopettaa ohjelman.
Toiminta on siis seuraava:
Ohjelman kaynnistyksessa mittari n�ytt�� nolla
0
0
0
0
0 (alkutila) nopeus = 0 km/h
Anna nopeus: 10
=> 2 km/h
Anna nopeus: 20
=> 6 km/h
Anna nopeus: 30
=> 12 km/h
Anna nopeus: 40
=> 20 km/h
Anna nopeus: 50
=> 30 km/h
Anna nopeus: 50
=> 38 km/h
Anna nopeus: 50
=> 44 km/h
Anna nopeus: 50
=> 48 km/h
Anna nopeus: 50
=> 50 km/h
Anna nopeus: 50
=> 50 km/h
Anna nopeus: -5
=> loppu

K�ytt�j�n sy�te ohjelmalle lihavoitu ja kallistettu.

Toteuta kayttaen taulukkoa.

Pvm: 26.10.2017
ver: 1.0 OksHa
************************/
#include <iostream>
using namespace std;
const int KESKIARVO_MAARA = 5;
int nopeustaulu[KESKIARVO_MAARA] = { 0,0,0,0,0 }; //{0} olisi riitt�nyt
int syote, nopeusmittari, nopeus_sum;
int main(void)
{
	cout << "Anna nopeus: ";
	cin >> syote;
	while (syote >= 0)
	{
		for (int i = 0; i < KESKIARVO_MAARA; i++) //t�ll� sijoitetaan annettu sy�te oikeaan kohtaan taulukossa
		{
			nopeustaulu[i] = syote;
			for (int j = 0; j < KESKIARVO_MAARA; j++) //t�ll� lasketaan taulun arvojen summa kun uusi sy�te on saatu
			{
				nopeus_sum += nopeustaulu[j];
			}
			nopeusmittari = nopeus_sum / KESKIARVO_MAARA; //t�ss� lasketaan taulukon arvojen keskiarvo
			nopeus_sum = 0; //nollataan uutta kierrosta varten
			cout << nopeusmittari << " km/h" << endl;
			cout << "Anna nopeus: ";
			cin >> syote;
			if (syote < 0)
				break;
		}
	}
	cout << "loppu" << endl;
}