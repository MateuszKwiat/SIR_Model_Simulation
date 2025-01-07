#include <iostream>
#include <SFML/Graphics.hpp>

#include "Slider.h"
#include "ExtendedRenderWindow.h"
#include "PopulationsProportionsPlot.h"
#include "SimulationWindow.h"

int main()
{
    ExtendedRenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    // window.setFramerateLimit(500);
    sf::Font font;
    if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/font.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }
    // ================================== Slider =========================================
    float value = 0.5f;
    auto size = sf::Vector2f(200.f, 60.f);
    auto position = sf::Vector2f(420.f, 40.f);
    const std::string str = "Test";
    Slider slider(window,
                  size,
                  position,
                  str,
                  &value, 20u, 14u,
                  font);

    // =================================== Plot ==========================================
    unsigned int c1 = 50u;
    unsigned int c2 = 60u;
    unsigned int c3 = 20u;
    PopulationsProportionsPlot plot(sf::Vector2f(10.f, 10.f), sf::Vector2f(300.f, 300.f),
        &c1, &c2, &c3, c1 + c2 + c3, font);

    // ============================= Simulation window ===================================
    auto sim_size = sf::Vector2f(200.f, 200.f);
    auto sim_position = sf::Vector2f(530.f, 10.f);
    SimulationWindow sim(sim_position, sim_size);

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
        sim.test_particle();

        slider.update(window);

        window.clear();
        window.draw(plot);
        window.draw(slider);
        window.draw(sim);

        window.display();
    }

    return 0;
}

