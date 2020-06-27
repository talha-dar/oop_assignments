#include"BankAccount.h"

//constructor
BankAccount::BankAccount(const char* _title, const char* _accNumber, const double _bal){
  if(_title && _accNumber && _bal>0){

    title=new char[strlen(_title)+1]{'\0'};
    strcpy(title, _title);

    accountNumber=new char[strlen(_accNumber)+1]{'\0'};
    strcpy(accountNumber, _accNumber);

    balance=_bal;
  }
  else{
    title=nullptr;
    accountNumber=nullptr;
    balance=0;
  }
}

//copy constructor
BankAccount::BankAccount(const BankAccount& obj){

  if(obj.title){
    title=new char[strlen(obj.title)+1]{'\0'};
    strcpy(title, obj.title);
  }
  else{
    title=nullptr;
  }
  
  if(obj.accountNumber){
    accountNumber=new char[strlen(obj.accountNumber)+1]{'\0'};
    strcpy(accountNumber, obj.accountNumber);
  }
  else{
    accountNumber=nullptr;
  }
  
  if(obj.balance>0){
    balance=obj.balance;
  }
  else{
    balance=0;
  }
}

//destructor
BankAccount::~BankAccount(){

  if(title){
    delete[] title;
    title=nullptr;
  }
  
  if(accountNumber){
    delete[] accountNumber;
    accountNumber=nullptr;
  }
  
  balance=0;
}

//operator
BankAccount& BankAccount::operator=(const BankAccount& obj){

  if(this!=&obj){
    if(obj.title){
      if(title){
	delete[] title;
	title=nullptr;
      }
      title=new char[strlen(obj.title)+1]{'\0'};
      strcpy(title, obj.title);
    }
    
    if(obj.accountNumber){
      if(accountNumber){
	delete[] accountNumber;
	accountNumber=nullptr;
      }
      accountNumber=new char[strlen(obj.accountNumber)+1]{'0'};
      strcpy(accountNumber, obj.accountNumber);
    }

    balance=obj.balance;
  }
  
  return *this;
}

bool BankAccount::operator==(const char* _title){
  int lhsLen=0;
  int rhsLen=0;
  bool check=false;
  if(title && _title){
    lhsLen=strlen(title);
    rhsLen=strlen(_title);
    if(lhsLen==rhsLen){
      for(int i=0; i<lhsLen;i++){
	if(title[i]!=_title[i]){
	  return false;
	}
      }
      check=true;
    }
  }
  return check;
}

bool BankAccount::operator!=(const char* _title){
  int lhsLen=0;
  int rhsLen=0;
  bool check=true;
  if(title && _title){
    lhsLen=strlen(title);
    rhsLen=strlen(_title);
    if(lhsLen==rhsLen){
      for(int i=0; i<lhsLen;i++){
	if(title[i]!=_title[i]){
	  return true;
	}
      }
      check=false;
    }
  }
  return check;
}

ostream& BankAccount::operator<<(const BankAccount& _obj){
  cout<<"\nTitle: "<<_obj.title;
  cout<<"\nAccount Number: "<<_obj.accountNumber;
  cout<<"\nBalance: "<<_obj.balance;
  return cout;
}

istream& BankAccount::operator>>(const BankAccount& _obj){
  cout<<"\nEnter Title: ";
  cin>>_obj.title;
  cout<<"\nEnter Account Number: ";
  cin>>_obj.accountNumber;
  // cout<<"\nEnter Balance: ";
  // cin>>_obj.balance;
  return cin;
}
//setters
void BankAccount::set_title(const char* _title){
  if(_title){
    if(title){
      delete[] title;
      title=nullptr;
    }
    title=new char[strlen(_title)+1]{'\0'};
    strcpy(title, _title);
  }
}

void BankAccount::set_accountNumber(const char* _accNumber){
  if(_accNumber){
    if(accountNumber){
      delete[] accountNumber;
      accountNumber=nullptr;
    }
    accountNumber=new char[strlen(_accNumber)+1]{'\0'};
    strcpy(accountNumber, _accNumber);
  }
}

void BankAccount::set_balance(const double _bal){
  if(_bal>=0){
    balance=_bal;
  }
}

//getters
char* BankAccount::get_title()const{
  char* temp=nullptr;
  if(title){
    temp=new char[strlen(title)+1]{'\0'};
    strcpy(temp, title);
  }
  return temp;
}

char* BankAccount::get_accountNumber()const{
  char* temp=nullptr;
  if(accountNumber){
    temp=new char[strlen(accountNumber)+1]{'\0'};
    strcpy(temp, accountNumber);
  }
  return temp;
}

double BankAccount::get_balance()const{
  return balance;
}

//methods
void BankAccount::display()const{
  cout<<"\n\tBanking Account Details.";
  cout<<"\nTitle: "<<title;
  cout<<"\nAccount Name: "<<accountNumber;
  cout<<"\nBalance: "<<balance;
}
