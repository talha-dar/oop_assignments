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
int Doctor::getDoctorsCount(){
  return doctorsCount;
}

int Doctor::getSurgeonCount(){
  return surgeonCount;
}
