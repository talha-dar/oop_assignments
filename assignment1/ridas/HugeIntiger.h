#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class HugeInteger{
private:
	char *dat;
	int size;
public:
	HugeInteger();
	HugeInteger(int);//it is a parameterized constructor that takes size of huge intiger
	HugeInteger(const HugeInteger &);
	~HugeInteger();
	void setSize(int);
	const int getSize();
	void input();
	void print();
	HugeInteger sum(HugeInteger);
	HugeInteger subtract(HugeInteger);
	HugeInteger multiply(const HugeInteger &);
	bool equal(const HugeInteger &);
  //  ~HugeInteger();
};