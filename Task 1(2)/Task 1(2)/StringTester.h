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

	int Length();

	bool EqualTo(const String& st) const;

	String Append(const String& c);

private:
	char* m_string;
};
#endif