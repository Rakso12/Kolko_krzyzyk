#pragma once

#include "ResourceMenager.h"

/// <summary>
/// Klasa dla przycisków spe³niaj¹cych ró¿ne funkcje w programie.
/// </summary>
class Button
{
private:
	/// <summary>
	/// obiekt odpowiadaj¹cy za wygl¹d przycisku
	/// </summary>
	sf::RectangleShape button;
	/// <summary>
	/// obiekt odpowiadaj¹cy za tekst na przycisku
	/// </summary>
	sf::Text button_text;
	/// <summary>
	/// obiekt odpowiadaj¹cy za czcionkê tekstu przycisku
	/// </summary>
	sf::Font button_text_font;
public:
	Button(ResourceMenager* resource, std::string text, sf::Vector2f position);
	void setText(std::string tekst);
	sf::Text getText();
	sf::RectangleShape getButton();
};
