#pragma once
#include "StringTester.h"
class String;

class Spell
{
public:
	Spell();
	Spell(const char* c);
	Spell(String spellName);
	Spell(Spell&& _other);
	Spell(const Spell& _other);
	~Spell();
	void Cast();
	
	bool Compare(Spell a, Spell b);

	void operator=(const Spell& other);
	void operator=(const char* c);
	void operator=(Spell&& other);
	bool operator <(Spell& other);

public:
	String spellName;
	//String castString;
};