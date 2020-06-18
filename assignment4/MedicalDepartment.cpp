#include"MedicalDepartment.h"

MedicalDepartment::MedicalDepartment(const int _doctorsCapacity):Department(_doctorsCapacity,1, 0){
  currentPatient=nullptr;
}

MedicalDepartment::~MedicalDepartment(){
  currentPatient=nullptr;
}

void MedicalDepartment::setCurrentPatient(Patient* _currentPatient){
  if(_currentPatient){
    currentPatient=_currentPatient;
  }
}
void MedicalDepartment::setPatientInQueue(Patient* _patient){
  currentPatient=_patient;
}

void MedicalDepartment::updateCurrentPatient(){
  currentPatient=getPatientZero();
}

void MedicalDepartment::prescribeMedicine(const char* _meds){
  if(currentPatient){
    currentPatient->setPrescribedMedicine(_meds);
  }
}

void MedicalDepartment::displayCurrentPatient()const{
  currentPatient->display();
}
