#include "TestString.h"

#include <iostream>
#include <algorithm>

TestString::TestString()
    : m_isMoreOne(true)
{
    srand(time(NULL));
}

TestString::~TestString()
{
}

void TestString::addRandomElement()
{
    for(size_t i = 0; i < 15; ++i)
        m_array.push_back(generator());

    print();
}

void TestString::sort()
{
    std::sort(m_array.begin(), m_array.end());

    print();
}

void TestString::erase()
{
    auto pred = [](
        char _symb
      )
    {
        if (_symb == 'a' ||
            _symb == 'b' ||
            _symb == 'c' ||
            _symb == 'd' ||
            _symb == 'e')
        {
            return true;
        }

        return false;
    };

    for (size_t i = 0; i < m_array.size(); ++i)
    {
        auto& str = m_array[i];

        auto iter = std::find_if(str.begin(), str.end(), pred);

        if (iter != str.end())
        {
            m_array.erase(i);
            --i;
        }
    }

    print();
}

void TestString::insert()
{
    for (size_t i = 0; i < 3; ++i)
    {
        if (m_array.size() > 1)
        {
            inserter(m_isMoreOne);
        }
        else 
        {
            inserter(!m_isMoreOne);
        }
    }
    print();
}

void TestString::clear()
{
    m_array.clear();
    print();
}

void TestString::print()
{
    std::cout << "CArray: ";

    for (const auto& el : m_array)
    {
        std::cout << el << ' ';
    }

    std::cout << std::endl;
}

std::string TestString::generator()
{
    std::string result;
    int wordSize = rand() % 10 + 1;

    for (size_t i = 0; i < wordSize; i++)
        result += static_cast<char>(rand() % 26 + 97);

    return result;
}

int TestString::generatorPosition(
    int _limit
  )
{
    return rand() % _limit;
}

void TestString::inserter(bool _isMoreOne)
{
    m_array.insert(
        generatorPosition(m_array.size() - static_cast<int>(_isMoreOne)),
        generator()
    );
}
