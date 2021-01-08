#pragma once

#include "Check.h"

class AiMedium
{
	int wsp_x, wsp_y;
public:
	void moveAiMedium(std::vector<std::vector<Field*>> pola, int size);
	int getX();
	int getY();
	sf::Vector2i findBestMove(std::vector<std::vector<Field*>>pola, int size, int wsp_x, int wsp_y, Check* check, char znak);
	int minMax(std::vector<std::vector<Field*>>pola, int depth, bool isMax, int size, Check* check);
	bool isMovesLeft(std::vector<std::vector<Field*>>pola, int size);
};
