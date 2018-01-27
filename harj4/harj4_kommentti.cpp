#include <iostream> //kutsuu esikäännöstä "iostream" linkitysvaiheessa. Näppäimistö ja näyttö, cout & cin
using namespace std; //määrittää käytettävän nimiavaruuden, jonka nimi on tässä "std"
// määritellään vakioita
#define MAX 10 // vanha, EI suositeltava tapa. Vakiot kirjoitetaan isolla, tapa. Tässä määritellään MAX-muuttujan alkuarvoksi 10
const int max = 20; // uusi, suositeltava tapa. Määrittää int-(luku)tyyppisen vakion max-nimisen muuttujan arvoksi 20
// muuttujien esittely
int summa; // int-tyyppinen summa-niminen muuttuja ilman ilmaistua alkuarvoa
//aliohjelmien esittely
void Laske(int, int); // Laske-niminen aliohjelma, joka käyttää kahta int-tyyppistä parametria

void main() // pääohjelma alkaa ja on kapseloitu aaltosulkeiden (rivi 11. ja 22. väliin)
{
	int luku1 = 2; // määritellään kokonaisluku, jonka nimi on luku1 ja sen alkuarvo on 2
	int luku2; // määritellään kokonaisluku, jonka nimi on luku2, mutta sille ei ole asetettu alkuarvoa
	cout << "Syötä luku: "; // tulostaa näytölle tekstiä
	cin >> luku2; // määrittää luku2-muuttujaan käyttäjän syöttämä arvo
	Laske(luku1, luku2); // kutsuu aliohjelmaa Laske() ja kopioi parametrit luku1 ja luku2 sinne
	if (summa < MAX) // jos summa-nimisen muuttujan arvo on pienempi kuin muuttujan MAX, niin tulostaa näytölle seuraavalla rivillä olevan tekstin
		cout << "Summa on pienempi kuin " << MAX; // summa-arvo tuli aliohjelmasta Laske. MAX arvo on määritelty rivillä 4.
	if (summa < max) // jos summa-nimisen muuttujan arvo on pienempi kuin muuttujan max, niin tulostaa näytölle seuraavalla rivillä olevan tekstin
		cout << "Summa on pienempi kuin " << max; // summa-arvo tuli aliohjelmasta Laske. max arvo on määritelty rivillä 5.
}
void Laske(int eka, int toka) // tässä nimetään minkä nimiä kutsujan lähettämät arvot ovat
{
	summa = eka + toka; // laskee yhteen luvut eka ja toka. Palauttaa summa-muuttujan arvon mainiin
}