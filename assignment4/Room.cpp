#include"Room.h"

//default parametrized constructor
Room::Room(Patient* _occupant){
  if(_occupant){
    occupant=_occupant;
  }
  else{
    occupant=nullptr;
  }
}

//destructor
Room::~Room(){
  occupant=nullptr;
}

//setters
void Room::set_occupant(Patient* _occupant){
  if(_occupant){
    occupant=_occupant;
  }
}

//getters
Patient Room::get_occupant()const{
  return *occupant;
}
