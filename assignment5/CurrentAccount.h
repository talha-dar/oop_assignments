#pragma once
#include<iostream>
#include<cstring>
#include"BankAccount.h"
using namespace std;

class CurrentAccount:public BankAccount{
private:
  double transactionFee;
  static double requiredMinimumBalance;
public:
  //constructor
  CurrentAccount(const char* _title=nullptr, const char* _accNumber=0, const double _balance=0, const double _transactionFee=0);
  //copy constructor
  CurrentAccount(const CurrentAccount&);
  //destructor
  ~CurrentAccount();
  //assignment operator
  CurrentAccount& operator=(const CurrentAccount&);
  //setters
  void set_transactionFee(const double _fee=0);
  static void set_requiredMinimumBalance(const double _requiredMinBal=0);
  //getters
  double get_transactionFee()const;
  static double get_requiredMinimumBalance();
  //methods
  void deposit(const double _bal=0)override;
  void withdraw(const double _bal=0)override;
  void display()const override;
};

double CurrentAccount::requiredMinimumBalance=1000;
