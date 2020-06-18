#include"Department.h"

Department::Department(const int _doctorsCapacity, const int _patientsCapacity, const int _roomsAvailable){
  if(_doctorsCapacity>0){
    doctorsRoster=new Doctor*[_doctorsCapacity];
    doctorsCapacity=_doctorsCapacity;
  }
  else{
    doctorsCapacity=0;
    doctorsRoster=nullptr;
  }
  if(_patientsCapacity>0){
    patientsRoster=new Patient*[_patientsCapacity];
    patientsCapacity=_patientsCapacity;
  }
  else{
    patientsCapacity=0;
    doctorsRoster=nullptr;
  }
  if(_roomsAvailable>0){
    roomsList=new Room[_roomsAvailable];
    roomsAvailable=_roomsAvailable;
  }
  else{
    roomsAvailable=0;
    roomsList=nullptr;
  }
  doctorsCount=0;
  patientsCount=0;
}

Department::~Department(){
  if(doctorsRoster){
    delete[] doctorsRoster;
    doctorsRoster=nullptr;
  }
  if(patientsRoster){
    delete[] patientsRoster;
    patientsRoster=nullptr;
  }
  if(roomsList){
    delete[] roomsList;
    roomsList=nullptr;
  }
}

//setters
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

//getters
Patient* Department::getPatientZero()const{
  if(patientsRoster[0]){
    return patientsRoster[0];
  }
  else{
    return nullptr;
  }
}

Patient* Department::getPatientFromRoster(const int _index)const{
  if(_index>0 && _index<=patientsCount){
    if(patientsRoster[_index-1]){
      return patientsRoster[_index-1];
    }
  }
  return nullptr;
}

Doctor* Department::getDoctorFromRoster(const int _index)const{
  if(_index>0 && _index<=doctorsCount){
    if(doctorsRoster[_index-1]){
      return doctorsRoster[_index-1];
    }
  }
  return nullptr;
}

Room* Department::getRoomFromList(const int _index)const{
  if(_index>0 && _index<=roomsAvailable){
    return &roomsList[_index-1];
  }
  return nullptr;
}

void Department::displayDoctorFromRoster(const int _index)const{
  Doctor* temp=getDoctorFromRoster(_index);
  if(temp){
    temp->display();
  }
  else{
    cout<<"\nTarget doctor not found.";
  }
}

void Department::displayPatientFromRoster(const int _index)const{
  Patient* temp=getPatientFromRoster(_index);
  if(temp){
    temp->display();
  }
  else{
    cout<<"\nTarget patient not found.";
  }
}
