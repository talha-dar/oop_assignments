#pragma once
#include<iostream>
#include"Room.h"
#include"Doctor.h"
using namespace std;

class OperationTheatre:public Room{
 private:
  Doctor* surgeon;
public:
  OperationTheatre(Doctor* _surgeon=nullptr, Patient* _patient=nullptr);
  ~OperationTheatre();
  //setter
  void set_surgeon(Doctor* _surgeon=nullptr);
  void set_patient(Patient* _patient=nullptr);
  //getter
  Doctor get_surgeon()const;
  Patient get_patient()const;
};
