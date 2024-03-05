#include "StringTester.h"
#include <iostream> //Access to strlen, strcpy, strcat, strcmp
#include "ctype.h"

using namespace std;

String::String()
{
	m_string = new char[8] {"DEFAULT"};

}

String::String(const char* c)
{
	m_string = new char[(strlen(c)) + 1];
	strcpy_s(m_string, (strlen(c)) + 1, c);

	cout << c << endl;
}

String::String(String& st)
{
	m_string = new char[(strlen(st.m_string)) + 1];
	strcpy_s(m_string, (strlen(st.m_string)) + 1, st.m_string);

	cout << st.m_string << endl;
}

String::~String()
{
	delete m_string;
}

char String::CharacterAt(size_t _index)
{
	if (_index < 0 || _index > this->Length()) return '\0';	// prevents attempts to read outside the array
	else return m_string[_index];
	/*Returns a char representing the character at the location. If index is less than 0 or 
	greater than length, return '\0'*/
}

int String::Length() const
{
	return strlen(m_string); /* Returns an integer representing
	 the count of characters up to the null termination character */
}

bool String::EqualTo(const String& st) const
{
	if (strcmp(m_string, st.m_string) == 0) { return true; }
	else return false; /*Returns true if str contains the same characters.*/
}

String String::Append(const String& c)
{
	int newLength = Length() + c.Length() + 1;
	char* string = new char[newLength];

	strcpy_s(string, newLength, this->m_string); //copies first part of string to new string
	strcat_s(string, newLength, c.m_string); //appends 2nd part of string to new string

	delete[] m_string;
	m_string = string;

	return string;
	/*Adds str to the end of the string*/
}

String String::Prepend(const String& c)
{
	int newLength = Length() + c.Length() + 1;
	char* string = new char[newLength];

	strcpy_s(string, newLength, c.m_string);
	strcat_s(string, newLength, m_string);

	delete[] m_string;
	m_string = string;

	return string; 
	//Adds str to the beginning of the string
}

const char* String::CStr() const
{
	/*Return the const char* that is useable with std::cout.eg: std::cout << str.cstr() << std::endl;*/
	
	return m_string;
}

void String::ToLower()
{
	//for (m_string[0] = tolower(m_string[0]))
	//{
	//	;
	//}

	for (int i = 0; i < Length(); i = i + 1)
	{
		m_string[i] = tolower(m_string[i]); //Translate current index into potential lowercase variation
	} //This is where i++ happens


	// use this logic inside a for loop for entire length of m_string
	//For everyone char in m_string
	//thisChar = tolower(thisChar)

	//Convert all characters to lowercase
}

void String::ToUpper()
{
	for (int i = 0; i < Length(); i = i + 1)
	{
		m_string[i] = toupper(m_string[i]);
	}
	//Convert all characters to uppercase
}

size_t String::Find(const String& c)
{
	for (int i = 0; i < (strlen(this->m_string) - strlen(c.m_string)); i++)
	{
		bool compareflag = true;
			for (int j = 0; j < (strlen(c.m_string)); j++)
			{
				if (m_string[i + j] != c.m_string[j])
				{
					compareflag = false;
				}
			}
			if (compareflag == true) {
				return i;
			}
	}
	return -1;
	//Returns the location of the findString.If not found, return -1
}

size_t String::Find(int _startIndex, const String& c)
{
	int startFrom = _startIndex;
	//cout << "Please Input Start Index" << endl;
	//cin >> startFrom;
	for (int i = startFrom; i < (strlen(this->m_string) - strlen(c.m_string)); i++)
	{
		bool compareflag = true;
			for (int j = 0; j < (strlen(c.m_string)); j++)
			{	 
				if (m_string[i + j] != c.m_string[j])
				{
					compareflag = false;
				}
		}
		if (compareflag == true) {
			return i;
		}
	}
	return -1;
	// Returns the location of the strToFind. Beginning the search from startIndex. If not found, return -1
}

String String::Replace(const String _find, const String& _replace)
{
	int testFind = this->Find(_find);
	if (testFind == -1)
	{
		return *this;
	}

	while (testFind != -1)		// allows Find to keep searching until it can't
	{
		char* beforeF = new char[testFind + 1];		// char pointer for everything before what needs to be replaced
		for (size_t i = 0; i < testFind + 1; i++)
		{
			beforeF[i] = m_string[i];
			if (i == testFind)
			{
				beforeF[i] = '\0';
			}
		}
		char* afterF = new char[strlen(m_string) - strlen(beforeF) - strlen(_find.m_string) + 1];	// char pointer for everything after what needs to be replaced
		int afterFIndex = 0;
		for (int i = testFind + strlen(_find.m_string); i <= strlen(m_string); i++)
		{
			afterF[afterFIndex] = m_string[i];
			afterFIndex++;
		}
		char* replace = new char[strlen(beforeF) + strlen(m_string) + strlen(afterF) + 1];	// char pointer for what needs to be replaced
		strcpy_s(replace, strlen(beforeF) + strlen(m_string) + strlen(afterF) + 1, beforeF);
		strcat_s(replace, strlen(beforeF) + strlen(m_string) + strlen(afterF) + 1, _replace.m_string);
		strcat_s(replace, strlen(beforeF) + strlen(m_string) + strlen(afterF) + 1, afterF);


		delete[]m_string;

		m_string = replace;

		testFind = this->Find(strlen(beforeF) + strlen(_replace.m_string), _find);	// makes Find only search after previous replaces, prevents repeat replacing

		delete[]beforeF;
		delete[]afterF;
	}

	return *this;
	// Replaces all occurrences of findString with replaceString
}

String String::ReadFromConsole()
{
	delete[] m_string;
	m_string = new char[64];
	cout << "Please Input String" << endl;
	cin.get (m_string,64);
	return *this;
	// Wait for input in the console window and store the result
}

void String::WriteToConsole()
{
	cout << m_string << endl;
}

bool String::operator==(const String otherstring)
{
	if (strcmp(this->m_string, otherstring.m_string) == 0) {
		return true;
	}
	else {
		return false;
	}
	// Returns true if lhs == rhs.
}

bool String::operator!=(const String otherstring)
{
	
	if (strcmp(this->m_string, otherstring.m_string) != 0) {
		return true;
	}
	else 
	{
		return false;
	}
	//return false;
	// Returns false if lhs == rhs.
}

char String::operator[](const int index)
{
		return CharacterAt(index);
	// Returns the character located at position n.
}

void String::operator=(const String& _str)
{
	delete[] m_string;
	m_string = new char[_str.Length() + 1];
	strcpy_s(m_string, _str.Length() + 1, _str.CStr());
	// Replaces the characters in lhs with the characters in rhs.
}

bool String::operator<(const String Roger)
{
	if (strcmp(this->m_string, Roger.m_string) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	// Returns true if this string comes before rhs in the alphabet
}