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
        ReseauNeuronal();
        ~ReseauNeuronal();

    private:
        std::vector<Couche> couches;
    };
} // namespace kitsAI

#endif