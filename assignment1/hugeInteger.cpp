#include "hugeInteger.h"

//constructors
hugeInteger::hugeInteger()
{
    dat = nullptr;
    size = 0;
}

hugeInteger::hugeInteger(int _size)
{
    if (_size <= 0)
    {
        cout << "\nArgument has no affect.";
        size = 0;
        dat = nullptr;
    }
    else
    {
        size = _size;
        dat = new char[size + 1]{'\0'};
    }
}

//destructor
hugeInteger::~hugeInteger()
{
    if (dat)
    {
        delete[] dat;
        dat=nullptr;
    }
}

//copy constructor
hugeInteger::hugeInteger(const hugeInteger &_hi)
{
    dat = new char[_hi.size + 1]{'\0'};
    strcpy(dat, _hi.dat);
    size = _hi.size;
}

//input
void hugeInteger::input()
{
    char temp[1000] = {'\0'};
    int c = 0;
    int num=0;
    //take inputs for hugeInteger
    if (size == 0)
    {
        cout << "\nEnter size of HugeInteger: ";
        cin >> num;
    }
    size = num;

    cout << "\nEnter a hugeInteger: ";
    cin.ignore();
    cin.getline(temp, 999);

    //validate hugeInteger
    //count left most zeroes
    while (temp[c] == '0')
    {
        c++;
    }

    //put rest of hugeInteger into dat
    dat = new char[size + 1]{'\0'};
    for (int i = 0; i < size; i++)
    {
        dat[i] = temp[i + c];
    }
}

//output
void hugeInteger::print()
{
    cout << endl;
    cout << dat;
}

//arithmatic
hugeInteger hugeInteger::sum(hugeInteger _hi)
{
    int sum = 0, tens_factor = 1, c = 0;
    int order = 0, temp = 0;
    int num = 0, summand = 0;
    hugeInteger result;

    if (size > _hi.size) //summation if left operand>right operand
    {
        while ((_hi.size - 1 - c) >= 0) //iterate through smaller hugeInteger, sum with corresponding part of larger hugeInt
        {
            num = (dat[size - 1 - c] - 48);
            summand = (_hi.dat[_hi.size - 1 - c] - 48);
            sum += ((num + summand) * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
        while (size - 1 - c >= 0) //iterate through remaining larger hugeInteger and add it to sum
        {
            num = (dat[size - 1 - c] - 48);
            sum = sum + (num * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
    }
    else //summation if left operand<right operand
    {
        while ((size - 1 - c) >= 0) //iterate through smaller hugeInteger, sum with corresponding part of larger hugeInt
        {
            num = (_hi.dat[_hi.size - 1 - c] - 48);
            summand = (dat[size - 1 - c] - 48);
            sum += ((num + summand) * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
        while (_hi.size - 1 - c >= 0) //iterate through remaining larger hugeInteger and add it to sum
        {
            num = (_hi.dat[_hi.size - 1 - c] - 48);
            sum = sum + (num * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
    }
    // found order of int sum produced
    temp = sum;
    while (temp != 0)
    {
        temp /= 10;
        order++;
    }
    //convert sum to char and place in result class
    result.size = order;
    result.dat = new char[result.size + 1]{'\0'};
    for (int i = result.size - 1; i >= 0; i--)
    {
        result.dat[i] = (sum % 10) + 48;
        sum /= 10;
    }
    //return the result
    return result;
}

hugeInteger hugeInteger::subtract(hugeInteger _hi)
{
    int sum = 0, tens_factor = 1, c = 0;
    int order = 0, temp = 0;
    int num = 0, subtrahend = 0;
    bool negative = false;
    hugeInteger result;

    if (size > _hi.size) //subtraction if left operand>right operand
    {
        result.size = size;
        while ((_hi.size - 1 - c) >= 0) //iterate through smaller hugeInteger, sum with corresponding part of larger hugeInt
        {
            num = (dat[size - 1 - c] - 48);
            subtrahend = (_hi.dat[_hi.size - 1 - c] - 48);
            sum += ((num - subtrahend) * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
        while (size - 1 - c >= 0) //iterate through remaining larger hugeInteger and add it to sum
        {
            num = (dat[size - 1 - c] - 48);
            sum = sum + (num * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
    }
    else //subtraction if left operand<right operand, the result will be nagative
    {
        negative = true;
        while ((size - 1 - c) >= 0) //iterate through smaller hugeInteger, sum with corresponding part of larger hugeInt
        {
            num = (_hi.dat[_hi.size - 1 - c] - 48);
            subtrahend = (dat[size - 1 - c] - 48);
            sum += ((num - subtrahend) * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
        while (_hi.size - 1 - c >= 0) //iterate through remaining larger hugeInteger and add it to sum
        {
            num = (_hi.dat[_hi.size - 1 - c] - 48);
            sum = sum + (num * tens_factor);
            tens_factor = tens_factor * 10;
            c++;
        }
    }
    //find order of int sum, make mem on result object, put int sum into result.dat after converison to char
    if (sum == 0) // if subtraction results in zero
    {
        result.size = 1;
        result.dat = new char[2]{'\0'};
        result.dat[0] = '0';
        return result;
    }
    else
    {
        if (negative)
        {
            cout << "\nSutraction result was negative for " << dat << "-" << _hi.dat << ".";
        }
        //find order of int sum produced
        temp = sum;
        while (temp != 0)
        {
            temp /= 10;
            order++;
        }
        //convert sum to char and place in result class
        result.size = order;
        result.dat = new char[result.size + 1]{'\0'};
        for (int i = result.size - 1; i >= 0; i--)
        {
            result.dat[i] = (sum % 10) + 48;
            sum /= 10;
        }
        return result;
    }
}

hugeInteger hugeInteger::multiply(hugeInteger _hi)
{
    int inner_sum = 0, total_sum = 0;           //total_sum is the result of the multiplication
    int prod = 0, multiplier = 0, multiplicand; //self explainatory
    int order = 0;                              //length of integer produced in total_sum
    int temp = 0;
    int tens_factor = 1, inner_tens_factor = 1; //to shift the summations one digit left
    int c = 0, d = 0;                           //for iterations
    hugeInteger result;

    //multiplication here
    if (size > _hi.size)
    {                                 //if left operand is greater than right
        while (_hi.size - 1 - c >= 0) //iterate backwards over smaller hugeInt
        {
            multiplier = _hi.dat[_hi.size - 1 - c] - 48; //multiply this digit of smaller hugeInt with every digit of larger hugeInt
            while (size - 1 - d >= 0)                    //iterate backwards over larger hugeInt
            {
                multiplicand = dat[size - 1 - d] - 48; //digit of larger hugeInt
                prod = multiplicand * multiplier;
                inner_sum += prod * inner_tens_factor;
                inner_tens_factor *= 10;
                d++;
            }
            total_sum += inner_sum * tens_factor;
            tens_factor *= 10;
            inner_sum = 0;
            inner_tens_factor = 1; //reset
            d = 0;
            c++;
        }
    }
    else //if left operand is smaller than right
    {
        while (size - 1 - c >= 0) //iterate backwards over smaller hugeInt
        {
            multiplier = dat[size - 1 - c] - 48; //multiply this digit of smaller hugeInt with every digit of larger hugeInt
            while (_hi.size - 1 - d >= 0)        //iterate backwards over larger int
            {
                multiplicand = _hi.dat[_hi.size - 1 - d] - 48; //digit of larger hugeInt
                prod = multiplicand * multiplier;
                inner_sum += prod * inner_tens_factor;
                inner_tens_factor *= 10;
                d++;
            }
            total_sum += inner_sum * tens_factor;
            tens_factor *= 10;
            inner_sum = 0;
            inner_tens_factor = 1; //reset
            d = 0;
            c++;
        }
    }
    //find the order of total_sum,  the final product of multiplication
    temp = total_sum;
    while (temp != 0)
    {
        temp /= 10;
        order++;
    }
    //make memory on object result and put total_sum in it after conversion to char
    result.size = order;
    result.dat = new char[result.size + 1]{'\0'};
    for (int i = result.size - 1; i >= 0; i--)
    {
        result.dat[i] = (total_sum % 10) + 48;
        total_sum /= 10;
    }
    //return result
    return result;
}

bool hugeInteger::equal(hugeInteger _hi)
{
    if (size == _hi.size) //no need to compare hugeInt if sizes are unequal
    {
        for (int i = 0; i < size; i++)
        {
            if (dat[i] != _hi.dat[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
