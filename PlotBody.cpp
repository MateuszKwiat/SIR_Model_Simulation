//
// Created by Mateusz Kwiatkowski on 26/11/2024.
//

#include "PlotBody.h"

PlotBody::PlotBody(const sf::Vector2f& plot_position, const sf::Vector2f& plot_size, float plot_body_proportion) {
    this->setPosition(sf::Vector2f(plot_position.x + plot_size.x * plot_body_proportion,
                                       plot_position.y + plot_size.y * plot_body_proportion));

    this->setSize(sf::Vector2f(plot_size.x - plot_size.x * plot_body_proportion,
                                   plot_size.y - plot_size.y * plot_body_proportion * 2.f));

    this->setFillColor(sf::Color::Black);

    this->initialize_lines();
}

void PlotBody::initialize_lines() {
    auto current_position = sf::Vector2f(this->getPosition().x, this->getPosition().y + this->getSize().y / 4.f);
    const auto line_size = sf::Vector2f(this->getSize().x, 1.f);

    for (auto & line : lines) {
        line = new sf::RectangleShape();
        line->setSize(line_size);
        line->setOrigin(line->getPosition().x, line->getSize().y / 2);
        line->setPosition(current_position);
        line->setFillColor(sf::Color::White);
        current_position.y += this->getSize().y / 4.f;
    }
}
