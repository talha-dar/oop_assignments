#include"HugeIntiger.h"
HugeInteger::HugeInteger()
{
	dat = nullptr;
	size = 0;
}
HugeInteger::HugeInteger(const  HugeInteger &obj)
{
	int i = 0;
	if (obj.dat !=nullptr)
	{
		i=strlen(obj.dat);
		size = i;
		dat = new char[size+1]{'\0'};
		i = 0;
		while (i<size)
		{
			dat[i] = obj.dat[i];
			i++;
		}
	}
	else
	{
		dat =nullptr;
	}
}

HugeInteger::HugeInteger(int s)
{
	if (s > 0)
	{
		size = s;
	}
}

HugeInteger::~HugeInteger(){
	if(dat){
		delete[] dat;
		dat=nullptr;
		size=0;
	}
}
void HugeInteger::setSize(int s)
{
	if (s > 0)
	{
		size = s;
	}
}
const int HugeInteger::getSize()
{
	return size;
}
void HugeInteger::input()
{
	int c=0;
	cout << "Enter the size of hugeintiger: " << endl;
	cin >> size;
	setSize(size);
	cout << "Enter your huge intiger :" << endl;
	char* temp = new char[100]{'\0'};
	cin>>temp;
	while(temp[c]=='0'){
		c++;
	}
	dat=new char[strlen(temp)+1]{'\0'};
	for(int i=0;i<size;i++){
		dat[i]=temp[i+c];
	}
	delete[] temp;
	temp=nullptr;
}
void  HugeInteger::print()
{
	cout << "Huge Integer :" << dat << endl;
}
HugeInteger HugeInteger::sum(HugeInteger h)
{
	int i = 0, s = 0, j = 0;
	HugeInteger Sum;
	if (size > h.size)
	{
		s = size - h.size;
		char* temp = new char[size];
		while (i!= size)
		{
			temp[i] = h.dat[j];
			j++, i++;
		}
		temp[i] = '\0';
		i = 0;
		while (i != s)
		{
			h.dat[i] = 0;
			i++;
		}
		h.size = size;
		j = 0;
		while (i != size)
		{
			h.dat[i] = temp[j];
			i++, j++;
		}
		Sum.dat = h.dat;
	}
	else if (h.size > size)
	{
		s = h.size -size;
		char* temp = new char[h.size];
		while (i != h.size)
		{
			temp[i] = dat[j];
			j++, i++;
		}
		temp[i] = '\0';
		i = 0;
		while (i != s)
		{
		    dat[i] = 0;
			i++;
		}
		  size = h.size;
		j = 0;
		while (i != h.size)
		{
			dat[i] = temp[j];
			i++, j++;
		}
		dat[i] = '\0';
		Sum.dat = dat;
	}
	Sum.size = size+2;
	Sum.dat = new char[Sum.size];
	Sum.dat[Sum.size] = '\0';
	i = 0;
	int div=0, r = 0;
	size--,Sum.size--;
	int a = 0,c=0;
	while (size>=0)
	{
		Sum.dat[Sum.size] = dat[size] + h.dat[size];
		if (Sum.dat[Sum.size] > 9)
		{
			if (size == 0)
			{
				r = Sum.dat[Sum.size] % 10;
				div = Sum.dat[Sum.size]/ 10;
				Sum.dat[Sum.size] = r;
				Sum.dat[Sum.size-1] = div;
	    	}
			else 
			{
				r = Sum.dat[Sum.size] % 10;
				div = Sum.dat[Sum.size] / 10;
				Sum.dat[Sum.size] = r;
				dat[size - 1] += div;
			}  
		}
		size--,Sum.size--;
		c++;
	}
	size = h.size;
	Sum.size = size + 2;
	Sum.dat[Sum.size] = '\0';
	if (Sum.size>c)
	{
		Sum.dat[0] = 0;
	}
	j = 0;
	while (j< Sum.size)
	{
		Sum.dat[j] = Sum.dat[j] + 48;
		j++;
	}
	cout << endl;
	cout << "Sum : " << endl;
	return Sum;
}
HugeInteger HugeInteger::subtract(HugeInteger h)
{
	if (size < h.size)
	{
		cout << endl;
		cout << "Difference cannot be calculated left hand operand is smaller " << endl;
		h.dat = nullptr;
		return h;
	}
	else if (size == h.size)
	{
		if (dat[0] < h.dat[0])
		{
			cout << endl;
			cout << "Difference cannot be calculated left hand operand is smaller " << endl;
			return h;
		}
	}
	 if (size>h.size)
	{
		int s = 0,i=0,j=0;
		s = size - h.size;
		char* temp = new char[h.size];
		while (i!=h.size)
		{
			temp[i] = h.dat[i];
//			temp[i] += 48;
			 i++;
		}
		temp[i] = '\0';
//		cout << temp << endl;
		h.size = size;
		h.dat = new char[h.size];
		i = 0;
		while (i != s)
		{
			h.dat[i] = 0;
//			h.dat[i] = h.dat[i] - 48;
			i++;
		}
		j = 0;
		while (i != size)
		{
			h.dat[i] = temp[j];
			i++, j++;
		}
		h.dat[i] = '\0';
		i = 0;
		while (i <size)
				{
				h.dat[i] += 48;
				i++;
				}
//		subtract.dat = h.dat;
	}
	 int k = 0;
	 if (dat[k] == h.dat[k])
	 {
		 while (dat[k] == h.dat[k])
		 {
			 k++;
		 }
		 if (h.dat[k] > dat[k])
		 {
			 k = 0;
			 char *t = new char[size];
			 while (k < size)
			 {
				 t[k] = dat[k];
				 k++;
			 }
			 t[k] = '\0';
			 k = 0;
			 while (k<size)
			 {
				 dat[k] = h.dat[k];
				 k++;
			 }
			 dat[k] = '\0';
			 k = 0;
			 while (k<size)
			 {
				 h.dat[k] = t[k];
				 k++;
			 }
			 h.dat[k] = '\0';
		 }
	 }
	HugeInteger subtract;
	int i = size;
	subtract.size =size + 1;
	subtract.dat = new char[subtract.size];
	subtract.dat[subtract.size] = '\0';
	i--;
	int c = 0;
	while (i>=0)
	{
		if (dat[i] < h.dat[i])
		{
			dat[i-1]=dat[i-1]-1;
		    dat[i] += 10;
		}
		if (dat[i -1] == 0)
		{
			dat[i - 1] = dat[i - 1] - 1;
			dat[i] += 10;
		}
		subtract.dat[i] = dat[i] - h.dat[i];
		subtract.dat[i] = subtract.dat[i] + 48;
		i--,c++;
	}
//	c++;
	cout << endl;
	subtract.dat[c] = '\0';
	cout << "After Subtracting  ";
	return subtract;
}
HugeInteger HugeInteger::multiply(const HugeInteger &h)
{
	HugeInteger Mul;
	int div = 0, r = 0;
	Mul.dat = new char[50];
	Mul.dat[50] = '\0';
	char **temp = new char*[20];
	int i = 0;
	while (i < 20)
	{
		temp[i] = new char[20];
		temp[i][20] = '\0';
		i++;
	}
	char **temp2 = new char*[20];
	i = 0;
	int col = 0;
	while (i< 20)
	{
		temp2[i] = new char[20];
		temp2[i][20] = '\0';
		i++; 
	}
	for (int i = 0; i < 20; i++)
	{
		while (col < 20)
		{
			temp[i][col] -= 48;
			temp[i][col] = 0;
			col++;
		}
		col = 0;
	}
	i = 0;
	int s = 19, e = 0;
	int j = h.size, k = size, s2 = s, s1 = 0, count = h.size, c = 0, a = 0, b = 0, s3 = s, cc = 0, cc2 = 0;
	j--, k--, count--;
	while (c < h.size)
	{
		while (i < size)
		{
			temp[s1][s2] = dat[k] * h.dat[j];
			if (s1 == 0)
			{
				cc++;
			}
			//	Mul.dat[s2] = dat[k] * h.dat[j];
			if (div != 0)
			{
				temp[s1][s2] += div;
				//	Mul.dat[s2] += div;
				div = 0, r = 0;
			}
			if (temp[s1][s2] > 9)
			{
				if (i == size - 1)
				{
					r = temp[s1][s2] % 10;
					div = temp[s1][s2] / 10;
					temp[s1][s2] = r;
					temp[s1][s2 - 1] = div;
				}
				else
				{
					r = temp[s1][s2] % 10;
					//	r = Mul.dat[s2] % 10;
					div = temp[s1][s2] / 10;
					temp[s1][s2] = r;
					//	div = Mul.dat[s2] / 10;
					//	Mul.dat[s2] = r;
				}
				//		dat[k-1]+=
			}
			k--, i++, s2--;
		}
		b = 19;
		while (b > s)
		{
			temp[s1][b] = 0;
			b--;
		}
		//		e = 0;
		while (a <= 19)
		{
	//		temp[s1][a] += 48;
	//		cout << temp[s1][a];
			temp2[s1][a] = temp[s1][a];
			a++;
			//'
		}
		if (c == 1)
		{
			cc2 = cc;
		}
//		cout << endl;
		b++;
		a = 0;
		i = 0, j--, s1++, c++, k = size, div = 0, r = 0, s--;
		k--;
		s2 = s;
		//	cout << s2 << " ";
		//		count++;
	}
	int mulS = 50;
	i = 0;
	while (i<mulS)
	{
		Mul.dat[i] = 0;
		Mul.dat[i] -= 48;
		i++;
	}
	mulS--;
	i = 0, j = 19,k=19;
		while (k>0)
		{
			while (i<h.size)
			{
			   temp[i+1][j]= temp[i][j] + temp[i+1][j];
				i++;
			}
			 Mul.dat[mulS]=temp[i][j];
			 div = 0;
			if (Mul.dat[mulS]>9)
			{
				r = Mul.dat[mulS] % 10;
				div = Mul.dat[mulS] / 10;
				Mul.dat[mulS] = r;
		    	temp[i-2][j - 1] += div;
			}
			Mul.dat[mulS] += 48;
			i = 0, j--,k--,mulS--;
		}
		cout << "             After Multiplication: " << endl;
                cout<<"       the answer is at the end  "<<endl;
	return Mul;
}
bool HugeInteger::equal(const HugeInteger &rhs)
{
	int i = 0;
	if (size == rhs.size)
	{
		while (i < size)
		{
			if (dat[i]!=rhs.dat[i])
			{
				return false;
			}
			i++;
		}
	}
	else{
		return false;
	}
	return true;
}
