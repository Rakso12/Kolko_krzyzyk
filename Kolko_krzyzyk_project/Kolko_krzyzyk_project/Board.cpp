#include "Board.h"
#include <typeinfo>

void Board::DrawBoard()
{

    // Wst�pne tworzenie obiekt�w do planszy
    // ------------------------------------------------------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(400, 400), "Kolko i krzyzyk"); // tworzenie okna

    std::vector <std::vector <Field*>> pola;
    int rozmiar = 6;

    for (int i = 0; i < rozmiar; i++)
    {
        std::vector<Field*> wiersz;
        for (int j = 0; j < rozmiar; j++) {
            wiersz.push_back(new Field());
            wiersz[j]->setPosition(j * 31, i * 31);
            wiersz[j]->setPozycja(j * 31, i * 31);
        }
        pola.push_back(wiersz);
        wiersz.clear();
    }

    // Obs�uga okna
    // -------------------------------------------------------------------------------------------------

    Check sprawdz;
    sf::Vector2f pozycjamyszki;
    sf::Vector2i pozycjam;
    int wsp_x = 0, wsp_y = 0;
    //char znak = 'X';
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
                wsp_x = (int) pozycjamyszki.x/31;
                wsp_y = (int) pozycjamyszki.y/31;
                
                if(pozycjamyszki.x <= (rozmiar * 31)-1 && pozycjamyszki.y <= (rozmiar * 31)-1)
                    if (pola[wsp_y][wsp_x]->isAvailable() == 0) {
                        if (licznik % 2 == 0){
                            pola[wsp_y][wsp_x]->setText('X');
                            sprawdz.czyWygrana(pola, rozmiar, "X");
                        }
                        if (licznik % 2 != 0) {
                            pola[wsp_y][wsp_x]->setText('O');
                            sprawdz.czyWygrana(pola, rozmiar, "O");
                        }
                        pola[wsp_y][wsp_x]->setAvailable();
                        licznik++;

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
