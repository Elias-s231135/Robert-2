#pragma once
#include "StringTester.h"
class String;

class Spell
{
public:
	Spell(String spellName, int damage);
	
	void Cast();
	
	bool Compare(Spell a, Spell b);

public:
	String spellName;
	int damage;
};