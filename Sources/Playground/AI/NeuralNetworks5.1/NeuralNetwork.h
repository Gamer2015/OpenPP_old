#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Layer.h"
#include <vector>
#include <memory>

#include <iostream>

class NeuralNetwork
{
public:

	std::vector<float> train(const std::vector<float>& inputs, const std::vector<float>& results)
	{
		std::vector<std::vector<float> > layer_outputs;
		std::vector<float> next_input(inputs);
		layer_outputs.push_back(next_input);

		for(int i = 0; i < layers.size(); ++i) {
			next_input = layers[i].process(next_input);
			layer_outputs.push_back(next_input);
		}

		for(int i = 0; i < layers.back().neurons.size(); ++i) {
			if(std::abs(layer_outputs.back()[i] - results[i]) > 0.5) {
				for(int j = 0; j < layers.back()[i].weights.size(); ++j) {
					layers.back()[i].weights[j] += layer_outputs[layer_outputs.size()-2][j] * (results[i] - next_input[i]) * 0.05;
				}
				layers.back()[i].bias += (results[i] - next_input[i]) * 0.05;
			}
		}
		return next_input;
	}

	std::vector<float> process(const std::vector<float>& inputs)
	{
		std::vector<float> next_input(inputs);

		for(int i = 0; i < layers.size(); ++i)
			next_input = layers[i].process(next_input);

		return next_input;
	}

	Layer& operator[](size_t position) { return layers[position]; }
	Layer& add_layer()
	{
		layers.push_back(Layer());
		return layers.back();
	}

private:
	std::vector<Layer> layers;
};

#endif // NEURAL_NETWORK_H
