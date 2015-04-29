#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <vector>
#include <memory>

class NeuralNetwork;

class Layer
{
	friend class NeuralNetwork;

public:
	std::vector<float> process(const std::vector<float>& inputs)
	{
		std::vector<float> results;
		for(int i = 0; i < neurons.size(); ++i)
			results.push_back(neurons[i].process(inputs));

		return results;
	}

	Neuron& operator[](size_t position) { return neurons[position]; }
	Neuron& add_neuron()
	{
		neurons.push_back(Neuron());
		return neurons.back();
	}

private:
	std::vector<Neuron> neurons;
};

#endif // LAYER_H
