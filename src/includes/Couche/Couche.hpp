#ifndef COUCHE_HPP
#define COUCHE_HPP

#pragma once

#include "../Neurone/Neurone.hpp"
#include <vector>

namespace kitsAI
{
    class Couche
    {
    public:
        Couche(int nb_neurones, double bias);
        ~Couche();

    private:
        std::vector<Neurone> m_neurones;
        double b;
    };
} // namespace kitsAI

#endif