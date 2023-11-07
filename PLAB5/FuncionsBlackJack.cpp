#include "FuncionsBlackJack.h"
using namespace std;

//Escriure a partir d'aqui les funcions demanades NO posar main(), Preguntar() ni la definicio del tipus Carta.
void InicialitzarBaralla(Carta* cartes)
{
	for (int pal = 0; pal < PALS; pal++)
	{
		for (int numero = 0; numero < NUMEROS; numero++)
		{
			cartes[pal * NUMEROS + numero].Pal = pal + 1;
			cartes[pal * NUMEROS + numero].Numero = numero + 1;
		}
	}
}

void MostrarCarta(Carta carta)
{
	switch (carta.Numero)
	{
	case 1:
		cout << "A"; break;
	case 11:
		cout << "J"; break;
	case 12:
		cout << "Q"; break;
	case 13:
		cout << "K"; break;
	default:
		cout << carta.Numero; break;
	}
	switch (carta.Pal)
	{
	case CORS:
		cout << "C" << endl; break;
	case PIQUES:
		cout << "P" << endl; break;
	case DIAMANTS:
		cout << "D" << endl; break;
	case TREBOLS:
		cout << "T" << endl; break;
	default:
		cout << "???" << endl; break;
		break;
	}
}