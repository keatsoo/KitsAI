#include "Neurone.hpp"

kitsAI::Neurone::Neurone(double weight) {
    w = weight;
}

void kitsAI::Neurone::setWeight(double weight){
    w = weight;
}

double kitsAI::Neurone::getWeight(){
    return w;
}