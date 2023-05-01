#include "ReseauNeuronal.hpp"
#include <functional>

kitsAI::ReseauNeuronal::ReseauNeuronal(std::vector<double> sizes)
{
    std::function<double(double)> activation = [this](double value)
    { return activation_function(value); };
    for (size_t i = 0; i < sizes.size() - 1; i++)
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

    for (size_t i = 0; i < m_layers.size() - 1; i++)
    {
        outputs.clear();
        outputs = m_layers[i].calculate(layerInput);
        layerInput = outputs;
    }

    return outputs;
}

void kitsAI::ReseauNeuronal::backpropagate(std::vector<double> &inputs, std::vector<double> &outputs, double learning_rate)
{
}

double kitsAI::ReseauNeuronal::activation_function(double x)
{
    return 1 + x;
}
