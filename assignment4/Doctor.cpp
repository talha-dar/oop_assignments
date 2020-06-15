#include"Doctor.h"

Doctor::Doctor(const bool _surgeonStatus, const char* _name, const int _age, const char _sex ):Person(_name, _age, _sex){
  surgeonStatus=_surgeonStatus;
  doctorsCount++;
  if(surgeonStatus){
    surgeonCount++;
  }
}

Doctor::~Doctor(){
  doctorsCount--;
  if(surgeonStatus){
    surgeonCount--;
  }
}

//setters
void Doctor::set_surgeonStatus(const bool _surgeonStatus){
  if(!surgeonStatus && _surgeonStatus){
    surgeonStatus=_surgeonStatus;
    surgeonCount++;
  }
  else if(surgeonStatus && !_surgeonStatus){
    surgeonStatus=_surgeonStatus;
    surgeonCount--;
  }
}

int Doctor::get_doctorsCount(){
  return doctorsCount;
}

int Doctor::get_surgeonCount(){
  return surgeonCount;
}

