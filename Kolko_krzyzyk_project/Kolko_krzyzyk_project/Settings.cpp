#include "Settings.h"

void Settings::drawSetting(ResourceMenager* resource)
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");

	// Ograniczenie liczby klatek na sekundê
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(12);

	Button* button1 = new Button(resource, "GRAJ", sf::Vector2f(100, 20));
	Button* button2 = new Button(resource, " LOW | MEDIUM", sf::Vector2f(100, 130));
	Button* button3 = new Button(resource, ("SIZE = " + std::to_string(getRozmiar())), sf::Vector2f(100, 240));
	Button* button4 = new Button(resource, "     UP   |  DOWN ", sf::Vector2f(100, 350));
	Button* button5 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 460));

	Board* board = new Board();
	Settings* settings = new Settings();

	sf::Vector2f pozycjamyszki;
	std::string roz;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Obs³uga przycisku zamkniêcia
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjamyszki = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				// Obs³uga przycisku NEW GAME
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 120 && pozycjamyszki.y > 20)
				{
					window.close();
					board->DrawBoard(settings->rozmiar, 1, resource);
				}

				// Obs³uga przycisku low level
				if (pozycjamyszki.x <= 250 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 230 && pozycjamyszki.y > 130)
				{
					window.close();
					board->DrawBoard(settings->rozmiar, 2, resource);
				}

				// Obs³uga przycisku medium level
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 250 && pozycjamyszki.y <= 230 && pozycjamyszki.y > 130)
				{
					window.close();
					//board->DrawBoard(settings->rozmiar, 3, resource);
				}

				// Obs³uga przycisku rozmiar++
				if (pozycjamyszki.x <= 250 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->up(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}

				// Obs³uga przycisku rozmiar--
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 250 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->down(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}

				// Obs³uga przycisku Exit Game
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 560 && pozycjamyszki.y > 460)
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

		window.draw(button4->getButton());
		window.draw(button4->getText());

		window.draw(button5->getButton());
		window.draw(button5->getText());
		window.display();
	}
}

int Settings::getRozmiar()
{
	return rozmiar;
}

void Settings::up(Settings* settings)
{
	if (settings->rozmiar >= 10 && settings->rozmiar < 30) 
	{
		settings->rozmiar = settings->rozmiar + 1;
	}
}

void Settings::down(Settings* settings)
{
	if (settings->rozmiar > 10) {
		settings->rozmiar = settings->rozmiar - 1;
	}
}
