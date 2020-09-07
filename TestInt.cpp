#include "TestInt.h"

#include <iostream>
#include <algorithm>

TestInt::TestInt()
{
	srand(time(NULL));
}

TestInt::~TestInt()
{
}

void TestInt::addRandomElement()
{
	for (size_t i = 0; i < 20; ++i)
	{
		m_array.push_back(generator(100));
	}

	print();
}

void TestInt::sort()
{
	std::sort(m_array.begin(), m_array.end());

	print();
}

void TestInt::erase()
{
	int readyToDelete = 0;

	for (size_t i = 0; i < m_array.size(); ++i)
	{
		if (readyToDelete == 1)
		{
			m_array.erase(i);
			--i;
			readyToDelete = 0;
			continue;
		}

		++readyToDelete;
	}

	print();
}

void TestInt::insert()
{
	for (size_t i = 0; i < 10; ++i)
	{
		m_array.insert(
			generator(m_array.size() - 1),
			generator(100));
	}

	print();
}

void TestInt::clear()
{
	m_array.clear();
	print();
}

void TestInt::print()
{
	std::cout << "CArray: ";
	for (const auto& el : m_array)
	{
		std::cout << el << ' ';
	}

	std::cout << std::endl;
}

int TestInt::generator(int _limit)
{
	return rand() % _limit;
}
