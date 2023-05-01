#ifndef COUCHE_HPP
#define COUCHE_HPP

#pragma once

#include "../Neurone/Neurone.hpp"
#include <vector>
#include <functional>

namespace kitsAI
{
    class Couche
    {
    public:
        Couche(int nb_neurones, double bias, std::function<double(double)> &activation_function);
        ~Couche();

        /// @brief Calculer les sorties à l'aide des entrées
        /// @param inputs 
        /// @return 
        std::vector<double> calculate(std::vector<double> &inputs);

        /// @brief Retourner un vecteur de doubles contenant les poids de tous les neurones de la couche
        /// @return 
        std::vector<double> getWeights();

    private:
        std::vector<Neurone> m_neurones;
        std::function<double(double)> a_func;
        double b;
    };
} // namespace kitsAI

#endif