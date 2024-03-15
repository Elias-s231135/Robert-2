#include "Player.h"
#include "StringTester.h"
#include <algorithm>
#include <iostream>

using namespace std;

Player::Player()
{
	epSpell = "expensive petroleum"; //make string (spell name)
	//epSpell = Spell(spellString); // make spell object using String object
	spellList.push_back(epSpell); // add spell object to the list
	
	//

	fSpell = "friarball"; //Replace information in string object
	//fSpell = spellString; // make new spell object using same string object (with new info)
	spellList.push_back(fSpell); //Place new spell object in the list

	gSpell = "graham";
	//gSpell = spellString;
	spellList.push_back(gSpell);

	mSpell = "match";
	//mSpell = spellString;
	spellList.push_back(mSpell);

	pSpell = "pocket sand";
	//pSpell = spellString;
	spellList.push_back(pSpell);

	rSpell = "rock";
	//rSpell = spellString;
	spellList.push_back(rSpell);
}

Player::~Player()
{
}

bool Player::FindSpell(Spell spell)
{
	std::sort(spellList.begin(), spellList.end());

	int l = 0;						//start of list
	int r = spellList.size() - 1;	//end of list
	
	while (l <= r)					//while start of list is less or equal to end of list
	{
		int m = ((l + r) / 2);		//m = start + end divided by 2, 0 + 5 = 5, / 2 = 2.5, = 2
		if (spellList[m].spellName == spell.spellName)	//if 2 = spell to look for
		{
			return true;								//found(?)
		}
		if (spellList[m].spellName < spell.spellName)	//if 2 < spell to look for
		{
			l = m + 1;									//l = 2 + 1, = 3
		}
		if (spellList[m].spellName > spell.spellName)	//
		{
			r = m - 1;
		}
		//break;
	}
	return false;
}
