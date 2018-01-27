#pragma once
/*
Tetris by Hannu Oksman 2017

Tassa tiedostossa on otsikot ja mm. aliohjelmien esittelyt
*/

#include <iostream>
#include <time.h> //random koneen kellosta
#include <fstream> //tiedostopuskurin kirjoitus ja luku
using namespace std;
struct HIGHSCORE { //pisteiden tallennus
	char nimi[20];
	int score;
	char paiva[20];
};
const int dimensio = 7; //ruudukon koko, sisaltaa kaikki reunat
extern int pisteet; //pisteet maaritelty tetris_koulukone
void KentanTulostus(char[dimensio][dimensio]); //tulostaa ruudukon, lahettaa aliohjelmaan kaksiulotteisen char-taulukon
void PalikanLuonti(char *&, HIGHSCORE[10]); //luo palikan, lahettaa osoittimen keskusmuistiosoitteen ja tietuetaulukon
void Liikkuminen(char *&, char[dimensio][dimensio]); //liikuttaa palikkaa, lahettaa osoittimen keskusmuistiosoitteen ja kaksiulotteisen char-taulukon
void TallennaPisteet(int pisteet, HIGHSCORE huippupisteet[10]); //pisteiden tallennus tiedostoon, lahettaa pisteet ja tietuetaulukon
void LuePisteet(HIGHSCORE[10]); //pisteiden tulostus tiedostosta, lahettaa tietuetaulukon
void PalikoidenPoistoV(char [dimensio][dimensio]); //palikoiden poisto vaakasuunnassa, lahetetaan kaksiulotteisen char-taulukon
void PalikoidenPoistoP(char[dimensio][dimensio]); //palikoiden poisto pystysuunnassa, lahetetaan kaksiulotteisen char-taulukon
void PystyTarkastelu(char *&, char, int, int, char[dimensio + 1], char[dimensio][dimensio]); //tarkastaa montako perakkaista palikkaa on pystysuunnassa
void VaakaTarkastelu(char *&, char, int, int, char[dimensio + 1], char[dimensio][dimensio]); //tarkastaa montako perakkaista palikkaa on vaakasuunnassa
void PalikoidenPudotus(char[dimensio][dimensio]); //jos palikan alla on tyhjaa, niin tama pudottaa palikan alas
int Valikko(); //paavalikko