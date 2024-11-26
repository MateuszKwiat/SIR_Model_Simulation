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
}
