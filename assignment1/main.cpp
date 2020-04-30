#include<iostream>
#include<cstring>
#include"hugeInteger.h"
#include"hugeInteger.cpp"
using namespace std;

int main(){
  hugeInteger h1, h2;
  h1.input();
  h2.input();
  hugeInteger res=h1.sum(h2);
  res.print();
  return 0;
}
