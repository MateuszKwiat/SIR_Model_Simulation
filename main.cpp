#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "ExtendedRenderWindow.h"

int main()
{
    float value = 0;
    auto proportions = sf::Vector2f(0.5f, 0.25f);
    auto position = sf::Vector2f(200, 200);
    const std::string str = "Test";
    ExtendedRenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    Slider slider(window,
                  proportions,
                  position,
                  str,
                  &value, 20u, 14u);

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

