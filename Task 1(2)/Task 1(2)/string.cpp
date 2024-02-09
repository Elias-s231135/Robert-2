#include "StringTester.h"
#include <iostream> //Access to strlen, strcpy, strcat, strcmp

String::String()
{
}

String::String(const char* c)
{
	//Dynamically allocating space for this object
	
}

String::String(const String& _other)
{
}

String::~String()
{
}

size_t String::Length() const
{
	return size_t();
}

char& String::CharacterAt(size_t _index)
{
	// TODO: insert return statement here
}

const char& String::CharacterAt(size_t _index) const
{
	// TODO: insert return statement here
}

bool String::EqualTo(const String& _other) const
{
	return false;
}

String& String::Append(const String& _str)
{
	// TODO: insert return statement here
}

String& String::Prepend(const String& _str)
{
	// TODO: insert return statement here
}

const char* String::CStr() const
{
	return nullptr;
}

String& String::ToLower()
{
	// TODO: insert return statement here
}

String& String::ToUpper()
{
	// TODO: insert return statement here
}

size_t String::Find(const String& _str)
{
	return size_t();
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	return size_t();
}

String& String::Replace(const String& _find, const String& _replace)
{
	// TODO: insert return statement here
}

String& String::ReadFromConsole()
{
	// TODO: insert return statement here
}

String& String::WriteToConsole()
{
	// TODO: insert return statement here
}

bool String::operator==(const String& _other)
{
	return false;
}

bool String::operator!=(const String& _other)
{
	return false;
}

String& String::operator=(const String& _str)
{
	// TODO: insert return statement here
}

char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
