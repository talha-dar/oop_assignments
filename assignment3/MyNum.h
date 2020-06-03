#pragma once
#include<iostream>
using namespace std;

class MyNum{
 private:
  int value;
  static int count;
 public:
  //parametrized default constructor
  MyNum(const int _value=0);
  //destructor
  ~MyNum();
  //setters
  void set_value(const int);
  //getters
  int get_value();
  static int get_count();
  //operators
  friend ostream& operator<<(ostream&, const MyNum&);
  friend istream& operator>>(istream&, MyNum&);
  //mutators
  void make_positive();
  void make_negative();
};
