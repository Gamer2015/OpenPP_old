#include "Char.h"

namespace Openpp
{
namespace Utility
{

bool Char::IsCapital(char Character)
{
	if(Character >= 'A' && Character <= 'Z')
		return true;
	return false;
}
bool Char::IsSmall(char Character)
{
	if(Character >= 'a' && Character <= 'z')
		return true;
	return false;
}
bool Char::IsLetter(char Character)
{
	if(IsSmall(Character) || IsCapital(Character))
		return true;
	return false;
}

bool Char::IsNumber(char Character)
{
	if(Character >= '0' && Character <= '9')
		return true;
	return false;
}

} // namespace Types
} // namespace Openpp
