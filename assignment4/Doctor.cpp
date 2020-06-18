#include"Doctor.h"

Doctor::Doctor(const char* _name, const int _age, const char _sex ):Person(_name, _age, _sex),surgeonStatus(false){
  doctorsCount++;
}

Doctor::~Doctor(){
  doctorsCount--;
  if(surgeonStatus){
    surgeonCount--;
  }
}

//setters
void Doctor::setSurgeonStatus(const bool _status){
  surgeonStatus=_status;
}

//getters
int Doctor::getDoctorsCount(){
  return doctorsCount;
}

int Doctor::getSurgeonCount(){
  return surgeonCount;
}

bool Doctor::getSurgeonStatus()const{
  return surgeonStatus;
}
