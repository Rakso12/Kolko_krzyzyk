#include "Field.h"

Field::Field(ResourceMenager* resource) {

	button_text.setFillColor(sf::Color::Blue);
	button_text.setCharacterSize(15);
	button_text.setFont(*resource->getFont("../Resources/arial.ttf"));
	button_text.setString(" _ ");

	button.setSize(sf::Vector2f(30, 30));
	button.setFillColor(sf::Color::White);
}

Field::Field(Field& main_board)
{
	button = main_board.button;
	button_text = main_board.button_text;
	available = main_board.available;
}

/// <summary>
/// Funkcja utawiajaca pozycje obiektu przycisku wraz z jego tekstem
/// </summary>
/// <param name="x">startowa wspo³¿êdna int x</param>
/// <param name="y">startowa wspo³¿êdna int y</param>
void Field::setPosition(int x, int y)
{
	button.setPosition((int)x, (int)y);
	button_text.setPosition(
		button.getPosition().x + button.getSize().x / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getSize().y / 2 - button_text.getGlobalBounds().height);
}

/// <summary>
/// Funkcja ustawiaj¹ca w obiekcie znak podany jako argument
/// </summary>
/// <param name="text">zmienna znaku aktualnego gracza</param>
void Field::setText(char text) {
	button_text.setString(text);
}

/// <summary>
/// Funkcja ustawiajaca dostepnosc pola na niedostepne
/// </summary>
void Field::setUnAvailable(){
	available = 1;
}

void Field::setAvailable() {
	available = 0;
}

/// <summary>
/// Funkcja sprawdzaj¹ca dostepnosc pola
/// </summary>
/// <returns>jesli dostepne 0, jesli niedostepne 1</returns>
int Field::isAvailable() {
	if (available == 1) { return 1;}
	else { return 0; }
}

/// <summary>
/// Funkcja zwracajaca tekst pola
/// </summary>
/// <returns>tekst pola</returns>
sf::Text Field::getText() {
	return button_text;
}

/// <summary>
/// Funkcja zwracajaca przycisk - jego wyglad
/// </summary>
/// <returns>przycisk</returns>
sf::RectangleShape Field::getButton() {
	return button;
}
