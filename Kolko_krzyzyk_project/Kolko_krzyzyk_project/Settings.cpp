#include "Settings.h"

void Settings::drawSetting()
{
	// tworzenie obiekt�w do odwo�a� w obs�udze przycisk�w
	Board* board = new Board();
	Settings* settings = new Settings();

	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(5);
	// tworzenie przycisku Start
	Button* button1 = new Button();
	button1->setText("TRZY WYGRA");
	button1->setPosition(100, 20);

	// tworzenie przycisku Settings
	Button* button2 = new Button();
	button2->setText("PIEC WYGRA");
	button2->setPosition(100, 130);

	// tworzenie przycisku Settings
	Button* button3 = new Button();
	std::string roz = "SIZE = " + std::to_string(getRozmiar());
	button3->setText(roz);
	button3->setPosition(100, 240);

	// tworzenie przycisku Exit Game
	Button* button4 = new Button();
	button4->setText("     UP   |  DOWN ");
	button4->setPosition(100, 350);

	// tworzenie przycisku Exit Game
	Button* button5 = new Button();
	button5->setText("EXIT GAME");
	button5->setPosition(100, 460);

	// tworzenie wykorzystywanych pozniej zmiennych pozycji
	sf::Vector2f pozycjamyszki;
	sf::Vector2i pozycjam;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Obs�uga przycisku zamkni�cia
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjam = sf::Mouse::getPosition(window);
				pozycjamyszki = window.mapPixelToCoords(pozycjam);

				// Obs�uga przycisku NEW GAME
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 120 && pozycjamyszki.y > 20)
				{
					window.close();
					board->DrawBoard(settings->rozmiar);
				}
				// Obs�uga przycisku piecWygrywa
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 230 && pozycjamyszki.y > 130)
				{
					settings->piecWygrywa();
				}
				// Obs�uga przycisku rozmiar++
				if (pozycjamyszki.x <= 250 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->up(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}
				// Obs�uga przycisku rozmiar--
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 250 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->down(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}
				// Obs�uga przycisku Exit Game
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

void Settings::trzyWygrywa()
{
}

void Settings::piecWygrywa()
{
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
