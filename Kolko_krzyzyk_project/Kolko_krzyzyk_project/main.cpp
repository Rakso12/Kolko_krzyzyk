//ten super main którego musze zapisaæ
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Taka fajna dupa");
    sf::RectangleShape kwadrat;

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