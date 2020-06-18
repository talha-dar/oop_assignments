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
  void setOccupant(Patient* _occupant=nullptr);

  //getters
  Patient getOccupant()const;
};
