#pragma once
#include<iostream>
#include<cstring>
#include"BankAccount.h"
using namespace std;

class CheckingAccount:public BankAccount{
private:
  double feeChargedPerTransaction;
public:
  //constructor
  CheckingAccount(const char* _title=nullptr, const char*  _accNumber=nullptr, const double _bal=0, const double _feeCharged=0);
  //copy constructor
  CheckingAccount(const CheckingAccount&);
  //destructor
  ~CheckingAccount();
  //operators
  CheckingAccount& operator=(const CheckingAccount&);
  //setters
  void set_feeChargedPeTransaction(const double _fee=0);
  //getters
  double get_feeChargedPerTransaction()const;
  //methods
  void withdraw(const double _bal=0)override;
  void deposit(const double _bal=0)override;
  void display()const override;
};
