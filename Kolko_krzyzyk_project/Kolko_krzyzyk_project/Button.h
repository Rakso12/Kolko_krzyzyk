#pragma once

#include "ResourceMenager.h"

/// <summary>
/// Klasa dla przycisk�w spe�niaj�cych r�ne funkcje w programie.
/// </summary>
class Button
{
private:
	/// <summary>
	/// obiekt odpowiadaj�cy za wygl�d przycisku
	/// </summary>
	sf::RectangleShape button;
	/// <summary>
	/// obiekt odpowiadaj�cy za tekst na przycisku
	/// </summary>
	sf::Text button_text;
	/// <summary>
	/// obiekt odpowiadaj�cy za czcionk� tekstu przycisku
	/// </summary>
	sf::Font button_text_font;
public:
	Button(ResourceMenager* resource, std::string text, sf::Vector2f position);
	void setText(std::string tekst);
	sf::Text getText();
	sf::RectangleShape getButton();
};
