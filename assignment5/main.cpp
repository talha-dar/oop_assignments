#include<iostream>
#include"Branch.h"
#include"Branch.cpp"
#include"BankAccount.h"
#include"BankAccount.cpp"
#include"SavingsAccount.h"
#include"SavingsAccount.cpp"
#include "CurrentAccount.h"
#include"CurrentAccount.cpp"
#include"CheckingAccount.h"
#include"CheckingAccount.cpp"
#include"InvestmentAccount.h"
#include"InvestmentAccount.cpp"
using namespace std;

int main(){
  int choice=1;
  BankBranch Branch1(10);
  while(choice){
    Branch1.menu();
  }
  return 0;
}
