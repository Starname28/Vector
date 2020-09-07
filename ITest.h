#pragma once
#include <ctime>

class ITest
{
public:
	ITest() = default;

	virtual ~ITest() = 0;

	virtual void addRandomElement() = 0;

	virtual void sort() = 0;

	virtual void erase() = 0;

	virtual void insert() = 0;

	virtual void clear() = 0;

	virtual void print() = 0;
};