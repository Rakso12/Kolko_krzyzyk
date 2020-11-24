#include <SFML/Graphics.hpp>
#include "Field.h"
#include <iostream>

#include <vector>

int main(){
    sf::RenderWindow window(sf::VideoMode(400, 400), "K�ko i krzy�yk"); // tworzenie okna
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
        pola[i]->setPosition(x * 31, y * 31);
        x++;
    }

    while (window.isOpen()) // je�li plik otwarty wykonuj
    {
        sf::Event event; // klasa zdarzenia, co zostanie wykonane zapisuje si� w obiekcie "event"
        while (window.pollEvent(event)) // nas�uchiwanie zdarze�
        {
            if (event.type == sf::Event::Closed) // je�li event ma typ Closed (zamkni�cie Xem) to zamknij okno
                window.close();
        }

        window.clear();

        for (int i = 0; i < rozmiar * rozmiar; i++)
        {
            window.draw(pola[i]->getButton());
            window.draw(pola[i]->getText());
        }

        window.display(); // wy�wietlenie okna
    }

    for (int i = 0; i < rozmiar * rozmiar; i++)
    {
        free(pola[i]);
    }
    return 0;
}