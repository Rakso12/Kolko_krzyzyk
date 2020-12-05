#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

/// <summary>
/// Klasa pola na planszy
/// </summary>
class Field
{
	sf::RectangleShape button; // wyglad - ksztalt
	sf::Text button_text; // wyglad - tekst
	sf::Font button_text_font; // czcionka

public:
	Field(); // konstruktor
	~Field(); // dekonstruktor

	int pozycjaX, pozycjaY;

	void setPozycja(int x, int y);

	sf::RectangleShape getButton(); // daj wyglad
	sf::Text getText(); // daj wyglad tekstu

	void setPosition(int x, int y); // zmien pozycje na
	void setText(char text); // ustaw tekst
	
};