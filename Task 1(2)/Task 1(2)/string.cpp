#include "StringTester.h"
#include <iostream> //Access to strlen, strcpy, strcat, strcmp

String::String()
{
	//Create some new memory space to fill with data - new keyword
	//Fill that char[] with whatever data you want

}

String::String(const char* c)
{
	m_string = new char[(strlen(c)) + 1];
	strcpy_s(m_string, (strlen(c)) + 1, c);

	std::cout << c << std::endl;
}

String::String(String& st)
{

}

String::~String()
{

}

char String::CharacterAt(size_t _index)
{
	if (_index < 0 || _index > this->Length()) return '\0';
	else return m_string[_index]; /*Returns a char representing
	the character at the location. If index is less than 0 or 
	greater than length, return '\0'*/
}

int String::Length()
{
	return strlen(m_string); /* Returns an integer representing
	 the count of characters up to the null termination character */
}

bool String::EqualTo(const String& st) const
{
	if (strcmp(m_string, st.m_string) == 0) { return true; }
	else return false; /*Returns true if str contains the same characters.*/
}

String& String::Append(const String& c)
{
	/*Adds str to the end of the string*/
}
