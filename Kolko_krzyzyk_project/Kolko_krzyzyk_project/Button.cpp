#include "Button.h"

Button::Button()
{
	button_text.setFillColor(sf::Color::Magenta);
	button_text.setCharacterSize(40);

	if (!button_text_font.loadFromFile("../Resources/arial.ttf")) { std::cout << "no i sie zepsulo..."; }
	button_text.setFont(button_text_font);

	button_text.setString("");

	button.setSize(sf::Vector2f(300, 100));
	button.setFillColor(sf::Color::Blue);
}

void Button::setPosition(int x, int y)
{
	button.setPosition(x, y);
	button_text.setPosition(button.getPosition().x + button.getSize().x / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getSize().y / 2 - button_text.getGlobalBounds().height);
}

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
