#pragma once

#include <SFML/System.hpp>
#include "ResourceMenager.h"


/// <summary>
/// Klasa poszczególnego pola na planszy gry
/// </summary>
class Field
{
	/// <summary>
	/// obiekt odpowiadaj¹cy za wygl¹d pola
	/// </summary>
	sf::RectangleShape button;
	/// <summary>
	/// obiekt odpowiadaj¹cy za tekst na polu ( O / X / _ )
	/// </summary>
	sf::Text button_text;
	/// <summary>
	/// Zmienna dostêpnoœci pola (0 jeœli dostêpne, 1 jeœli niedostêpne)
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
