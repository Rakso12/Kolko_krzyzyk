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

// sprawdzanie pionu

	// plan byl dobry ale cos sie zjebalo...
	if (pola[x - 1][y - 1]->getText().getString().toAnsiString() == znak &&
		pola[x - 2][y - 2]->getText().getString().toAnsiString() == znak
		) 
		return true;
	else if (pola[x - 1][y]->getText().getString().toAnsiString() == znak &&
		pola[x - 2][y]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x - 1][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x - 2][y + 2]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x][y - 1]->getText().getString().toAnsiString() == znak &&
		pola[x][y - 2]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x][y + 2]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x + 1][y - 1]->getText().getString().toAnsiString() == znak &&
		pola[x + 2][y - 2]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x + 1][y]->getText().getString().toAnsiString() == znak &&
		pola[x + 2][y]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x + 1][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x + 2][y + 2]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x + 1][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x - 1][y - 1]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x - 1][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x + 1][y - 1]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x + 1][y]->getText().getString().toAnsiString() == znak &&
		pola[x - 1][y]->getText().getString().toAnsiString() == znak
		)
		return true;
	else if (pola[x][y + 1]->getText().getString().toAnsiString() == znak &&
		pola[x][y - 1]->getText().getString().toAnsiString() == znak
		)
		return true;
		//if (pola[j][i]->getText().getString().toAnsiString() == znak)

	// zmiana ekranu przy wygranej
	else return false;
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


