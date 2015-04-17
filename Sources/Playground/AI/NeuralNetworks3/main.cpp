#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class SNeuron
{
private:
    struct Input {
        Input(SNeuron* neuron) : neuron(neuron), weight() {}

        std::shared_ptr<SNeuron> neuron;
        float weight;
    };

public:
    struct Test
    {
        std::vector<float> inputs;
        float output;
    };
    SNeuron() : bias(), inputs(), output() {}

    void train(std::vector<Test> tests)
    {
        float success_rate;
        float learn_rate = 1.0;

        int i;
        for(i = 0; i < 1000 && success_rate < 1.0; ++i) {

            int success_count = 0;

            for(std::vector<Test>::iterator iter = tests.begin(); iter != tests.end(); ++iter) {

                if(iter->inputs.size() != this->inputs.size())
                    return;

                test(iter->inputs);

                if(std::abs(output - iter->output) > 0.01) {
                    for(int i = 0; i < this->inputs.size(); ++i) {
                        this->inputs[i].weight += iter->inputs[i] * (iter->output - output);
                    } bias -= (iter->output - output) * learn_rate;
                }
                else success_count++;
            }
            success_rate = float(success_count)/tests.size();
        }
        std::cout << "test cycles: " << i << std::endl;
    }
    void test(std::vector<float> inputs)
    {
        for(int i = 0; i < this->inputs.size() && i < inputs.size(); ++i)
            this->inputs[i].neuron.get()->output = inputs[i];

        process();
    }
    void process()
    {
        output = 1 / (1+exp(-sigsum()));
    }

    void add_input(SNeuron* neuron)
    {
        inputs.push_back(Input(neuron));
    }

private:
    float output;
    float bias;
    std::vector<Input> inputs;

    float sigsum()
    {
        float sum = 0;
        for(int i = 0; i < inputs.size(); ++i)
            sum += (inputs[i].weight * inputs[i].neuron->output);
        sum -= inputs.size() * bias;
        return sum;
    }
    friend void test(const std::vector<Test>& data);
};

void test(const std::vector<SNeuron::Test>& data)
{
    SNeuron neuron;
    for(int i = 0; i < data[0].inputs.size(); ++i)
        neuron.add_input(new SNeuron());

    std::cout << "before test" << std::endl;
    for(int i = 0; i < data.size(); ++i)
    {
        for(int j = 0; j < data[i].inputs.size(); ++j)
            std::cout << data[i].inputs[j] << ' ';
        neuron.test(data[i].inputs);
        std::cout << "| " << neuron.output << std::endl;
    }

    neuron.train(data);


    std::cout << "after test" << std::endl;
    for(int i = 0; i < data.size(); ++i)
    {
        for(int j = 0; j < data[i].inputs.size(); ++j)
            std::cout << data[i].inputs[j] << ' ';
        neuron.test(data[i].inputs);
        std::cout << "| " << neuron.output << std::endl;
    }
    std::cout << std::endl;
}
void and_neuron_test()
{
    std::cout << "and-neuron test" << std::endl;
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;

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

    test(tests);
}
void or_neuron_test()
{
    std::cout << "Testing or-neuron:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 0;
    dummy.inputs = {0, 0};
    tests.push_back(dummy);

    dummy.output = 1;
    dummy.inputs = {0, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 0};
    tests.push_back(dummy);

    dummy.inputs = {1, 1};
    tests.push_back(dummy);

    test(tests);
}
void nor_neuron_test()
{
    std::cout << "Testing nor-neuron:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 1;
    dummy.inputs = {0, 0};
    tests.push_back(dummy);

    dummy.output = 0;
    dummy.inputs = {0, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 0};
    tests.push_back(dummy);

    dummy.inputs = {1, 1};
    tests.push_back(dummy);

    test(tests);
}
void nand_neuron_test()
{
    std::cout << "Testing nand-neuron:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
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

    test(tests);
}

void no_neuron_test()
{
    std::cout << "Testing no-neuron:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 0;
    dummy.inputs = {0, 0};
    tests.push_back(dummy);

    dummy.inputs = {1, 0};
    tests.push_back(dummy);

    dummy.inputs = {0, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 1};
    tests.push_back(dummy);

    test(tests);
}
void all_neuron_test()
{
    std::cout << "Testing all-neuron:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 1;
    dummy.inputs = {0, 0};
    tests.push_back(dummy);

    dummy.inputs = {1, 0};
    tests.push_back(dummy);

    dummy.inputs = {0, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 1};
    tests.push_back(dummy);

    test(tests);
}

void and3_test()
{
    std::cout << "and3-test:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 0;
    dummy.inputs = {0, 0, 0};
    tests.push_back(dummy);
    dummy.inputs = {0, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 0};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 0, 0};
    tests.push_back(dummy);
    dummy.inputs = {1, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {1, 1, 0};
    tests.push_back(dummy);

    dummy.output = 1;
    dummy.inputs = {1, 1, 1};
    tests.push_back(dummy);

    test(tests);
}

void nand3_test()
{
    std::cout << "nand3-test:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 1;
    dummy.inputs = {0, 0, 0};
    tests.push_back(dummy);
    dummy.inputs = {0, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 0};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 0, 0};
    tests.push_back(dummy);
    dummy.inputs = {1, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {1, 1, 0};
    tests.push_back(dummy);

    dummy.output = 0;
    dummy.inputs = {1, 1, 1};
    tests.push_back(dummy);

    test(tests);
}
void or3_test()
{
    std::cout << "or3-test:\n";
    std::vector<SNeuron::Test> tests;
    SNeuron::Test dummy;
    dummy.output = 0;
    dummy.inputs = {0, 0, 0};
    tests.push_back(dummy);
    dummy.output = 1;
    dummy.inputs = {0, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 0};
    tests.push_back(dummy);
    dummy.inputs = {0, 1, 1};
    tests.push_back(dummy);

    dummy.inputs = {1, 0, 0};
    tests.push_back(dummy);
    dummy.inputs = {1, 0, 1};
    tests.push_back(dummy);
    dummy.inputs = {1, 1, 0};
    tests.push_back(dummy);
    dummy.inputs = {1, 1, 1};
    tests.push_back(dummy);

    test(tests);
}

int main(void)
{
    nand3_test();
    //or_neuron_test();
    //nor_neuron_test();
    //and_neuron_test();
    //nand_neuron_test();
    //no_neuron_test();
    //all_neuron_test();
    return 0;
}
