#ifndef OPENPP_TYPES_STRING_HPP_
#define OPENPP_TYPES_STRING_HPP_

#include <string>
#include <vector>

namespace Openpp
{
namespace Types
{

class String : public std::string
{
public:
	String() : std::string() {}
	String(const std::string& _string) : std::string(_string) {}
	String(const std::string& _string, size_t _position, size_t _length = std::string::npos) : std::string(_string, _position, _length) {}
	String(const char* const _cstring) : std::string(_cstring) {}
	String(const char* const _cstring, size_t _length) : std::string(_cstring, _length) {}
	String(size_t _length, char _character) : std::string(_length, _character) {}
	template <class InputIterator>
	String(InputIterator _start, InputIterator _end) : std::string(_start, _end) {}

	/// self explaining
	bool contains(const std::string& _string) const
	{
		return (this->find(_string) != ::std::string::npos);
	}

	/// self explaining
	String repeat(size_t _count) const
	{
		String _temp(*this);
		for(int i = 1; i < _count; ++i)
			_temp += *this;
		return _temp;
	}

	/// self explaining
	String reverse() const
	{
		return String(this->rbegin(), this->rend());
	}

	/// self explaining
	std::vector<String> split(const std::string& _delimiter, const std::string& _prefix="", const std::string& _postfix= "") const
	{
		std::vector<String> _result;

		std::size_t _pos_old = 0;
		std::size_t _pos_new = this->find_first_of(_delimiter);
		while (_pos_new != std::string::npos)
		{
			String _temp(*this, _pos_old, (_pos_new - _pos_old));
			_result.push_back(_prefix + _temp + _postfix);

			_pos_new = this->find_first_of(_delimiter, _pos_old = (_pos_new+1));
		}
		return _result;
	}
	std::vector<String> split(std::size_t _length, const std::string& _prefix="", const std::string& _postfix= "") const
	{
		std::vector<String> _result;

		std::size_t _position;

		for(_position = 0; _position + _length < this->length(); _position += _length)
		{
			_result.push_back(_prefix + this->substr(_position, _length) + _postfix);
		}
		if(_position < this->length() - 1)
			_result.push_back(_prefix + this->substr(_position) + _postfix);

		return _result;
	}

	/// self explaining
	String toupper() const
	{
		String _temp;
		for(const char* _character = this->c_str(); *_character != 0; ++_character)
			_temp += (char)std::toupper(*_character);
		return _temp;
	}
	String tolower() const
	{
		String _temp;
		for(const char* _character = this->c_str(); *_character != 0; ++_character)
			_temp += (char)std::tolower(*_character);
		return _temp;
	}

	/// Removes characters the sides of the string
	String trim(const String& _characters = " ") const
	{
		return String(this->begin()+this->find_first_not_of(_characters),
					  this->begin()+find_last_not_of(_characters) + 1);
	}
	String trimEnd(const String& _characters = " ") const
	{
		return String(this->begin(),
					  this->begin()+find_last_not_of(_characters) + 1);
	}
	String trimStart(const String& _characters = " ") const
	{
		return String(this->begin()+this->find_first_not_of(_characters),
					  this->end());
	}

	/// self explaining
	bool startsWith (const std::string& _string) const
	{
		return (this->substr(0, _string.length()) == _string);
	}
	bool endsWith (const std::string& _string) const
	{
		return (this->substr(this->length() - _string.length()) == _string);
	}
};

}
}

#endif // OPENPP_TYPES_STRING_HPP_
