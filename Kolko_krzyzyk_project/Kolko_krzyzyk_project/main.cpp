//ten super main którego musze zapisaæ
#include <SFML/Graphics.hpp>

/*
int main()
{
<<<<<<< HEAD
    sf::RenderWindow window(sf::VideoMode(400, 400), "Kó³ko i krzy¿yk"); // tworzenie okna

    std::vector <Field*> pola;
    int rozmiar = 6;
    int x = 0;
    int y = 0;
    for (int i = 0; i < rozmiar * rozmiar; i++) 
    {   
        pola.push_back(new Field);
        if (i % rozmiar == 0 && i != 0 ) {
            x = 0;
            y++;
        }
        pola[i]->setPosition(x * 31, y * 31);
        x++;
    }

    

 // tworzenie obiektu klasy pole(Field)
=======
    sf::RenderWindow window(sf::VideoMode(400, 400), "Taka fajna dupa");
    sf::RectangleShape pole1;
>>>>>>> parent of e2272b3... dodanie klasy Field i rysowanie planszy

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

<<<<<<< HEAD
        window.clear(); //czyszczenie okna
        

        for (int i = 0; i < rozmiar * rozmiar; i++)
        {
            window.draw(pola[i]->getButton());
            window.draw(pola[i]->getText());
        }
        window.display();
        //pola[5]->setText('O');
        sf::sleep( sf::seconds(1));

        window.clear();

        for (int i = 0; i < rozmiar * rozmiar; i++)
        {
            window.draw(pola[i]->getButton());
            window.draw(pola[i]->getText());
        }

        window.display(); // wyœwietlenie okna
=======
        window.clear();  
        window.draw(kwadrat);
        window.display();
>>>>>>> parent of e2272b3... dodanie klasy Field i rysowanie planszy

    }

    return 0;
}
*/
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void plansza(vector <char> tablica, int rozmiar){ //wypisywanie wyniku na planszy
    for (int i = 0; i < rozmiar * rozmiar; i++)
    {
        cout << tablica[i];
        if (i + 1 % rozmiar != 0) {
            cout << '|';
        }
        if(i % rozmiar-2 == 0 && i != (rozmiar * rozmiar) - 1 ){
            cout << endl;
            for (int j = 0; j < ( rozmiar * 2 ) - 3; j++) {
                cout << "_ ";
            }
            cout << endl;
        }
    }
}

void ruch(vector <char> &tablica_wynikow, char znak){
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
}

void wygrana(bool wygrana, vector <char> &tablica_wynikow, char znak) {
    //  TODO: uzupe³niæ funkcje sprawdzania wygranej po ruchu
    // Sprawdzanie wiersza, kolumny i przek¹tnych dla danego ruchu ewentualnie sprawdzanie x+1 x-1 y-1 y+1 i przek¹tynych od postawionego znaku
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
        plansza(tablica_wynikow, rozmiar);// nadpisywanie tabeli

        if (licznik_ruchow % 2 == 0) { // ruch krzy¿yka
            znak = 'X';
            ruch(tablica_wynikow, znak);
            system("cls");
            licznik_ruchow++;
            continue;
        }

        if (licznik_ruchow % 2 != 0) { // ruch kó³ka
            znak = 'O';

            ruch(tablica_wynikow, znak);
            system("cls");
            licznik_ruchow++;
            continue;
        }
    }

    
    return 0;
}