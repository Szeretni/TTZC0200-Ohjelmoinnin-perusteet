#pragma once
/*
Tetris by Hannu Oksman 2017
*/

#include <iostream>
#include <time.h> //random koneen kellosta
#include <fstream>
using namespace std;
struct HIGHSCORE {
	char nimi[20];
	int score;
	char paiva[20];
};
const int dimensio = 7;
extern int pisteet;
void KentanTulostus(char[dimensio][dimensio]);
void PalikanLuonti(char *&, HIGHSCORE[10]);
void Liikkuminen(char *&, char[dimensio][dimensio]);
void TallennaPisteet(int pisteet, HIGHSCORE huippupisteet[10]);
void LuePisteet(HIGHSCORE[10]);
void PalikoidenPoistoV(char[dimensio][dimensio]);
void PalikoidenPoistoP(char[dimensio][dimensio]);
void PystyTarkastelu(char *&, char, int, int, char[dimensio + 1], char[dimensio][dimensio]);
void VaakaTarkastelu(char *&, char, int, int, char[dimensio + 1], char[dimensio][dimensio]);
void PalikoidenPudotus(char[dimensio][dimensio]);
int Valikko();