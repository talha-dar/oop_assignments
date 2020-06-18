#include"Department.h"

Department::Department(const int _doctors, const int _patient, const int _rooms){
  if(_doctors>0){
    doctorsRoster=new Doctor*[_doctors]{nullptr};
    doctors=_doctors;
  }
  else{
    doctors=0;
  }
  if(_patient>0){
    patientsRoster=new Patient*[_patient]{nullptr};
    patients=_patient;
  }
  else{
    patients=0;
  }
  if(_rooms>0){
    roomsList=new Room[_rooms]{nullptr};
    rooms=_rooms;
  }
  else{
    rooms=0;
  }
  doctorsCount=0;
  patientsCount=0;
}

Department::~Department(){
  if(doctorsRoster){
    for(int i=0; i<doctors;i++){
      if(doctorsRoster[i]){
	delete doctorsRoster[i];
	doctorsRoster[i]=nullptr;
      }
    }
    delete[] doctorsRoster;
    doctorsRoster=nullptr;
  }
  if(patientsRoster){
    for(int i=0; i<patients;i++){
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
  if(doctorsCount<doctors){
    if(_doctorptr){
      doctorsRoster[doctorsCount]=_doctorptr;
      doctorsCount++;
    }
  }
}

void Department::admitPatient(Patient* _patientptr){
  if(patientsCount<patients){
    if(_patientptr){
      patientsRoster[patientsCount]=_patientptr;
      patientsCount++;
    }
  }
}
