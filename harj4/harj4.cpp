#include <iostream> //kutsuu esik‰‰nnˆst‰ "iostream" linkitysvaiheessa. N‰pp‰imistˆ ja n‰yttˆ, cout & cin
using namespace std; //m‰‰ritt‰‰ k‰ytett‰v‰n nimiavaruuden, jonka nimi on t‰ss‰ "std"
// m‰‰ritell‰‰n vakioita
#define MINIMI 10 // vanha, EI suositeltava tapa. Vakiot kirjoitetaan isolla, tapa. T‰ss‰ m‰‰ritell‰‰n MINIMI-vakion arvoksi 10
const int MAKSIMI = 20; // uusi, suositeltava tapa. M‰‰ritt‰‰ int-kokonaislukutyyppisen vakion MAKSIMI arvoksi 20
// muuttujien esittely
int summa; // int-tyyppinen summa-niminen muuttuja ilman ilmaistua alkuarvoa
//aliohjelmien esittely
void Laske(int, int); // Laske-niminen aliohjelma, johon kutsuttaessa l‰hetet‰‰n kaksi int-tyyppist‰ parametria

void main() // p‰‰ohjelma alkaa ja on kapseloitu aaltosulkeiden, rivien 12. ja 25., v‰liin
{
	int luku1 = 2; // m‰‰ritell‰‰n kokonaisluku, jonka nimi on luku1 ja alkuarvo on 2
	int luku2; // m‰‰ritell‰‰n kokonaisluku, jonka nimi on luku2, mutta sille ei ole asetettu alkuarvoa (sill‰ kuitenkin on joku arvo)
	cout << "Syˆt‰ luku: "; // tulostaa n‰ytˆlle teksti‰
	cin >> luku2; // m‰‰ritt‰‰ luku2-muuttujan arvoksi k‰ytt‰j‰n syˆtt‰m‰n arvon
	Laske(luku1, luku2); // kutsuu aliohjelmaa Laske() ja kopioi parametrit luku1 ja luku2 sinne
	if (summa < MINIMI) // jos summa:n arvo on pienempi kuin MINIMI:, niin tulostaa n‰ytˆlle seuraavalla rivill‰ olevan tekstin
		cout << "Summa on pienempi kuin " << MINIMI << "." << endl; // tulostaa: tekstin, muuttujan arvon, tekstin (.) ja rivinvaihdon
	if (summa > MAKSIMI) // jos summa:n arvo on suurempi kuin MAKSIMI:m, niin tulostaa n‰ytˆlle seuraavalla rivill‰ olevan tekstin
		cout << "Summa on suurempi kuin " << MAKSIMI << "." << endl; // tulostaa: tekstin, muuttujan arvon, tekstin ja rivinvaihdon
	if (MINIMI < summa && summa < MAKSIMI) // jos MINIMI:n arvo on suurempi kuin summa:n ja summa:n arvo on pienempi kuin MAKSIMI:n, niin tulostaa seuraavan rivin
		cout << "Summa on " << MINIMI << " ja " << MAKSIMI <<" v‰liss‰.\n"; // tulostaa: tekstin, muuttujan, tekstin, muuttujan, tekstin ja rivinvaihto
}
void Laske(int eka, int toka) // t‰ss‰ nimet‰‰n kutsujan l‰hett‰m‰t arvot
{
	summa = eka + toka; // laskee yhteen luvut eka ja toka. Palauttaa summa:n arvon kutsujalle k‰yttˆ‰ varten
}