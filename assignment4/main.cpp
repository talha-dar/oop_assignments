#include<iostream>
#include<cstring>
#include"Person.h"
#include"Person.cpp"
#include"Patient.h"
#include"Patient.cpp"
#include"Doctor.h"
#include"Doctor.cpp"
#include"Room.h"
#include"Room.cpp"
#include"Department.h"
#include"Department.cpp"
#include"OperationTheatre.h"
#include"OperationTheatre.cpp"
#include"SurgicalDepartment.h"
#include"SurgicalDepartment.cpp"
#include"MedicalDepartment.h"
#include"MedicalDepartment.cpp"
#include"Hospital.h"
#include"Hospital.cpp"

using namespace std;


int main(){
  //declare the hospital
  // medical department was constructor with just one doctor.
  Hospital one;


  //testing SurgicalDepartment

  //declare some patients and doctors
  Patient p1("talha", 20, 'm');
  Patient p2("dar", 21, 'f');
  Doctor d1("strange", 420, 'm');
  Doctor d2("sherlock", 52, 'f');

  //induct doctors as surgeons in surgery department
  d1.setSurgeonStatus(true);
  d2.setSurgeonStatus(true);
  one.surgical.inductSurgeon(&d1);
  one.surgical.inductSurgeon(&d2);
  
  //admit patients(admitted sequectially, so their id's are 1,2,3... and so on)
  one.surgical.admitPatient(&p1);//id=1
  one.surgical.admitPatient(&p2);//id=2
  one.surgical.schedulePatientForSurgery(2);
  cout<<endl;
  cout<<"\nPatients in surgical department: ";
  one.surgical.displayPatientFromRoster(1);
  cout<<endl;
  one.surgical.displayPatientFromRoster(2);

  cout<<endl;
  cout<<"\nDoctors in surgical department: ";
  one.surgical.displayDoctorFromRoster(1);
  cout<<endl;
  one.surgical.displayDoctorFromRoster(2);
  
  //testing medical department
  Patient p3("kenobi", 30, 'm');
  Patient p4("sheperd", 40, 'f');

  d1.setSurgeonStatus(false);
  one.medical.inductDoctor(&d1);

  one.medical.setCurrentPatient(&p3);
  one.medical.prescribeMedicine("rooh af zaa");

  // check attributes of current patient in medical department outdoor, after prescribing medicine.
  cout<<endl;
  cout<<"\nCurrent patient in medical outdoor after having been prescribed medicine: ";
  one.medical.displayCurrentPatient();

  cout<<endl<<endl;
  return 0;
}
