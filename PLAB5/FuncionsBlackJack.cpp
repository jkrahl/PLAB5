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
	case ACE:
		cout << "A"; break;
	case JACK:
		cout << "J"; break;
	case QUEEN:
		cout << "Q"; break;
	case KING:
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

void Intercanviar(Carta& c1, Carta& c2)
{
	Carta aux;
	aux = c1;
	c1 = c2;
	c2 = aux;
}

int Aleatori(int min, int max)
{
	int aleatori;

	aleatori = min + (rand() % (max - min + 1));
	return aleatori;
}

void Remenar(Carta* cartes, int numIntercanvis)
{
	for (int i = 0; i < numIntercanvis; i++)
		Intercanviar(cartes[Aleatori(0, NUM_CARTES - 1)], cartes[Aleatori(0, NUM_CARTES - 1)]);
}

int PuntsCarta(Carta carta)
{
	int valor;
	switch (carta.Numero)
	{
	case JACK:
	case QUEEN:
	case KING:
		valor = 10; break;
	default:
		valor = carta.Numero; break;
	}
	return valor;
}

/*bool Preguntar()
{
	char c;
	cout << "Vols un altra carta? (S/N)" << endl;
	cin >> c;
	while (c != 's' && c != 'S' && c != 'n' && c != 'N')
	{
		cout << "Error: Opcio incorrecte." << endl << "Vols un altra carta? (S/N)" << endl;
		cin >> c;
	}
	if (c == 'S' || c == 's')
		return true;
	else
		return false;
}
*/

bool EstrategiaOrdinador(bool JugadorEsPlanta, int PuntsOrdinador, int PuntsJugador)
{
	if ((PuntsJugador > 21) || (JugadorEsPlanta && (PuntsOrdinador > PuntsJugador)) || PuntsOrdinador >= 17)
		return false;
	else
		return true;
}

int CalcularGuanyador(bool JugadorHaPerdut, bool OrdinadorHaPerdut, int PuntsJugador, int PuntsOrdinador)
{
	if (JugadorHaPerdut && OrdinadorHaPerdut) {
		cout << "Empat" << endl;
		return 0;
	}
	else if (JugadorHaPerdut) {
		cout << "Ordinador guanya" << endl;
		return 2;
	}
	else if (OrdinadorHaPerdut) {
		cout << "Jugador guanya" << endl;
		return 1;
	}
	else if (PuntsJugador > PuntsOrdinador) {
		cout << "Jugador guanya" << endl;
		return 1;
	}
	else if (PuntsOrdinador > PuntsJugador) {
		cout << "Ordinador guanya" << endl;
		return 2;
	}
	else {
		cout << "Empat" << endl;
		return 0;
	}
}

int JocBlackJack(Carta* cartes)
{
	bool JugadorEsPlanta = false, OrdinadorEsPlanta = false, JugadorHaPerdut = false, OrdinadorHaPerdut = false;
	int PuntsJugador = 0, PuntsOrdinador = 0, i = 0, guanyador;
	do {
		//bool JugadorVolCarta, OrdinadorVolCarta;
		if (!JugadorEsPlanta)
		{
			//JugadorVolCarta = Preguntar();
			if (Preguntar())
			{
				cout << "Carta Jugador: ";
				MostrarCarta(cartes[i]);
				PuntsJugador += PuntsCarta(cartes[i]);
				i++;
			}
			else
				JugadorEsPlanta = true;
		}
		if (!OrdinadorEsPlanta)
		{
			//OrdinadorVolCarta = EstrategiaOrdinador(JugadorEsPlanta, PuntsOrdinador, PuntsJugador);
			if (EstrategiaOrdinador(JugadorEsPlanta, PuntsOrdinador, PuntsJugador))
			{
				cout << "Carta Ordinador: ";
				MostrarCarta(cartes[i]);
				PuntsOrdinador += PuntsCarta(cartes[i]);
				i++;
			}
			else
				OrdinadorEsPlanta = true;
		}
	} while ((!JugadorEsPlanta && !OrdinadorEsPlanta) && PuntsJugador <= 21 && PuntsOrdinador <= 21);

	if (PuntsJugador > 21) JugadorHaPerdut = true;
	if (PuntsOrdinador > 21) OrdinadorHaPerdut = true;

	guanyador = CalcularGuanyador(JugadorHaPerdut, OrdinadorHaPerdut, PuntsJugador, PuntsOrdinador);

	return guanyador;
}