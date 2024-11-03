#include <SFML/Graphics.hpp>
#include "Slider.h"

int main()
{
    float value = 0;
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    Slider slider(window, &value);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        slider.draw(window);

        window.display();
    }

    return 0;
}