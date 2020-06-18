#pragma once
#include<iostream>
#include<cstring>
#include"Department.h"
using namespace std;

// since outdoors departments work on first come first serve(for every specialist doctor, but we assume we have only one specialist), we can only prescribe medicine to one patient at a time, this patient is dereferenced by pointer attribute 'currentPatient'

// to prescribe medicine, we must first point currentPatient to a patient in Depart::patientRoster, in our case, PatientRoster has only one patient at any given time.

// we considet Department::PatientRoster[0] to be the next patient in queue, CurrentPatient is current patient being treated.

class MedicalDepartment:public Department{
private:
  Patient* currentPatient;
public:
  // default parametrized constructor
  MedicalDepartment(const int _doctorsCapacity=0);
  
  //destructor
  ~MedicalDepartment();
  
  //setters - mutators
  void setCurrentPatient(Patient* _currentPatient=nullptr);
  void updateCurrentPatient();// this will set currentPatient to patient in Department
  void setPatientInQueue(Patient* _nextPatient=nullptr);
  void prescribeMedicine(const char* _meds=nullptr);
  void displayCurrentPatient()const;
};
