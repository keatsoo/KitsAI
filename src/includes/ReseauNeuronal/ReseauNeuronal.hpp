#ifndef RESEAUNEURONAL_HPP
#define RESEAUNEURONAL_HPP

#pragma once

#include "Couche/Couche.hpp"
#include <vector>

namespace kitsAI
{
    class ReseauNeuronal
    {
    public:
        ReseauNeuronal(std::vector<double> sizes);
        ~ReseauNeuronal();

        std::vector<double> think(std::vector<double> &inputs);
        void backpropagate(std::vector<double> &inputs, std::vector<double> &outputs, double learning_rate);
        double activation_function(double x);

        double activation_function_derivative(double x);

    private:
        std::vector<Couche> m_layers;
    };
} // namespace kitsAI

#endif