#pragma once

#include "End.h"
#include "AiLow.h"
#include "AiMedium.h"

/// <summary>
/// Klasa obs³uguj¹ca ca³¹ logikê planszy gry.
/// </summary>
class Board
{
public:
	void DrawBoard(int size, int level, ResourceMenager* resource);
};
