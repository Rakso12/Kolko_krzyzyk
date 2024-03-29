#pragma once

#include "ResourceMenager.h"

/// <summary>
/// Klasa dla przycisków spełniających różne funkcje w programie.
/// </summary>
class Button
{
private:
	/// <summary>
	/// obiekt odpowiadający za wygląd przycisku
	/// </summary>
	sf::RectangleShape button;
	/// <summary>
	/// obiekt odpowiadający za tekst na przycisku
	/// </summary>
	sf::Text button_text;
	/// <summary>
	/// obiekt odpowiadający za czcionkę tekstu przycisku
	/// </summary>
	sf::Font button_text_font;
public:
	Button(ResourceMenager* resource, std::string text, sf::Vector2f position);
	void setText(std::string tekst);
	sf::Text getText();
	sf::RectangleShape getButton();
};
