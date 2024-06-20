#pragma once

#include <string>

class HashTable
{
public:

	HashTable(unsigned int size);

	~HashTable();

	int& operator [] (const std::string& str);

	const int& operator [] (const std::string str) const;

	int AddTo(std::string key, int value);

private:
	static unsigned int Hash(const std::string& str);

	int* m_data;

	unsigned int m_size;
};

