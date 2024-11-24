//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "Slider.h"
#include "PopulationsProportionsPlot.h"

class ExtendedRenderWindow final : public sf::RenderWindow {
public:
    using sf::RenderWindow::draw;
    ExtendedRenderWindow(sf::VideoMode video_mode, const char * str);
    ExtendedRenderWindow() = default;
    void draw(const Slider& slider);
    void draw(const PopulationsProportionsPlot& plot);
};
