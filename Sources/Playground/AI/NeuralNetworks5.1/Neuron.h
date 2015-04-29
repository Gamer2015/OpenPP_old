#ifndef NERUON_H
#define NERUON_H

#include <memory>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

#include <iostream>

class Neuron
{
	friend class NeuralNetwork;

public:
	float process(const std::vector<float>& inputs)
	{
		while(inputs.size() > weights.size())
			weights.push_back(1);

		float sum = 0;
		for(int i = 0; i < weights.size(); ++i)
			sum += (weights[i] * inputs[i]);
		sum += weights.size() * bias;
		return 1 / (1+exp(-sum));
	}

private:
	float bias;
	std::vector<float> weights;
};

#endif // NERUON_H
