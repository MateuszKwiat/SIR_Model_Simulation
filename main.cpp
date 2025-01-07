#include <iostream>
#include <SFML/Graphics.hpp>

#include "Slider.h"
#include "ExtendedRenderWindow.h"
#include "PopulationsProportionsPlot.h"

int main()
{
    ExtendedRenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    float value = 0.5f;
    auto size = sf::Vector2f(200.f, 60.f);
    auto position = sf::Vector2f(600, 200);
    const std::string str = "Test";
    Slider slider(window,
                  size,
                  position,
                  str,
                  &value, 20u, 14u);
    unsigned int c1 = 50u;
    unsigned int c2 = 60u;
    unsigned int c3 = 20u;
    PopulationsProportionsPlot plot(sf::Vector2f(50.f, 50.f), sf::Vector2f(300.f, 300.f),
        &c1, &c2, &c3, c1 + c2 + c3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        slider.update(window);

        window.clear();
        window.draw(plot);
        window.draw(slider);

        window.display();
    }

    return 0;
}

