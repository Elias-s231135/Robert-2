#pragma once

#ifndef CUSTOM_STRING_HEADER

#define CUSTOM_STRING_HEADER

class String
{
public:
	String();
	String(const char* c);
	String(String& st);
	~String();

	char CharacterAt(size_t _index);

	int Length() const;

	bool EqualTo(const String& st) const;

	String Append(const String& c);
	String Prepend(const String& c);

	const char* CStr() const;

	void ToLower();
	void ToUpper();

	size_t Find(const String& c);
	//size_t Find(size_t _startIndex, const String _str);

	//String Replace(const String _find, const String& _replace);

	String ReadFromConsole();
	void WriteToConsole();

private:
	char* m_string;
};
#endif