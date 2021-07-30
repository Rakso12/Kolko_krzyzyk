#pragma once

#include <vector>
#include "Field.h"

/// <summary>
/// Klasa oodpowiedzialna za sprawdzanie wygranej na planszy.
/// </summary>
class Check
{
	/// <summary>
	/// Zmienna odpowiedzialna za ilo�� wygrywaj�cych ruch�w domy�lnie 3 w rz�dzie wygrywa.
	/// </summary>
	int ile_wygrywa = 5;
public:
	int best_AI = 0;
	Check() = default;
	bool czyWygrana(std::vector <std::vector <Field*>> pola, int rozmiar, std::string znak);
	void setIleWygrywa(int liczba);
	int getIleWygrywa();
};
