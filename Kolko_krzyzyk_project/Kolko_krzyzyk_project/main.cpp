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

void plansza(vector <char> tablica){ //wypisywanie wyniku na planszy
    for (int i = 0; i < 9; i++)
    {
        cout << tablica[i] << " ";
        if(i == 2 || i == 5){
            cout << endl;
        }
    }
}

void ruch(vector <char> tablica_wynikow, char znak){
    int miejsce;
    cout << "Podaj index pola";
    cin >> miejsce;
    if (tablica_wynikow[miejsce] == ' ') {
        tablica_wynikow[miejsce] = znak;
    }
    else {
        cout << "Dane miejsce jest zajête!!!";
        ruch(tablica_wynikow, znak);
    }
    plansza(tablica_wynikow);
}


int main(){
    int rozmiar, licznik_ruchow = 0;
    char znak;
    bool wygrana = false;

    vector <char> tablica_wynikow;

    cout << "Podaj rozmiar ";  // generowanie planszy o podanych rozmiarach
    cin >> rozmiar ;
    for (int i = 0; i < rozmiar*rozmiar; i++){
        tablica_wynikow.push_back(' ');
    }
    
    while (wygrana == false){
         // nadpisywanie tabeli

        if (licznik_ruchow % 2 == 0) { // ruch krzy¿yka
            znak = 'X';
            ruch(tablica_wynikow, znak);
            system("cls");
            continue;
        }

        if (licznik_ruchow % 2 != 0) { // ruch kó³ka
            znak = 'O';

            ruch(tablica_wynikow, znak);
            system("cls");
            continue;
        }
        licznik_ruchow++;
    }

    
    return 0;
}