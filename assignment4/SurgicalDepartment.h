#include <iostream>
#include"Department.h"
#include"OperationTheatre.h"
class SurgicalDepartment:public Department{
private:
  OperationTheatre* ops;
  int opsCount;
  int opsOccupied;
public:

  //default parametrized constructor
  SurgicalDepartment(const int _opsCount=0, const int _doctorsCapacity=0, const int _patientsCapacity=0);

  //destructor
  ~SurgicalDepartment();

  //setters and mutators
  void occupyOperationTheatre(Doctor* _doctor=nullptr, Patient* _patient=nullptr);
  void freeOperationTheatre(const int _count=0); //frees the i'th op in our ops*

  //getters
  int getOpsCount()const;
  int getOpsOccupied()const;
};
