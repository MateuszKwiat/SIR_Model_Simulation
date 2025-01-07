//
// Created by Mateusz Kwiatkowski on 30/11/2024.
//

#include "TextAnnotations.h"
#include <iostream>
#include <format>

TextAnnotations::TextAnnotations(const sf::Vector2f &plot_size,
                                 const sf::Vector2f &plot_position,
                                 const std::array<sf::RectangleShape*, 3>& lines,
                                 const std::array<PopulationBar, 3>& population_bars,
                                 const sf::Vector2f& plot_body_size,
                                 const sf::Font& font) {

    // if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/font.ttf")) {
    //     std::cerr << "Failed to load font." << std::endl;
    // }

    const auto text_position = sf::Vector2f(plot_position.x + plot_size.x / 2.f, plot_position.y + plot_size.y / 20.f);

    plot_label = new sf::Text();
    susceptible_label = new sf::Text();
    infectious_label = new sf::Text();
    recovered_label = new sf::Text();

    this->initialize_text(plot_label, text_position, static_cast<unsigned int>(plot_size.y / 15.f), "SIR Proportions", font);
    this->initialize_y_ticks(plot_size, plot_position, lines, font);
    this->initialize_labels(population_bars, plot_body_size, plot_size, font);
}

TextAnnotations::~TextAnnotations() {
    delete plot_label;
    for (const auto& y_tick : *y_ticks) {
        delete y_tick;
    }
    delete susceptible_label;
    delete infectious_label;
    delete recovered_label;
}

void TextAnnotations::initialize_labels(const std::array<PopulationBar, 3> &population_bars, const sf::Vector2f& plot_body_size,
                                        const sf::Vector2f &plot_size, const sf::Font& font) const {

    const auto char_size = static_cast<unsigned int>(plot_size.y / 20.f);
    constexpr float first_bar_spacing = 5.f;
    const float bar_spacing = (plot_body_size.x - first_bar_spacing) / 8.f;
    auto label_position = sf::Vector2f(population_bars[0].getPosition().x + bar_spacing,
        population_bars[0].getPosition().y + population_bars[0].getSize().y + plot_body_size.y / 18.f);

    const std::array<sf::Text*, 3> labels = {susceptible_label, infectious_label, recovered_label};
    const std::array<std::string, 3> labels_names = {"S: ", "I: ", "R: "};

    for (int i = 0; i < 3; i++) {
        const std::string label_value = std::format("{:.2f}", population_bars[i].getSize().y / plot_body_size.y);
        initialize_text(labels[i], label_position, char_size, labels_names[i] + label_value, font);
        label_position.x += bar_spacing * 3.f;
    }
}


void TextAnnotations::initialize_y_ticks(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                                         const std::array<sf::RectangleShape*, 3>& lines, const sf::Font& font) {
    y_ticks = new std::array<sf::Text*, 5>{};
    constexpr std::array<float, 5> ticks = { 1.f, 0.75f, 0.5f, 0.25f, 0.0f };
    const float distance_between_lines = lines[1]->getPosition().y - lines[0]->getPosition().y;
    auto current_tick_position = sf::Vector2f(plot_position.x + plot_size.x / 18.f, lines[0]->getPosition().y - distance_between_lines);
    int i = 0;
    for (auto& y_tick : *y_ticks) {
        y_tick = new sf::Text(std::format("{:.2f}", ticks[i++]), font, static_cast<unsigned int>(plot_size.y / 25.f));
        y_tick->setPosition(sf::Vector2f(current_tick_position.x - y_tick->getGlobalBounds().width / 2.f, current_tick_position.y - y_tick->getGlobalBounds().height / 2.f));
        y_tick->setFillColor(sf::Color::Black);
        current_tick_position.y += distance_between_lines;
    }
}

void TextAnnotations::initialize_text(sf::Text *text, const sf::Vector2f &position, const unsigned int char_size,
                                      const std::string &str, const sf::Font& font) const {
    text->setFont(font);
    text->setString(str);
    text->setCharacterSize(char_size);
    text->setStyle(sf::Text::Bold);
    text->setFillColor(sf::Color::Black);
    text->setOrigin(text->getGlobalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
    text->setPosition(position);
}

