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

	// sprawdzanie strefy niebieskiej
	if(x > 1 && x < rozmiar - 2 && y > 1 && y < rozmiar - 2){	
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
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;

		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;

		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;

		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy zielonej
	if (x > 1 && x < rozmiar - 2 && y == 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
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
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;

		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy fioletowej
	if (x > 1 && x < rozmiar - 2 && y == rozmiar - 2) {
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
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;

		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;

		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;

		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy szarej
	if (y > 1 && y < rozmiar - 2 && x == 1) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
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
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}
	 
	// sprawdzanie strefy czerwonej
	if (y > 1 && y < rozmiar - 2 && x == rozmiar - 2) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
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
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy czarnej prawa strona
	if (y > 1 && y < rozmiar - 2 && x == rozmiar - 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
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
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy czarnej lewa strona
	if (y > 1 && y < rozmiar - 2 && x == 0) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
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
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy brazowej dol
	if (x > 1 && x < rozmiar - 2 && y == rozmiar - 1) {
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
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy brazowej gora
	if (x > 1 && x < rozmiar - 2 && y == 0) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;

		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy górny róg
	if (x == 0 && y == 0) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy górny róg
	if (x == rozmiar - 1 && y == 0) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else
			return false;
	}
	
	// sprawdzanie strefy lewy dolny róg
	if (x == 0 && y == rozmiar - 1) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy dolny róg
	if (x == rozmiar - 1 && y == rozmiar - 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy górny róg brazowy
	if (x == 1 && y == 1) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy górny róg brazowy
	if (x == rozmiar - 2 && y == 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy dolny róg brazowy
	if (x == 1 && y == rozmiar - 2) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy dolny róg brazowy
	if (x == rozmiar - 2 && y == rozmiar - 2) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak) // P1X
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak) // P2X
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy górny róg prawa strona
	if (x == 1 && y == 0) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy górny róg lewa strona
	if (x == rozmiar - 2 && y == 0) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy dolny róg prawa
	if (x == 1 && y == rozmiar - 1) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy dolny róg lewa
	if (x == rozmiar - 2 && y == rozmiar - 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 1]->getText().getString().toAnsiString() == znak) // P4X
			return true;
		else
			return false;
	}


	// sprawdzanie strefy lewy górny róg dol
	if (x == 0 && y == 1) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P8
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy górny róg dol
	if (x == rozmiar - 1 && y == 1) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y + 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x]->getText().getString().toAnsiString() == znak
			) // P4
			return true;
		else if (pola[y + 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y + 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P7
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy lewy dolny róg gora
	if (x == 0 && y == rozmiar - 2) {
		if (pola[y][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x + 2]->getText().getString().toAnsiString() == znak
			) // P2
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x + 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x + 2]->getText().getString().toAnsiString() == znak
			) // P6
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
	}

	// sprawdzanie strefy prawy dolny róg gora
	if (x == rozmiar - 1 && y == rozmiar - 2) {
		if (pola[y][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y][x - 2]->getText().getString().toAnsiString() == znak
			) // P1
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x]->getText().getString().toAnsiString() == znak
			) // P3
			return true;
		else if (pola[y - 1][x - 1]->getText().getString().toAnsiString() == znak &&
			pola[y - 2][x - 2]->getText().getString().toAnsiString() == znak
			) // P5
			return true;
		else if (pola[y - 1][x]->getText().getString().toAnsiString() == znak &&
			pola[y + 1][x]->getText().getString().toAnsiString() == znak) // P3X
			return true;
		else
			return false;
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
