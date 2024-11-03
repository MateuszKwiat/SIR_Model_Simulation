//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//

//  TODO
// get rid of random values, make it work based on proportions and window size
// add responsiveness to mouse
// finally make it possible to change the value of value XD

#include "Slider.h"

#include <iostream>

Slider::Slider(const sf::RenderWindow& window, float* val) {
    value = val;
    this->initialize_slider_body(window);
    this->initialize_slider_range();
    this->initialize_slider();
    this->initialize_slider_range();
    this->initialize_texts();
}

void Slider::initialize_slider() {
    const auto size = sf::Vector2f(15.f, 25.f);
    const auto origin = sf::Vector2f(size.x / 2, size.y / 2);
    const auto position = slider_range->getPosition();

    slider = new sf::RectangleShape(size);
    slider->setOrigin(origin);
    slider->setPosition(position);
    slider->setFillColor(sf::Color::Red);
}

void Slider::initialize_slider_body(const sf::RenderWindow& window) {
    const auto size = sf::Vector2f(160.f, 70.f);
    const auto origin = sf::Vector2f(size.x / 2.f, size.y / 2.f);
    const auto position = sf::Vector2f(static_cast<float>(window.getSize().x) / 2.f,
                                       static_cast<float>(window.getSize().y) / 2.f);

    slider_body = new sf::RectangleShape(size);
    slider_body->setOrigin(origin);
    slider_body->setPosition(position);
    slider_body->setFillColor(sf::Color::White);
}

void Slider::initialize_slider_range() {
    const auto size = sf::Vector2f(120.f, 15.f);
    const auto origin = sf::Vector2f(size.x / 2.f, size.y / 2.f);
    const auto position = sf::Vector2f(slider_body->getPosition().x,slider_body->getPosition().y + slider_body->getSize().y / 5.f);

    slider_range = new sf::RectangleShape(size);
    slider_range->setOrigin(origin);
    slider_range->setPosition(position);
    slider_range->setFillColor(sf::Color::Black);
}

void Slider::initialize_texts() {
    label = new sf::Text();
    range_low = new sf::Text();
    range_high = new sf::Text();

    if(!font.loadFromFile("/Users/mateuszkwiatkowski/Projects/sir_model_simulation/PixeloidMono-d94EV.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }

    auto position = sf::Vector2f(slider_body->getPosition().x, slider_body->getPosition().y - slider_body->getSize().y / 3.5f);
    this->initialize_single_text(*label, "Test: 0.5", position, 20u);

    position = sf::Vector2f(slider_range->getPosition().x - slider_range->getSize().x / 2.f - 10.f, slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_low, "0", position, 15u);

    position = sf::Vector2f(slider_range->getPosition().x + slider_range->getSize().x / 2.f + 10.f, slider_range->getPosition().y - slider_range->getSize().y / 4.f);
    this->initialize_single_text(*range_high, "1", position, 15u);
}

void Slider::initialize_single_text(sf::Text& text, const std::string& str, const sf::Vector2f& position, unsigned int char_size) const {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(char_size);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
    text.setPosition(position);
}

void Slider::draw(sf::RenderWindow& window) const {
    window.draw(*slider_body);
    window.draw(*slider_range);
    window.draw(*slider);
    window.draw(*label);
    window.draw(*range_low);
    window.draw(*range_high);
}

void Slider::update(float& x) {

}

Slider::~Slider() {
    delete slider_body;
    delete slider_range;
    delete slider;
}