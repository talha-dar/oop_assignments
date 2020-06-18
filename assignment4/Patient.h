#pragma once
#include<iostream>
#include<cstring>
#include"Person.h"
using namespace std;

class Patient:public Person{
private:
  //attributes
  
  //set on construction
  int patientID;//unique to patient(...hopefully)
  static int patientCount;//total patients in the hospital
  
  //set by MedicalDepartmett
  char* prescribedMedicines;

  //set by SurgicalDepartment
  bool surgeryStatus;
  bool roomOccupancyStatus;
  
public:

  //default parametrized constructor
  Patient(const char* _name=nullptr, const int _age=0, const char _sex='\0');
  Patient(const Person& _obj);

  //assignment constructor
  Patient(const Patient&);

  //destructor
  ~Patient();

  //setter
  void setPrescribedMedicine(const char* _meds=nullptr);
  void setSurgeryStaus(const bool _status=false);
  void setRoomOccupancyStatus(const bool _status=false);
  
  //getter
  int getPatientID()const;
  char* getPrescribedMedicines()const;
  bool getSurgeryStatus()const;
  bool getRoomOccupancyStaus()const;

  // display
  void display()const;
};

int Patient::patientCount;
