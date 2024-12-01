//
// Created by Mateusz Kwiatkowski on 30/11/2024.
//

#include "TextAnnotations.h"
#include <iostream>
#include <format>

TextAnnotations::TextAnnotations(const sf::Vector2f &plot_size, const sf::Vector2f &plot_position,
                                 const std::array<sf::RectangleShape*, 3>& lines) {
    if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/font.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }

    const auto text_position = sf::Vector2f(plot_position.x + plot_size.x / 2.f, plot_position.y + plot_size.y / 20.f);

    plot_label = new sf::Text();
    this->initialize_text(plot_label, text_position, static_cast<unsigned int>(plot_size.y / 15.f), "SIR Proportions");
    this->initialize_y_ticks(plot_size, plot_position, lines);

}

TextAnnotations::~TextAnnotations() {
    delete plot_label;
    for (const auto& y_tick : *y_ticks) {
        delete y_tick;
    }
}

void TextAnnotations::initialize_y_ticks(const sf::Vector2f& plot_size, const sf::Vector2f& plot_position,
                                         const std::array<sf::RectangleShape*, 3>& lines) {
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


void TextAnnotations::initialize_text(sf::Text *text, const sf::Vector2f &position, const unsigned int char_size, const std::string &str) const {
    text->setFont(font);
    text->setString(str);
    text->setCharacterSize(char_size);
    text->setStyle(sf::Text::Bold);
    text->setFillColor(sf::Color::Black);
    text->setOrigin(text->getGlobalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
    text->setPosition(position);
}

