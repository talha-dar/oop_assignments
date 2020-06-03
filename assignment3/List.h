#pragma once
#include "MyNum.h"
#include "MyNum.cpp"

class List{
 private:
  MyNum* list;
  int size;
 public:
  //parametrized default constructor
  List(const int _list=0);
  //copy constructor
  List(const List&);
  //assignment operator
  List& operator=(const List&);
  //destructor
  ~List();
  //getters
  int get_size()const;
  //operators
  MyNum& operator[](const int)const;//subscript op
  List operator+(const List&);//concatenation
  friend ostream& operator<<(ostream&, const List&);//cout
  friend istream& operator>>(istream&, List&);// cin
  List& operator-();//unary op
  List& operator+();//unary op
};

void print(const List&);
