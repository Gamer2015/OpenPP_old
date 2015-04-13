#include <iostream>
#include <array>

int main ()
{
	enum { AIR, GROUND, KILL };
	const unsigned int NO_COLLISION_TILE_COUNT = 1;
	int nocollide[1] = { KILL };

	unsigned int tile = KILL;
	for(int i = 0; i < NO_COLLISION_TILE_COUNT; ++i)
		if(tile == nocollide[i])
			std::cout << "nope" << std::endl;
	std::cout << tile << std::endl;

	return 0;
}
