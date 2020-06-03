#include "MyNum.h"

int MyNum::count;

//parametrized default constructor
MyNum::MyNum(const int _value){
  value=_value;
  MyNum::count++;
}

//destructor
MyNum::~MyNum(){
  MyNum::count--;
}

//setters
void MyNum::set_value(const int _value){
  value=_value;
}

//getters
int MyNum::get_value(){
  return value;
}

int MyNum::get_count(){
  return MyNum::count;
}

//operators
ostream& operator<<(ostream& out, const MyNum& obj){
  out<<obj.value;
  return out;
}

istream& operator>>(istream& in, MyNum& obj){
  in>>obj.value;
  return in;
}

//mutators
void MyNum::make_negative(){
  if(value>0){
    value*=-1;
  }
}

void MyNum::make_positive(){
  if(value<0){
    value*=-1;
  }
}
