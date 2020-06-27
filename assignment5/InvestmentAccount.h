#pragma once
#include<iostream>
#include<cstring>
#include"BankAccount.h"
using namespace std;

class InvestmentAccount:public BankAccount{
private:
  double transactionFee;
  double percentProfit;
  static double minimumRequiredBalance;
public:
  //constructor
  InvestmentAccount(const char* _title=nullptr, const char*  _accNumber=nullptr, const double _bal=0, const double _feeCharged=0, const double percentProfit=0);
  //destructor
  ~InvestmentAccount();
  //copy constructor
  InvestmentAccount(const InvestmentAccount&);
  //operator
  InvestmentAccount& operator=(const InvestmentAccount&);
  //setters
  void set_transactionFee(const double _fee=0);
  void set_precentageProfit(const double _pp=0);
  static void set_requiredMinimumBalance(const double _bal);
  //getters
  double get_transactionFee()const;
  double get_percentageProfit()const;
  static double get_minimumRequiredBalance();
  //methods
  void withdraw(const double _bal=0)override;
  void deposit(const double _bal=0)override;
  void display()const override;
};

double InvestmentAccount::minimumRequiredBalance=1000;
