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

void ExtendedRenderWindow::draw(const PopulationsProportionsPlot& plot) {
    RenderWindow::draw(plot);
    RenderWindow::draw(*plot.plot_body);
    for (const auto line : plot.plot_body->lines) {
        RenderWindow::draw(*line);
    }
    RenderWindow::draw(*plot.susceptible_population_bar);
    RenderWindow::draw(*plot.infectious_population_bar);
    RenderWindow::draw(*plot.recovered_population_bar);
    RenderWindow::draw(*plot.text_annotations->plot_label);
    for (const auto tick : *plot.text_annotations->y_ticks) {
        RenderWindow::draw(*tick);
    }
    RenderWindow::draw(*plot.text_annotations->susceptible_label);
    RenderWindow::draw(*plot.text_annotations->infectious_label);
    RenderWindow::draw(*plot.text_annotations->recovered_label);
}

void ExtendedRenderWindow::draw(const SimulationWindow& simulation_window) {
    RenderWindow::draw(simulation_window);
    for (const auto particle : simulation_window.particles) {
        RenderWindow::draw(*particle);
    }
}

void ExtendedRenderWindow::draw(const Button &button) {
    RenderWindow::draw(button);
    RenderWindow::draw(*button.text);
}