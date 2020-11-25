#include "Board.h"

void Board::DrawBoard()
{
    // Wstêpne tworzenie obiektów do planszy
    // ------------------------------------------------------------------------------------------------
    sf::RenderWindow window(sf::VideoMode(400, 400), "Kó³ko i krzy¿yk"); // tworzenie okna
    
    std::vector <Field*> pola;
    int rozmiar = 7;
    int x = 0;
    int y = 0;
    for (int i = 0; i < rozmiar * rozmiar; i++)
    {
        pola.push_back(new Field);
        if (i % rozmiar == 0 && i != 0) {
            x = 0;
            y++;
        }
        pola[i]->setPosition(int(x * 31), int(y * 31));
        pola[i]->setPozycja(int(x * 31), int(y * 31));
        x++;
    }

    // Obs³uga okna
    // -------------------------------------------------------------------------------------------------

    sf::Vector2f pozycjamyszki;
    sf::Vector2i pozycjam;
    int xxx;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) {
                pozycjam = sf::Mouse::getPosition(window);
                pozycjamyszki = window.mapPixelToCoords(pozycjam);
                xxx = pozycjamyszki.x; // NIE DZIALA X -> Pozycja x myszzki DO NAPRAWY
                    if (int(pozycjamyszki.x) >= 0 && int(pozycjamyszki.x) < 30)
                    {
                        // ta
                    }
            }
        }

        window.clear();

        pola[2]->setText('X');
        pola[3]->setText('O');

        // Rysowanie pól ze znakami
        for (int i = 0; i < rozmiar * rozmiar; i++)
        {
            window.draw(pola[i]->getButton());
            window.draw(pola[i]->getText());
        }
        window.display(); // wyœwietlenie okna
    }
    // zwalnianie pamieci TODO
}
