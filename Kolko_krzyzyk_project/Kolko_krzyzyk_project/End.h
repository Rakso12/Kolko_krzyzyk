#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Button.h"
#include "Menu.h"
#include "ResourceMenager.h"

class End
{
public:
	void drawEnd(std::string znak, ResourceMenager* resource);
};
