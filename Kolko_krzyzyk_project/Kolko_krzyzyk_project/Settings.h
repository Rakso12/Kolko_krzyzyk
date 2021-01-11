#pragma once

#include "Board.h"
#include "Button.h"

class Settings
{
public:
	int rozmiar = 10;
	void drawSetting(ResourceMenager* resource);
	int getRozmiar();

	void up(Settings* settings);
	void down(Settings* settings);
};
