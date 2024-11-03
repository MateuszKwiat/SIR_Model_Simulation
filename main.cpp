#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "ExtendedRenderWindow.h"

int main()
{
    float value = 0;
    ExtendedRenderWindow window(sf::VideoMode(400, 400), "SFML works!");
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

        window.draw(slider);

        window.display();
    }

    return 0;
}