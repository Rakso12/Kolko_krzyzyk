#pragma once

#include <SFML/System.hpp>
#include "ResourceMenager.h"


/// <summary>
/// Klasa poszczeg�lnego pola na planszy gry
/// </summary>
class Field
{
	/// <summary>
	/// obiekt odpowiadaj�cy za wygl�d pola
	/// </summary>
	sf::RectangleShape button;
	/// <summary>
	/// obiekt odpowiadaj�cy za tekst na polu ( O / X / _ )
	/// </summary>
	sf::Text button_text;
	/// <summary>
	/// Zmienna dost�pno�ci pola (0 je�li dost�pne, 1 je�li niedost�pne)
	/// </summary>
	int available = 0;
	

public:
	Field(ResourceMenager* resource); // konstruktor
	sf::RectangleShape getButton(); // daj wyglad
	sf::Text getText(); // daj wyglad tekstu

	void setPosition(int x, int y); // zmien pozycje na
	void setText(char text); // ustaw tekst
	void setUnAvailable();
	void setAvailable();
	int isAvailable();

	Field(Field& main_board);

};
