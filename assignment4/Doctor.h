#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"
using namespace std;

class Doctor:public Person{
 private:
  static int doctorsCount;
  static int surgeonCount;
protected:
  bool surgeonStatus;//accessably by departments only
 public:
  Doctor(const char* _name=nullptr, const int _age=0, const char _sex='\0');
  ~Doctor();
  //getters
  bool get_surgeonStatus()const;
  static int get_doctorsCount();
  static int get_surgeonCount();
};

int Doctor::doctorsCount;
int Doctor::surgeonCount;
