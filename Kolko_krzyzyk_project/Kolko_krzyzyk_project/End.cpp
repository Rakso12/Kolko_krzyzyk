#include "End.h"

void End::drawEnd(std::string znak, ResourceMenager* resource)
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(2);

	// Wyglad pokazywania wyniku
	Button* button1 = new Button(resource, ("WINNER: " + znak), sf::Vector2f(100, 80));

	// Przycisk PLAY AGAIN
	Button* button2 = new Button(resource, "PLAY AGAIN", sf::Vector2f(100, 240));

	// Tworzenie przycisku Exit Game
	Button* button3 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 450));

	// tworzenie wykorzystywanych pozniej zmiennych pozycji
	sf::Vector2f pozycjamyszki;
	sf::Vector2i pozycjam;

	// tworzenie obiektów do odwo³añ w obs³udze przycisków
	Board* board = new Board();
	Menu menu;

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
	
				// Obs³uga przycisku Play Again
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 340 && pozycjamyszki.y > 240)
				{
					window.close();
					menu.drawMenu(resource);
				}

				// Obs³uga przycisku Exit Game
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 550 && pozycjamyszki.y > 450)
				{
					window.close();
				}
			}
		}

		// Rysowanie ekranu koncowego
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
