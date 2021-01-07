#pragma once

#include "Board.h"
#include "Field.h"
#include "Check.h"

class AiMedium
{
	int wsp_x, wsp_y;
public:
	void moveAiMedium(std::vector<std::vector<Field*>> pola, int size);
	int getX();
	int getY();
	//std::vector<int> minmax(std::vector<std::vector<Field*>> pola, int ile_ruchow, int size);
};
