/************************
Tehtävä: Harjoitus 13b
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 12 (Palautus vko 43)

a) Kayta cstring-kirjastoa (C:n merkkitaulukot)
tehdäksesi merkkijonojen yhdistämisen
b) Kayta string-kirjastoa (C++:n merkkijonot)
tehdäksesi merkkijonojen yhdistämisen  TEE, JOS ON AIKAA

Esimerkki
Anna etunimi: Aku
Anna sukunimi: Ankka
Nimesi oli: Aku Ankka

Pvm: 5.10.2017
ver: 1.0 OksHa
************************/
#include <iostream><cstring><string>
using namespace std;
char mj1[20];
char mj2[20];
char vali[2] = " ";
int main(void)
{
	cout << "Anna etunimi: ";
	cin >> mj1;
	cout << "Anna sukunimi: ";
	cin >> mj2;
	strcat(mj1, vali);
	strcat(mj1, mj2);
	cout << "Nimesi on: " << mj1 << endl;
}