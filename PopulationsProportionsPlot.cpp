//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#include "PopulationsProportionsPlot.h"

PopulationsProportionsPlot::PopulationsProportionsPlot(const sf::Vector2f& position,
                                                       const sf::Vector2f& size,
                                                       const unsigned int* susceptible_count,
                                                       const unsigned int* infectious_count,
                                                       const unsigned int* recovered_count,
                                                       unsigned int population_count,
                                                       const sf::Font& font) : population_count(population_count) {
    this->setPosition(position);
    this->setSize(size);
    // this->setFillColor(sf::Color(249, 250, 250, 255));
    this->setFillColor(sf::Color(44, 46, 48, 255));
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1);
    this->susceptible_count = susceptible_count;
    this->infectious_count = infectious_count;
    this->recovered_count = recovered_count;

    this->initialize_plot_body();
    this->initialize_bars();

    text_annotations = new TextAnnotations(this->getSize(), this->getPosition(), *plot_body->get_lines(),
        {*susceptible_population_bar, *infectious_population_bar, *recovered_population_bar },
        plot_body->getSize(), font);
}

void PopulationsProportionsPlot::initialize_plot_body() {
    constexpr float plot_body_proportion = 1.f / 9.f;
    plot_body = new PlotBody(this->getPosition(), this->getSize(), plot_body_proportion);
}

void PopulationsProportionsPlot::initialize_single_bar(PopulationBar** bar, const sf::Color &color, const unsigned int count,
                                                       const float bars_spacing, sf::Vector2f &current_position) const {
    const float bar_height = plot_body->getSize().y * (static_cast<float>(count) / static_cast<float>(population_count));
    *bar = new PopulationBar(sf::Vector2f(bars_spacing * 2, bar_height), color);
    current_position.y = plot_body->getPosition().y + (plot_body->getSize().y - bar_height);
    (*bar)->setPosition(current_position);
    current_position.x += bars_spacing * 3;
}

void PopulationsProportionsPlot::initialize_bars() {
    constexpr float first_bar_spacing = 5.f;
    const float bars_spacing = (plot_body->getSize().x - first_bar_spacing) / 8.f;
    auto current_position = sf::Vector2f(plot_body->getPosition().x + first_bar_spacing, plot_body->getSize().y);

    initialize_single_bar(&susceptible_population_bar, sf::Color(68, 107, 118, 255),
                          *susceptible_count, bars_spacing, current_position);

    initialize_single_bar(&infectious_population_bar, sf::Color(230, 121, 101, 255),
                          *infectious_count, bars_spacing, current_position);

    initialize_single_bar(&recovered_population_bar, sf::Color(78, 77, 77, 255),
                          *recovered_count, bars_spacing, current_position);
}

PopulationsProportionsPlot::~PopulationsProportionsPlot() {
    delete plot_body;
    delete susceptible_population_bar;
    delete infectious_population_bar;
    delete recovered_population_bar;
    delete text_annotations;
}

void PopulationsProportionsPlot::update() {

}
