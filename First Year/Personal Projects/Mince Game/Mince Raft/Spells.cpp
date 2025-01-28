#include "Spells.h"
#include "StringTester.h"
#include <iostream>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for

Spell::Spell()
{
}

Spell::Spell(const char* c)
{
    spellName = c;
}

Spell::Spell(String spellName)
{
    this->spellName = spellName;
}

Spell::Spell(Spell&& _other)
{
    
}

Spell::Spell(const Spell& _other)
{
    this->spellName = _other.spellName;
}

Spell::~Spell()
{
}

void Spell::Cast()
{
    if (spellName == "graham")
    {
        cout << "Graham has been summoned." << endl;
        sleep_for(3s);
        while (true)
        {
            cout << "\"Graham is here.\"" << endl;
        }
    }
    else if (spellName == "expensive petroleum")
    {
        cout << "You create a bucket of petrol, but some splashes out, causing you to slip and spill it all." << endl;
    }
    else if (spellName == "friarball")
    {
        cout << "You cast a friarball, but it falls to the floor, causing the cluster of friars to scream in agony and roll away." << endl;
    }
    else if (spellName == "match")
    {
        cout << "You tried to manifest a match, but ended up conjuring a match 3 puzzle game." << endl;
    }
    else if (spellName == "pocket sand")
    {
        cout << "You tried to throw some sand, but a gust of wind blows it into your eyes." << endl;
    }
    else if (spellName == "rock")
    {
        cout << "You tried to find a rock to throw, but there weren't any nearby." << endl;
    }
}

bool Spell::Compare(Spell a, Spell b)
{
    return false;
}

void Spell::operator=(const Spell& other)
{
    this->spellName = other.spellName;
}

void Spell::operator=(const char* c)
{
    this->spellName = c;
}

void Spell::operator=(Spell&& other)
{

}

bool Spell::operator<(Spell& other)
{
    return this->spellName < other.spellName;
}
