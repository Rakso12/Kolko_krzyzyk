#include "Field.h"

Field::Field() {

	button_text.setFillColor(sf::Color::Blue);
	button_text.setCharacterSize(15);

	if (!button_text_font.loadFromFile("../Resources/arial.ttf")) { std::cout << "no i sie zepsulo..."; }
	button_text.setFont(button_text_font);

	button_text.setString(" . ");

	button.setSize(sf::Vector2f(30, 30));
	button.setFillColor(sf::Color::White);
}

Field::~Field()
{

}

void Field::setPosition(int x, int y)
{
	button.setPosition((int)x, (int)y);
	button_text.setPosition(
		button.getPosition().x + button.getSize().x / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getSize().y / 2 - button_text.getGlobalBounds().height);
}

void Field::setText(char text) {
	button_text.setString(text);
}


sf::Text Field::getText() {
	return button_text;
}

void Field::setPozycja(int x, int y){
	pozycjaX = x;
	pozycjaY = y;
}

sf::RectangleShape Field::getButton() {
	return button;
}

