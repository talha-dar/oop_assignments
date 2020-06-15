#include"Patient.h"

// default parametrized constructor
Patient::Patient(const int _patientID,const char* _name, const int _age, const char _sex):Person(_name, _age, _sex){
  cout<<"\nPatient constructor.";
  if(_patientID>0){
    patientID=_patientID;
  }
  else{
    patientID=0;
  }
  prescribedMedicines=nullptr;
  surguryStatus=false;
  roomOccupancyStatus=false;
}

// default parametrized constructor 2
Patient::Patient(const int _patientID,const Person& _obj):Person(_obj){
  cout<<"\nPatient constructor 2.";
  if(_patientID>0){
    patientID=_patientID;
  }
  else{
    patientID=0;
  }
  prescribedMedicines=nullptr;
  surguryStatus=false;
  roomOccupancyStatus=false;
}


//assignment constructor
Patient::Patient(const Patient& obj):Person(obj){
  patientID=obj.patientID;
  
  if(obj.prescribedMedicines){
    prescribedMedicines=new char[strlen(obj.prescribedMedicines)+1]{'\0'};
    strcpy(prescribedMedicines, obj.prescribedMedicines);
  }

  surguryStatus=obj.surguryStatus;
  roomOccupancyStatus=obj.roomOccupancyStatus;
  
}

//destructor
Patient::~Patient(){
  if(prescribedMedicines){
    delete[] prescribedMedicines;
    prescribedMedicines=nullptr;
  }
}

//setter
void Patient::set_patientID(const int _patientID){
  if(_patientID>0){
    patientID=_patientID;
  }
}

//getter
int Patient::get_patientID()const{
  return patientID;
}

char* Patient::get_prescribedMedicines()const{
  char* temp=nullptr;
  if(prescribedMedicines){
    temp=new char[strlen(prescribedMedicines)+1]{'\0'};
  }
  return temp;
}

bool Patient::get_surguryStatus()const{
  return surguryStatus;
}

//display
void Patient::display()const{
  Person::display();
  cout<<"\nPatient ID: "<<patientID;
  if(surguryStatus){
    cout<<"\nPrescribed Medicines: "<<prescribedMedicines;
  }
  cout<<"\nSurgury Status: ";
  if(surguryStatus){
    cout<<"Due.";
  }
  else{
    cout<<"Nothing scheduled.";
  }
}

