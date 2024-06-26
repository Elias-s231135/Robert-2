#pragma once

#include <string>

class HashTable
{
public:

	HashTable(unsigned int size);

	~HashTable();

	void PrintAll();

	int& operator [] (const std::string& str);

	const int& operator [] (const std::string str) const;

	void AddTo(std::string key, int value);

	void Remove(std::string key);

	void Clear();

	//int Access(std::string key);

	//void;

private:
	unsigned int Hash(const std::string& str) const;
	int* m_data;

	unsigned int m_size;
};