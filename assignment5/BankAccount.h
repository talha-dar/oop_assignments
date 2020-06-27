#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class BankAccount{
private:
  char* title;
  char* accountNumber;
  double balance;
public:
  //default constructor
  BankAccount(const char* _title=nullptr, const char* _accNumber=nullptr, const double _bal=0);
  //copy constructor
  BankAccount(const BankAccount&);
  //destructor
  ~BankAccount();
  //operator
  BankAccount& operator=(const BankAccount&);
  bool operator==(const char* _title);
  bool operator!=(const char* _title);
  ostream& operator<<(const BankAccount&);
  istream& operator>>(const BankAccount&);
  //setters
  void set_title(const char* _title=nullptr);
  void set_accountNumber(const char* _accNumber=nullptr);
  void set_balance(const double _bal);
  //getters
  char* get_title()const;
  char* get_accountNumber()const;
  double get_balance()const;
  //methods (pure virtual ones)
  virtual void deposit(const double _bal=0)=0;
  virtual void withdraw(const double _bal=0)=0;
  virtual void display()const;
};
