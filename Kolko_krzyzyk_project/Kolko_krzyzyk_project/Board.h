#pragma once

#include "End.h"
#include "AiLow.h"
#include "AiMedium.h"

/// <summary>
/// Klasa obs�uguj�ca ca�� logik� planszy gry.
/// </summary>
class Board
{
public:
	void DrawBoard(int size, int level, ResourceMenager* resource);
};
