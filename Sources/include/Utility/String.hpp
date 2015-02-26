#ifndef LIBREPP_UTILITY_STRING_H_
#define LIBREPP_UTILITY_STRING_H_

/***************************\
 * Usage: Platform independent Expansion of std::string
 * Date: 2nd February 2015
 * Author: Stefan Kreiner
 * _______________________________
 *
 * Notes:
 *  - Not Thread-Save
 *
\**************************/

#include <string>
#include <vector>
#include "Char.h"

namespace Librepp
{
namespace Utility
{
namespace String
{


//// Splits the String into a Vector of Strings with a defined Length
/// If String.size() % Length is not 0 the last String has less Elements
static std::vector<std::string> Split(const std::string& rString, unsigned int Length, const std::string& rEnding = "");

//// Splits the String into a Vector of Strings
static std::vector<std::string> Explode(const std::string& rString, const std::string& rDelimiter, int SearchStart = 0);

//// Splits the String into a Vector of Strings, but doesn't erase delimiter
static std::vector<std::string> SoftExplode(const std::string& rString, const std::string& rDelimiter, int SearchStart = 0);

//// Takes the StringVector and Connects its Elements by "Delimiter"
static std::string Implode(const std::vector<std::string>& rvString, const std::string& rDelimiter = "");


//// Returns a String repeated RepeatCount times
static std::string Repeat(const std::string& rString, unsigned int RepeatCount);

//// Removes TrimChars from both sides of the String
/// Modifies the content of rString
static void Trim(std::string& rString, const std::string& rTrimChars = "\0\t\n\x0B\r ");

/// Returns the String in reversed Order
static std::string Reverse(const std::string& rString);


//// insert "Sequence" before each Pattern
/// Modifies the content of rString
static void InsertBeforePattern(std::string& rString, const std::string& rPattern, const std::string& rSequence);

//// Make sure "Sequence" appears before each Pattern
/// Modifies the content of rString
static void HaveBeforePattern(std::string& rString, const std::string& rPattern, const std::string& rSequence);

//// Make sure "Sequence" appears before each Pattern
/// Modifies the content of rString
static void HaveCharsBeforePattern(std::string& rString, const std::string& rPattern, const std::string& rChars, char rInsert);


//// Replaces all occurences of 'Char' with 'Replaces'
/// Modifies the content of rString
static void ReplaceChar(std::string& rString, char Char, char Replace);

//// Replaces all occurences of 'Char' with 'Replaces'
/// Modifies the content of rString
/// if rReplaces.length() < rChars.length() the last characters will be replaced with " "
static void ReplaceChars(std::string& rString, const std::string& rChars, const std::string& rReplaces);
static void ReplaceChars(std::string& rString, const std::string& rChars, std::string& rReplaces);

//// Replaces all occurences of Pattern with Replace
/// Modifies the content of rString
static void ReplacePattern(std::string& rString, const std::string& rPattern, const std::string& rReplace);


//// Count the Appearences of Char
/// Case Sensetive
static unsigned int CountChar(const std::string& rString, char Char);

//// Count the Sum of appearences of the Chars
/// Case Sensetive
static unsigned int CountChars(const std::string& rString, const std::string& rChars);

//// Count the Appearences of Pattern
/// Case Sensetive
static unsigned int CountPattern(const std::string& rString, const std::string& rPattern);

//// Returns true if rString ends with rEnd
static bool EndsWith(const std::string& rString, const std::string& rEnd);

//// Returns true if rString starts with rStart
static bool StartsWith(const std::string& rString, const std::string& rStart);

//// Returns true if rString starts with rStart
static bool HasPatternAtPosition(const std::string& rString, const std::string& rPattern, unsigned int position);

/*
/// Modifies the rString, all lowercase letters are uppercase afterwards
static void ToUpper(std::string& rString);
static std::string ToUpper(const std::string& rString);

/// Modifies the rString, all uppercase letters are lowercase afterwards
static void ToLower(std::string& rString);
static std::string ToLower(const std::string& rString);
*/

//// Returns true if there are Only Letters in the String
static bool HasOnlyLetters(const std::string& rString);

//// Returns true if there are Only Numbers in the String
static bool HasOnlyNumbers(const std::string& rString);

//// Returns true if there is at least 1 Letter in the String
static bool HasLetters(const std::string& rString);

//// Returns true if there is at least 1 Number in the String
static bool HasNumbers(const std::string& rString);

} // namespace String
} // namespace Types
} // namespace Librepp

#include "String.inl"

#endif /// LIBREPP_UTILITY_STRING_H_
