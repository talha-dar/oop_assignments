#include<iostream>
#include"List.h"
#include"List.cpp"
using namespace std;

int main(){
  //testing List

  cout<<"\n\tConstructors.";
  //default constructor
  List l1(12345);
  cout<<"\nl1 after parametrized default construction: "<<l1;

  //copy constructor
  List l2=l1;
  cout<<"\nl2 after copy construction with l1: "<<l2;

  cout<<"\n\n\tAssignment.";
  //assignment operator
  List l3(67890);
  cout<<"\nl3 after parametrized default construction: "<<l3;
  
  (l2=l1)=l3;//cascading assignment case
  cout<<"\nCascading assignment (l2=l1)=l3. l2 becomes: "<<l2;

  cout<<"\n\n\tMutators.";
  //operators
  l3=l1+l2;//concatenation
  cout<<"\nl3=l1+l2 concatenation. l3 becomes:  "<<l3;

  cout<<"\n\n\tSubscripts.";
  //subscript
  cout<<"\nSubscripting first digit of l1 and last digit of l3: "<<l1[0]<<" "<<l3[9];
  cout<<"\nAssign first digit of l1 to last digit of l3: ";
  cout<<"\nOriginal l3: "<<l1;
  l3[9]=l1[0];
  cout<<"\nFinal l3: "<<l3;

  //Cin and Cout
  cout<<"\n\n\tCin and Cout";
  List l4(12345);
  cout<<"\ncin>>l4: ";
  cin>>l4;
  cout<<"\ncout<<l4: "<<l4;

  // Unary ops
  cout<<"\n\n\tUnary ops.";
  cout<<"\ncout<<-l4: ";
  cout<<-l4;
  cout<<"\nprint(-l4): ";
  print(-l4);
  cout<<"\ncout<<+l4: "<<+l4;
  cout<<"\nprint(+l4): ";
  print(+l4);
  
  //end here
  cout<<endl;
  return 0;
}
