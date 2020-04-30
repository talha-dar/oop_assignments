#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
  char *data;
  int count; //number of characters in data
  int size = 0;

public:
  //parametrized constructor
  MyString(const int _size = 100); //-written
  
  //copy constructor
  MyString(const MyString &);                       //-written
  MyString(const MyString &, const int, const int); //copes obj to this, from a given range -written and tested

  //destructor
  ~MyString(); //-written and tested

  //mutators
  void add(const char); //appends a char to data-written and tested
  void clear();         //empties out data-written

  //getters
  int length() const; //-written and tested

  //operators
  MyString &operator=(const MyString &); //assignment - written
  MyString operator+(const MyString &);//concatenation - written

  char &operator[](const int index);             //indexing operator - written
  const char &operator[](const int index) const; //const indexing for const obj- written

  //increment & decrement ops
  MyString& operator ++ ();//pre-increment op
  MyString operator ++(int);//post-increment op
  MyString& operator -- ();//pre-decrement op
  MyString operator --(int);//post-decrement
  
  //char assignment op
  void operator =(const char*);
};

//other functions
void print(const MyString&);
void strDeepCopy(char *&, const char *);                  //copies till '\0' of src with memory management
void strCopy(char *&, const char *, const int limit = 0); //copies till src[limit] to dest, if 0, then copies till \0
int strLength(const char *);
void arrayGrow(char *&, int &); //grow array size by given increment
