#include"OperationTheatre.h"

OperationTheatre::OperationTheatre(Doctor* _surgeon, Patient* _patient):Room(_patient){
  surgeon=_surgeon;
}

OperationTheatre::~OperationTheatre(){
  surgeon=nullptr;
}

void OperationTheatre::setSurgeon(Doctor* _surgeon){
  if(_surgeon && _surgeon!=surgeon){
    if(_surgeon->getSurgeonStatus()){
      surgeon=_surgeon;
    }
  }
  else{
    surgeon=nullptr;
  }
}

void OperationTheatre::setPatient(Patient* _patient){
  //nullptr means theatre has no patient in it
  this->setOccupant(_patient);
}

Doctor OperationTheatre::getSurgeon()const{
  return *surgeon;
}

Patient OperationTheatre::getPatient()const{
  return this->getOccupant();
}
