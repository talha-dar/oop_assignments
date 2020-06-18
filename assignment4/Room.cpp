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
void Room::setOccupant(Patient* _occupant){
  occupant=_occupant;//nullptr means the room is empty so no validation here
}

//getters
Patient Room::getOccupant()const{
  return *occupant;
}
