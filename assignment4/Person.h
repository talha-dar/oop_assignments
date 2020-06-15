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
  void set_name(const char* _name=nullptr);
  void set_age(const int _age=0);
  void set_sex(const char _sex='\0');
  //getters
  char* get_name()const;
  int get_age()const;
  char get_sex()const;
  //misc
  void display()const;
};
