#include "Editor/Editor.hpp"
#include "Initialize.hpp"

int main(int argc, char* argv[])
{
	Initialize();
	Editor().run();

	return 0;
}
