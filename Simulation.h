//
// Created by Mateusz Kwiatkowski on 08/01/2025.
//
#pragma once
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "Slider.h"
#include "ExtendedRenderWindow.h"
#include "PopulationsProportionsPlot.h"
#include "SimulationWindow.h"

class Simulation {
private:
    std::random_device rd;
    std::mt19937* gen = nullptr;
    ExtendedRenderWindow* window = nullptr;
    sf::Font* font = nullptr;

    // TEST OBJECTS
    Slider* slider = nullptr;
    PopulationsProportionsPlot* populations_plot = nullptr;
    SimulationWindow* simulation_window = nullptr;

private:
    void initialize_test_objects();
public:
    Simulation();
    ~Simulation();
    void run() const;
};



