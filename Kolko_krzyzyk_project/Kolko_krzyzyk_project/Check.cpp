#include "Check.h"
#include <iostream>

int Check::czyWygrana(std::vector<std::vector<Field*>> pola, int rozmiar)
{
	// sprawdzanie pionu

	int licznik = 0;
	int ile_wygrywa = 3;
	bool tmp = false;

	// sprawdzanie pionu
	
	if (!tmp) {
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++) {
				if (pola[j][i]->getText().getString().toAnsiString() == "X")
				{
					licznik++;
					if (licznik == ile_wygrywa) {
						tmp = true;
					}
				}
				else {
					licznik = 0;
				}
			}
		}
	}

	// sprawdzanie poziomu

	if (!tmp) {
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++) {
				if (pola[i][j]->getText().getString().toAnsiString() == "X")
				{
					licznik++;
					if (licznik == ile_wygrywa) {
						tmp = true;
					}
				}
				else {
					licznik = 0;
				}
			}
		}
	}
	
	// sprawdzanie skosu od lewej

	// DO ZROBIENIA SPRAWDZANIE PRZEK¥TNYCH POD I NAD / LEWA / PRAWA
	/*
	if (!tmp) {
		for (int i = 0; i < rozmiar-1; i++)
		{
			if (pola[i+1][i]->getText().getString().toAnsiString() == "X")
			{
				licznik++;
				if (licznik == ile_wygrywa) {
					tmp = true;
				}
			}
			else {
				licznik = 0;
			}
		}
	}
	*/
	std::cout << tmp << "wynik" << std::endl;

	return 0;
}
