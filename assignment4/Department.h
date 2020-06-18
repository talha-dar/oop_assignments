#pragma once
#include<iostream>
#include<cstring>
#include"Doctor.h"
#include"Patient.h"
#include"Room.h"
using namespace std;

class Department{
private:
  //attributes
  
  //set by constructor
  int doctors;
  int doctorsCount;
  Doctor** doctorsRoster;
  int patients;
  int patientsCount;
  Patient** patientsRoster;
  int rooms;
  Room* roomsList;
  static int departmentsCount;//total count of departments in hospital
public:
  //default parametrized constructor
  Department(const int _doctors=0, const int _patients=0, const int _rooms=0);
  //destructor
  ~Department();

  //setters and mutators
  void inductDoctor(Doctor* _doctorptr=nullptr);//add a preexisting doctor to current roster
  void admitPatient(Patient* _patientptr=nullptr);//adds either a pre-existing patient, or creates a new one from given attributes.
};

int Department::departmentsCount;
