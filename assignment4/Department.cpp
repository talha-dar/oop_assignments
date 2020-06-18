#include"Department.h"

Department::Department(const int _doctorsCapacity, const int _patientsCapacity, const int _roomsAvailable){
  if(_doctorsCapacity>0){
    doctorsRoster=new Doctor*[_doctorsCapacity]{nullptr};
    doctorsCapacity=_doctorsCapacity;
  }
  else{
    doctorsCapacity=0;
  }
  if(_patientsCapacity>0){
    patientsRoster=new Patient*[_patientsCapacity]{nullptr};
    patientsCapacity=_patientsCapacity;
  }
  else{
    patientsCapacity=0;
  }
  if(_roomsAvailable>0){
    roomsList=new Room[_roomsAvailable]{nullptr};
    roomsAvailable=_roomsAvailable;
  }
  else{
    roomsAvailable=0;
  }
  doctorsCount=0;
  patientsCount=0;
}

Department::~Department(){
  if(doctorsRoster){
    for(int i=0; i<doctorsCapacity;i++){
      if(doctorsRoster[i]){
	delete doctorsRoster[i];
	doctorsRoster[i]=nullptr;
      }
    }
    delete[] doctorsRoster;
    doctorsRoster=nullptr;
  }
  if(patientsRoster){
    for(int i=0; i<patientsCapacity;i++){
      if(patientsRoster[i]){
	delete patientsRoster[i];
	patientsRoster[i]=nullptr;
      }
    }
    delete[] patientsRoster;
    patientsRoster=nullptr;
  }
  if(roomsList){
    delete[] roomsList;
    roomsList=nullptr;
  }
}

void Department::inductDoctor(Doctor* _doctorptr){
  if(doctorsCount<doctorsCapacity){
    if(_doctorptr){
      doctorsRoster[doctorsCount]=_doctorptr;
      doctorsCount++;
    }
  }
}

void Department::admitPatient(Patient* _patientptr){
  if(patientsCount<patientsCapacity){
    if(_patientptr){
      patientsRoster[patientsCount]=_patientptr;
      patientsCount++;
    }
  }
}
