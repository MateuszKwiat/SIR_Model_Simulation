//
// Created by Mateusz Kwiatkowski on 08/01/2025.
//

#include "Button.h"

Button::Button(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &str, const sf::Font &font) : got_pressed(false){
    this->setPosition(position);
    this->setSize(size);
    text = new sf::Text(font, str, 20u);
    not_pressed_color = sf::Color(44, 46, 48);
    pressed_color = sf::Color(32, 34, 36);
    this->setFillColor(not_pressed_color);
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1);

    // text
    const auto text_position = sf::Vector2f(position.x + size.x / 2.f,
                                            position.y + size.y / 2.f);
    const auto text_origin = sf::Vector2f(text->getGlobalBounds().position.x + text->getGlobalBounds().size.x / 2.f,
                                          text->getGlobalBounds().position.y + text->getGlobalBounds().size.y / 2.f);
    text->setOrigin(text_origin);
    text->setPosition(text_position);
    text->setFillColor(sf::Color::White);
}

Button::~Button() {
    delete text;
}

bool Button::is_pressed(const sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
        this->getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
        this->setFillColor(pressed_color);
        got_pressed = true;
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && got_pressed) {
        this->setFillColor(not_pressed_color);
        got_pressed = false;
        return true;
    }
    return false;
}


