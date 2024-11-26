//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#include "PopulationsProportionsPlot.h"

PopulationsProportionsPlot::PopulationsProportionsPlot(const sf::Vector2f& position, const sf::Vector2f& size, const unsigned int* susceptible_count,
                               const unsigned int* infectious_count, const unsigned int* recovered_count, unsigned int population_count)
                                   : population_count(population_count) {
    this->setPosition(position);
    this->setSize(size);
    this->setFillColor(sf::Color::White);
    this->susceptible_count = susceptible_count;
    this->infectious_count = infectious_count;
    this->recovered_count = recovered_count;
    this->initialize_plot_body();
    this->initialize_bars();
}

void PopulationsProportionsPlot::initialize_plot_body() {
    constexpr float plot_body_proportion = 1.f / 8.f;
    plot_body.setPosition(sf::Vector2f(this->getPosition().x + this->getSize().x * plot_body_proportion,
                                       this->getPosition().y + this->getSize().y * plot_body_proportion));

    plot_body.setSize(sf::Vector2f(this->getSize().x - this->getSize().x * plot_body_proportion,
                                   this->getSize().y - this->getSize().y * plot_body_proportion * 2.f));

    plot_body.setFillColor(sf::Color::Black);
}

void PopulationsProportionsPlot::initialize_single_bar(PopulationBar** bar, const sf::Color &color, const unsigned int count,
                                                       const float bars_spacing, sf::Vector2f &current_position) {
    const float bar_height = this->getSize().y * (static_cast<float>(count) / static_cast<float>(population_count));
    *bar = new PopulationBar(sf::Vector2f(bars_spacing * 2, bar_height), color);
    current_position.y = this->getPosition().y + (this->getSize().y - bar_height);
    (*bar)->setPosition(current_position);
    current_position.x += bars_spacing * 3;
}

void PopulationsProportionsPlot::initialize_bars() {
    const float bars_spacing = this->getSize().x / 8.f;
    float bar_height = 0.f;
    sf::Vector2f current_position = this->getPosition();

    initialize_single_bar(&susceptible_population_bar, sf::Color::Green, *susceptible_count, bars_spacing, current_position);
    initialize_single_bar(&infectious_population_bar, sf::Color::Red, *infectious_count, bars_spacing, current_position);
    initialize_single_bar(&recovered_population_bar, sf::Color::White, *recovered_count, bars_spacing, current_position);
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
