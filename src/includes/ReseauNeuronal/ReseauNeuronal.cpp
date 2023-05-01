#include "ReseauNeuronal.hpp"
#include <functional>
#include <cmath>

kitsAI::ReseauNeuronal::ReseauNeuronal(std::vector<double> sizes)
{
    std::function<double(double)> activation = [this](double value)
    { return activation_function(value); };
    for (size_t i = 0; i < sizes.size(); i++)
    {
        m_layers.push_back(Couche(sizes[i], 0.1, activation));
    }
}

kitsAI::ReseauNeuronal::~ReseauNeuronal()
{
}

std::vector<double> kitsAI::ReseauNeuronal::think(std::vector<double> &inputs)
{
    std::vector<double> outputs;
    std::vector<double> layerInput(inputs);

    for (size_t i = 0; i < m_layers.size(); i++)
    {
        outputs.clear();
        outputs = m_layers[i].calculate(layerInput);
        layerInput = outputs;
    }

    return outputs;
}

void kitsAI::ReseauNeuronal::backpropagate(std::vector<double> &inputs, std::vector<double> &outputs, double learning_rate)
{
    std::vector<double> prediction = think(inputs);              // Prédiction originale, probablement erronée
    std::vector<std::vector<double>> weight_gr(m_layers.size()); // Weight gradient
    std::vector<double> bias_gr(m_layers.size(), 0.0);                // Bias gradient
    std::vector<double> out_errors;

    // On va calculer l'erreur pour chaque output
    for (size_t i = 0; i < outputs.size(); i++)
    {
        double err = prediction[i] - outputs[i];
        out_errors.push_back(err * activation_function_derivative(prediction[i]));
    }

    // Maintenant on va rétropropager
    // Pour chaque couche...
    for (size_t i = m_layers.size() - 1; i >= 0; --i)
    {
        std::vector<double> currentLayerGradients;
        std::vector<double> currentLayerWeights = m_layers[i].getWeights();

        // ...et chaque neurone dans la couche...
        for (size_t j = 0; j < currentLayerWeights.size(); j++)
        {
            double neuron_gr = out_errors[j];
            
            // On calcule la dérivée de l'erreur par rapport a chaque poids
            for (size_t k = 0; k < prediction.size(); k++)
            {
                weight_gr[i][j] += neuron_gr * prediction[k];
            }
            
            // On calcule la dérivée de l'erreur par rapport au biais
            bias_gr[i] += neuron_gr;

            // On calcule la dérivée de l'erreur par rapport à l'entrée du neurone (pour la couche précédente)
            double inputGradient = neuron_gr * currentLayerWeights[j];
            currentLayerGradients.push_back(inputGradient);
        }
        
        out_errors = currentLayerGradients;
    }

    // On va mettre à jour les poids et biais
    for (size_t i = 0; i < m_layers.size(); i++)
    {
        m_layers[i].updateWeightWithGradient(weight_gr[i], learning_rate);
        m_layers[i].updateBiasWithGradient(bias_gr[i], learning_rate);
    }
    
}

double kitsAI::ReseauNeuronal::activation_function(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

double kitsAI::ReseauNeuronal::activation_function_derivative(double x)
{
    double fx = activation_function(x);
    return fx * (1.0 - fx);
}