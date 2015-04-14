#include <iostream>
#include <vector>

struct Test
{
	std::vector<bool> inputs;
	float output;
};

class Neuron
{

public:
	Neuron(int inputs) : weights(inputs), threshold(inputs) {}

	void train(std::vector<Test> tests)
	{
		float success_rate;
		int i;
		for(i = 0; i < 100 && success_rate < 0.95; ++i) {

			int success_count = 0;

			for(std::vector<Test>::iterator iter = tests.begin(); iter != tests.end(); ++iter) {

				if(iter->inputs.size() != weights.size())
					return;

				bool success = process(iter->inputs);
				success = (success == iter->output);

				if(success == false) {
					for(int i = 0; i < weights.size(); ++i) {
						weights[i] += iter->inputs[i] * (iter->output - success);
					}
				}
				else success_count++;
			}

			success_rate = float(success_count) / tests.size();
		}
		std::cout << "needed test-circles: " << i << std::endl;
	}
	bool process(std::vector<bool> inputs)
	{
		if(inputs.size() != weights.size())
			return false;

		float sum = 0;
		for(int i = 0; i < inputs.size(); ++i)
			sum += weights[i] * inputs[i];

		output = sum > threshold;
		return output;
	}

private:
	bool output;
	float threshold;
	std::vector<float> weights;

	enum { FAILURE=0, SUCCESS=1, ERROR=2 };

	int intern_test(std::vector<bool> inputs)
	{
		if(inputs.size() != weights.size())
			return ERROR;

		return process(inputs);
	}

	friend std::ostream& operator<<(std::ostream&, const Neuron& neuron);
};
std::ostream& operator<<(std::ostream& os, const Neuron& neuron)
{
	std::cout << "Threshold: " << neuron.threshold << std::endl;
	for(int i = 0; i < neuron.weights.size(); ++i)
		std::cout << "weight " << i << ": " << neuron.weights[i] << std::endl;
	return os;
}

class NeuralNetwork
{
public:
	NeuralNetwork(int inputs) : threshold(inputs), weights(inputs) {}

	void train(std::vector<Test> tests)
	{
		float success_rate;
		int i;
		for(i = 0; i < 100 && success_rate < 0.95; ++i) {

			int success_count = 0;

			for(std::vector<Test>::iterator iter = tests.begin(); iter != tests.end(); ++iter) {

				int success = intern_test(iter->inputs);
				if(success == ERROR)
					return;

				success = (success == iter->output);

				if(success == false) {
					for(int i = 0; i < weights.size(); ++i) {
						weights[i] += iter->inputs[i] * (iter->output - success);
					}
				}
				else success_count++;
			}

			success_rate = float(success_count) / tests.size();
		}
		std::cout << "needed test-circles: " << i << std::endl;
	}
	bool process(std::vector<bool> inputs)
	{
		if(inputs.size() != weights.size())
			return false;

		float sum = 0;
		for(int i = 0; i < inputs.size(); ++i)
			sum += weights[i] * inputs[i];

		output = sum > threshold;
		return output;
	}

private:
	bool output;
	float threshold;
	std::vector<float> weights;

	enum { FAILURE=0, SUCCESS=1, ERROR=2 };

	int intern_test(std::vector<bool> inputs)
	{
		if(inputs.size() != weights.size())
			return ERROR;

		return process(inputs);
	}

	friend std::ostream& operator<<(std::ostream&, const Neuron& neuron);
};

// working
void or_neuron_test()
{
	std::cout << "Testing or-neuron:\n";
	Neuron neuron(2);

	// setting test data
	std::vector<Test> tests;
	Test dummy;
	dummy.output = 0;
	dummy.inputs = {0, 0};
	tests.push_back(dummy);

	dummy.output = 1;
	dummy.inputs = {1, 0};
	tests.push_back(dummy);

	dummy.inputs = {1, 1};
	tests.push_back(dummy);

	dummy.inputs = {0, 1};
	tests.push_back(dummy);

	// train neuron with data
	neuron.train(tests);

	// show results of training
	std::vector< std::vector<bool> > results;
	std::vector<bool> fdummy = {0, 0};
	results.push_back(fdummy);
	fdummy = {0, 1};
	results.push_back(fdummy);
	fdummy = {1, 1};
	results.push_back(fdummy);
	fdummy = {1, 0};
	results.push_back(fdummy);

	for(int i = 0; i < results.size(); ++i)
	{
		for(int j = 0; j < results[i].size(); ++j)
			std::cout << results[i][j] << ' ';
		std::cout << "| " << neuron.process(results[i]) << std::endl;
	}

	std::cout << neuron << std::endl;
}
void and_neuron_test()
{
	std::cout << "Testing and-neuron:\n";
	Neuron neuron(2);

	// setting test data
	std::vector<Test> tests;
	Test dummy;
	dummy.output = 0;
	dummy.inputs = {0, 0};
	tests.push_back(dummy);

	dummy.inputs = {1, 0};
	tests.push_back(dummy);

	dummy.inputs = {0, 1};
	tests.push_back(dummy);

	dummy.output = 1;
	dummy.inputs = {1, 1};
	tests.push_back(dummy);

	// train neuron
	neuron.train(tests);

	// show results of training
	std::vector< std::vector<bool> > results;
	std::vector<bool> fdummy = {0, 0};
	results.push_back(fdummy);
	fdummy = {0, 1};
	results.push_back(fdummy);
	fdummy = {1, 1};
	results.push_back(fdummy);
	fdummy = {1, 0};
	results.push_back(fdummy);

	for(int i = 0; i < results.size(); ++i)
	{
		for(int j = 0; j < results[i].size(); ++j)
			std::cout << results[i][j] << ' ';
		std::cout << "| " << neuron.process(results[i]) << std::endl;
	}
	std::cout << neuron << std::endl;
}

// they don't work
void nor_neuron_test()
{
	std::cout << "Testing nor-neuron:\n";
	Neuron neuron(2);

	// setting test data
	std::vector<Test> tests;
	Test dummy;

	dummy.output = 0;
	dummy.inputs = {1, 0};
	tests.push_back(dummy);

	dummy.inputs = {0, 1};
	tests.push_back(dummy);

	dummy.inputs = {1, 1};
	tests.push_back(dummy);

	dummy.inputs = {0.5, 1};
	tests.push_back(dummy);

	dummy.inputs = {1, 0.5};
	tests.push_back(dummy);

	dummy.inputs = {0.5, 0.5};
	tests.push_back(dummy);

	dummy.output = 1;
	dummy.inputs = {0, 0};
	tests.push_back(dummy);

	// train neuron
	neuron.train(tests);

	// show results of training
	std::vector< std::vector<bool> > results;
	std::vector<bool> fdummy = {0, 0};
	results.push_back(fdummy);
	fdummy = {0, 1};
	results.push_back(fdummy);
	fdummy = {1, 1};
	results.push_back(fdummy);
	fdummy = {1, 0};
	results.push_back(fdummy);

	for(int i = 0; i < results.size(); ++i)
	{
		for(int j = 0; j < results[i].size(); ++j)
			std::cout << results[i][j] << ' ';
		std::cout << "| " << neuron.process(results[i]) << std::endl;
	}
	std::cout << neuron << std::endl;
}
void nand_neuron_test()
{
	std::cout << "Testing nand-neuron:\n";
	Neuron neuron(2);

	// setting test data
	std::vector<Test> tests;
	Test dummy;
	dummy.output = 1;
	dummy.inputs = {0, 0};
	tests.push_back(dummy);

	dummy.inputs = {1, 0};
	tests.push_back(dummy);

	dummy.inputs = {0, 1};
	tests.push_back(dummy);

	dummy.output = 0;
	dummy.inputs = {1, 1};
	tests.push_back(dummy);

	// train neuron
	neuron.train(tests);

	// show results of training
	std::vector< std::vector<bool> > results;
	std::vector<bool> fdummy = {0, 0};
	results.push_back(fdummy);
	fdummy = {0, 1};
	results.push_back(fdummy);
	fdummy = {1, 1};
	results.push_back(fdummy);
	fdummy = {1, 0};
	results.push_back(fdummy);

	for(int i = 0; i < results.size(); ++i)
	{
		for(int j = 0; j < results[i].size(); ++j)
			std::cout << results[i][j] << ' ';
		std::cout << "| " << neuron.process(results[i]) << std::endl;
	}
	std::cout << neuron << std::endl;
}


int main(void)
{
	or_neuron_test();
	and_neuron_test();

	// not working
	//nor_neuron_test();
	//nand_neuron_test();
    return 0;
}
