#pragma once
#include<iostream>
#include"SurgicalDepartment.h"
using namespace std;

SurgicalDepartment::SurgicalDepartment(const int _opsCount, const int _doctorsCapacity, const int _patientsCapacity):Department(_doctorsCapacity, _patientsCapacity){
  if(_opsCount){
    ops=new OperationTheatre[_opsCount];
    opsCount=_opsCount;
  }
}

void SurgicalDepartment::occupyOperationTheatre(Doctor* _doctor, Patient* _patient){
  if(_doctor && _doctor->getSurgeonStatus() && _patient){
    if(opsOccupied<opsCount){
      ops[opsOccupied].setPatient(_patient);
      ops[opsOccupied].setSurgeon(_doctor);
      opsOccupied++;
    }
  }
}

void SurgicalDepartment::freeOperationTheatre(const int _count){
  if(_count>0 && _count<=opsOccupied){
    //will set the patient* and occupant* to nullptr
    ops[_count-1].setPatient();
    ops[_count-1].setSurgeon();
    opsOccupied--;
  }
}

void SurgicalDepartment::inductSurgeon(Doctor* _surgeon){
  if(_surgeon->getSurgeonStatus()){
    Department::inductDoctor(_surgeon);
  }
}

int SurgicalDepartment::getOpsCount()const{
  return opsOccupied;
}

int SurgicalDepartment::getOpsOccupied()const{
  return opsCount;
}
