#pragma once
#include<iostream>
using namespace std;
class HugeIntiger{
private:
	char *dat;
	int size;
public:
	HugeIntiger();
	HugeIntiger(int);//it is a parameterized constructor that takes size of huge intiger
	HugeIntiger(const HugeIntiger &);
	void setSize(int);
	const int getSize();
	void Input();
	void print();
//	HugeIntiger Add(HugeIntiger);
//	HugeIntiger Sub(HugeIntiger);
//	HugeIntiger Multiply(const HugeIntiger &);
//	bool Equal(const HugeIntiger &);
	~HugeIntiger();
};
