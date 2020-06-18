#pragma once
#include<iostream>
#include"SurgicalDepartment.h"
#include"MedicalDepartment.h"

class Hospital{
  //we need to be able to manipulate the attributes of surgical and department from outside of Hospital class, therefore we make them public, instead of private.
public:
  SurgicalDepartment surgical;
  MedicalDepartment medical;
  //constructor has a member initializer list in implementation, that takes default values as per scenarion given by assignment question.
  Hospital();
  //destructor
  ~Hospital();
  
  //setters
  
  //getters
};
