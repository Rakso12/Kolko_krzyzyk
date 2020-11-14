//ten super main którego musze zapisaæ
#include <SFML/Graphics.hpp>

/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Taka fajna dupa");
    sf::RectangleShape pole1;

    kwadrat.setSize(sf::Vector2f(100,100));
    kwadrat.setFillColor(sf::Color::Blue);
    kwadrat.setPosition(sf::Vector2f(200,200));
    kwadrat.setOrigin(kwadrat.getSize().x/2,kwadrat.getSize().y/2);

    while (window.isOpen())
    {
        sf::Event event; // klasa zdarzenia :) zdarzenia z okna odczytaj¹ sie w event 
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();  
        window.draw(kwadrat);
        window.display();

    }

    return 0;
}
*/
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void plansza(vector <int> tablica) //wypisywanie wyniku na planszy
{
    for (int i = 0; i < 9; i++)
    {
        cout << tablica[i] << " ";
        if(i == 2 || i == 5){
            cout << endl;
        }
    }
}


int main(){
    int rozmiar;
    vector <int> tablica_wynikow;
    cout << "Podaj rozmiar ";
    cin >> rozmiar ;
    for (int i = 0; i < rozmiar*rozmiar; i++){
        tablica_wynikow.push_back(0);
    }
    
    plansza(tablica_wynikow);

    cout << endl << endl;
    for (int i = 0; i < tablica_wynikow.size(); i++)
    {
        tablica_wynikow[i] = i;
    }

    plansza(tablica_wynikow);

    return 0;
}