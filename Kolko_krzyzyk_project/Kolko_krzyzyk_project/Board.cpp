#include "Board.h"
#include <typeinfo>
#include <SFML/System.hpp>

void Board::DrawBoard(int size, int level, ResourceMenager* resource)
{
    sf::RenderWindow window(sf::VideoMode(size * 31, size * 31), "Kolko i krzyzyk"); // tworzenie okna
    
    // Ograniczenie liczby klatek na sekundê
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(5);
    
    int rozmiar = size;
    int act_level = level;
    int ile_pol = rozmiar * rozmiar;
    int wsp_x = 0, wsp_y = 0, licznik = 0;

    Check sprawdz;
    End koniec;
    AiLow ailow;
    AiMedium aimedium;

    std::vector <std::vector <Field*>> pola;
    sf::Vector2f pozycjamyszki;

    for (int i = 0; i < rozmiar; i++)
    {
        std::vector<Field*> wiersz;
        for (int j = 0; j < rozmiar; j++) {
            wiersz.push_back(new Field(resource));
            wiersz[j]->setPosition(j * 31, i * 31);
        }
        pola.push_back(wiersz);
        wiersz.clear();
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                pozycjamyszki = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                wsp_x = (int)pozycjamyszki.x / 31;
                wsp_y = (int)pozycjamyszki.y / 31;

                if (pozycjamyszki.x <= (rozmiar * 31) - 1 && pozycjamyszki.y <= (rozmiar * 31) - 1) {
                    if (pola[wsp_y][wsp_x]->isAvailable() == 0) {
                        
                        // Plan gry gracz vs gracz
                        if (act_level == 1) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X")) {
                                    window.close();
                                    window.clear();
                                    koniec.drawEnd("X", resource);
                                }
                            }
                            if (licznik % 2 != 0) {
                                pola[wsp_y][wsp_x]->setText('O');
                                if (sprawdz.czyWygrana(pola, rozmiar, "O")) {
                                    window.close();
                                    window.clear();
                                    koniec.drawEnd("O", resource);
                                }
                            }
                            
                            pola[wsp_y][wsp_x]->setUnAvailable();
                            licznik++;
                            
                            if (licznik == ile_pol) {
                                window.clear();
                                koniec.drawEnd("NIKT", resource);
                            }
                        }

                        // Plan gry gracz vs s³aby komputer
                        if (act_level == 2) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X")) {
                                    window.close();
                                    koniec.drawEnd("X", resource);
                                }
                            }
                            
                            ailow.moveAiLow(pola, size);
                            
                            if (sprawdz.czyWygrana(pola, rozmiar, "O")) {
                                window.close();
                                koniec.drawEnd("O", resource);

                            }
                            
                            pola[wsp_y][wsp_x]->setUnAvailable();
                            licznik = licznik + 2;
                            
                            if (licznik == ile_pol) {
                                koniec.drawEnd("NIKT", resource);
                            }

                        }

                        // Plan gry gracz vs s³aby komputer
                        if (act_level == 3) {
                            if (licznik % 2 == 0) {
                                pola[wsp_y][wsp_x]->setText('X');
                                if (sprawdz.czyWygrana(pola, rozmiar, "X")) {
                                    window.close();
                                    koniec.drawEnd("X", resource);
                                }
                            }

                            aimedium.moveAiMedium(pola, size);

                            if (sprawdz.czyWygrana(pola, rozmiar, "O")) {
                                window.close();
                                koniec.drawEnd("O", resource);

                            }

                            pola[wsp_y][wsp_x]->setUnAvailable();
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

        // Rysowanie planszy
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++) {
                window.draw(pola[i][j]->getButton());
                window.draw(pola[i][j]->getText());
            }
        }
        window.display();
    }
    pola.clear();
}
