#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Person{
 private:
  char* name;
  int age;
  char sex;
 public:
  //default parametrized constructor
  Person(const char* _name=nullptr, const int _age=0, const char _sex='\0');
  //assignment constructor
  Person(const Person& obj);
  //destructor
  ~Person();
  //setters
  void setName(const char* _name=nullptr);
  void setAge(const int _age=0);
  void setSex(const char _sex='\0');
  //getters
  char* getName()const;
  int getAge()const;
  char getSex()const;
  //misc
  void display()const;
};
