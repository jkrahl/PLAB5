#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define PALS 4
#define CORS 1
#define DIAMANTS 2
#define TREBOLS 3
#define PIQUES 4
//--------------
#define NUMEROS 13
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13
//--------------

#define NUM_CARTES PALS*NUMEROS

using namespace std;

//Exercici 2
typedef struct Carta {
	int Pal;
	int Numero;
} Carta;

// Exercici 3
void InicialitzarBaralla(Carta*);

// Exercici 4
void MostrarCarta(Carta);

// Exercici 5
void Intercanviar(Carta&, Carta&);

// Exercici 6
int Aleatori(int, int);
void Remenar(Carta*, int);

//Exercici 7
int PuntsCarta(Carta);

//Exercici 8
bool Preguntar();

// Exercici 9
bool EstrategiaOrdinador(bool, int, int);

// Exercici 10
int CalcularGuanyador(bool, bool, int, int);

//Exercici 11
int JocBlackJack(Carta*);