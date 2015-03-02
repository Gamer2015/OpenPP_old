#include "String.hpp"

#include <string>
#include <vector>


namespace Openpp
{
namespace Utility
{

/// Public Static Methods

std::vector< std::string > String::Split(const std::string& rString, unsigned int Length, const std::string& rEnding)
{
    std::vector<std::string> vStringResult;

	std::size_t pos;

	for(pos = 0; pos + Length < rString.length(); pos += Length)
	{
		vStringResult.push_back(rString.substr(pos, Length) + rEnding);
	}
	if(pos < rString.length() - 1)
		vStringResult.push_back(rString.substr(pos) + rEnding);

	return vStringResult;
}
std::vector<std::string> String::Explode(const std::string& rString, const std::string& rDelimiter, int SearchStart)
{
    std::vector<std::string> vStringResult;

	std::size_t pos;
	std::size_t posOld = 0;

	for( pos = rString.find_first_of(rDelimiter, SearchStart); pos != std::string::npos; pos = rString.find_first_of(rDelimiter, posOld = pos + 1) )
	{
		vStringResult.push_back(rString.substr(posOld, pos - posOld));
	}
	if( posOld != 0)
		vStringResult.push_back(rString.substr(posOld));

	return vStringResult;
}
std::vector<std::string> String::SoftExplode(const std::string& rString, const std::string& rDelimiter, int SearchStart)
{
    std::vector<std::string> vStringResult;

	std::size_t pos;
	int begin = 0;

	for( pos = rString.find_first_of(rDelimiter, SearchStart); pos != std::string::npos; pos = rString.find_first_of(rDelimiter, begin = pos + 1) )
	{
		vStringResult.push_back(rString.substr(begin - (begin==0?0:1), pos - begin + (begin==0?0:1)));
	}
	if(begin != 0)
		vStringResult.push_back(rString.substr(begin - 1));

	return vStringResult;
}
std::string String::Implode(const std::vector<std::string>& rvString, const std::string& rDelimiter)
{
    std::string StringResult;

    std::vector<std::string>::const_iterator cVectorIter;
    for(cVectorIter = rvString.begin(); cVectorIter != rvString.end(); ++cVectorIter)
	{
		StringResult.append(*cVectorIter);

		if(cVectorIter != rvString.end() - 1)
			StringResult.append(rDelimiter);
	}

	return StringResult;
}

std::string String::Repeat(const std::string& rString, unsigned int RepeatCount)
{
    std::string StringResult;

	for(int i = 0; i < RepeatCount; i++)
		StringResult += rString;

	return StringResult;
}
void String::Trim(std::string& rString, const std::string& rTrimChars)
{
    std::string::iterator StringIter;
    for(StringIter = rString.begin(); StringIter != rString.end(); ++StringIter)
	{
		if(rTrimChars.find(*StringIter) == std::string::npos)
			break;
		else
			rString.erase(StringIter--);
	}
	if(StringIter != rString.end())
	{
		for(StringIter = rString.end() - 1; StringIter >= rString.begin(); --StringIter)
		{
			if(rTrimChars.find(*StringIter) == std::string::npos)
				break;
			else
				rString.erase(StringIter);
		}
	}
}
std::string String::Reverse(const std::string& rString)
{
    std::string StringResult;

    std::string::const_iterator cStringIter;
    for(cStringIter = rString.end() - 1; cStringIter >= rString.begin(); --cStringIter)
	{
		StringResult += *cStringIter;
	}
	return StringResult;
}

void String::InsertBeforePattern(std::string& rString, const std::string& rPattern, const std::string& rSequence)
{
	int SequenceLength = rSequence.length();

	for(std::size_t found = rString.find(rPattern); found != std::string::npos; found = rString.find(rPattern,found+1))
	{
		rString.insert(found, rSequence);
		found += SequenceLength;
	}
}
void String::HaveBeforePattern(std::string& rString, const std::string& rPattern, const std::string& rSequence)
{
	int SequenceLength = rSequence.length();

	for(std::size_t found = rString.find(rPattern); found != std::string::npos; found = rString.find(rPattern,found+1))
	{
		if(found < SequenceLength || rString.substr(found - SequenceLength, SequenceLength).compare(rSequence) != 0)
		{
			rString.insert(found, rSequence);
			found += SequenceLength;
		}
	}
}
void String::HaveCharsBeforePattern(std::string &rString, const std::string &rPattern, const std::string &rChars, char rInsert)
{
	for(std::size_t found = rString.find(rPattern); found != std::string::npos; found = rString.find(rPattern,found+1))
	{
		if(found > 0)
		{
			if(!(rChars.find(rString[found-1]) != std::string::npos))
			{
				rString.insert(rString.begin() + found, rInsert);
				found += 1;
			}
		}
		else if(found == 0)
		{
			rString.insert(rString.begin() + found, rInsert);
			found += 1;
		}
	}
}

void String::ReplaceChar(std::string& rString, char Char, char Replace)
{
	for(std::size_t found = rString.find_first_of(Char); found != std::string::npos; found = rString.find_first_of(Char, found + 1))
	{
		rString[found] = Replace;
	}
}
void String::ReplaceChars(std::string& rString, const std::string& rChars, const std::string& rReplaces)
{
	if(rChars.length() > rReplaces.length())
	{
		std::string Replaces;
		Replaces.append(rReplaces);

		ReplaceChars(rString, rChars, Replaces);
		return;
	}

	std::size_t foundCharPos;

	for(std::size_t found = rString.find_first_of(rChars); found != std::string::npos; found = rString.find_first_of(rChars,found + 1))
	{
		foundCharPos = rChars.find_first_of(rString[found]);
		rString[found] = rReplaces[foundCharPos];
	}
}
void String::ReplaceChars(std::string& rString, const std::string& rChars, std::string& rReplaces)
{
	while(rChars.length() > rReplaces.length())
		rReplaces.append(" ");

	ReplaceChars(rString, rChars, rReplaces);
}
void String::ReplacePattern(std::string& rString, const std::string& rPattern, const std::string& rReplace)
{
	int PatternSize = rPattern.length();
	int ReplaceSize = rReplace.length();
    int SizeDiff = ReplaceSize - PatternSize;

	for(std::size_t found = rString.find(rPattern); found != std::string::npos; found = rString.find(rPattern, found + 1))
	{
		rString.replace(found, PatternSize, rReplace);
        found += SizeDiff;
	}
}

unsigned int String::CountChar(const std::string& rString, char Char)
{
	unsigned int count = 0;

	std::size_t found = rString.find_first_of(Char);
	while (found != std::string::npos)
	{
		count++;
		found = rString.find_first_of(Char,found+1);
	}

	return count;
}
unsigned int String::CountChars(const std::string& rString, const std::string& rChars)
{
	unsigned int count = 0;
	std::size_t found = rString.find_first_of(rChars);

	while (found != std::string::npos)
	{
		count++;
		found = rString.find_first_of(rChars,found+1);
	}

	return count;
}
unsigned int String::CountPattern(const std::string& rString, const std::string& rPattern)
{
	unsigned int count = 0;

	std::size_t found = rString.find(rPattern);
	while (found != std::string::npos)
	{
		count++;
		found = rString.find(rPattern,found+1);
	}

	return count;
}

bool String::EndsWith(const std::string& rString, const std::string& rEnd)
{
	return (rString.substr(rString.length() - rEnd.length(), rEnd.length()).compare(rEnd) == 0);
}
bool String::StartsWith(const std::string& rString, const std::string& rStart)
{
	return (rString.substr(0, rStart.length()).compare(rStart) == 0);
}
bool String::HasPatternAtPosition(const std::string& rString, const std::string& rPattern, unsigned int position)
{
	if(position + rPattern.length() > rString.size())
		return false;

	return (rString.substr(position, rPattern.length()).compare(rPattern) == 0);
}


bool String::HasOnlyLetters(const std::string& rString)
{
	if(rString.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
	{
		return false;
	}
	return true;
}
bool String::HasOnlyNumbers(const std::string& rString)
{
	if(rString.find_first_not_of("0123456789") != std::string::npos)
	{
		return false;
	}
	return true;
}
bool String::HasLetters(const std::string& rString)
{
	if(rString.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
	{
		return true;
	}
	return false;
}
bool String::HasNumbers(const std::string& rString)
{
	if(rString.find_first_of("0123456789") != std::string::npos)
	{
		return true;
	}
	return false;
}

} // namespace Types
} // namespace Openpp
