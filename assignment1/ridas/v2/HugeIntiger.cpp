#include"HugeIntiger.h"
#include<iostream>
#include<cstring>
using namespace std;

HugeIntiger::HugeIntiger()
{
	dat = nullptr;
	size = 0;
}

HugeIntiger::HugeIntiger(const  HugeIntiger &obj)
{
	int i = 0;
	if (obj.dat != nullptr)
	{
		while (obj.dat[i] != '\0')
		{
			i++;
		}
		size = obj.size;
		dat = new char[size];
		i = 0;
		while (i<size)
		{
			dat[i] = obj.dat[i];
			i++;
		}
		dat[size] = '\0';
	}
	else
	{
		dat = nullptr;
	}
}

HugeIntiger::HugeIntiger(int s)
{
	if (s > 0)
	{
		size = s;
	}
}

void HugeIntiger::setSize(int s)
{
	if (s > 0)
	{
		size = s;
	}
}

const int HugeIntiger::getSize()
{
	return size;
}

void HugeIntiger::Input()
{
	cout << "Enter the size of hugeintiger: " << endl;
	cin >> size;
	setSize(size);
	dat = new char[100];
	cout << "Enter your huge intiger :" << endl;
	cin >> dat;
	char *temp = new char[size];
	int i = 0, s2 = 0, index = 0;
	s2 = strlen(dat);
//	cout << " val of s2" << s2;
	//	cin.getline(dat,size);
	while (i<s2)
	{
		if (dat[i] == 48)
		{
			i++;
		}
		else {
			index = i;
			break;
		}
	}
	i = 0;
	while (i <size)
	{
		temp[i] = dat[index];
		//		cout << dat[index] << " ";
		i++, index++;
	}
	temp[i] = '\0';
	dat = new char[size];
	dat[size] = '\0';
	i = 0;
	while (i <size)
	{
		dat[i] = temp[i];
		dat[i] = dat[i] - 48;
//		dat[i] += 48;
		i++;
	}
	//		strcpy(dat,temp);
}
void HugeIntiger::print()
{
	int i = 0;
	while (i <size)
	{
		dat[i] +=48;
		i++;
	}
	cout << dat << endl;
}
HugeIntiger::~HugeIntiger()
{
	if (dat!=nullptr)
	{
	//	cout << " no data ";
		delete[]dat;
		dat = nullptr;
	}
	dat = nullptr;
}
