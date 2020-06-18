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
  void setSurgeon(Doctor* _surgeon=nullptr);
  void setPatient(Patient* _patient=nullptr);
  //getter
  Doctor getSurgeon()const;
  Patient getPatient()const;
};
