#pragma once

#include <SFML/System.hpp>
#include "ResourceMenager.h"


/// <summary>
/// Klasa pola na planszy
/// </summary>
class Field
{
	sf::RectangleShape button; // wyglad - ksztalt
	sf::Text button_text; // wyglad - tekst
	int available = 0;
	

public:
	Field(ResourceMenager* resource); // konstruktor
	~Field(); // dekonstruktor

	int pozycjaX = 0, pozycjaY = 0;

	void setPozycja(int x, int y);

	sf::RectangleShape getButton(); // daj wyglad
	sf::Text getText(); // daj wyglad tekstu

	void setPosition(int x, int y); // zmien pozycje na
	void setText(char text); // ustaw tekst
	void setAvailable();
	int isAvailable();
};
