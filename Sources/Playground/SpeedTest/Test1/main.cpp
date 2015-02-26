#include <iostream>
#include <Utility/String.hpp>
#include <Timer/Timer.h>

namespace LUS = Librepp::Utility::String;

int main(void)
{
	std::string str("64343563456posfguhovxbz90sd3fovl uh	52p9cfz29pawaacwzp9782p2 czhf<posfguhovxbz90sdfo3vl");
	Timer t1;
	Timer t2;

	t1.start();
	for(int i = 0; i < 10000; ++i)
	{
		if(LUS::HasNumbers(str));
			std::cout << "Nummer vorhanden!\n";
	}
	t1.stop();
	std::cout << "HasNumbers1: " << t1.getElapsedTimeInMicroSec() << std::endl;

	t2.start();
	for(int i = 0; i < 10000; ++i)
	{
		if(LUS::HasNumbers(str));
			std::cout << "Nummer vorhanden!\n";
	}
	t2.stop();
	std::cout << "HasNumbers2: " << t2.getElapsedTimeInMicroSec() << std::endl;

    return 0;
}
