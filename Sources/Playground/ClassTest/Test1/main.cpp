#include <iostream>
#include <vector>

class CSomething
{
public:
	CSomething() : data() { Children.push_back(this); }
	CSomething(int _data) : data(_data) { Children.push_back(this); }

	static std::vector< CSomething* > Children;

	int data;
};
std::vector< CSomething* > CSomething::Children;

class CAnimal
{
public:
	virtual std::string noise() = 0;
};
class Dog : public CAnimal
{
public:
	std::string noise()
	{
		return "ruff!";
	}
};
class Dog2 : public Dog
{
public:
	std::string noise()
	{
		return "ruff2!";
	}
};

int main(void)
{
	CSomething s1(5);
	CSomething s2(20);

	std::cout << CSomething::Children[1]->data << std::endl;

	Dog dog;
	CAnimal* animal;
	animal = &dog;
	std::cout << animal->noise() << std::endl;

	Dog2 dog2;
	animal = &dog2;
	std::cout << animal->noise() << std::endl;

	Dog* anyDog;
	anyDog = &dog2;
	std::cout << anyDog->noise() << std::endl;


    return 0;
}
