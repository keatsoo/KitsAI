#include "Couche.hpp"
#include <random>

kitsAI::Couche::Couche(int nb_neurones, double bias, std::function<double(double)> &activation_function)
{
    // Générer des nombre aléatoires, c'est surtout du blabla
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(-100, 100);

    // Je crée autant de neurones que demandé, et à chaque fois son poids sera un nombre aléatoire entre -1 et 1
    for (size_t i = 0; i < nb_neurones; i++)
    {
        m_neurones.push_back(Neurone(((double)distribution(generator)) / 100));
    }

    b = bias;
    a_func = activation_function;
}

kitsAI::Couche::~Couche()
{
}

std::vector<double> kitsAI::Couche::calculate(std::vector<double> &inputs)
{
    std::vector<double> weights = getWeights();
    std::vector<double> outputs;
    std::vector<double> layerInput = inputs;

    // Pour chaque neurone, calculer le bias + la somme pondérée des entrées, puis l'ajouter a outputs après l'avoir calculée via la fonction d'activation
    for (size_t loop_neuron = 0; loop_neuron < weights.size(); loop_neuron++)
    {
        double sum = b;
        for (size_t loop_input = 0; loop_input < layerInput.size(); loop_input++)
        {
            sum += layerInput[loop_input] * weights[loop_neuron];
        }
        outputs.push_back(a_func(sum));
    }

    return outputs;
}

std::vector<double> kitsAI::Couche::getWeights()
{
    std::vector<double> out_weights;
    for (size_t i = 0; i < m_neurones.size(); i++)
    {
        out_weights.push_back(m_neurones[i].getWeight());
    }
    return out_weights;
}

void kitsAI::Couche::updateWeightWithGradient(std::vector<double> gradient, double learning_rate)
{
    for (size_t i = 0; i < m_neurones.size(); i++)
    {
        double grdt = m_neurones[i].getWeight() + learning_rate * gradient[i];
        m_neurones[i].setWeight(grdt);
    }
}

void kitsAI::Couche::updateBiasWithGradient(double gradient, double learning_rate)
{
    b += learning_rate * gradient;
}