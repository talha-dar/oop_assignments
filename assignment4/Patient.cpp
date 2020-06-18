#include"Patient.h"

// default parametrized constructor
Patient::Patient(const char* _name, const int _age, const char _sex):Person(_name, _age, _sex){
  prescribedMedicines=nullptr;
  surgeryStatus=false;
  roomOccupancyStatus=false;
  patientID=patientCount;
  patientCount++;
}

// default parametrized constructor 2
Patient::Patient(const Person& _obj):Person(_obj){
  prescribedMedicines=nullptr;
  surgeryStatus=false;
  roomOccupancyStatus=false;
  patientCount++;
  patientID=(patientCount+1)*patientCount;//just a formula to ensure patientIDs remain unique
}


//assignment constructor
Patient::Patient(const Patient& obj):Person(obj){
  patientID=obj.patientID;
  
  if(obj.prescribedMedicines){
    prescribedMedicines=new char[strlen(obj.prescribedMedicines)+1]{'\0'};
    strcpy(prescribedMedicines, obj.prescribedMedicines);
  }

  surgeryStatus=obj.surgeryStatus;
  roomOccupancyStatus=obj.roomOccupancyStatus;
  
}

//destructor
Patient::~Patient(){
  if(prescribedMedicines){
    delete[] prescribedMedicines;
    prescribedMedicines=nullptr;
  }
  patientCount--;
}

//settters
void Patient::setPrescribedMedicine(const char* _meds){
  if(_meds){
    if(prescribedMedicines){
      delete[] prescribedMedicines;
      prescribedMedicines=nullptr;
    }
    prescribedMedicines=new char[strlen(_meds)+1]{'\0'};
    strcpy(prescribedMedicines, _meds);
  }
}

void Patient::setRoomOccupancyStatus(const bool _status){
  roomOccupancyStatus=_status;
}

void Patient::setSurgeryStaus(const bool _status){
  surgeryStatus=_status;
}

//getter
int Patient::getPatientID()const{
  return patientID;
}

char* Patient::getPrescribedMedicines()const{
  char* temp=nullptr;
  if(prescribedMedicines){
    temp=new char[strlen(prescribedMedicines)+1]{'\0'};
    strcpy(temp, prescribedMedicines);
  }
  return temp;
}

bool Patient::getSurgeryStatus()const{
  return surgeryStatus;
}

//display
void Patient::display()const{
  Person::display();
  cout<<"\nPatient ID: "<<patientID;
  if(prescribedMedicines){
    cout<<"\nPrescribed Medicines: "<<prescribedMedicines;
  }
  cout<<"\nSurgery Status: ";
  if(surgeryStatus){
    cout<<"Due.";
  }
  else{
    cout<<"Nothing scheduled.";
  }
}
