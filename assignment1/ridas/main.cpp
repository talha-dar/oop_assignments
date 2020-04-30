#include "HugeIntiger.h"
#include "HugeIntiger.cpp"
#include <iostream>

using namespace std;
int main()
{
	HugeInteger h1, h2;
	h1.input();
	h2.input();
	
	cout<<"\nPrinting...";
	h1.print();
	h2.print();
	
	cout<<"\nSummation...";
	HugeInteger res=h1.sum(h2);
	res.print();
}
