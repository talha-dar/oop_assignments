#include"Person.h"

// constructor
Person::Person(const char* _name, const int _age, const char _sex){
  if(_name && _age>0 && _sex){
    //get_ length of _name, then create suitable memory on this->name and copy _name to it.
    int l=strlen(_name);
    name=new char[l+1]{'\0'};
    strcpy(name, _name);
    //set_ other attributes
    age=_age;
    sex=_sex;
  }
  else{
    name=nullptr;
    age=0;
    sex='\0';
  }
}

// assignment constructor
Person::Person(const Person& obj){
  if(obj.name){
    // create memory on this->name according to length of obj.name then copy obj.name to this->name
    name=new char[strlen(obj.name)+1]{'\0'};
    strcpy(name, obj.name);
  }
  age=obj.age;
  sex=obj.sex;
}

// destructor
Person::~Person(){
  if(name){
    delete name;
    name=nullptr;
  }
}

// set_ters

void Person::setName(const char* _name){
  if(_name){
    int l=strlen(_name);
    if(name){
      delete[] name;
      name=nullptr;
    }
    name=new char[l+1]{'\0'};
    strcpy(name, _name);
  }
}

void Person::setAge(const int _age){
  if(_age>0){
    age=_age;
  }
  else{
    age=0;
  }
}

void Person::setSex(const char _sex){
  if(_sex){
    sex=_sex;
  }
}

// get_ters

char* Person::getName()const{
  char* temp=nullptr;
  if(name){
    int l=strlen(name);
    temp=new char[l+1]{'\0'};
    strcpy(temp, name);
  }
  return temp;
}

int Person::getAge()const{
  return age;
}

char Person::getSex()const{
  return sex;
}

void Person::display()const{
  cout<<"\nName: "<<name;
  cout<<"\nAge: "<<age;
  cout<<"\nSex: "<<sex;
}
