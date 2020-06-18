#pragma once
#include<iostream>
#include<cstring>
#include"Patient.h"

class Room{
private:
  Patient* occupant;
public:
  Room(Patient* _occupant=nullptr);
  ~Room();

  //setter
  void set_occupant(Patient* _occupant=nullptr);

  //getters
  Patient get_occupant()const;
};
