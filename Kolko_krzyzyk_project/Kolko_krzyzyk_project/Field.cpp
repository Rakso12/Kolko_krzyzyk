#include "Field.h"

Field::Field(){
	button_text.setFillColor(sf::Color::Blue); // ustawienie koloru t�a przycisku
	button_text.setCharacterSize(15); // ustawienie wielko�ci tekstu
	
	if (!button_text_font.loadFromFile("../Resources/arial.ttf")) { std::cout << "no i sie zdup�o jak zawsze..."; } // �adowanie fontu dla tekstu na przycisku
	button_text.setFont(button_text_font);

	button_text.setString("X");

	button.setSize(sf::Vector2f(30, 30));
	button.setFillColor(sf::Color::White);
}

/// <summary>
/// Funkcja klasy Field zwracaj�ca obiekt przycisku
/// </summary>
/// <returns> przycisk / obiekt</returns>
sf::RectangleShape Field::getButton(){
	return button;
}


/// <summary>
/// Ustawienie pozycji przycisku na planszy
/// </summary>
/// <param name="x"> warto�� na osi X�w </param>
/// <param name="y"> warto�� na osi Yk�w </param>
void Field::setPosition(int x, int y)
{
	button.setPosition(x, y); // 100, 100
	//button_text.setOrigin(15, 15);
	button_text.setPosition(
		button.getPosition().x + button.getSize().x/2 - button_text.getGlobalBounds().width/2 ,
		button.getPosition().y + button.getSize().y/2 - button_text.getGlobalBounds().height);
}

/// <summary>
/// Funkcja klasy Field zwracaj�ca obiekt tekstu na przycisku
/// </summary>
/// <returns> tekstu obiektu / obiekt</returns>
sf::Text Field::getText(){
	return button_text;
}