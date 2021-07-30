#include "Settings.h"

/// <summary>
/// Funkcja obs�uguj�ca rysowanie okna menu opcji wraz z obs�ug� przycisk�w i wy�wietlaniem sk�adowych.
/// </summary>
/// <param name="resource"> wska�nik do zmiennej obs�ugi zasob�w </param>
void Settings::drawSetting(ResourceMenager* resource)
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Kolko i krzyzyk");

	// Ograniczenie liczby klatek na sekund�
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(12);

	Button* button1 = new Button(resource, "PLAY", sf::Vector2f(100, 20));
	Button* button2 = new Button(resource, " LOW | MEDIUM", sf::Vector2f(100, 140));
	Button* button3 = new Button(resource, ("SIZE = " + std::to_string(getRozmiar())), sf::Vector2f(100, 260));
	Button* button4 = new Button(resource, "     UP   |  DOWN ", sf::Vector2f(100, 350));
	Button* button5 = new Button(resource, "EXIT GAME", sf::Vector2f(100, 470));

	Board* board = new Board();
	Settings* settings = new Settings();

	sf::Vector2f pozycjamyszki;
	std::string roz;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // Obs�uga przycisku zamkni�cia
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				pozycjamyszki = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				// Obs�uga przycisku NEW GAME
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 120 && pozycjamyszki.y > 20)
				{
					window.close();
					board->DrawBoard(settings->rozmiar, 1, resource);
				}

				// Obs�uga przycisku low level
				if (pozycjamyszki.x <= 250 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 230 && pozycjamyszki.y > 140)
				{
					window.close();
					board->DrawBoard(settings->rozmiar, 2, resource);
				}

				// Obs�uga przycisku medium level
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 250 && pozycjamyszki.y <= 230 && pozycjamyszki.y > 130)
				{
					window.close();
					board->DrawBoard(settings->rozmiar, 3, resource);
				}

				// Wy�wietlanie rozmiaru
				if (pozycjamyszki.x <= 250 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->up(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}

				// Obs�uga przycisku rozmiar-- / rozmiar --
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 260 && pozycjamyszki.y <= 450 && pozycjamyszki.y > 350)
				{
					settings->down(settings);
					roz = "SIZE = " + std::to_string(settings->getRozmiar());
					button3->setText(roz);
				}

				// Obs�uga przycisku Exit Game
				if (pozycjamyszki.x <= 400 && pozycjamyszki.x > 100 && pozycjamyszki.y <= 570 && pozycjamyszki.y > 470)
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

/// <summary>
/// Funkcja zwracaj�ca aktualnie ustawiony przez u�ytkownika rozmiar planszy.
/// </summary>
/// <returns>zmienna liczbowa - rozmiar</returns>
int Settings::getRozmiar()
{
	return rozmiar;
}

/// <summary>
/// Funkcja zwi�kszaj�ca rozmiar o jeden.
/// </summary>
/// <param name="settings"> objekt ustawie� </param>
void Settings::up(Settings* settings)
{
	if (settings->rozmiar >= 10 && settings->rozmiar < 30) 
	{
		settings->rozmiar = settings->rozmiar + 1;
	}
}

/// <summary>
/// Funkcja zmniejszaj�ca rozmiar o jeden
/// </summary>
/// <param name="settings"> obiekt ustawie� </param>
void Settings::down(Settings* settings)
{
	if (settings->rozmiar > 10) {
		settings->rozmiar = settings->rozmiar - 1;
	}
}
