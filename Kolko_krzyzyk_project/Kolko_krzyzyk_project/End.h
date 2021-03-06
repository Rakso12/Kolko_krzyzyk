#pragma once

#include "Menu.h"
#include "ResourceMenager.h"

/// <summary>
/// Klasa obsługująca menu końcowe po rozgrywce wraz z prezentacją rezultatu partii.
/// </summary>
class End
{
public:
	void drawEnd(std::string znak, ResourceMenager* resource);
};
