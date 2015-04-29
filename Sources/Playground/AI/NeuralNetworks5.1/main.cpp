#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <fstream>
#include <ctime>
#include "NeuralNetwork.h"

const int width = 28;
const int height = 28;
const int area = width * height;

struct Picture
{
	unsigned char data[height][width];
};

void get_pictures(const std::string& path, std::vector<Picture>& pictures)
{
	std::ifstream file(path, std::ios::binary);
	if(file.is_open())
	{
		file.seekg(0, std::ios::end);
		int count = file.tellg();
		file.seekg(0, std::ios::beg);

		file.seekg(16, std::ios::beg); // offset
		while(file.tellg() < count)
		{
			pictures.push_back(Picture());
			file.read((char*)&(pictures.back().data), area);
		}
	}
	file.close();
}
void get_labels(const std::string& path, std::vector<char>& numbers)
{
	std::ifstream file(path, std::ios::binary);
	if(file.is_open())
	{
		file.seekg(0, std::ios::end);
		int count = file.tellg();
		file.seekg(0, std::ios::beg);

		file.seekg(8, std::ios::beg); // offset
		while(file.tellg() < count)
		{
			numbers.push_back(char());
			file.read(&numbers.back(), 1);
		}
	}
	file.close();
}

int main(void)
{
	std::vector<char> train_numbers;
	get_labels("train-labels.idx1-ubyte", train_numbers);
	std::vector<Picture> train_pictures;
	get_pictures("train-images.idx3-ubyte", train_pictures);

	std::vector<char> test_numbers;
	get_labels("t10k-labels.idx1-ubyte", test_numbers);
	std::vector<Picture> test_pictures;
	get_pictures("t10k-images.idx3-ubyte", test_pictures);



	NeuralNetwork nw;
	Layer& l1 = nw.add_layer();

	for(int i = 0; i < 10; ++i)
		l1.add_neuron();

	for(int i = 0; i < train_pictures.size() && i < train_numbers.size(); ++i) {
		std::vector<float> data;
		for(int y = 0; y < height; ++y)
			for(int x = 0; x < width; ++x)
				data.push_back(train_pictures[i].data[y][x] / 256.0);

		std::vector<float> results;
		for(int j = 0; j < 10; ++j)
			if(j == train_numbers[i])
				results.push_back(1);
			else
				results.push_back(0);

		std::vector<float> testing =  nw.train(data, results);

		std::cout << i << ": " << std::endl << "testing: ";
		for(int j = 0; j < testing.size() && j < results.size(); ++j)
		{
			std::cout << testing[j] << ' ';
		}
		std::cout << std::endl;
		std::cout << "results: ";
		for(int j = 0; j < results.size() && j < results.size(); ++j)
		{
			std::cout << results[j] << ' ';
		}
		std::cout << std::endl;
	}

	int successes = 0;
	std::vector<int> success_count(10);
	std::vector<int> number_count(10);
	std::vector<int> guess_count(10);

	for(int i = 0; i < test_pictures.size() && i < test_numbers.size(); ++i) {
		std::vector<float> data;
		for(int y = 0; y < height; ++y)
			for(int x = 0; x < width; ++x)
				data.push_back(test_pictures[i].data[y][x] / 256.0);

		std::vector<float> results;
		for(int j = 0; j < 10; ++j)
			if(j == test_numbers[i])
				results.push_back(1);
			else
				results.push_back(0);

		std::vector<float> testing = nw.process(data);

		int max = 0;
		for(int j = 0; j < testing.size() && j < results.size(); ++j)
		{
			if(testing[j] > testing[max])
				max = j;
		}

		bool success = (max == test_numbers[i]);
		std::cout << i << ": " << success;
		if(!success) {
			std::cout << ' ' << max << ' ' << (int)test_numbers[i];
		}
		std::cout << std::endl;

		successes += success;
		success_count[test_numbers[i]] += success;
		number_count[test_numbers[i]]++;
		guess_count[max]++;
	}
	std::cout << "Correct: " << float(successes) << "/" << test_pictures.size() << " = " << float(successes) / test_pictures.size() * 100 << "%" << std::endl;
	for(int i = 0; i < success_count.size(); ++i)
	{
		std::cout << i << ": " << success_count[i] << "/" << number_count[i] << " = " << float(success_count[i]) / number_count[i] * 100 << "%" << std::endl;
	}
	std::cout << std::endl << "False: " << 10000 - float(successes) << "/" << test_pictures.size() << " = " << (10000 - float(successes)) / test_pictures.size() * 100 << "%" << std::endl;
	for(int i = 0; i < success_count.size(); ++i)
	{
		std::cout << i << ": " << guess_count[i] - success_count[i] << "/" << number_count[i] << " = " << float(guess_count[i] - success_count[i]) / number_count[i] * 100 << "%" << std::endl;
	}

	return 0;
}
