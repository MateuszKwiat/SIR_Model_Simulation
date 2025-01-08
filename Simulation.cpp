//
// Created by Mateusz Kwiatkowski on 08/01/2025.
//

#include "Simulation.h"

Simulation::Simulation() {
    gen = new std::mt19937(rd());
    window = new ExtendedRenderWindow (sf::VideoMode({1920, 1080}), "SIR Simulation");
    window->setFramerateLimit(120);
    font = new sf::Font();
    if(!font->openFromFile("../font.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }
    this->initialize_test_objects();
}

Simulation::~Simulation() {
    delete font;
    delete gen;
    delete window;
    delete slider;
    delete populations_plot;
    delete simulation_window;
}

void Simulation::initialize_test_objects() {
    // ================================== Slider =========================================
    float value = 0.5f;
    constexpr auto size = sf::Vector2f(200.f, 60.f);
    constexpr auto position = sf::Vector2f(420.f, 40.f);
    const std::string str = "Test";
    slider = new Slider(*window,
                  size,
                  position,
                  str,
                  &value, 20u, 14u,
                  *font);

    // =================================== Plot ==========================================
    constexpr unsigned int c1 = 50u;
    constexpr unsigned int c2 = 60u;
    constexpr unsigned int c3 = 20u;
    populations_plot = new PopulationsProportionsPlot(sf::Vector2f(10.f, 10.f), sf::Vector2f(300.f, 300.f),
        &c1, &c2, &c3, c1 + c2 + c3, *font);

    // ============================= Simulation window ===================================
    constexpr auto sim_size = sf::Vector2f(200.f, 200.f);
    constexpr auto sim_position = sf::Vector2f(530.f, 10.f);
    simulation_window = new SimulationWindow(sim_position, sim_size,2.f, *gen);

    // ================================== Button =========================================
    constexpr auto button_size = sf::Vector2f(100.f, 50.f);
    constexpr auto button_position = sf::Vector2f(740.f, 10.f);
    button = new Button(button_position, button_size, "Hello!", *font);
}

void Simulation::run() const {
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
            else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>())
                if (key_pressed->scancode == sf::Keyboard::Scancode::Escape)
                    window->close();
        }

        this->handle_updates();
        this->handle_drawing();
    }
}

void Simulation::handle_drawing() const {
    window->clear();

    window->draw(*populations_plot);
    window->draw(*slider);
    window->draw(*simulation_window);
    window->draw(*button);

    window->display();
}

void Simulation::handle_updates() const {
    simulation_window->update();
    slider->update(*window);
    button->is_pressed(*window);
}
