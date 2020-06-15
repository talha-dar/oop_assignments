#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"
using namespace std;

class Patient:public Person{
private:
  int patientID;//set on construction
  char* prescribedMedicines;//set by MedicalDepartment
  bool surguryStatus;//set by SurgicalDepartment
  bool roomOccupancyStatus;//set by Surgicaldepartment
public:
  //default parametrized constructor
  Patient(const int _patientID=0, const char* _name=nullptr, const int _age=0, const char _sex='\0');
  Patient(const int _patientID, const Person& _obj);
  //assignment constructor
  Patient(const Patient&);
  //destructor
  ~Patient();
  //setter
  void set_patientID(const int _patientID=0);
  //getter
  int get_patientID()const;
  char* get_prescribedMedicines()const;
  bool get_surguryStatus()const;
  bool get_roomOccupancyStaus()const;
  // display
  void display()const;
};
