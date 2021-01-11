#pragma once

#include "ResourceMenager.h"

class Button
{
private:
	sf::RectangleShape button;
	sf::Text button_text;
	sf::Font button_text_font;
public:
	Button(ResourceMenager* resource, std::string text, sf::Vector2f position);
	void setText(std::string tekst);
	sf::Text getText();
	sf::RectangleShape getButton();
};
