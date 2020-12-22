#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::RectangleShape button;
	sf::Text button_text;
	sf::Font button_text_font;
public:
	Button();
	void setPosition(int x, int y);
	void setPozycja(int x, int y);
	void setText(std::string tekst);
	sf::Text getText();
	sf::RectangleShape getButton();
};

