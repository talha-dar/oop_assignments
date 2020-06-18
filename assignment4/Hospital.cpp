#include"Hospital.h"

Hospital::Hospital():surgical(3, 10, 20), medical(1){
  //no other initializations here
}

Hospital::~Hospital(){
  //no dynamic memory to delete in Hospital class
}

