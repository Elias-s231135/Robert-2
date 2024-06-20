#include "HashTable.h"

HashTable::HashTable(unsigned int size) : m_size(size), m_data(new int[size])
{
}

HashTable::~HashTable()
{
	delete[] m_data;
}

int& HashTable::operator[](const std::string& str)
{
	auto hashedKey = Hash(str) % m_size;
	return m_data[hashedKey];
}

const int& HashTable::operator[](const std::string str) const
{
	auto hashedKey = Hash(str) % m_size;
	return m_data[hashedKey];
}

int HashTable::AddTo(std::string key, int value)
{
	return 0;
}

unsigned int HashTable::Hash(const std::string& str)
{
	return 0;
}
