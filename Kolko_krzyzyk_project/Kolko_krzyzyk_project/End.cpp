#include "End.h"

/// <summary>
/// Funkcja obs�uguj�ca rysowanie okna menu po zako�czeniu rozgrywki wraz z obs�ug� przycisk�w i wy�wietlaniem wyniku rozgrywki.
/// </summary>
/// <param name="resource"> wska�nik do zmiennej obs�ugi zasob�w </param>
void End::drawEnd(std::string znak, ResourceMenager* resource)
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");

	// Ograniczenie liczby klatek na sekund�
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(2);

	Button* button1 = new Button(resource, ("WINNER: " + znak), sf::Vector2f(100, 80));
	Button* button2 = new Button(resource, "PLAY AGAIN", sf::Vector2f(100, 240));
	Button* button3 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 450));

	sf::Vector2f pozycjamyszki;
	Menu menu;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Obs�uga przycisku zamkni�cia
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjamyszki = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	
				// Obs�uga przycisku Play Again
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 340 && pozycjamyszki.y > 240)
				{
					window.close();
					menu.drawMenu(resource);
				}

				// Obs�uga przycisku Exit Game
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
