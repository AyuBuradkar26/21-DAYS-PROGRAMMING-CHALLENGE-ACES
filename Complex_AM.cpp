#include<iostream>
#include<stdio.h>
using namespace std;

class Complex
{
	double real,img;
	public:
		Complex();
		Complex operator +(Complex&);
		Complex operator -(Complex&);
		Complex operator *(Complex&);
		Complex operator /(Complex&);
		friend ostream& operator <<(ostream&,Complex&);
		friend istream& operator >>(istream&,Complex&);
		void display();
};

Complex::Complex()
{
	real=0.0;
	img=0.0;
}

Complex Complex::operator +(Complex& C)
{
	Complex res;
	res.real=real+C.real;
	res.img=img+C.img;
	return res;
}

Complex Complex::operator -(Complex& C)
{
	Complex res;
	res.real=real-C.real;
	res.img=img-C.img;
	return res;
}

Complex Complex::operator *(Complex& C)
{
	Complex res;
	res.real=real*C.real-img*C.img;
	res.img=real*C.img+img*C.real;
	return res;
}

Complex Complex::operator /(Complex& C)
{
	if(C.real==0 && C.img==0)
	{
		cout<<"Invalid input for division(Denominator==0)"<<endl;
	}
	else{
	Complex res;
    res.real=(real*C.real+img*C.img)/(C.real*C.real+C.img*C.img);
    res.img=(img*C.real-real*C.img)/(C.real*C.real+C.img*C.img);
	return res;
	}  
}

istream& operator >>(istream& in,Complex& C)
{
	cout<<"Real part= ";
	in>>C.real;
	cout<<"Imaginary part= ";
	in>>C.img;
	return in;
}

ostream& operator <<(ostream& out,Complex& C)
{
	cout<<"real=";
	out<<C.real<<endl;
	cout<<"img=";
	out<<C.img<<endl;
	return out;
}
void Complex::display()
{
	if (img<0)
	{
		cout<<real<<"-"<<"i"<<-img<<endl;
	}
	else
	{
	    cout<<real<<"+"<<"i"<<img<<endl;		
	}
}

int main()
{
	Complex C1,C2,C3;
	char ans;
	do
	{
		cout<<"1.accept\n2.addition\n3.substraction\n4.multiplication\n5.division\n6.display"<<endl;
		cout<<"Select option: ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1://Accept
			{
				cin>>C1;
				cin>>C2;
			}
			break;
			case 2://Addition
			{
				C3=C1+C2;
				cout<<C3<<endl;
			}
			break;
			case 3://Substraction
			{
				C3=C1-C2;
				cout<<C3<<endl;
			}
			break;
			case 4://Multiplication
			{
				C3=C1*C2;
				cout<<C3<<endl;
			}
			break;
			case 5://Division
			{
				C3=C1/C2;
				cout<<C3<<endl;
			}
			break;
			case 6://Output
			{
				cout<<"==>";
				C3.display();
			}
			break;
		}
		cout<<"Do you want to continue (Y/N)?: ";
		cin>>ans;
	}while(ans=='Y');
	return 0;
}
