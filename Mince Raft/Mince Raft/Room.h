#pragma once

class String;
class Item;

class Room
{
public:
	Room(String describe, Item*);
	~Room();
	const void rDescription();
public:
	Item* robert3;
private:

};