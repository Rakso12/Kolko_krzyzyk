#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

/// <summary>
/// Klasa pola na planszy
/// </summary>
class Field
{
	sf::RectangleShape button;
	sf::Text button_text;
	sf::Font button_text_font;

public:
	Field();
	sf::RectangleShape getButton();
	void setPosition(int x, int y);
	sf::Text getText();
	//void setText(char text);
};

