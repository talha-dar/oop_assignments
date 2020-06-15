#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"
using namespace std;

class Doctor:Person{
 private:
  bool surgeonStatus;
  static int doctorsCount;
  static int surgeonCount;
 public:
  Doctor(const bool _surgeonStatus=false, const char* _name=nullptr, const int _age=0, const char _sex='\0');
  ~Doctor();
  //setters
  void set_surgeonStatus(const bool _surgeonStatus=false);
  //getters
  bool get_surgeonStatus()const;
  static int get_doctorsCount();
  static int get_surgeonCount();
};

int Doctor::doctorsCount;
int Doctor::surgeonCount;
