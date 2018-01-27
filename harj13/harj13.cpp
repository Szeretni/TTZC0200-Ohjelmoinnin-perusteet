/************************
Tehtävä: Harjoitus 13a
Tekijä: Hannu Oksman
Kuvaus:
Harjoitus 13 (Palautus vko 43)

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
//A-kohta. B-kohta on alempana
/*#include <iostream>
#include<cstring>
using namespace std;
char mj1[20];
char mj2[20];
int main(void)
{
	cout << "Anna etunimi: ";
	cin >> mj1;
	cout << "Anna sukunimi: ";
	cin >> mj2;
	strcat(mj1, " ");
	strcat(mj1, mj2);
	cout << "Nimesi on: " << mj1 << endl;
}
*/
//B-kohta

#include <iostream>
#include <string>
using namespace std;
string str1,str2;
string vali = " ";
int main(void)
{
cout << "Anna etunimi: ";
cin >> str1;
cout << "Anna sukunimi: ";
cin >> str2;
str1 = str1 + " " + str2;
cout << "Nimesi on: " << str1 << endl;
}
