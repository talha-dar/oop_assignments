#include"MedicalDepartment.h"

MedicalDepartment::MedicalDepartment(const int _doctorsCapacity):Department(_doctorsCapacity,1, 0){
  currentPatient=nullptr;
}

MedicalDepartment::~MedicalDepartment(){
  currentPatient=nullptr;
}

void MedicalDepartment::setPatientInQueue(Patient* _patient){
  currentPatient=_patient;
}

void MedicalDepartment::updateCurrentPatient(){
  currentPatient=getPatientZero();
}