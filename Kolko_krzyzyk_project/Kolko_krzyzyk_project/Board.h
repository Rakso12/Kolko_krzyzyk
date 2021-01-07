#pragma once

#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Check.h"
#include "End.h"
#include "AiLow.h"
#include "AiMedium.h"
#include "ResourceMenager.h"

class Board
{
public:
	void DrawBoard(int size, int level, ResourceMenager* resource);
};
