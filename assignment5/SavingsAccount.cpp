#include"SavingsAccount.h"

//constructor
SavingsAccount::SavingsAccount(const char* _title, const char* _accNumber, const double _bal, const double _interestRate):BankAccount(_title, _accNumber, _bal){
  if(_interestRate>0 && _interestRate<=1){
    interestRate=_interestRate;
  }
}

//copy constructor
SavingsAccount::SavingsAccount(const SavingsAccount& obj):BankAccount(obj){
  interestRate=obj.interestRate;
}

//destructor
SavingsAccount::~SavingsAccount(){
  interestRate=0;
}

//operators
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& obj){
  if(this!=&obj){
    interestRate=obj.interestRate;
    BankAccount::operator=(obj);
  }
  return *this;
}

//setter
void SavingsAccount::set_interestRate(const double _interestRate){
  if(_interestRate>0 && _interestRate<=1){
    interestRate=_interestRate;
  }
}

//getters
double SavingsAccount::get_interestRate()const{
  return interestRate;
}

//methods
double SavingsAccount::calculateInterest(){
  return (interestRate*get_balance());
}

void SavingsAccount::deposit(const double _bal){
  double currentBalance=get_balance();
  if(_bal>0){
    currentBalance+=_bal;
    set_balance(currentBalance);
  }
}

void SavingsAccount::withdraw(const double _bal){
  double currentBalance=get_balance();
  double withdrawl=_bal*interestRate;
  if(_bal>0 && currentBalance>=withdrawl){
    withdrawl=currentBalance-withdrawl;
    set_balance(withdrawl);
  }
}

void SavingsAccount::display()const{
  BankAccount::display();
  cout<<"\n\tSavings Account Details.";
  cout<<"\nInterest Rate: "<<interestRate;
}
