#include "Menu.h"

void Menu::drawMenu()
{
	sf::RenderWindow window(sf::VideoMode(400, 600), "Kolko i krzyzyk");
	
	// tworzenie przycisku Start
	
	sf::RectangleShape button;
	sf::Text button_text;
	sf::Font button_text_font;

	button.setSize(sf::Vector2f(200, 140));
	button.setFillColor(sf::Color::White);
	button.setPosition(sf::Vector2f(100, 100));
	
	button_text.setPosition(
		button.getPosition().x - button_text.getGlobalBounds().width / 2,
		button.getPosition().y - button_text.getGlobalBounds().height / 2);
	button_text.setFillColor(sf::Color::Blue);
	button_text.setCharacterSize(30);
	if (!button_text_font.loadFromFile("../Resources/arial.ttf")) { std::cout << "no i sie zepsulo..."; }
	button_text.setFont(button_text_font);
	button_text.setString(" START ");


	sf::Vector2f pozycjamyszki;
	sf::Vector2i pozycjam;
	Board* board = new Board();
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjam = sf::Mouse::getPosition(window);
				pozycjamyszki = window.mapPixelToCoords(pozycjam);
				if (pozycjamyszki.x <= 300 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 140 && pozycjamyszki.y > 100)
				{
					window.close();
					board->DrawBoard();
				}
			}
		}

		window.clear();
		window.draw(button);
		window.draw(button_text);
		window.display();
		
	}
}
