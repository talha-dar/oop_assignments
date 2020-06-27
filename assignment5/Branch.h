#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include"BankAccount.h"
using namespace std;

class BankBranch{
private:
  BankAccount** accounts;
  int capacity;
  int count;
  double totalBalance;
public:
  BankBranch(const int _capacity=0);
  ~BankBranch();
  void add_account(BankAccount* _obj=nullptr);
  void delete_account(const char* _title=nullptr);
  void update_account(const char* _title=nullptr);
  void find_account_by_number(const char* _accNum=nullptr);
  void find_account_by_keyword(const char* _keyword=nullptr);
  void menu(BankAccount* _obj=nullptr, const char* _title=nullptr, const char* _accNum=nullptr, const char* _keyword=nullptr);

  //operators
  BankAccount* operator[](const int);//non const subscript
  const BankAccount* operator[](const int)const;//const subscript
  ofstream& operator<<(const BankAccount&);
  istream& operator>>(const BankAccount&);

  //getters
  int get_capacity()const;
  int get_count()const;

  //File IOstream
  void create_file();
};
