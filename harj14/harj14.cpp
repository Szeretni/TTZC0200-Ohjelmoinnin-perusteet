/************************
Teht�v�: Harjoitus 14
Tekij�: Hannu Oksman
Kuvaus:
Harjoitus 14 (Palautus vko 45)

T�SS� TEHT�V�SS� ON K�YTETT�V� C-kielen merkkitaulukoita! Taulukon m��rittely on siis muotoa

char mjono[xx];

Tee ohjelma, joka kysyy k�ytt�j�lt� 17 merkki�
pitk�n merkkijonon (ei v�lily�ntej�).
a) Ohjelma tulostaa merkkijonon k��nteisess� j�rjestyksess� n�yt�lle
(tulostus tyyppi� "cout << mjono1[4];" jne)
b) Ohjelma k��nt�� annetun merkkijonon toiseen
merkkijonoon ja tulostaa sen n�yt�lle
(tulostus tyyppi� "cout << mjono2;")
c) merkkijono voi olla kuinka pitk�
tahansa (max 100 kirjainta).
Sy�tetyn merkkijonon pituutta ei saa
laskea mill��n kirjastofunktiolla
(esim. lenght tms.) Ohjelma
tutkii onko annettu merkkijono
palindromi ja ilmoittaa sen k�ytt�j�lle.
V�lily�nnit jonossa ovat sallittuja.

K�ytt�j� sy�tt�� jonon: ABC_Kissa_kavelee
ohjelma tulostaa: eelevak_assiK_CBA

Pvm: 5.10.2017
ver: 1.0 OksHa
************************/
//KOHTA A:
#include <iostream>
using namespace std;
char merkkijono[100];
int merkkien_maara = 17;
int kaanto = merkkien_maara / 2; //t�t� k�ytet��n merkkien vaihdossa. jos esim. 5 merkki�, niin kaanto=2, jolloin vaihtaa 0.&4. ja 1.&3. merkkien paikkoja
int i;
int main(void)
{
	cout << "Anna 17. merkki�. V�lily�nti, tabulaattori ja rivinvaihto eiv�t kelpaa: ";
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
	cout << "Anna 17. merkki�. V�lily�nti, tabulaattori ja rivinvaihto eiv�t kelpaa: ";
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
	cout << "Alkuper�inen: " << merkkijono << " ja k��nnetty: " << toinenmj << endl;
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
	cin.getline(merkkijono, 101); //sallii v�lily�nnit
	merkkien_maara = strlen(merkkijono); //strlen laskee merkkien m��r�n
	kaanto = merkkien_maara / 2;
	strcpy(toinenmj, merkkijono); //kopioi annetun merkkijonen toiseen, jotta voi verrata alkuper�ist� ja k��nnetty�
	for (i = 0; i < kaanto; i++)
	{
		char temp = toinenmj[i];
		toinenmj[i] = toinenmj[merkkien_maara - i - 1]; //-1, koska muutoin poimii lopetusmerkin
		toinenmj[merkkien_maara - i - 1] = temp;
	}
	palin = strcmp(merkkijono, toinenmj); //vertaa merkki merkilt� char desimaaliarvoa ja jos eroa, niin palauttaa erotuksen
	if (palin == 0) //jos eroa ei ole, niin erotus on 0 ja kyseess� on palindromi
	{
		cout << "Annaettu merkkijono on palindromi." << endl;
	}
	else
	{
		cout << "Annettu merkkijono ei ole palindromi." << endl;
	}
	cout << "Sy�tetty merkkijono:  " << merkkijono << endl;
	cout << "K��nnetty merkkijono: " << toinenmj << endl;
}
*/