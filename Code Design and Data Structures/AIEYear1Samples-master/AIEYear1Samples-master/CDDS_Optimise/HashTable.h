#pragma once

#include "raylib.h"
#include <string>

class HashTable
{
public:

	HashTable(unsigned int size);

	~HashTable();

	//void PrintAll();

	Texture2D& operator [] (const std::string& str);

	const Texture2D& operator [] (const std::string str) const;

	void AddTo(std::string key, Texture2D value);

	void Remove(std::string key);

	void Clear();

	//int Access(std::string key);

	//void;

private:
	unsigned int Hash(const std::string& str) const;
	Texture2D* m_data;

	unsigned int m_size;
};