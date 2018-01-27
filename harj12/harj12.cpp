/************************
Teht‰v‰: Harjoitus 12
Tekij‰: Hannu Oksman
Kuvaus:
Harjoitus 12 (Palautus vko 43)

Tee ohjelma, joka kysyy k‰ytt‰j‰lt‰ kokonaisluvun v‰lilt‰ 1-9 ja
tulostaa vastauksen perusteella seuraavan kuvion (jos vastaus on 6):

1
22
333
4444
55555
666666

Jokainen numero tulee tulostaa toistorakenten avulla erikseen lauseella:
cout << rivinro;

Pvm: 5.10.2017
ver: 1.0 OksHa
************************/
/*#include <iostream>
#include <climits> //jotta voi k‰ytt‰‰ INT_MAX
using namespace std;
char merkki;
int luku, i, j;

void main()
{
	while (true)
	{
		cout << "Anna kokonaisluku v‰lilt‰ 1-9: \n";
		cin.get(merkki);
		cin.ignore(INT_MAX, '\n'); //ettei tule overflow, tyhjent‰‰ puskurista int-tyypin maksimiarvon verran merkkej‰ tai kun lopetusmerkki tulee
		luku = (int)merkki - '0'; //Luvun 1 ASCII-numero on 49, joten 1=49-48 ('0' = 48)
		if (luku > 0 && luku < 10)
		{
			for (i = 1; i <= luku; i++)
			{
				for (j = 1; j <= i; j++)
				{
					cout << i;
				}
				cout << endl;
			}
			break;
		}
	}
}
*/

#include <iostream>
#include <climits> //jotta voi k‰ytt‰‰ INT_MAX
using namespace std;
int luku, i, j;
float murtoluku;
void main()
{
	while (true)
	{
		cout << "Anna kokonaisluku v‰lilt‰ 1-9: \n";
		cin >> murtoluku; //k‰ytt‰j‰n pit‰isi antaa vain kokonaisluvun, mutta saattaa antaa esim 1.2. Nyt K‰ytt‰j‰n input tallennetaan floatiksi
		luku = (int)murtoluku;  //muutetaan float int-muotoon ja tallennetaan lukuun
		if (luku == murtoluku) //t‰ll‰ verrataan, ett‰ kyseess‰ on kokonaisluku. Jos k‰ytt‰j‰ on antanut 1.2, niin murtoluku=1.2 ja luku=1, jolloin pyyt‰‰ k‰ytt‰j‰lt‰ uuden luvun
		{
			if (luku < 10 && luku > 0)
			{
				for (i = 1; i <= luku; i++)
				{
					for (j = 1; j <= i; j++)
					{
						cout << i;
					}
					cout << endl;
				}
				break;
			}
			cin.clear(); //jos k‰ytt‰j‰ antaa muun kuin numeron, niin menisi loputtomaan looppiin, koska cin on vikatilassa eik‰ sit‰ voi en‰‰ kutsua
			cin.ignore(INT_MAX, '\n'); //Vikatilasta p‰‰see pois kuittaamalla vikatilan ja tyhjent‰m‰ll‰ puskurin (Google) 
		}
	}
}