#pragma once
#include <vector>

using namespace std;

class String;

class Player
{
public:
	Player();
	~Player();

	bool FindSpell(String spell);

private:
	std::vector<String> spellList;// = { "rock", "pocket sand", "friarball", "expensive petroleum", "match", "Graham" }; //char[]
};