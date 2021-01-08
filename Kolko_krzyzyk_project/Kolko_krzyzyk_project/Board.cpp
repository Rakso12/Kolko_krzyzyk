#include "Board.h"
#include <typeinfo>
#include <SFML/System.hpp>

void Board::DrawBoard(int size, int level, ResourceMenager* resource)
{
    // Wst�pne tworzenie obiekt�w do planszy
    // ------------------------------------------------------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(size * 31, size * 31), "Kolko i krzyzyk"); // tworzenie okna
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(5);
    std::vector <std::vector <Field*>> pola;
    int rozmiar = size;
    int act_level = level;
    int ile_pol = rozmiar * rozmiar;

    for (int i = 0; i < rozmiar; i++)
    {
        std::vector<Field*> wiersz;
        for (int j = 0; j < rozmiar; j++) {
            wiersz.push_back(new Field(resource));
            wiersz[j]->setPosition(j * 31, i * 31);
            wiersz[j]->setPozycja(j * 31, i * 31);
        }
        pola.push_back(wiersz);
        wiersz.clear();
    }

    // Obs�uga okna
    // -------------------------------------------------------------------------------------------------

    Check sprawdz;
    End koniec;
    AiLow ailow;
    AiMedium aimedium;
    sf::Vector2f pozycjamyszki;
    sf::Vector2i pozycjam;
    int wsp_x = 0, wsp_y = 0;
    int licznik = 0;

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
                wsp_x = (int)pozycjamyszki.x / 31;
                wsp_y = (int)pozycjamyszki.y / 31;

                if (pozycjamyszki.x <= (rozmiar * 31) - 1 && pozycjamyszki.y <= (rozmiar * 31) - 1) {
                    if (pola[wsp_y][wsp_x]->isAvailable() == 0) {
                        
                        // Two player play
                        if (act_level == 1) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X", wsp_x, wsp_y)) {
                                    window.close();
                                    window.clear();
                                    koniec.drawEnd("X", resource);
                                }
                            }
                            if (licznik % 2 != 0) {
                                pola[wsp_y][wsp_x]->setText('O');
                                if (sprawdz.czyWygrana(pola, rozmiar, "O", wsp_x, wsp_y)) {
                                    window.close();
                                    window.clear();
                                    koniec.drawEnd("O", resource);
                                }
                                
                            }
                            pola[wsp_y][wsp_x]->setAvailable();
                            licznik++;
                            if (licznik == ile_pol) {
                                window.clear();
                                koniec.drawEnd("NIKT", resource);
                            }
                        }

                        // Low level play
                        if (act_level == 2) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X", wsp_x, wsp_y)) {
                                    window.close();
                                    koniec.drawEnd("X", resource);
                                }
                            }
                            ailow.moveAiLow(pola, size);
                            if (sprawdz.czyWygrana(pola, rozmiar, "O", ailow.getX(), ailow.getY())) {
                                window.close();
                                koniec.drawEnd("O", resource);

                            }
                            pola[wsp_y][wsp_x]->setAvailable();
                            licznik = licznik + 2;
                            if (licznik == ile_pol) {
                                koniec.drawEnd("NIKT", resource);
                            }

                        }

                        // Medium level play
                        if (act_level == 3) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X", wsp_x, wsp_y)) {
                                    window.close();
                                    koniec.drawEnd("X", resource);
                                }
                            }
                            //aimedium.moveAiMedium(pola, size);
                            if (sprawdz.czyWygrana(pola, rozmiar, "O", aimedium.getX(), aimedium.getY())) {
                                window.close();
                                koniec.drawEnd("O", resource);

                            }
                            pola[wsp_y][wsp_x]->setAvailable();
                            licznik = licznik + 2;
                            if (licznik == ile_pol) {
                                koniec.drawEnd("NIKT", resource);
                            }

                        }
                    }
                }
            }
        }

        window.clear();

        // Rysowanie p�l ze znakami
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++) {
                window.draw(pola[i][j]->getButton());
                window.draw(pola[i][j]->getText());
            }
        }

        window.display(); // wy�wietlenie okna
    }
    pola.clear();
}
