#include "Couche.hpp"
#include <random>

kitsAI::Couche::Couche(int nb_neurones, double bias)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(-100,100);

    for (size_t i = 0; i < nb_neurones; i++)
    {
        m_neurones.push_back(Neurone(((double) distribution(generator))/100));
    }

    b = bias;
}

kitsAI::Couche::~Couche()
{

}