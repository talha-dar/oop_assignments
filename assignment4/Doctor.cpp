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
int Doctor::get_doctorsCount(){
  return doctorsCount;
}

int Doctor::get_surgeonCount(){
  return surgeonCount;
}
