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
/*
void Button::setPosition(int x, int y)
{
	button.setPosition(x, y);
	button_text.setPosition(button.getPosition().x + button.getSize().x / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getSize().y / 2 - button_text.getGlobalBounds().height);
}
*/
void Button::setPozycja(int x, int y) {
}

void Button::setText(std::string text) {
	button_text.setString(text);
}

sf::Text Button::getText() {
	return button_text;
}

sf::RectangleShape Button::getButton() {
	return button;
}
