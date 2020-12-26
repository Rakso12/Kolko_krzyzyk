#pragma once

#include <vector>
#include "Board.h"
#include "Field.h"

class Check
{
	int ile_wygrywa = 3;
public:
	bool czyWygrana(std::vector <std::vector <Field*>> pola, int rozmiar, std::string znak, int x, int y);
	void setIleWygrywa(int liczba);
	int getIleWygrywa();
};
