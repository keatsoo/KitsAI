#ifndef NEURONE_HPP
#define NEURONE_HPP

#pragma once

namespace kitsAI
{
    class Neurone
    {
    private:
        double w;
    public:
        Neurone(double weight);
        // ~Neurone();

        void setWeight(double weight);
        double getWeight();
    };
} // namespace kitsAI

#endif