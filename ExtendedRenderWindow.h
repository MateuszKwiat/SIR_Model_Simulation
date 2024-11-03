//
// Created by Mateusz Kwiatkowski on 03/11/2024.
//
#pragma once

#include <SFML/Graphics.hpp>
#include "Slider.h"

class ExtendedRenderWindow final : public sf::RenderWindow {
public:
    ExtendedRenderWindow(sf::VideoMode video_mode, const char * str);
    ExtendedRenderWindow() = default;
    void draw(const Slider& slider);
};
