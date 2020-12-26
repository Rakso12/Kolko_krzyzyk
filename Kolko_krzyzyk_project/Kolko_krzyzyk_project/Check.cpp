#include "Check.h"
#include <iostream>

/// <summary>
/// Funkcja sprawdzajaca plansze czy  znajduja sie w niej wygrane ciagi znakow
/// kolka lub krzyza o liczebnosci rownej ustalonej liczbie wygrywajacego ciagu 
/// </summary>
/// <param name="pola"> Vektor zawierajacy plansze </param>
/// <param name="rozmiar"> Rozmiar boku planszy </param>
/// <param name="znak"> Aktualnie sprawdzany/wstawiany znak </param>
bool Check::czyWygrana(std::vector<std::vector<Field*>> pola, int rozmiar, std::string znak, int x, int y)
{
	int ile_wygrywa = getIleWygrywa();
	bool tmp = false;

	// sprawdzanie srodka
	if(x != 0 && x != rozmiar && y != 0 && y != rozmiar){	
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak
			) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak
			) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak
			) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak
			) // P4X
			return true;
	}
	return false;
}

/// <summary>
/// Funkcja ustawiajaca ilosc - dlugosc wygrywajacego ciagu znakow
/// </summary>
/// <param name="liczba">Dlugosc wygrywajacego ciagu</param>
void Check::setIleWygrywa(int liczba)
{
	ile_wygrywa = liczba;
}

/// <summary>
/// Funkcja zwracajaca wartosc dlugosci wygrywajacego ciagu znakow
/// </summary>
/// <returns>Dlugosc wygrywajacego ciagu</returns>
int Check::getIleWygrywa()
{
	return ile_wygrywa;
}


