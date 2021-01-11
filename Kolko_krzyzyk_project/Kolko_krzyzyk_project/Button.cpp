#include "Button.h"

Button::Button(ResourceMenager* resource, std::string text, sf::Vector2f position)
{
	button_text.setFillColor(sf::Color::Magenta);
	button_text.setCharacterSize(40);
	button_text.setFont(*resource->getFont("../Resources/arial.ttf"));
	button_text.setString(text);

	button.setSize(sf::Vector2f(300, 100));
	button.setFillColor(sf::Color::Blue);
	button.setPosition(position);
	button_text.setPosition(button.getPosition().x + button.getGlobalBounds().width / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getGlobalBounds().height / 2 - button_text.getGlobalBounds().height / 2 - button_text.getCharacterSize() / 2);
}

/// <summary>
/// Funkcja ustawiaj¹ca tekst przycisku
/// </summary>
/// <param name="text"> Tekst </param>
void Button::setText(std::string text) {
	button_text.setString(text);
}

/// <summary>
/// Funkcja zwracaj¹ca tekst przycisku
/// </summary>
/// <returns> sf::Text text </returns>
sf::Text Button::getText() {
	return button_text;
}

/// <summary>
/// Funkcja zwracaj¹ca
/// </summary>
/// <returns> obiekt button </returns>
sf::RectangleShape Button::getButton() {
	return button;
}
