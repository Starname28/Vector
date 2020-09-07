#pragma once
#include "ITest.h"
#include "CArray.h"

#include <string>

class TestInt :
    public ITest
{
public:
    TestInt();

    ~TestInt() override;

    void addRandomElement() override;

	void sort() override;

	void erase() override;

	void insert() override;

	void clear() override;

	void print() override;

private:
    CArray<int> m_array;

	int generator(int _limit);
};

