#include <iostream>
#include <cstdlib>
#include <ctime>

//class TransportationObject
//{
//public:
//	virtual void travel() const
//	{
//		std::cout << "transportation:" << std::endl;
//	}
//};
//class Car : public TransportationObject
//{
//public:
//	virtual void travel() const { std::cout << "transportation: Car" << std::endl; }
//};
//class Bike: private TransportationObject
//{
//public:
//	virtual void travel() const { std::cout << "transportation: Bike" << std::endl; }
//};

//TransportationObject* find_best_choise(TransportationObject* o1,TransportationObject* o2)
//{
//	if(rand() % 2 == 0)
//		return o1;
//	else
//		return o2;
//}

//int main(void)
//{
//  srand (time(NULL)); // for finding best choise
//	Car car;
//	Bike bike;

//	TransportationObject* object = find_best_choise(&car, &bike);

//// Now do something with the desired Object
//	object->travel();
//}
int main(void)
{
	int a = 500;
	char b = 65;
	void* c = &b;
	std::cout << *(char*)c << std::endl;
	c = &a;
	std::cout << *(int*)c << std::endl;
	return 0;
}
