#include "Menu.h"

/// <summary>
/// Funkcja obs³uguj¹ca rysowanie okna Menu wraz z obs³ug¹ przycisków.
/// </summary>
/// <param name="resource"> wskaŸnik do zmiennej obs³ugi zasobów </param>
void Menu::drawMenu(ResourceMenager* resource)
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");
	
	// Ograniczenie liczby klatek na sekundê
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(2);

	Button* button1 = new Button(resource, "NEW GAME", sf::Vector2f(100,80));
	Button* button2 = new Button(resource, "SETTINGS", sf::Vector2f(100, 240));
	Button* button3 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 400));

	Board* board = new Board();
	Settings* settings = new Settings();

	sf::Vector2f mousePosition;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Obs³uga przycisku zamkniêcia
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // Translacja pozycji myszki na koordynaty mapy
				
				// Obs³uga przycisku New Game
				if (mousePosition.x <= 400 && mousePosition.x > 100 && mousePosition.y <= 180 && mousePosition.y > 80)
				{
					window.close();
					board->DrawBoard(10, 1, resource); // Domyœlna plansza do gry - 2v2 rozmiar - 10x10
				}

				// Obs³uga przycisku Settings
				if (mousePosition.x <= 400 && mousePosition.x > 100 && mousePosition.y <= 340 && mousePosition.y > 240)
				{
					window.close();
					settings->drawSetting(resource);
				}

				// Obs³uga przycisku Exit Game
				if (mousePosition.x <= 400 && mousePosition.x > 100 && mousePosition.y <= 500 && mousePosition.y > 400)
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
