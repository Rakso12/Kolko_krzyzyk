#pragma once

#include "Board.h"
#include "Field.h"

class AiLow
{
	int wsp_y, wsp_x;
public:
	void moveAiLow(std::vector<std::vector<Field*>> pola, int size);
	int getY();
	int getX();
};

