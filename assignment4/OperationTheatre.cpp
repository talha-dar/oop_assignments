#include"OperationTheatre.h"

OperationTheatre::OperationTheatre(Doctor* _surgeon, Patient* _patient):Room(_patient){
  surgeon=_surgeon;
}

OperationTheatre::~OperationTheatre(){
  surgeon=nullptr;
}

void OperationTheatre::set_surgeon(Doctor* _surgeon){
  if(_surgeon && _surgeon!=surgeon){
    if(_surgeon->get_surgeonStatus()){
      surgeon=_surgeon;
    }
  }
}

void OperationTheatre::set_patient(Patient* _patient){
  if(_patient){
    this->set_occupant(_patient);
  }
}

Doctor OperationTheatre::get_surgeon()const{
  return *surgeon;
}

Patient OperationTheatre::get_patient()const{
  return this->get_occupant();
}
