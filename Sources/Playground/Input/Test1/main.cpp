#include <iostream>
#include <string>
#include <thread>
#include <atomic>

std::atomic<bool> pressed(false);
void foo()
{
	std::string lel;
	std::cin >> lel;
	pressed = true;
}

int main(void)
{
	std::thread t1(foo);

	while(pressed)
	{
		std::cout << "lelelel" << std::endl;
	}
	std::cout << "end" << std::endl;
	t1.join();

    return 0;
}
