#include "Field.h"

// Konstruktor obiektu Field ustawiaj¹cy wielkosci i wyglad pol na planszy 
Field::Field() {

	button_text.setFillColor(sf::Color::Blue);
	button_text.setCharacterSize(15);

	if (!button_text_font.loadFromFile("../Resources/arial.ttf")) { std::cout << "no i sie zepsulo..."; }
	button_text.setFont(button_text_font);

	button_text.setString(" _ ");

	button.setSize(sf::Vector2f(30, 30));
	button.setFillColor(sf::Color::White);
}

// Dekonstruktor
Field::~Field()
{
	// TODO: czy tu coœ jest wgl potrzebne na ten moment?
}

/// <summary>
/// Funkcja utawiajaca pozycje obiektu
/// </summary>
/// <param name="x">startowa wspolzedna int x</param>
/// <param name="y">startowa wspolzedna int y</param>
void Field::setPosition(int x, int y)
{
	button.setPosition((int)x, (int)y);
	button_text.setPosition(
		button.getPosition().x + button.getSize().x / 2 - button_text.getGlobalBounds().width / 2,
		button.getPosition().y + button.getSize().y / 2 - button_text.getGlobalBounds().height);
}

/// <summary>
/// Funkcja ustawiaj¹ca tekst w obiekcie podany jako argument
/// </summary>
/// <param name="text">zmienna char znak</param>
void Field::setText(char text) {
	button_text.setString(text);
}

/// <summary>
/// Funkcja ustawiajaca dostepnosc pola na niedostepne
/// </summary>
void Field::setAvailable(){
	available = 1;
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

// TODO: po co to zrobilem...
void Field::setPozycja(int x, int y){
	pozycjaX = x;
	pozycjaY = y;
}

/// <summary>
/// Funkcja zwracajaca przycisk - jego wyglad
/// </summary>
/// <returns>przycisk</returns>
sf::RectangleShape Field::getButton() {
	return button;
}
