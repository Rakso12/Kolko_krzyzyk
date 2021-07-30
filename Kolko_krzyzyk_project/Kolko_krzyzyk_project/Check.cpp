#include "Check.h"
#include <iostream>

/// <summary>
/// Funkcja sprawdzajaca plansze czy  znajduja sie w niej wygrane ciagi znakow
/// kolka lub krzyza o liczebnosci rownej ustalonej liczbie wygrywajacego ciagu 
/// </summary>
/// <param name="pola"> Vektor zawierajacy plansze </param>
/// <param name="rozmiar"> Rozmiar boku planszy </param>
/// <param name="znak"> Aktualnie sprawdzany/wstawiany znak </param>
bool Check::czyWygrana(std::vector<std::vector<Field*>> pola, int rozmiar, std::string znak)
{
	int ile_wygrywa = getIleWygrywa();

	for (int y = 0; y < rozmiar; ++y) {
		for (int x = 0; x < rozmiar - ile_wygrywa - 1; ++x) {
			int licznik = 0;
			for (int i = 0; i < ile_wygrywa; ++i) {
				if (pola[y][x + i]->getText().getString().toAnsiString() == znak) {
					licznik++;
				}
			}
			best_AI = std::max(best_AI, licznik);
			if (licznik == ile_wygrywa) {
				return true;
			}
		}
	}

	for (int x = 0; x < rozmiar; ++x) {
		for (int y = 0; y < rozmiar - ile_wygrywa - 1; ++y) {
			int licznik = 0;
			for (int i = 0; i < ile_wygrywa; ++i) {
				if (pola[y + i][x]->getText().getString().toAnsiString() == znak) {
					++licznik;
				}
			}
			best_AI = std::max(best_AI, licznik);
			if (licznik == ile_wygrywa) {
				return true;
			}
		}
	}
	// -----------------
	for (int x = 0; x < rozmiar - ile_wygrywa + 1; ++x)
		for (int y = 0; y < rozmiar - ile_wygrywa + 1; ++y)
		{
			int licznik = 0;
			int count = 0;
			for (int i = 0; i < ile_wygrywa; ++i)
			{
				if (pola[y + i][x + i]->getText().getString().toAnsiString() == znak) {
					++licznik;
				}
			}
			best_AI = std::max(best_AI, licznik);
			if (licznik == ile_wygrywa) {
				return true;
			}
		}

	for (int x = rozmiar - 1; x >= ile_wygrywa - 1; --x)
		for (int y = rozmiar - ile_wygrywa; y >= 0; --y)
		{
			int licznik = 0;
			for (int i = 0; i < ile_wygrywa; ++i)
			{
				if (pola[y + i][x - i]->getText().getString().toAnsiString() == znak)
					++licznik;
			}
			best_AI = std::max(best_AI, licznik);

			if (licznik == ile_wygrywa) {
				return true;
			}
		}
	return false;
}

/// <summary>
/// Funkcja ustawiajaca dlugosc wygrywajacego ciagu znakow
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
