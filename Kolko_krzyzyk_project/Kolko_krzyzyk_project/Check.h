#pragma once

#include <vector>
#include "Board.h"
#include "Field.h"

class Check
{
public:
	void czyWygrana(std::vector <std::vector <Field*>> pola, int rozmiar, std::string znak);
};
