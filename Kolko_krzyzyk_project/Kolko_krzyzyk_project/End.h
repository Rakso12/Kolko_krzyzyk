#pragma once

#include "Menu.h"
#include "ResourceMenager.h"

/// <summary>
/// Klasa obs�uguj�ca menu ko�cowe po rozgrywce wraz z prezentacj� rezultatu partii.
/// </summary>
class End
{
public:
	void drawEnd(std::string znak, ResourceMenager* resource);
};
