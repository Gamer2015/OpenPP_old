#ifndef ___OPENPP_TYPES_CHAR_EXPANSION__H___
#define ___OPENPP_TYPES_CHAR_EXPANSION__H___

/***************************\
 * Usage: Platform independent Expansion of char
 * Date: 2nd February 2015
 * Author: Stefan Kreiner
 * _______________________________
 *
 * Notes:
 *  - Not Thread-Save
 *
\**************************/

namespace Openpp
{
namespace Utility
{
namespace Char
{

/// Returns TRUE if Character is a capital letter
static bool IsCapital(char Character);

/// Returns TRUE if Character is a small letter
static bool IsSmall(char Character);

/// Returns TRUE if Character is a letter
static bool IsLetter(char Character);

/// Returns TRUE if Character is a Number
static bool IsNumber(char Character);

} // namespace Char
} // namespace Types
} // namespace Openpp

#include "Char.inl"

#endif /// ___OPENPP_TYPES_CHAR_EXPANSION__H___
