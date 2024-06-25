#include "String.h"
#include <cstring>
#include <cctype>
#include <iostream>

String::String()
	: m_str(nullptr)
	, m_length(0)
	, m_capacity(0)
{
}

String::String(const char* _str)
{
	m_length = strlen(_str);
	m_capacity = m_length + 1;
	m_str = new char[m_capacity];
	std::strcpy(m_str, _str);
}

String::String(const String& _other)
{
	m_length = _other.m_length;
	m_capacity = _other.m_capacity;
	m_str = new char[m_capacity];
	std::strcpy(m_str, _other.m_str);
}

String::~String()
{
	//Deletes the string.
	delete[] m_str;
}

size_t String::Length() const
{
	//Returns the length of the string.
	return m_length;
}

char& String::CharacterAt(size_t _index)
{
	//Returns the index of the character.
	if (_index < 0 || _index > m_length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	else
	{
		return m_str[_index];
	}
}

const char& String::CharacterAt(size_t _index) const
{
	//Returns the index of the character.
	int len = Length();

	if (_index < 0 || _index > m_length)
	{
		static char nullChar = '\0';
		return nullChar;
	}
	else
	{
		return m_str[_index];
	}
}


bool String::EqualTo(const String& _other) const
{
	//If the other string is equal to this string then it returns true.
	return strcmp(m_str, _other.m_str) == 0;
}

String& String::Append(const String& _str)
{
	//Adds a string to the end of another string.
	size_t newLength = m_length + _str.m_length;
	if (newLength >= m_capacity)
	{
		m_capacity = newLength + 1;
		char* newStr = new char[m_capacity];
		std::strcpy(newStr, m_str);
		std::strcat(newStr, _str.m_str);
		delete[] m_str;
		m_str = newStr;
	}
	else
	{
		std::strcat(m_str, _str.m_str);
	}
	m_length = newLength;
	return *this;
}

String& String::Prepend(const String& _str)
{
	//Adds a string to the front of another string.
	size_t newLength = m_length + _str.m_length;
	if (newLength >= m_capacity)
	{
		m_capacity = newLength + 1;
	}
	char* newStr = new char[m_capacity];
	std::strcpy(newStr, _str.m_str);
	std::strcat(newStr, m_str);
	delete[] m_str;
	m_str = newStr;
	m_length = newLength;
	return *this;
}

const char* String::CStr() const
{
	//Returns the string.
	return m_str;
}

String& String::ToLower()
{
	//Converts all characters to lowercase letters.
	for (size_t i = 0; i < m_length; ++i)
	{
		m_str[i] = tolower(m_str[i]);
	}
	return *this;
}

String& String::ToUpper()
{
	//Converts all characters to uppercase letters.
	for (size_t i = 0; i < m_length; ++i)
	{
		m_str[i] = toupper(m_str[i]);
	}
	return *this;
}

size_t String::Find(const String& _str)
{
	//Returns the index of the string you want to find.
	return Find(0, _str);
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	//Returns the index of the string you want to find.
	size_t strLength = _str.m_length;
	for (size_t i = _startIndex; i <= m_length - strLength; ++i)
	{
		if (strncmp(m_str + i, _str.m_str, strLength) == 0)
		{
			return i;
		}
	}
	return MAX_SIZE;
}

String& String::Replace(const String& _find, const String& _replace)
{
	//Finds all occurences of the string you want to find and replaces them all with the string you want to replace them with.
	size_t indexOfFind = Find(_find);
	while (indexOfFind != MAX_SIZE)
	{
		size_t newLength = m_length - _find.m_length + _replace.m_length;
		if (newLength >= m_capacity)
		{
			m_capacity = newLength + 1;
			char* newStr = new char[m_capacity];
			strncpy(newStr, m_str, indexOfFind);
			strcat(newStr, _replace.m_str);
			strcat(newStr, m_str + indexOfFind + _find.m_length);
			delete[] m_str;
			m_str = newStr;
		}
		else
		{
			char* temp = new char[m_capacity];
			strcpy(temp, m_str);
			strcpy(m_str + indexOfFind, _replace.m_str);
			strcat(m_str, temp + indexOfFind + _find.m_length);
			delete[]temp;
		}
		m_length = newLength;
		indexOfFind = Find(indexOfFind + _replace.m_length, _find);
	}
	return *this;
}

String& String::ReadFromConsole()
{
	//Stores things that are written in the console.
	char buffer[256];
	std::cin.getline(buffer, 256);
	*this = buffer;
	//delete[]buffer;
	return *this;
}

String& String::WriteToConsole()
{
	//Writes the string into the console.
	if (m_str != nullptr)
	{
		std::cout << m_str;
	}
	if (m_str == nullptr)
	{
		String nullChar = "\0";
		return nullChar;
	}
	else
	{
		return *this;
	}
}

bool String::operator==(const String& _other)
{
	//Returns true if the string is equal to the other string.
	return EqualTo(_other);
}

bool String::operator!=(const String& _other)
{
	//Returns true if the string is not equal to the other string.
	return !EqualTo(_other);
}

String& String::operator=(const String& _str)
{
	//Makes the string equal to the other string.
	if (this != &_str)
	{
		delete[] m_str;
		m_length = _str.m_length;
		m_capacity = _str.m_capacity;
		m_str = new char[m_capacity];
		strcpy(m_str, _str.m_str);
	}
	return *this;
}

char& String::operator[](size_t _index)
{
	//Returns the character at this index.
	//if (_index >= m_length)
	//{
	//	static char nullChar = '\0';
	//	return nullChar;
	//}

	return m_str[_index];
}

const char& String::operator[](size_t _index) const
{
	//Returns the character at this index.
	if (_index >= m_length)
	{
		static char nullChar = '\0';
		return nullChar;
	}

	return m_str[_index];
}

bool String::operator<(String& _other)
{
	//Returns true if the string is located before the other string in the alphabet.
	return std::strcmp(m_str, _other.m_str) < 0;
}

const bool String::operator<(const String& _other) const
{
	//Returns true if the string is located before the other string in the alphabet.
	return std::strcmp(m_str, _other.m_str) < 0;
}

String& String::operator+(const String& _str)
{
	//Returns a new string that combines a string and another string.
	String* result = new String(_str);
	result->Prepend(*this);
	return *result;
}

String& String::operator+=(const String& _str)
{
	//Combine two strings together.
	Append(_str);
	return *this;
}





