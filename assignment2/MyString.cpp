#include "MyString.h"

//constructor
MyString::MyString(const int _size)
{
  if (_size > 0)
  {
    data = new char[_size]{'\0'};
    size = _size;
  }
  else
  {
    data = nullptr;
    size = 0;
  }
  count = 0;
}

//copy constructor
MyString::MyString(const MyString &str)
{
  if (str.data)
  {
    //create memory for this
    data = new char[str.size]{'\0'};
    //copy attributes
    count = str.count;

    for (int i = 0; i < count; i++)
    {
      data[i] = str.data[i];
    }
  }
  else
  {
    data = nullptr;
    size = 0;
    count = 0;
  }
}

//constructor with parameters
MyString::MyString(const MyString &str, const int start, const int end)
{
  //validate source data && range
  if (str.data && ((start > 0 && start < end) && end < str.size))
  {
    //calc size for this
    size = end - start;
    count = 0;
    //make memory on this
    data = new char[size + 1]{'\0'};
    char t = 'a';
    //copy given range to this
    for (int i = 0; i <= size; i++)
    {
      t = str.data[start - 1 + i];
      add(t);
    }
    //update attriubutes
    size++;
    count = size;
  }
}

//destructor
MyString::~MyString()
{
  if (data)
  {
    delete[] data;
    data = nullptr;
  }
}

//mutators
void MyString::add(char ch)
{
  if (count == size - 1 || size == 0)
  {
    arrayGrow(data, size);
  }
  data[count] = ch;
  count++;
}

void MyString::clear()
{
  if (count != 0 && data)
  {
    for (int i = 0; i < count; i++)
    {
      data[i] = '\0';
    }
    count = 0;
  }
}

//getters
int MyString::length() const
{
  return count;
}

//operators
MyString &MyString::operator=(const MyString &str)
{
  if (this != &str)
  {
    if (data)
    {
      delete[] data;
      data = nullptr;
    }
    data = new char[str.size];
    strCopy(data, str.data);
    size = str.size;
    count = str.count;
  }
  return *this;
}

MyString MyString::operator+(const MyString &str)
{
  MyString res;
  //validate both operands
  if (data && str.data)
  {
    //add data of this to res
    for (int i = 0; i < count; i++)
    {
      res.add(data[i]);
    }
    //add data of str to res
    for (int i = 0; i < str.count; i++)
    {
      res.add(str.data[i]);
    }
  }
  return res;
}

//const indexing op
const char &MyString::operator[](const int index) const
{
  if (index > 0 && index < count)
  { //validate arg index
    return data[index];
  }
  else
  {
    return data[0];
  }
}

//indexing op
char &MyString::operator[](const int index)
{
  if (index > 0 && index < count)
  { //validate arg index
    return data[index];
  }
  else
  {
    return data[0];
  }
}

//increments ops
MyString &MyString::operator++()
{ //pre-increment op
  if (count != 0)
  {
    for (int i = 0; i < count; i++)
    {
      data[i] = data[i] + 1;
    }
  }
  return *this;
}

MyString MyString::operator++(int)
{ //post-increment
  MyString temp(size);
  temp.count=0;
  if (count != 0)
  {
    //populate temp string
    for (int i = 0; i < count; i++)
    {
      temp.add(data[i]);
    }
    //increment this.data
    for (int i = 0; i < count; i++)
    {
      data[i] = data[i] + 1;
    }
    return temp;
  }
  else
  {
    return *this;
  }
}

//decrement ops
MyString &MyString::operator--()
{ //pre-increment op
  if (count != 0)
  {
    for (int i = 0; i < count; i++)
    {
      data[i] = data[i] - 1;
    }
  }
  return *this;
}

MyString MyString::operator--(int)
{ //post-increment
  MyString temp(size);
  temp.count=0;
  if (count != 0)
  {
    //populate temp string
    for (int i = 0; i < count; i++)
    {
      temp.add(data[i]);
    }
    //increment this.data
    for (int i = 0; i < count; i++)
    {
      data[i] = data[i] - 1;
    }
    return temp;
  }
  else
  {
    return *this;
  }
}
//other functions
void strDeepCopy(char *&dest, const char *src)
{

  int l = strLength(src);
  dest = new char[l + 1]{'\0'};

  //copy data
  for (int i = 0; i < l; i++)
  {
    dest[i] = src[i];
  }
}

void strCopy(char *&dest, const char *src, const int limit)
{
  int l = 0;
  if (src && dest)
  {
    //check how many elements must be copied
    if (limit == 0)
    {
      l = strLength(src);
    }
    else
    {
      l = limit;
    }

    //copy elements
    for (int i = 0; i < l; i++)
    {
      dest[i] = src[i];
    }
  }
}

int strLength(const char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i;
}

void arrayGrow(char *&dest, int &size)
{
  if (size == 0)
  {
    dest = new char[2]{'\0'};
    size++;
  }
  else
  {
    char *temp = new char[size]{'\0'};

    //backup dest data to temp
    strCopy(temp, dest, size);

    //delete dest, and make new memory
    delete[] dest;
    dest = nullptr;

    dest = new char[size * 2]{'\0'};

    //copy temp data to dest
    for (int i = 0; i < size; i++)
    {
      dest[i] = temp[i];
    }
    //delete temp
    delete[] temp;
    temp = nullptr;
  }
}

void print(const MyString &str)
{
  //print stuff
  int l = str.length();
  if (l != 0)
  {
    for (int i = 0; i < l; i++)
    {
      cout << str[i]<<" ";
    }
  }
  else
  {
    cout << "String is empty.";
  }
  cout<<endl;
}
