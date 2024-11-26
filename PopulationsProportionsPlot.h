//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "PopulationBar.h"

class PopulationsProportionsPlot : public sf::RectangleShape {
private:
    sf::RectangleShape* plot_body{};
    PopulationBar* susceptible_population_bar{};
    PopulationBar* infectious_population_bar{};
    PopulationBar* recovered_population_bar{};
    const unsigned int* susceptible_count{};
    const unsigned int* infectious_count{};
    const unsigned int* recovered_count{};
    const unsigned int population_count{};

private:
    void update_sizes();
    void initialize_bars();
    void initialize_single_bar(PopulationBar** bar, const sf::Color &color, unsigned int count,
                               float bars_spacing, sf::Vector2f &current_position);
    void initialize_plot_body();

public:
    PopulationsProportionsPlot(const sf::Vector2f& position, const sf::Vector2f& size, const unsigned int* susceptible_count,
                               const unsigned int* infectious_count, const unsigned int* recovered_count, unsigned int population_count);
    ~PopulationsProportionsPlot();
    void update();

    friend class ExtendedRenderWindow;
};
