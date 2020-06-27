#include"InvestmentAccount.h"

InvestmentAccount::InvestmentAccount(const char* _title, const char*  _accNumber, const double _bal, const double _feeCharged, const double _percentProfit):BankAccount(_title, _accNumber, _bal){
  if(_feeCharged>0){
    transactionFee=_feeCharged;
  }
  if(_percentProfit>0){
    percentProfit=_percentProfit;
  }
}

//destructor
InvestmentAccount::~InvestmentAccount(){
  transactionFee=0;
  percentProfit=0;
}

//copy constructor
InvestmentAccount::InvestmentAccount(const InvestmentAccount& _obj):BankAccount(_obj){
  transactionFee=_obj.transactionFee;
  percentProfit=_obj.percentProfit;
}

//operator
InvestmentAccount& InvestmentAccount::operator=(const InvestmentAccount& _obj){
  if(this!=&_obj){
    BankAccount::operator=(_obj);
    transactionFee=_obj.transactionFee;
    percentProfit=_obj.percentProfit;
  }
  return *this;
}

//setters
void InvestmentAccount::set_transactionFee(const double _fee){
  if(_fee>0){
    transactionFee=_fee;
  }
}

void InvestmentAccount::set_precentageProfit(const double _pp){
  if(_pp>0){
    percentProfit=_pp;
  }
}

void InvestmentAccount::set_requiredMinimumBalance(const double _bal){
  if(_bal>0){
    minimumRequiredBalance=_bal;
  }
}

//getters
double InvestmentAccount::get_transactionFee()const{
  return transactionFee;
}

double InvestmentAccount::get_percentageProfit()const{
  return percentProfit;
}

double InvestmentAccount::get_minimumRequiredBalance(){
  return minimumRequiredBalance;
}

//methods
void InvestmentAccount::withdraw(const double _bal){
  double current=get_balance();
  double withdrawl=transactionFee+_bal;
  if(_bal>0 && current>=withdrawl){
    current-=withdrawl;
    set_balance(current);
  }
}

void InvestmentAccount::deposit(const double _bal){
  double current=get_balance();
  if(current>=transactionFee){
    current-=transactionFee;
  }
  if(_bal>0){
    current+=(_bal+_bal*percentProfit);
    set_balance(current);
  }
}

void InvestmentAccount::display()const{
  BankAccount::display();
  cout<<"\n\tInvestment Account details.";
  cout<<"\nTransaction Fee: "<<transactionFee;
  cout<<"\nPercent Profit: "<<percentProfit;
}
