#include <iostream>
#include <vector>
#include "includes/ReseauNeuronal/ReseauNeuronal.hpp"
#include <chrono>

using namespace std;

int main()
{
    vector<double> sizes = {3.0, 2.0, 3.0, 1.0};
    kitsAI::ReseauNeuronal NN(sizes);

    // Entrainement
    vector<vector<double>> training_data = {{1, 0, 0},
                                            {0, 1, 1},
                                            {0, 1, 0},
                                            {1, 0, 1},
                                            {0, 0, 1},
                                            {1, 1, 0},
                                            {0, 0, 1},
                                            {1, 1, 1}};
    vector<vector<double>> expected_out_data = {{1},
                                                {0},
                                                {0},
                                                {1},
                                                {0},
                                                {1},
                                                {0},
                                                {1}};

    if (training_data.size() != expected_out_data.size())
    {
        cerr << "Hey!!!! sumn wrong!!!!" << endl;
        return 1;
    }

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < 10000; i++)
    {
        for (size_t j = 0; j < training_data.size(); j++)
        {
            NN.backpropagate(training_data[j], expected_out_data[j], 0.2);
        }
        cout << "Itération numéro " << i << endl;
    }

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    double time_count = duration.count() / 1000.0;
    cout << "Temps écoulé pour l'entraînement... " << time_count << endl;

    // Réfléxions
    vector<double> data_exp_1 = {0, 0, 1};
    vector<double> out_ext_1 = NN.think(data_exp_1);

    cout << "Si je lui demande... 0, 0, 1, il devrait me répondre 0... et ici il me répond... " << out_ext_1[0] << endl;
    if (out_ext_1[0] < 0.5)
    {
        cout << "QUEL BG LE CREATEUR DE CETTE IA!!! " << endl;
    }
    else
    {
        cout << "QUEL MISKINE LE CREATEUR DE CETTE IA!!! ELLE EST CONNE..." << endl;
    }

    cout << "Je réessaie...." << endl;

    vector<double> data_exp_2 = {1, 1, 0};
    vector<double> out_ext_2 = NN.think(data_exp_1);

    cout << "Si je lui demande... 1, 1, 0, il devrait me répondre 1... et ici il me répond... " << out_ext_2[0] << endl;
    if (out_ext_2[0] > 0.5)
    {
        cout << "QUEL BG LE CREATEUR DE CETTE IA!!! " << endl;
    }
    else
    {
        cout << "QUEL MISKINE LE CREATEUR DE CETTE IA!!! ELLE EST CONNE..." << endl;
    }

    return 0;
}
