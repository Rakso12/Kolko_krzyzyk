#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Button.h"
#include "Menu.h"

class Settings
{
	int rozmiar = 10;
public:
	void drawSetting();
	void trzyWygrywa();
	void piecWygrywa();
	int getRozmiar();
};
