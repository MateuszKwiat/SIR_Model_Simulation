//
// Created by Mateusz Kwiatkowski on 21/11/2024.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "PopulationBar.h"
#include "PlotBody.h"
#include "TextAnnotations.h"

class PopulationsProportionsPlot final : public sf::RectangleShape {
private:
    PlotBody* plot_body{};
    PopulationBar* susceptible_population_bar = nullptr;
    PopulationBar* infectious_population_bar = nullptr;
    PopulationBar* recovered_population_bar = nullptr;
    const unsigned int* susceptible_count = nullptr;
    const unsigned int* infectious_count = nullptr;
    const unsigned int* recovered_count = nullptr;
    const unsigned int population_count{};
    TextAnnotations* text_annotations = nullptr;

private:
    void initialize_bars();
    void initialize_single_bar(PopulationBar** bar, const sf::Color &color, unsigned int count,
                               float bars_spacing, sf::Vector2f &current_position) const;
    void initialize_plot_body();

public:
    PopulationsProportionsPlot(const sf::Vector2f& position,
                               const sf::Vector2f& size,
                               const unsigned int* susceptible_count,
                               const unsigned int* infectious_count,
                               const unsigned int* recovered_count,
                               unsigned int population_count,
                               const sf::Font& font);

    ~PopulationsProportionsPlot() override;
    void update();

    friend class ExtendedRenderWindow;
};
