#include"Branch.h"

BankBranch::BankBranch(const int _capacity){
  if(_capacity>0){
    accounts=new BankAccount*[capacity];
    capacity=_capacity;
  }
  else{
    accounts=nullptr;
    capacity=0;
  }
  count=0;
  totalBalance=0;
}

BankBranch::~BankBranch(){
  if(accounts){
    delete[] accounts;
    accounts=nullptr;
    capacity=0;
  }
  count=0;
  totalBalance=0;
}

//getters
int BankBranch::get_capacity()const{
  return capacity;
}

int BankBranch::get_count()const{
  return count;
}

//operators
BankAccount* BankBranch::operator[](const int i){
  if(accounts[i]){
    return accounts[i];
  }
  else{
    return nullptr;
  }
}

const BankAccount* BankBranch::operator[](const int i)const{
  if(accounts[i]){
    return accounts[i];
  }
  else{
    return nullptr;
  }
}

//methods
void BankBranch::add_account(BankAccount* _obj){
  if(_obj && count<capacity){
    accounts[count++]=_obj;
  }
}

void BankBranch::delete_account(const char* _title){
  if(_title && count>0){
    for(int i=0; i<capacity; i++){
      if(accounts[i]){
	if(*accounts[i]==_title){
	  accounts[i]=nullptr;
	  count--;
	}
      }
    }
  }
}

void BankBranch::update_account(const char* _title){
  if(_title && count>0){
    for(int i=0; i<capacity; i++){
      if(accounts[i]){
	if(*accounts[i]==_title){
	  //
	}
      }
    }
  }
}

void BankBranch::find_account_by_number(const char* _accNum){
  char* temp=nullptr;
  int tempLen=0;
  int accNumlen=0;
  bool check=false;
  if(_accNum && count>0){
    accNumlen=strlen(_accNum);
    for(int i=0; i<capacity; i++){
      if(accounts[i]){
	temp=accounts[i]->get_accountNumber();
	tempLen=strlen(temp);
	if(tempLen == accNumlen){
	  for(int j=0; j<tempLen; j++){
	    if(temp[i]!=_accNum[i]){
	      check=false;
	      break;
	    }
	  }
	}
	if(check){
	  accounts[i]->display();
	  check=false;
	}
      }
    }
  }
}

void BankBranch::find_account_by_keyword(const char* _keyword){
  
}

void BankBranch::menu(BankAccount* _obj, const char* _title, const char* _accNum, const char* _keyword){
  int option=0;
  cout<<"\nEnter and option number to execute. ";
  cout<<"\n1. Add account\nDelete Account\nUpdate Account\nFind by number\nFind by keyword\n";
  cout<<"\nOption? =";
  cin>>option;
  if(option==1){
    add_account(_obj);
  }
  else if(option==2){
    delete_account(_title);
  }
  else if(option==3){
    update_account(_title);
  }
  else if(option==4){
    find_account_by_number(_accNum);
  }
  else if(option==5){
    find_account_by_keyword(_keyword);
  }
  else{
    cout<<"\nInvalid Option.";
  }
}

void BankBranch::create_file(){
  char database[]={"BankDatabase.txt"};
  ofstream fout(database);

  if(count>0){
    for(int i=0; i<count;i++){
      fout<<accounts[i]->get_title();
      fout<<accounts[i]->get_accountNumber();
      fout<<accounts[i]->get_balance();
    }
  }
  fout.close();
}
