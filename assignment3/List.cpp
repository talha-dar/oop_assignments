#include "List.h"

//parametrized constructor
List::List(const int _list){
  int temp=0, order=0;
  if(_list){//proceede here if argument was non zero

    //get order of argument int to create size of List accordingly
    temp=_list;
    while(temp!=0){
      temp/=10;
      order++;
    }
    size=order;//update size of this
    
    //create dynamic memory
    list=new MyNum[order];
    
    //assign digits of _list to this->list
    temp=_list;
    while(temp!=0){
      order--;
      list[order].set_value(temp%10);
      temp/=10;
    }
  }
  else{//do this if argument was 0
    list=new MyNum[1];
    list[0].set_value(0);
    size=1;
  }
}

//copy constructor
List::List(const List& obj){
  //update size
  size=obj.size;
  
  //create memory accordingly
  list=new MyNum[size];

  //copy list objects
  for(int i=0; i<size; i++){
    list[i]=obj.list[i];
  }
}

//assignment operator
List& List::operator=(const List & obj){
  if(this!=&obj){
    //delete this->list if needed
    if(list){
      delete[] list;
      list=nullptr;
    }

    //update size this->size
    size=obj.size;

    //create dynamic memory
    list=new MyNum[size];

    //copy each object of obj to this
    for(int i=0; i<size; i++){
      list[i]=obj.list[i];
    }
  }
  return *this;
}

//destructor
List::~List(){
  if(list){
    delete[] list;
    list=nullptr;
  }
  size=0;
}

//getters
int List::get_size()const{
  return size;
}
//operators

//subscript
MyNum& List::operator[](const int i)const{
  return list[i];
}

//concatenation operator
List List::operator+(const List & obj){
  List temp;

  //delete default memory and size from temp
  delete[] temp.list;
  temp.list=nullptr;
  temp.size=0;
  
  //create memory for concatenation
  temp.list=new MyNum[size+obj.size];

  //copy elements
  for(int i=0; i<size; i++){//copy elements of this to temp
    temp.list[temp.size++]=list[i];
  }
  for(int i=0; i<obj.size; i++){//copy elements of obj to temp
    temp.list[temp.size++]=obj.list[i];
  }

  //return concatenation result
  return temp;
}

//cout operator
ostream& operator<<(ostream& out, const List& obj){
  for(int i=0; i<obj.size; i++){
    out<<obj.list[i];
  }
  return out;
}

//cin operator
istream& operator>>(istream& in, List& obj){
  for(int i=0; i<obj.size; i++){
    in>>obj.list[i];
  }
  return in;
}

// unary op -
List& List::operator-(){
  for(int i=0; i<size;i++){
    list[i].make_negative();
  }
  return *this;
}

//unary op +
List& List::operator+(){
  for(int i=0; i<size; i++){
    list[i].make_positive();
  }
  return *this;
}

// prints List as a whole integer, displaying only one negative sign if all MyNum in the List are negative.
void print(const List& obj){
  List temp=obj;
  int polarity=1, len=0;
  if(temp[0].get_value()<0){
    polarity=-1;
  }
  if(polarity==-1){
    cout<<"-";
  }
  len=obj.get_size();
  for(int i=0; i<len; i++){
    cout<<polarity*obj[i].get_value();
  }
}
