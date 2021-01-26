#pragma once

#include "Board.h"
#include "Button.h"

/// <summary>
/// Klasa obs³uguj¹ca menu ustawieñ - zmiana rozmiaru planszy, wybór trudnoœci rozgrywki.
/// </summary>
class Settings
{
public:
	/// <summary>
	/// Rozmiar planszy
	/// </summary>
	int rozmiar = 10;
	void drawSetting(ResourceMenager* resource);
	int getRozmiar();

	void up(Settings* settings);
	void down(Settings* settings);
};
