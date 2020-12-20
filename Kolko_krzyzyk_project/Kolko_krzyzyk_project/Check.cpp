#include "Check.h"
#include <iostream>

void Check::czyWygrana(std::vector<std::vector<Field*>> pola, int rozmiar, std::string znak)
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
				if (pola[j][i]->getText().getString().toAnsiString() == znak)
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
				if (pola[i][j]->getText().getString().toAnsiString() == znak)
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
	
	// sprawdzanie skosu od lewej w dó³ razem z przek¹tn¹

	for(int k = 0; k < rozmiar - 2; k++){
		for(int i = 0; i < rozmiar; i++){
			for(int j = 0; j < rozmiar; j++){
				if(k < rozmiar - j){
					if(i == j + k){
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
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
		}
	}

	// sprawdzanie skosu od lewej w górê

	for (int k = 1; k < rozmiar - 2; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar - i) {
					if (i + k == j) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
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
		}
	}

	// sprawdzanie skosu od prawej w dó³

	for (int k = 2; k < rozmiar; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar) {
					if (i + j - 2 - rozmiar / 2 == k) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
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
		}
	}

	// sprawdzanie skosu od prawej w górê razem z przek¹tn¹
	
	for (int k = 2; k < rozmiar; k++) {
		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				if (k < rozmiar) {
					if (i + j == k) {
						if (pola[i][j]->getText().getString().toAnsiString() == znak)
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
		}
	}

	// zmiana ekranu przy wygranej

	if (tmp) {
		std::cout << "Wygra³ gracz: " << znak ;
	}
}
