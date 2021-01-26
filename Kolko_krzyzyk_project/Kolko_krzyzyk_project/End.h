#pragma once

#include "Menu.h"
#include "ResourceMenager.h"

/// <summary>
/// Klasa obs³uguj¹ca menu koñcowe po rozgrywce wraz z prezentacj¹ rezultatu partii.
/// </summary>
class End
{
public:
	void drawEnd(std::string znak, ResourceMenager* resource);
};
