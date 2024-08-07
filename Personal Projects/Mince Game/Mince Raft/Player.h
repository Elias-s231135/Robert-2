#pragma once
#include <vector>
#include "Spells.h"

using namespace std;

class String;

class Player
{
public:
	Player();
	~Player();

	bool FindSpell(Spell spell);
public:
	Spell epSpell;
	Spell fSpell;
	Spell gSpell;
	Spell mSpell;
	Spell pSpell;
	Spell rSpell;

private:
	std::vector<Spell> spellList; //= { "expensive petroleum", "friarball", "graham", "match", "pocket sand", "rock" }; //char[]
};