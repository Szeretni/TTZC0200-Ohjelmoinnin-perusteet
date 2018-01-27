/*//KERTAUS
#include <iostream>
#include <climits>
using namespace std;
void main()
{
	cout << "Vain char-taulukossa on lopetusmerkki, esim. int struct ei ole";

cout << "CHAR_MAX: " << CHAR_MAX << endl; //merkki
cout << "SHRT_MAX: " << SHRT_MAX << endl; //16-bittinen kokonaisluku
cout << "INT_MAX: " << INT_MAX << endl; //16/32-bittinen kokonaisluku
cout << "LONG_MAX: " << LONG_MAX << endl; //32-bittinen kokonaisluku
cout << "LLONG_MAX: " << LLONG_MAX << endl;
cout << "FLT_MAX: " << FLT_MAX << endl; //32-bittinen reaaliluku (4tavua). Tarkkuus 6 numeroa
cout << "DBL_MAX: " << DBL_MAX << endl; //64-bittinen 15 desimaalia (8tavua). Tarkkuus 15
cout << "LDBL_MAX: " << LDBL_MAX << endl; //80-bittinen reaaliluku (10tavua). Tarkkuus 18
char mj[10] = "Lauri"; //merkkitaulukko
cout << "mj:" << mj << endl;
cout << "mj[3]: " << mj[3] << endl;
cout << "unsigned saa positiivisen lukualueen" << endl;

int a = 1;
a = a + 1;
a++;
++a;
a += 1;
cout << "a: " << a << endl;

cout << "Toistorakenteet ovat 'do', 'do while' ja 'for'";
cout << "Hyppykäskyt continue ja break";


//Valintarakenteita
cout << "if-lauseen operaattoreita < > <= >= == != && ||\n";
cout << "Switch-case\n";

cout << "ASCII-merkit\n";
char merkki = 'a';
merkki -= 97;
for (int i = 0; i < 256; i++)
{
cout << i << ": " << merkki << endl;
merkki++;
}
}
*/

// ESIMERKKI 5-1
/*#include <iostream>
using namespace std;
int main()
{
double luku = 32767000000;
luku = luku + 1;
cout << luku << endl;
return 0;
}*/

//ESIMERKKI 5-5
/*#include <iostream> 
using namespace std;
int main()
{
	char merkki = 'a';
	cout << endl << "Merkki on nyt: " << merkki << (int)merkki;
	merkki = merkki + 1;
	cout << endl << "Merkki on nyt: " << merkki << (int)merkki << endl;
	char nimi[8] = "Hannu";
	cout << nimi << endl;
	cout << "Anna nimesi: ";
	cin >> nimi;
	cout << "Nimesi on siis " << nimi << endl;
	return 0;
}
*/
//ESIMERKKI 6-2
/*#include <iostream> 
using namespace std;
int main(void)
{
	int luku = 5;
	int lukux;
	char merkki = 'a';
	float reaali = 5.5;
	float reaalix;
	lukux = merkki;
	cout << "\nchar -> int " << lukux;
	lukux = reaali;
	cout << "\nfloat -> int " << lukux;
	reaalix = luku;
	cout << "\nint -> float " << reaalix;
	reaalix = merkki;
	cout << "\nchar -> float " << reaalix;
	return 0;
}
*/
//ESIMERKKI 6-2 MUOKATTU
/*#include <iostream> 
using namespace std;
int main(void)
{
	int luku = 5;
	float lukux;
	char merkki = 'a';
	float reaali = 5.5;
	float reaalix;
	lukux = merkki;
	cout << "\nchar -> int " << lukux;
	lukux = (int)reaali; //                        huomio. n„in voi tarkentaa min„ tyypin„ haluaa muuttaa muuttujan
	cout << "\nfloat -> int " << lukux;
	reaalix = (float)luku; //                      conversion from 'int' to 'float', possible loss of data kts. ylempi kommentti
	cout << "\nint -> float " << reaalix; //       valittaa koska int arvo on t„sm„llinen, float on reaaliluku ja sen tarkkuus on rajattu, joten se on ep„tarkka
	reaalix = merkki;
	cout << "\nchar -> float " << reaalix;
	return 0;
}
*/
//ESIMERKKI 6-4
/*#include <iostream> 
using namespace std;
#include <cstring> 
int main()
{
	char jono1[10] = "C-kieli";
	char jono2[10] = { 'C', '+', '+', '\0' };
	cout << "Alkuarvo jono1:ssa on: " << jono1;
	strcpy_s(jono1, jono2);
	cout << "\nJa lopputulos on: " << jono1;
	return 0;
}
*/
//ESIMERKKI 6-13
/*#include <iostream> 
using namespace std;
int main()
{
	int luku;
	char merkki1, merkki2;
	cout << "\nLuku? ";
	cin >> luku;
	cout << "Merkki1? ";
	cin.get(merkki1);
	cout << "Merkki2? ";
	cin.get(merkki2);
	cout << "\nLuku: " << luku;
	cout << "\nMerkki1: " << merkki1;
	cout << "\nMerkki2: " << merkki2 << endl;
	return 0;
}
*/
//ESIMERKKI 6-14
/*#include <iostream> 
using namespace std;
int main()
{
	int ika = -1;
	char kokonimi[30];
	char osoite[30];

	while (ika < 0)
	{
	cout << "\nIk„? ";
	cin >> ika;
		if (ika < 0)
			cout << "Anna pos ik„";
		else
		{
			cout << "Hienoa" << endl;
			cout << "Hyvin meni" << endl;
		}
	}

	cout << "Nimi? ";
	cin.get(); // luetaan yksi merkki n„pp„inpuskurista
	cin.get(kokonimi, 30);
	cout << "Osoite? ";
	cin.get();
	cin.get(osoite, 30);
	cout << "\nIk„ : " << ika;
	cout << "\nNimi: " << kokonimi;
	cout << "\nOsoite: " << osoite << endl;
	return 0;
}
*/
//ESIMERKKI 6-14
/*#include <iostream>
using namespace std;
int main()
{
int ika;
char kokonimi[30];
char osoite[30];
cout << "\nIk„? ";
cin >> ika;
cout << "Nimi? ";
cin.get();
cin.get(kokonimi, 30);
cout << "Osoite? ";
cin.get();
cin.get(osoite, 30);
cout << "\nIk„ : " << ika;
cout << "\nNimi: " << kokonimi;
cout << "\nOsoite: " << osoite;
return 0;
}*/
//ESIMERKKI 6-17
/*#include <iostream> 
using namespace std;
int main()
{
	int luku1 = 5, luku2 = 2;
	float summa, erotus, tulo, osamaara, jaannos;
	
	luku1 = luku1 + 1;
	luku1 += 1;
	++luku1;
	luku1++;

	summa = luku1 + luku2;
	erotus = luku1 - luku2;
	tulo = luku1 * luku2;
	osamaara = luku1 / luku2;
	jaannos = luku1 % luku2;
	cout << "\nLuku1: " << luku1 << " Luku2: " << luku2;
	cout << "\nSumma: " << summa;
	cout << "\nErotus: " << erotus;
	cout << "\nTulo: " << tulo;
	cout << "\nOsamäärä: " << osamaara;
	cout << "\nJakojäännös: " << jaannos;
	return 0;
}*/

//ESIMERKKI 6-21
/*#include <iostream> 
using namespace std;
int main()
{
	int luku1 = 5, luku2 = 5;
	cout << "\nluku1: " << luku1;
	cout << "\nluku1++: " << luku1++; //ensin suoritetaan cout, joten muutos ei näy
	cout << "\nluku1: " << luku1;
	cout << "\nluku2: " << luku2;
	cout << "\n--luku2: " << --luku2; //-- suoritetaan ennen cout, joten muutos näkyy
	cout << "\nluku2: " << luku2;
	return 0;
}
*/
//ESIMERKKI 7-4
/*#include <iostream> 
using namespace std;
int main()
{
	int luku;
	cout << "Syötä luku: ";
	cin >> luku;
	if (luku < 0)
	{
		luku = luku * -1;
		cout << "\nLuku on positiivisena: " << luku;
	}
	else
		cout << "\nLuku on positiivinen";
	return 0;
}*/

//ESIMERKKI 7-6
/*#include <iostream> 
using namespace std;
int main()
{
	int valinta;
	cout << "VALIKKO";
	cout << "\n\n1 Uusi tiedosto ";
	cout << "\n2 Avaa tiedosto";
	cout << "\n3 Talleta tiedosto";
	cout << "\n0 Lopeta \nValintasi: ";
	cin >> ws >> valinta; // ws: whitespace: välilyönti, enter ja tabulator. Jos löytyy, niin ottaa pois kunnes tulee joku muu
	switch (valinta)
	{
	case 0:	cout << "\nValittu lopetus";
		break;
	case 1: cout << "\nValittu uusi tiedosto";
		break;
	case 2:	cout << "\nValittu tiedoston avaus";
		break;
	case 3:	cout << "\nValittu tiedoston talletus";
		break;
	default:	cout << "\nVirhe: ei ko. toimintoa!";
		break;
	}
	return 0;
}
*/

//ESIMERKKI 7-10
/*#include <iostream> 
using namespace std;
#include <cstring> 
int main()
{
	char jono1[10] = "alku";
	char jono2[15] = "loppu";
	int tulos;
	tulos = strcmp(jono1, jono2);
	if (tulos < 0)
		cout << jono1 << " oli enimmäinen";
	else
		cout << jono2 << " oli ensimmäinen";
	return 0;
}
*/
//ESIMERKKI 13-7
/*#include <iostream> 
using namespace std;
int main()
{
	cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << 1234.5678 << '\n';
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << 1234.5678 << '\n';
	cout.precision(2);
	cout << 1234.5678 << '\n';
	return 0;
}*/

//ESIMERKKI 7-13
/*#include <iostream> 
using namespace std;
int main()
{
	int kerrat = 4;
	int lkm = 0;
	do
	{
		cout << "\nTerve";
		lkm++;
	} while (lkm < kerrat);
	return 0;
}
*/

//ESIMERKKI 7-14
/*#include <iostream> 
using namespace std;
int main()
{
	int kerrat = 4;
	int lkm;
	for (lkm = 0; lkm < kerrat; lkm++)
		cout << "\nTerve";
	return 0;
}
*/
//ESIMERKKI 7-16
/*#include <iostream> 
using namespace std;
int main()
{
	char merkki;
	int lkm = 0;
	cout << "Kirjoita lause (keskeytys CTRL-C): ";
	while (cin.get(merkki))
	{
		if (merkki == '.')
			break;
		if (merkki == ' ')
			continue; //continue hyppää suoraan ehtoon, ei jatka suoritusta alemmas eikä hyppää toistosta ulos
		lkm++;
	}
	cout << "\nLauseessa oli yhteensä " << lkm << " kirjainta";
	return 0;
}
*/
//ESIMERKKI 9-3
/*#include <iostream> 
using namespace std;
//Tietuekuvaus. Tietotyyppi. Loogisesti yhteenkuuluvien tietojen joukko
//Huomioi aaltosulkeiden jälkeinen ;
//Kirjoita suurella, niin näkee koodista että on ohjelmoidan oma tietotyyppi
struct PVM
{
	int pp; //voisi laittaa peräkkäin, mutta tämä parempi tyyli
	int kk; //mm. helpompi kommentoida
	int vv; //ja voi käyttää eri tietotyyppejä
	char vp[15];//antaa myös automaattisesti VS kenttämuuttujan, nopeampi koodata
};
int main()
{
	PVM pvm1 = { 1, 1, 1996, "ti" };
	PVM pvm2;
	cout << "\nMonesko päivä tänään on "
		"(syötä muodossa 99 99 99 vp)?\n";
	cin >> ws >> pvm2.pp >> ws >> pvm2.kk >> ws >> pvm2.vv >> ws >> pvm2.vp;
	cout << "\nVuoden ensimmäinen päivä on: ";
	cout << pvm1.pp << '.' << pvm1.kk << '.' << pvm1.vv << pvm1.vp;
	cout << "\nTänään on: " << pvm2.pp << '.' << pvm2.kk << '.' << pvm2.vv << pvm2.vp;
	return 0;
}
*/
//ESIMERKKI 9-10
/*#include <iostream> 
using namespace std;
int main()
{
	const int max = 5; //monipuolistaa rakennetta, ei tarvitse kuin tätä muuttaa kun muotoilee taulukkoa
	int luvut[max] = { 1, 2, 3, 4, 5 };
	int ind;
	for (ind = 0; ind < max; ind++)
	{
		cout << "\nJärjestysnumero: " << ind;
		cout << " Sisältö: " << luvut[ind];
	}
	return 0;
}
*/

/*//ESIMERKKI 9-11
#include <iostream> 
using namespace std;
int main()
{
	int luvut[2][5] = { { 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 } };
	int rivi, sarake;
	for (rivi = 0; rivi < 2; rivi++)
		for (sarake = 0; sarake < 5; sarake++)
		{
			cout << "\nIndeksit: (" << rivi << ", ";
			cout << sarake << ")";
			cout << " Sisältö: " << luvut[rivi][sarake];
		}
	return 0;
}
*/
//ESIMERKKI 9-12
/*#include <iostream> 
using namespace std;
struct PVM
{
	//kenttämuuttujat pp kk vv
	int pp, kk, vv;
};
int main()
{
	PVM paivat[5] = { { 1, 1, 96 },
	{ 1, 2, 96 },
	{ 1, 3, 96 },
	{ 1, 4, 96 },
	{ 1, 5, 96 } };
	int ind;
	for (ind = 0; ind < 5; ind++)
	{
		cout << "\nPäivä: ";
		cout << paivat[ind].pp << '.';
		cout << paivat[ind].kk << '.';
		cout << paivat[ind].vv;
	}
	return 0;
}
*/

/*//ESIMERKKI 9-14
#include <iostream> 
using namespace std;
int main()
{
	int luku = 2;
	int *osoitin;
	osoitin = &luku;
	cout << "\nLuku-muuttujan osoite on: " << osoitin;
	cout << "\nLuku-muuttujan osoite on: " << &luku;
	cout << "\nLuku-muuttujan sisältö on: " << *osoitin;
	return 0;
}
*/

/*//ESIMERKKI 9-16
#include <iostream> 
using namespace std;
struct PVM
{
	int pp, kk, vv;
};
int main()
{
	PVM tietue = { 1, 1, 1996 };
	PVM *tietueosoitin;
	tietueosoitin = &tietue;
	cout << "\nVuosi suoraan tulostettuna: ";
	cout << tietue.vv;
	cout << "\nVuosi osoittimen kautta tulostettuna: ";
	cout << tietueosoitin->vv;
	cout << "\nVuosi osoittimen kautta tulostettuna: ";
	cout << (*tietueosoitin).vv;
	return 0;
}
*/

/*//ESIMERKKI 9-17
#include <iostream> 
using namespace std;
struct PVM
{
	int pp, kk, vv;
};
int main()
{
	int laskuri;
	PVM paivat[5] = { { 1, 1, 96 },
	{ 1, 2, 96 },
	{ 1, 3, 96 },
	{ 1, 4, 96 },
	{ 1, 5, 96 } };
	PVM *osoitin = paivat;
	laskuri = 0;
	while (laskuri < 5)
	{
		cout << "\nKuukausi: " << osoitin[laskuri].kk;
		laskuri++;
	}
	return 0;
}
*/

/*//ESIMERKKI 9-18
#include <iostream> 
using namespace std;
struct PVM
{
	int pp, kk, vv;
};
int main()
{
	int laskuri;
	PVM paivat[5] = { { 1, 1, 96 },
	{ 1, 2, 96 },
	{ 1, 3, 96 },
	{ 1, 4, 96 },
	{ 1, 5, 96 } };
	PVM *osoitin = paivat;
	laskuri = 0;
	while (laskuri < 5)
	{
		cout << "\nKuukausi: " << osoitin->kk;
		osoitin++;
		laskuri++;
	}
	return 0;
}
*/

/*//ESIMERKKI 9-19
#include <iostream> 
using namespace std;
struct PVM
{
	int pp, kk, vv;
};
int main()
{
	int laskuri;
	PVM *paivat[5] = { NULL };
	PVM paiva1 = { 1, 1,96 };
	PVM paiva2 = { 1, 2, 96 };
	paivat[0] = &paiva1;
	paivat[1] = &paiva2;
	laskuri = 0;
	while (paivat[laskuri] != NULL && laskuri < 5)
	{
		cout << "\nKuukausi: " << paivat[laskuri]->kk;
		laskuri++;
	}
	return 0;
}
*/

/*//ESIMERKKI 9-20
#include <iostream> 
using namespace std;
struct PVM
{
	int pp, kk, vv;
};
int main()
{
	PVM paiva = { 1, 2, 96 };
	PVM *osoitin1 = &paiva;
	PVM **osoitin2 = &osoitin1;
	cout << "\nKuukausi: " << osoitin1->kk;
	cout << "\nKuukausi: " << (*osoitin2)->kk;
	cout << "\nKuukausi: " << (**osoitin2).kk;
	return 0;
}
*/

/*//ESIMERKKI 9-21
#include <iostream> 
using namespace std;
int main()
{
	int luku = 3;
	int &viittaus = luku;
	viittaus = viittaus + 1;
	cout << "Viittaus: " << viittaus;
	cout << "\nLuku: " << luku;
	return 0;
}
*/

/*//ESIMERKKI 10-1
#include <iostream> 
using namespace std;
void Aliohjelma();	//esittely 
int main()
{
	Aliohjelma(); //kutsu 
	return 0;
}
void Aliohjelma() //määrittely 
{
	cout << "Tämä on Aliohjelma";
}
*/

/*//ESIMERKKI 10-5
#include <iostream> 
using namespace std;
int KysyValinta();
double Korota(int, int);
int main()
{
	int valinta;
	int kanta, eksp;
	double vastaus;
	valinta = KysyValinta();
	while (valinta != 0)
	{
		if (valinta == 1)
		{
			cout << "\nSyötä kantaluku: ";
			cin >> kanta;
			cout << "\nSyötä eksponentti: ";
			cin >> eksp;
			vastaus = Korota(kanta, eksp);
			cout << "\nVastaus on: " << vastaus;
		}
		else
			cout << "\nKo. valintaa ei ole";
		valinta = KysyValinta();
	}
	return 0;
}
int KysyValinta()
{
	int valinta;
	cout << "\nLUVUN KOROTUS POTENSSIIN";
	cout << "\n\n1) Korota luku potenssiin";
	cout << "\n0) Lopeta";
	cout << "\nValintasi: ";
	cin >> valinta;
	return valinta;
}
double Korota(int kanta, int eksp)
{
	double tulo;
	int laskuri;
	if (eksp == 0)
		tulo = 1;
	else
		if (eksp > 0)
		{
			tulo = kanta;
			for (laskuri = 1; laskuri < eksp; laskuri++)
				tulo *= kanta;
		}
		else
		{
			tulo = 1 / double(kanta);
			for (laskuri = -1; laskuri > eksp; laskuri--)
				tulo = tulo * 1 / double(kanta);
		}
	return tulo;
}
*/
/*//ESIMERKKI 10-6
#include <iostream> 
using namespace std;
void Korota(int);	//esittely 
int main()
{
	int luku;
	cout << "\nSyötä jokin kokonaisluku: ";
	cin >> luku;
	Korota(luku);
	cout << "\nPääohjelman luku on: " << luku;
	return 0;
}
void Korota(int p_luku)
{
	p_luku = p_luku * p_luku;
	cout << "\nLuku * luku: " << p_luku;
}
*/

/*//ESIMERKKI 10-7
#include <iostream> 
using namespace std;
void Korota(int *);	//esittely pointterin lähetys
int main()
{
	int luku;
	cout << "\nSyötä jokin kokonaisluku: ";
	cin >> luku;
	Korota(&luku);
	cout << "\nLuku *luku: " << luku;
	return 0;
}
void Korota(int *p_luku)
{
	*p_luku = (*p_luku) * (*p_luku);
}
*/

/*//ESIMERKKI 10-8
#include <iostream> 
using namespace std;
void Korota(int &);	//esittely osoitteen lähetys
int main()
{
	int luku;
	cout << "\nSyötä jokin kokonaisluku: ";
	cin >> luku;
	Korota(luku);
	cout << "\nLuku * luku: " << luku;
	return 0;
}
void Korota(int &p_luku)
{
	p_luku = p_luku * p_luku;
}
*/

/*//ESIMERKKI 10-9
#include <iostream> 
using namespace std;
int Korota(int);	//esittely 
int main()
{
	int luku, tulos;
	cout << "\nSyötä jokin kokonaisluku: ";
	cin >> luku;
	tulos = Korota(luku);
	cout << "\nLuku * luku: " << tulos;
	return 0;
}
int Korota(int p_luku)
{
	return(p_luku * p_luku);
}
*/

/*//ESIMERKKI 10-10
#include <iostream> //kulmasulkeet etsivät oletuskirjastoista
using namespace std;
#include "pvm.h" //ei ole, on lisättävä oma otsikkotiedosto "header files"-kansion
	//lainausmerkit tarkoittaa, että etsii työskentelyhakemistosta
	//voisi olla myös polkukin. oletuksena etsii projektin "header files"-kansiosta
void Nayta(PVM);
int main()
{
	PVM tietue;
	cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
	cin >> tietue.pp >> tietue.kk >> tietue.vv;
	Nayta(tietue);
	return 0;
}
void Nayta(PVM p_tietue)
{
	cout << "\nPäivämäärä on: ";
	cout << p_tietue.pp << "." << p_tietue.kk << "." << p_tietue.vv;
}
*/

/*//ESIMERKKI 10-11
#include <iostream> 
using namespace std;
#include "pvm.h" 
void Kysy(PVM *);
int main()
{
	PVM tietue;
	Kysy(&tietue);
	cout << "\nPäivämäärä on: ";
	cout << tietue.pp << "." << tietue.kk << "." << tietue.vv;
	return 0;
}
void Kysy(PVM *p_tietue)
{
	cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
	cin >> p_tietue->pp >> p_tietue->kk >> (*p_tietue).vv; //-> osoittimien kanssa viittaa tietueen kenttämuuttujaan
}
*/

/*//ESIMERKKI 10-12
#include <iostream> 
using namespace std;
#include "pvm.h" 
void Kysy(PVM &);
int main()
{
	PVM tietue;
	Kysy(tietue);
	cout << "\nPäivämäärä on: ";
	cout << tietue.pp << "." << tietue.kk << "." << tietue.vv;
	return 0;
}
void Kysy(PVM &p_tietue)
{
	cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
	cin >> p_tietue.pp >> p_tietue.kk >> p_tietue.vv;
}
*/

/*
//ESIMERKKI 10-13
#include <iostream> 
using namespace std;
#include "pvm.h" 
PVM Kysy();
int main()
{
	PVM tietue;
	tietue = Kysy();
	cout << "\nPäivämäärä on: ";
	cout << tietue.pp << "." << tietue.kk << "." << tietue.vv;
	return 0;
}
PVM Kysy()
{
	PVM p_tietue;
	cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
	cin >> p_tietue.pp >> p_tietue.kk >> p_tietue.vv;
	return p_tietue;
}
*/

//ESIMERKKI 10-14
/*#include <iostream> 
using namespace std;
#include "pvm.h" 
PVM *Kysy();
int main()
{
	PVM *tietue;
	tietue = Kysy();
	cout << "\nPäivämäärä on: ";
	cout << tietue->pp << "." << tietue->kk << "." << tietue->vv;
	return 0;
}
PVM *Kysy()
{
	static PVM p_tietue; //automaattimuuttuja pinossa. tila vapautuu kun palautuu lohkosta. siksi ei toimi
		//static lisämääre tarkoittaa, ettei vapaudu kun poistuu aaltosuluista
	cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
	cin >> p_tietue.pp >> p_tietue.kk >> p_tietue.vv;
	return &p_tietue;
}
*/

/*//ESIMERKKI 10-15
#include <iostream> 
using namespace std;
//alla olevat 3 ovat identtiset
//void Kysy(int *, int); 
//void Kysy(int *p_taulu, int lkm);
void Kysy(int[], int lkm);
int main()
{
	int ind;
	int taulu[5];
	//Kysy(taulu, 5); alla oleva täsmälleen sama
	Kysy(&taulu[0], 5); //merkkijonoon voi lähettää &mj[]. ei tarvitse pituutta, koska lopetusmerkki
	for (ind = 0; ind < 5; ind++)
		cout << "\n" << taulu[ind];
	return 0;
}
//void Kysy(int p_taulu[], int lkm), alla oleva täsmälleen sama
void Kysy(int *p_taulu, int lkm)
{
	for (int ind = 0; ind < lkm; ind++)
	{
		cout << "Syötä luku: ";
		cin >> p_taulu[ind];
	}
}
*/

/*//ESIMERKKI 10-27
#include <iostream> 
using namespace std;
int luku = 3; //public, julkinen, ei ole minkään lohkon sisällä. Toimii kaikkialla
void Aliohjelma(void); //esittely
int main()
{
	Aliohjelma(); //aliohjelman kutsu
	cout << "\nLuku on pääohjelmassa: " << luku;
	return 0;
}
void Aliohjelma(void) //aliohjelman määrittely
{
	int luku = 5; //lokaali, paikallinen, lohkon sisällä
	{
		int luku = 123; //auto-muuttujuat. Lohkojen sisällä olevat syntyvät ja kuolevat lohkojen sisällä
	}
	cout << "\nAliohjelman luku on: " << luku;
	cout << "\nGlobaali luku on: " << ::luku; //:: pääsee globaaleihin muuttujiin
}
*/

//ESIMERKKI TIEDOSTOJEN KÄSITTELY
//ESIMERKKI 10-10
/*#include <fstream> //tiedostojen käsittelyssä tarvitaan tämä
#include <iostream> 
using namespace std;
#include "pvm.h" 
void Nayta(PVM);
int main()
{
	PVM tietue;
	ifstream lue("tiedot.txt"); //input file stream
	if (lue.is_open())
	{ // tiedosto on olemassa
		while (lue.peek() != EOF)
		{
			lue >> tietue.pp >> tietue.kk >> tietue.vv;
			lue.get(); //luetaan rivinvaihto roskiin tiedostosta
			cout << tietue.pp <<  "." << tietue.kk << "." << tietue.vv << endl;
		}
		lue.close();
	}
	else
	{ // tiedosto ei ole olemassa
		cout << "\nSyötä päivämäärä muodossa pp kk vv: ";
		cin >> tietue.pp >> tietue.kk >> tietue.vv;
	}
	Nayta(tietue);
	return 0;
}
void Nayta(PVM p_tietue)
{
	cout << "\nPäivämäärä on: ";
	cout << p_tietue.pp << "." << p_tietue.kk << "." << p_tietue.vv; //cout on kahva iostream:n puskuriin
	ofstream kirjoita("tiedot.txt"); //output filestream
	kirjoita << p_tietue.pp << " " << p_tietue.kk << " " << p_tietue.vv << endl; //huomaa kahva
	kirjoita << p_tietue.pp+1 << " " << p_tietue.kk+1 << " " << p_tietue.vv+1 << endl;
	kirjoita.close(); //pitää sulkea puskuri, jotta tallentaa tiedostoon
}
*/

/*//ESIMERKKI 11-1
#include <iostream> 
using namespace std;
int main()
{
	int *luku_osoitin1 = NULL;
	int vastaus;
	cout << "\nVarataanko tila (0=ei, 1=kyllä) ?";
	cin >> vastaus;
	if (vastaus == 1)
	{
		luku_osoitin1 = new int;
		if (luku_osoitin1)
		{
			cout << "Luvun sisältö? ";
			cin >> *luku_osoitin1;
		}
		else
			cout << "\nTilanvaraus epäonnistui";
		if (luku_osoitin1)
			cout << "\nSyötit luvun: " << *luku_osoitin1;
	}
	else
		cout << "Tilaa ei varattu";
	delete luku_osoitin1;
	return 0;
}
*/

/*//ESIMERKKI 11-2
#include <iostream> 
using namespace std;
#include "pvm.h" 
int main()
{
	PVM *pvm = NULL;
	pvm = new PVM;
	if (pvm)
	{
		cout << "Syötä pp kk vv ";
		cin >> pvm->pp >> pvm->kk >> pvm->vv;
		cout << "Pvm on: " << pvm->pp << "/";
		cout << pvm->kk << "/" << pvm->vv;
	}
	else
		cout << "Tilanvaraus epäonnistui";
	delete pvm;
	return 0;
}
*/

/*//ESIMERKKI 11-3
#include <iostream> 
using namespace std;
int main()
{
	int *luku_osoitin1 = NULL;
	int vastaus;
	cout << "\nVarataanko tila (0=ei, 1=kyllä) ?";
	cin >> vastaus;
	if (vastaus == 1)
	{
		luku_osoitin1 = new int(4); //arvon asetus
		if (luku_osoitin1)
			cout << "Luku alustettu arvolla: " << *luku_osoitin1;
		else
			cout << "Tilanvaraus epäonnistui";
	}
	else
		cout << "Tilaa ei varattu";
	delete luku_osoitin1;
	return 0;
}
*/

/*//ESIMERKKI 11-4
#include <iostream> 
using namespace std;
int main()
{
	int *luku_osoitin1 = NULL;
	int vastaus, laskuri = 0;
	cout << "\nMontako lukua varataan ? ";
	cin >> vastaus;
	luku_osoitin1 = new int[vastaus]; //dynaaminen tilanvaraus
	if (luku_osoitin1) // sama kuin (luku_osoitin1 != NULL) onnistuiko muistinvaraus
	{
		for (laskuri = 0; laskuri < vastaus; laskuri++)
		{
			cout << "\nLuku ?";
			cin >> luku_osoitin1[laskuri];
		}
		for (laskuri = 0; laskuri < vastaus; laskuri++)
		{
			cout << "\nLuku: " << luku_osoitin1[laskuri];
			cout << " osoitteessa: " << &luku_osoitin1[laskuri];
		}
	}
	else
		cout << "\nTilanvaraus epäonnistui";
	delete[] luku_osoitin1; // jos deletoi monta kertaa, niin kaatuu
	luku_osoitin1 = NULL; // nollaa lopuksi
	return 0;
}
*/

//ESIMERKKI 11-5
/*#include <iostream> 
using namespace std;
int main()
{
	int **osoitin;
	int rivit, sarakkeet;
	int rind, sind;
	cout << "Montako riviä? ";
	cin >> rivit;
	cout << "Montako saraketta? ";
	cin >> sarakkeet;
	osoitin = new int*[rivit];
	for (rind = 0; rind < rivit; rind++)
	{
		osoitin[rind] = new int[sarakkeet];
	}
	for (rind = 0; rind < rivit; rind++)
	{
		for (sind = 0; sind << sarakkeet; sind++)
		{
			osoitin[rind][sind] = rind;
		}
	}
	for (rind = 0; rind < rivit; rind++)
	{
		for (sind = 0; sind < sarakkeet; sind++)
		{
			cout << osoitin[rind][sind] << " (";
			cout << &osoitin[rind][sind] << ") ";
		}
		cout << "\n";
	}
	for (rind = 0; rind << rivit; rind++)
	{
		delete[] osoitin[rind];
	}
	delete[] osoitin;
	return 0;
}
*/

/*
//ESIMERKKI 11-6
#include <iostream> 
using namespace std;
struct Alkio
{
	int luku;
	Alkio *seuraava;
};
int KysyValinta();
int main()
{
	Alkio *alku = NULL;
	Alkio *kohdalla, *uusi;
	int vastaus;
	vastaus = KysyValinta();
	while (vastaus != 0)
	{
		switch (vastaus)
		{
		case 1: uusi = new Alkio;
			if (uusi)
			{
				cout << "\nLuku: ";
				cin >> uusi->luku;
				uusi->seuraava = NULL;
				if (!alku)
					alku = uusi;
				else
				{
					kohdalla = alku;
					while (kohdalla->seuraava)
						kohdalla = kohdalla->seuraava;
					kohdalla->seuraava = uusi;
				}
			}
			else
				cout << "\nTilanvaraus epäonnistui";
			break;
		case 2:	kohdalla = alku;
			while (kohdalla)
			{
				cout << "\nLuku: " << kohdalla->luku;
				cout << " osoite: " << &kohdalla->luku;
				kohdalla = kohdalla->seuraava;
			}
			break;
		default:	cout << "\nVirheellinen valinta";
		}
		vastaus = KysyValinta();
	}
	Alkio *seuraava;
	kohdalla = alku;
	while (kohdalla)
	{
		seuraava = kohdalla->seuraava;
		delete kohdalla;
		kohdalla = seuraava;
	}
	return 0;
}
int KysyValinta()
{
	int vastaus;
	cout << "\nVALIKKO";
	cout << "\n1) Lisää uusi luku";
	cout << "\n2) Näytä kaikki luvut";
	cout << "\n0) Lopetus\n";
	cin >> vastaus;
	return vastaus;
}
*/

//ESIMERKKI 11-7
#include <iostream> 
using namespace std;
struct Alkio
{
	int luku;
	Alkio *seuraava;
};
int LisaaLuku(Alkio *&, int);
void TulostaLuvut(Alkio *);
int PoistaLuku(Alkio *&, int);
int KysyValinta();
int main()
{
	Alkio *alku = NULL;
	int vastaus, ok, apu;
	vastaus = KysyValinta();
	while (vastaus != 0)
	{
		switch (vastaus)
		{
		case 1:	cout << "\nSyötä uusi luku: ";
			cin >> apu;
			ok = LisaaLuku(alku, apu);
			if (ok == 0)
				cout << "\nTilanvaraus epäonnistui, lukua ei lisätty";
			break;
		case 2: TulostaLuvut(alku);
			break;
		case 3:	cout << "\nPoistettava luku: ";
			cin >> apu;
			ok = PoistaLuku(alku, apu);
			if (ok == 0)
				cout << "\nPoistettavaa ei löytynyt";
			break;
		default:	cout << "\nVirheellinen valinta";
		}
		vastaus = KysyValinta();
	}
	Alkio *seuraava;
	Alkio *kohdalla = alku;
	while (kohdalla)
	{
		seuraava = kohdalla->seuraava;
		delete kohdalla;
		kohdalla = seuraava;
	}
	return 0;
}
int KysyValinta()
{
	int vastaus;
	cout << "\nVALIKKO";
	cout << "\n1) Lisää uusi luku";
	cout << "\n2) Näytä kaikki luvut";
	cout << "\n3) Poista luku";
	cout << "\n0) Lopetus\n";
	cin >> vastaus;
	return vastaus;
}
int LisaaLuku(Alkio *&p_alku, int p_luku)
{
	Alkio *uusi = new Alkio;
	if (uusi)
	{
		uusi->luku = p_luku;
		uusi->seuraava = NULL;
		Alkio *kohdalla;
		if (!p_alku)
			p_alku = uusi;
		else
		{
			kohdalla = p_alku;
			while (kohdalla->seuraava)
				kohdalla = kohdalla->seuraava;
			kohdalla->seuraava = uusi;
		}
		return 1;
	}
	else
		return 0;
}
void TulostaLuvut(Alkio *p_alku)
{
	Alkio *kohdalla;
	kohdalla = p_alku;
	while (kohdalla)
	{
		cout << "\nLuku: " << kohdalla->luku;
		cout << " osoite: " << &kohdalla->luku;
		kohdalla = kohdalla->seuraava;
	}
}
int PoistaLuku(Alkio *&p_alku, int p_luku)
{
	Alkio *edellinen = NULL;
	Alkio *pois = p_alku;
	while (pois != NULL && pois->luku != p_luku)
	{
		edellinen = pois;
		pois = pois->seuraava;
	}
	if (pois == NULL)
		return 0;
	else
	{
		if (pois == p_alku)
			p_alku = pois->seuraava;
		else
			edellinen->seuraava = pois->seuraava;
		delete pois;
		return 1;
	}
}


//.ignore OVERFLOWN ESTÄMINEN RAJOITTAMALLA PITUUTTA
/*#include <iostream>
using namespace std;
char nimi[20];
int luku;
int main()
{
cout << "Anna nimi: ";
cin.get(nimi, 20);
cin.ignore(100, '\n');
cin >> luku;
cout << nimi << endl;
cout << luku << endl;
return 0;
}*/

//UUSIEN MUUTTUJIEN GENEROINTI
/*#include <iostream>
using namespace std;
int luku[5];
void main()
{
	cout << "Anna viisi lukua: " << endl;

	for (int i = 0; i < 5; i++) {
		cout << "Anna " << i << ". luku.";
		cin >> luku[i];
	}
	cout << luku[0] << luku[1] << luku[2] << luku[3] << luku[4];
}*/

//by Ville Paananen 21.9.2017
/*#include <iostream>, <algorithm>
using namespace std;
int luku[100], a, b, c;
void loop() {
	for (int b = (a - 1); b > 0; b--) {
		c = (b - 1);
		if (luku[b] < luku[c]) {
			swap(luku[c], luku[b]);
		}
	}
}
void main() {
	cout << "How many numbers do you want to use ?\n";
	cin >> a;
	for (int i = 0; i < a; i++) {
		cout << "Give the number " << (i + 1) << ".\n";
		cin >> luku[i];
	}
	for (int i = 0; i < a; i++) {
		loop();
	}
	cout << endl << "Lukujen järjestys on ";
	for (int i = 0; i < a; i++) {
		cout << luku[i] << ", ";
	}
}*/

/*
//ATOI
// crt_atoi.c  
// This program shows how numbers   
// stored as strings can be converted to  
// numeric values using the atoi functions.  

#include <stdlib.h>  
#include <stdio.h>  
#include <errno.h>  

int main(void)
{
	char    *str = NULL;
	int     value = 0;

	// An example of the atoi function.  
	str = "  -2309 ";
	value = atoi(str);
	printf("Function: atoi( \"%s\" ) = %d\n", str, value);

	// Another example of the atoi function.  
	str = "31412764";
	value = atoi(str);
	printf("Function: atoi( \"%s\" ) = %d\n", str, value);

	// Another example of the atoi function   
	// with an overflow condition occuring.  
	str = "3336402735171707160320";
	value = atoi(str);
	printf("Function: atoi( \"%s\" ) = %d\n", str, value);
	if (errno == ERANGE)
	{
		printf("Overflow condition occurred.\n");
	}
}
*/

//ESIMERKKI VAIHTOLAJITTELUSTA
/*#include <iostream>
using namespace std;
int main()
{
	const int MAX = 4;
	int taulu[MAX] = { 2,7,1,3 };
	cout << "Vaihtolajittelu";
	for (int ind = 0; ind < MAX; ind++)
	{
		cout << "\nJärjestysnumero: " << ind;
		cout << " Sisältö: " << taulu[ind];
	}
	cout << endl;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			cout << i << j << endl;
			if (taulu[j] < taulu[i])
			{
				int temp = taulu[i];
				taulu[i] = taulu[j];
				taulu[j] = temp;
			}
		}
	}
	for (int ind = 0; ind < MAX; ind++)
	{
		cout << "\nJärjestysnumero: " << ind;
		cout << " Sisältö: " << taulu[ind];
	}
	cout << endl;
}
*/

/*//OSOITIN TESTAILUA
#include <iostream>
using namespace std;
int main()
{
int luku = 5;
int *osoitin = &luku;
cout << osoitin << endl;
cout << *osoitin << endl;
cout << *(osoitin++) << endl;
cout << *osoitin << endl;
cout << osoitin << endl;
int inttau[5] = { 5,4,3,2,1 };
osoitin = inttau;         //inttau == &inttau[0]
cout << *osoitin << endl;
osoitin++;
cout << *osoitin << endl;
cout << inttau[3] << endl; // == *(3+osoitin)
osoitin = inttau;
cout << *(3 + osoitin) << endl;
cout << "-----" << endl;
cout << inttau << endl;       //taulukon nimi on ensimmäisen muistipaikan osoite
cout << inttau + 1 << endl;   //toisen muistipaikan osoite
cout << *inttau << endl;      //ensimmäisen muistipaikan sisältö
cout << *(inttau +1) << endl; //toisen muistipaikan sisältö
}
*/

/*//POINTTERI OSOITIN TESTIÄ
#include <iostream>
using namespace std;
int main()
{
int luku;
int *osoitin = &luku;
luku = 5;
cout << "Yksittäinen luku\n";
cout << osoitin << endl; //osoite
cout << *osoitin << endl; //sisältö
cout << "Lukutaulun ensimmäiseen alkioon\n";
int lukutaulu[3] = { 1,2,3 };
osoitin = lukutaulu;
cout << osoitin << endl; //osoite
cout << *osoitin << endl; //sisältö
cout << "Lukutaulun kolmas alkio\n";
cout << &osoitin[2] << endl; //osoite //lukutaulu[2] == *(lukutaulu+2)
cout << osoitin[2] << endl; //sisältö
}
*/

/*//RIVI JA SARAKE
#include <iostream> 
using namespace std;
int main()
{
	int taulukko[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int rivi, sarake;
	for (rivi = 0; rivi < 2; rivi++)
	{
		for (sarake = 0; sarake < 3; sarake++)
		{
			cout << "Rivi ja sarake: " << rivi << "," << sarake << " : arvo: " << taulukko[rivi][sarake] << endl;
		}
	}
}
*/