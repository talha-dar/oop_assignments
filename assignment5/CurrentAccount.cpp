#include"CurrentAccount.h"

//constructor
CurrentAccount::CurrentAccount(const char* _title, const char* _accNumber, const double _balance, const double _transactionFee):BankAccount(_title, _accNumber, _balance){
  if(_transactionFee>0){
    transactionFee=_transactionFee;
  }
}

//copy constructor
CurrentAccount::CurrentAccount(const CurrentAccount& _obj):BankAccount(_obj){
  transactionFee=_obj.transactionFee;
}

//destructor
CurrentAccount::~CurrentAccount(){
  transactionFee=0;
}
//assignment operator
CurrentAccount& CurrentAccount::operator=(const CurrentAccount& _obj){
  if(this!=&_obj){
    BankAccount::operator=(_obj);
    transactionFee=_obj.transactionFee;
  }
  return *this;
}
//setters
void CurrentAccount::set_transactionFee(const double _fee){
  if(_fee>0){
    transactionFee=_fee;
  }
}

void CurrentAccount::set_requiredMinimumBalance(const double _requiredMinBal){
  if(_requiredMinBal>0){
    requiredMinimumBalance=_requiredMinBal;
  }
}

//getters
double CurrentAccount::get_transactionFee()const{
  return transactionFee;
}

double CurrentAccount::get_requiredMinimumBalance(){
  return requiredMinimumBalance;
}

//methods
void CurrentAccount::deposit(const double _bal){
  double currentBalance=get_balance();
  if(_bal>0){
    currentBalance+=_bal;
    set_balance(currentBalance);
  }
}

//methods
void CurrentAccount::withdraw(const double _bal){
  double currentBalance=get_balance();
  double withdrawl=_bal+transactionFee;
  if(_bal>0 && withdrawl>=currentBalance){
    currentBalance-=withdrawl;
    set_balance(currentBalance);
  }
}

void CurrentAccount::display()const{
  BankAccount::display();
  cout<<"\nCurrent Account Details: ";
  cout<<"\nTransaction Fee: "<<transactionFee;
  cout<<"\nRequired Minimum Balance: "<<requiredMinimumBalance;
}
