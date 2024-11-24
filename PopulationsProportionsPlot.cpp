//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#include "PopulationsProportionsPlot.h"

PopulationsProportionsPlot::PopulationsProportionsPlot(const sf::Vector2f& position, const sf::Vector2f& size, const unsigned int* susceptible_count,
                               const unsigned int* infectious_count, const unsigned int* recovered_count, unsigned int population_count)
                                   : population_count(population_count) {
    this->setPosition(position);
    this->setSize(size);
    this->setFillColor(sf::Color::Transparent);
    this->susceptible_count = susceptible_count;
    this->infectious_count = infectious_count;
    this->recovered_count = recovered_count;
    this->initialize_bars();
}

void PopulationsProportionsPlot::initialize_bars() {
    const float bars_spacing = this->getSize().x / 8.f;
    sf::Vector2f current_position = this->getPosition();

    susceptptible_bar_size = sf::Vector2f(bars_spacing * 2, );
    susceptible_population_bar = new PopulationBar(current_position, sf::Vector2f(bars_spacing * 2, size.y), sf::Color::Green);
    current_position.x += bars_spacing * 3;
    infectious_population_bar = new PopulationBar(current_position, sf::Vector2f(bars_spacing * 2, size.y), sf::Color::Red);
    current_position.x += bars_spacing * 3;
    recovered_population_bar = new PopulationBar(current_position, sf::Vector2f(bars_spacing * 2, size.y), sf::Color::White);

}

PopulationsProportionsPlot::~PopulationsProportionsPlot() {
    delete susceptible_population_bar;
    delete infectious_population_bar;
    delete recovered_population_bar;
}

void PopulationsProportionsPlot::update_sizes() {

}

void PopulationsProportionsPlot::update() {

}
