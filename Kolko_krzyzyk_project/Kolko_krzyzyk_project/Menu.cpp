#include "Menu.h"

void Menu::drawMenu(ResourceMenager* resource)
{

	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(2);
	// tworzenie przycisku Start

	Button* button1 = new Button(resource, "NEW GAME", sf::Vector2f(100,80));

	// tworzenie przycisku Settings
	Button* button2 = new Button(resource, "SETTINGS", sf::Vector2f(100, 240));

	
	// tworzenie przycisku Exit Game
	Button* button3 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 400));

	// tworzenie wykorzystywanych pozniej zmiennych pozycji
	sf::Vector2f pozycjamyszki;
	sf::Vector2i pozycjam;

	// tworzenie obiektów do odwo³añ w obs³udze przycisków
	Board* board = new Board();
	Settings* settings = new Settings();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Obs³uga przycisku zamkniêcia
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjam = sf::Mouse::getPosition(window);
				pozycjamyszki = window.mapPixelToCoords(pozycjam);
				// Obs³uga przycisku New Game
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 180 && pozycjamyszki.y > 80)
				{
					window.close();
					board->DrawBoard(10, 1, resource);
				}
				// Obs³uga przycisku Settings
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 340 && pozycjamyszki.y > 240)
				{
					window.close();
					settings->drawSetting(resource);
				}
				// Obs³uga przycisku Exit Game
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 500 && pozycjamyszki.y > 400)
				{
					window.close();
				}
			}
		}

		// Rysowanie menu
		window.clear();
		window.draw(button1->getButton());
		window.draw(button1->getText());

		window.draw(button2->getButton());
		window.draw(button2->getText());

		window.draw(button3->getButton());
		window.draw(button3->getText());
		window.display();
	}
}
