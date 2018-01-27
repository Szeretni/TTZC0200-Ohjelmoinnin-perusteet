#include <iostream> //kutsuu esik��nn�st� "iostream" linkitysvaiheessa. N�pp�imist� ja n�ytt�, cout & cin
using namespace std; //m��ritt�� k�ytett�v�n nimiavaruuden, jonka nimi on t�ss� "std"
// m��ritell��n vakioita
#define MAX 10 // vanha, EI suositeltava tapa. Vakiot kirjoitetaan isolla, tapa. T�ss� m��ritell��n MAX-muuttujan alkuarvoksi 10
const int max = 20; // uusi, suositeltava tapa. M��ritt�� int-(luku)tyyppisen vakion max-nimisen muuttujan arvoksi 20
// muuttujien esittely
int summa; // int-tyyppinen summa-niminen muuttuja ilman ilmaistua alkuarvoa
//aliohjelmien esittely
void Laske(int, int); // Laske-niminen aliohjelma, joka k�ytt�� kahta int-tyyppist� parametria

void main() // p��ohjelma alkaa ja on kapseloitu aaltosulkeiden (rivi 11. ja 22. v�liin)
{
	int luku1 = 2; // m��ritell��n kokonaisluku, jonka nimi on luku1 ja sen alkuarvo on 2
	int luku2; // m��ritell��n kokonaisluku, jonka nimi on luku2, mutta sille ei ole asetettu alkuarvoa
	cout << "Sy�t� luku: "; // tulostaa n�yt�lle teksti�
	cin >> luku2; // m��ritt�� luku2-muuttujaan k�ytt�j�n sy�tt�m� arvo
	Laske(luku1, luku2); // kutsuu aliohjelmaa Laske() ja kopioi parametrit luku1 ja luku2 sinne
	if (summa < MAX) // jos summa-nimisen muuttujan arvo on pienempi kuin muuttujan MAX, niin tulostaa n�yt�lle seuraavalla rivill� olevan tekstin
		cout << "Summa on pienempi kuin " << MAX; // summa-arvo tuli aliohjelmasta Laske. MAX arvo on m��ritelty rivill� 4.
	if (summa < max) // jos summa-nimisen muuttujan arvo on pienempi kuin muuttujan max, niin tulostaa n�yt�lle seuraavalla rivill� olevan tekstin
		cout << "Summa on pienempi kuin " << max; // summa-arvo tuli aliohjelmasta Laske. max arvo on m��ritelty rivill� 5.
}
void Laske(int eka, int toka) // t�ss� nimet��n mink� nimi� kutsujan l�hett�m�t arvot ovat
{
	summa = eka + toka; // laskee yhteen luvut eka ja toka. Palauttaa summa-muuttujan arvon mainiin
}