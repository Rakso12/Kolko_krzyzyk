#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Button.h"
#include "Menu.h"
#include <string>

class Settings
{
public:
	int rozmiar = 10;
	void drawSetting();
	void trzyWygrywa();
	void piecWygrywa();
	int getRozmiar();

	void up(Settings* settings);
	void down(Settings* settings);
};
