#include "ITest.h"
#include "TestInt.h"
#include "TestString.h"

#include <iostream>

const bool isInt    = true;//for test
const bool isString = false;

std::string NameTest(bool _isInt)
{
    if (_isInt)
        return "\n\t\t***Test for Int***";
    else
        return "\n\t\t***Test for string***";
}

void Print(ITest& _test, bool _isInt)
{
    std::cout << NameTest(_isInt) << std::endl;

    std::cout << "\nAdd random elements : " << std::endl;
    _test.addRandomElement();

    std::cout << "\nSort elements : " << std::endl;
    _test.sort();

    std::cout << "\nErase elements : " << std::endl;
    _test.erase();

    std::cout << "\nInsert random element in random position : " << std::endl;
    _test.insert();

    std::cout << "\nClear all: " << std::endl;
    _test.clear();
}

int main()
{
    TestInt testInt;
    Print(testInt, isInt);

    TestString testString;
    Print(testString, isString);

    system("pause");
    return 0;
}