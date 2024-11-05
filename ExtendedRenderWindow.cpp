//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//

#include "ExtendedRenderWindow.h"

ExtendedRenderWindow::ExtendedRenderWindow(sf::VideoMode video_mode, const char *str) : sf::RenderWindow(video_mode, *str) {}

void ExtendedRenderWindow::draw(const Slider &slider) {
    RenderWindow::draw(*slider.slider_body);
    RenderWindow::draw(*slider.slider_range);
    RenderWindow::draw(*slider.slider);
    RenderWindow::draw(*slider.label);
    RenderWindow::draw(*slider.range_low);
    RenderWindow::draw(*slider.range_high);
}
