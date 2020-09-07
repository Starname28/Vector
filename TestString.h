#pragma once
#include "ITest.h"
#include "CArray.h"

#include <string>

class TestString :
    public ITest
{
public:

	TestString();

	~TestString() override;

	void addRandomElement() override;

	void sort() override;

	void erase() override;

	void insert() override;

	void clear() override;

	void print() override;

private:
	CArray<std::string> m_array;

	const bool m_isMoreOne;

	std::string generator();

	int generatorPosition(int _limit);

	void inserter(bool _isMoreOne);
};

