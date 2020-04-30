#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class hugeInteger
{
private:
    //attributes
    char *dat;
    int size;

public:
    //constructor
    hugeInteger();
    hugeInteger(int);

    //destructor
    ~hugeInteger();

    //copy constructor
    hugeInteger(const hugeInteger &);

    //input
    void input();

    //output
    void print();

    //arithmatic
    hugeInteger sum(hugeInteger);
    hugeInteger subtract(hugeInteger);
    hugeInteger multiply(hugeInteger);
    bool equal(hugeInteger);
};