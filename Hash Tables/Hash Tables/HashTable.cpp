#include "HashTable.h"
#include <iostream>

HashTable::HashTable(unsigned int size) : m_size(size), m_data(new int[size])
{
}

HashTable::~HashTable()
{
	delete[] m_data;
}

void HashTable::PrintAll()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_data[i] << ", ";
	}
	std::cout << "\n" << std::endl;

	//return *this;
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

void HashTable::AddTo(std::string key, int value)
{
	auto hashedKey = Hash(key) % m_size;
	m_data[hashedKey] = value;
}

void HashTable::Remove(std::string key)
{
	auto hashedKey = Hash(key) % m_size;
	m_data[hashedKey] = 0;
}

void HashTable::Clear()
{
	delete[] m_data;
	std::cout << "hash table must be reinitialised" << std::endl;
	m_data = 0;
}

//int HashTable::Access(std::string key)
//{	
//	return m_data[0//key];
//}

unsigned int HashTable::Hash(const std::string& str) const
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < str.length(); ++i)
	{
		hash = (hash * 1313) + str[i];
	}
	hash = hash % m_size;
	return (hash);
}