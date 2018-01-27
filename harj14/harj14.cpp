/************************
Tehtävä: Harjoitus 14
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 14 (Palautus vko 45)

TäSSä TEHTÄVÄSSÄ ON KÄYTETTÄVÄ C-kielen merkkitaulukoita! Taulukon määrittely on siis muotoa

char mjono[xx];

Tee ohjelma, joka kysyy käyttäjältä 17 merkkiä
pitkän merkkijonon (ei välilyäntejä).
a) Ohjelma tulostaa merkkijonon käänteisessä järjestyksessä näytälle
(tulostus tyyppiä "cout << mjono1[4];" jne)
b) Ohjelma kääntää annetun merkkijonon toiseen
merkkijonoon ja tulostaa sen näytälle
(tulostus tyyppiä "cout << mjono2;")
c) merkkijono voi olla kuinka pitkä
tahansa (max 100 kirjainta).
Syätetyn merkkijonon pituutta ei saa
laskea millään kirjastofunktiolla
(esim. lenght tms.) Ohjelma
tutkii onko annettu merkkijono
palindromi ja ilmoittaa sen käyttäjälle.
Välilyännit jonossa ovat sallittuja.

Käyttäjä syöttää jonon: ABC_Kissa_kavelee
ohjelma tulostaa: eelevak_assiK_CBA

Pvm: 5.10.2017
ver: 1.0 OksHa
************************/
//KOHTA A:
#include <iostream>
using namespace std;
char merkkijono[100];
int merkkien_maara = 17;
int kaanto = merkkien_maara / 2; //tätä käytetään merkkien vaihdossa. jos esim. 5 merkkiä, niin kaanto=2, jolloin vaihtaa 0.&4. ja 1.&3. merkkien paikkoja
int i;
int main(void)
{
	cout << "Anna 17. merkkiä. Välilyönti, tabulaattori ja rivinvaihto eivät kelpaa: ";
	for (i = 0; i < merkkien_maara; i++)
		{
			cin >> ws; //poistaa white spaces
			cin.get(merkkijono[i]);
		}
	for (i = 0; i < kaanto; i++)
		{
			char temp = merkkijono[i];
			merkkijono[i] = merkkijono[merkkien_maara - i - 1]; //-1, koska muutoin poimii lopetusmerkin
			merkkijono[merkkien_maara - i - 1] = temp;
		}
	for (i = 0; i < merkkien_maara; i++)
		{
			cout << merkkijono[i];
		}
	cout << endl;
}

//KOHTA B
/*#include <iostream>
#include <cstring> //strcpy varten
using namespace std;
char merkkijono[100], toinenmj[100];
int merkkien_maara = 17;
int kaanto = merkkien_maara / 2;
int i;
int main(void)
{
	cout << "Anna 17. merkkiä. Välilyönti, tabulaattori ja rivinvaihto eivät kelpaa: ";
	for (i = 0; i < merkkien_maara; i++)
		{
			cin >> ws;
			cin.get(merkkijono[i]);
		}
	strcpy(toinenmj, merkkijono);
	for (i = 0; i < kaanto; i++)
		{
			char temp = toinenmj[i];
			toinenmj[i] = toinenmj[merkkien_maara - i - 1]; //-1, koska muutoin poimii lopetusmerkin
			toinenmj[merkkien_maara - i - 1] = temp;
		}
	cout << "Alkuperäinen: " << merkkijono << " ja käännetty: " << toinenmj << endl;
}
*/
//KOHTA C
/*#include <iostream>
#include <cstring> //strcpy varten
using namespace std;
char merkkijono[101], toinenmj[101];
int merkkien_maara, kaanto, i, palin;
int main(void)
{
	cout << "Anna max. 100 kirjainta ";
	cin.getline(merkkijono, 101); //sallii välilyönnit
	merkkien_maara = strlen(merkkijono); //strlen laskee merkkien määrän
	kaanto = merkkien_maara / 2;
	strcpy(toinenmj, merkkijono); //kopioi annetun merkkijonen toiseen, jotta voi verrata alkuperäistä ja käännettyä
	for (i = 0; i < kaanto; i++)
	{
		char temp = toinenmj[i];
		toinenmj[i] = toinenmj[merkkien_maara - i - 1]; //-1, koska muutoin poimii lopetusmerkin
		toinenmj[merkkien_maara - i - 1] = temp;
	}
	palin = strcmp(merkkijono, toinenmj); //vertaa merkki merkiltä char desimaaliarvoa ja jos eroa, niin palauttaa erotuksen
	if (palin == 0) //jos eroa ei ole, niin erotus on 0 ja kyseessä on palindromi
	{
		cout << "Annaettu merkkijono on palindromi." << endl;
	}
	else
	{
		cout << "Annettu merkkijono ei ole palindromi." << endl;
	}
	cout << "Syötetty merkkijono:  " << merkkijono << endl;
	cout << "Käännetty merkkijono: " << toinenmj << endl;
}
*/