//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "PopulationBar.h"

class PopulationsProportionsPlot : public sf::RectangleShape {
private:
    PopulationBar* susceptible_population_bar{};
    PopulationBar* infectious_population_bar{};
    PopulationBar* recovered_population_bar{};
    const unsigned int* susceptible_count{};
    const unsigned int* infectious_count{};
    const unsigned int* recovered_count{};
    sf::Vector2f susceptible_bar_size{};
    sf::Vector2f infectious_bar_size{};
    sf::Vector2f recovered_bar_size{};
    const unsigned int population_count{};

private:
    void update_sizes();
    void initialize_bars();

public:
    PopulationsProportionsPlot(const sf::Vector2f& position, const sf::Vector2f& size, const unsigned int* susceptible_count,
                               const unsigned int* infectious_count, const unsigned int* recovered_count, unsigned int population_count);
    ~PopulationsProportionsPlot();
    void update();
    const PopulationBar* get_susceptible_population_bar() const {return susceptible_population_bar;}
    const PopulationBar* get_infectious_population_bar() const {return infectious_population_bar;}
    const PopulationBar* get_recovered_population_bar() const {return recovered_population_bar;}
};
