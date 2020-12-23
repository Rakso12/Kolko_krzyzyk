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
	int licznik = 0;
	int ile_wygrywa = getIleWygrywa();
	bool tmp = false;

	// sprawdzanie pionu
	
	if (!tmp) {
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++) {
				if (pola[j][i]->getText().getString().toAnsiString() == znak)
				{
					licznik++;
					if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
						return true;
					}
				}
				else {
					licznik = 0;
				}
			}
			licznik = 0;
		}
	}
	licznik = 0;
	// sprawdzanie poziomu

	if (!tmp) {
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++) {
				if (pola[i][j]->getText().getString().toAnsiString() == znak)
				{
					licznik++;
					if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
						return true;
					}
				}
				else {
					licznik = 0;
				}
			}
			licznik = 0;
		}
	}
	licznik = 0;
	// sprawdzanie skosu od lewej w dó³ razem z przek¹tn¹

	for(int k = 0; k < rozmiar - 2; k++){
		for(int i = 0; i < rozmiar; i++){
			for(int j = 0; j < rozmiar; j++){
				if(k < rozmiar - j){
					if(i == j + k){
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
						{
							licznik++;
							if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
								return true;
							}
						}
						else {
							licznik = 0;
						}
					}
				}
			}
			licznik = 0;
		}
	}
	licznik = 0;
	// sprawdzanie skosu od lewej w górê

	for (int k = 1; k < rozmiar - 2; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar - i) {
					if (i + k == j) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
						{
							licznik++;
							if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
								return true;
							}
						}
						else {
							licznik = 0;
						}
					}
				}
			}
		}
		licznik = 0;
	}
	licznik = 0;
	// sprawdzanie skosu od prawej w dó³

	for (int k = 2; k < rozmiar; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar) {
					if (i + j - 2 - rozmiar / 2 == k) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
						{
							licznik++;
							if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
								return true;
							}
						}
						else {
							licznik = 0;
						}
					}
				}
			}
		}
		licznik = 0;
	}
	licznik = 0;
	// sprawdzanie skosu od prawej w górê razem z przek¹tn¹
	
	for (int k = 2; k < rozmiar; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar) {
					if (i + j == k) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
						{
							licznik++;
							if (licznik == ile_wygrywa) { // sprawdzanie czy ilosc znakow w ciagu jest rowny ilosci wygrywajacej
								return true;
							}
						}
						else {
							licznik = 0;
						}
					}
				}
			}
		}
		licznik = 0;
	}
	licznik = 0;
	// zmiana ekranu przy wygranej
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


