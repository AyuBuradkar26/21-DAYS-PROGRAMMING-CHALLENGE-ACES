#include<iostream>
#include<string.h>
using namespace std;

class per_info
{
	private:
		string DOB,Blood_grp,license_No;
	public:
		per_info();
		per_info(per_info&);
		
		friend class student;
		~per_info();
};


per_info::per_info()
{
	DOB="10/01/2000";
	Blood_grp="B+";
	license_No="MH-120904";
}

per_info::per_info(per_info& P )
{
	DOB=P.DOB;
	Blood_grp=P.Blood_grp;
	license_No=P.license_No;
}


per_info::~per_info()
{
	cout<<"destructor called"<<endl;
}


class student
{
	private:
		string Name,Class,Adrs,mob_No;
		char Div;
		int Roll_No;
		 
	public:
		student();
		student(student&);
		static int cnt;
		void create(per_info&);
        void display(per_info&);
		inline static void getcount()
		{
			cnt++;
		}
		inline static void dis_count()
		{
			cout<<"count= "<<cnt<<endl;
		}     		
};

int student::cnt=0;

student::student()
{
	Name="XYZ";
	Roll_No=1000;
	Class="SE";
	Div='A';
	Adrs="Ak,Pune";
	mob_No= "9876543210";
}

student::student(student& S)
{
	this->Name=S.Name;
	this->Roll_No=S.Roll_No;
    this->Class=S.Class;
    this->Div=S.Div;
    this->Adrs=S.Adrs;
    this->mob_No=S.mob_No;
}

void student:: display(per_info& P)
{
	cout<<"Name: "<<Name<<endl;
	cout<<"Roll number: "<<Roll_No<<endl;
	cout<<"Class: "<<Class<<endl;
	cout<<"Division: "<<Div<<endl;
	cout<<"Address: "<<Adrs<<endl;
	cout<<"Contact number: "<<mob_No<<endl;
	
	cout<<"Date of birth: "<<P.DOB<<endl;
	cout<<"Blood group: "<<P.Blood_grp<<endl;
	cout<<"Driving license number:"<<P.license_No<<endl;
	cout<<"----------------------------------------------"<<endl;
}

void student::create(per_info& I)
{
	cout<<"-----------------------------------------------";
	cout<<"Name: ";
	cin>>Name;
	cout<<"Roll number: ";
	cin>>Roll_No;
	cout<<"Class: ";
	cin>>Class;
	cout<<"Division: ";
	cin>>Div;
	cout<<"Address: ";
	cin>>Adrs;
	cout<<"Contact number: ";
	cin>>mob_No;
	cout<<"Date of birth: ";
	cin>>I.DOB;
	cout<<"Blood group: ";
	cin>>I.Blood_grp;
	cout<<"Driving license number:";
	cin>>I.license_No;
	cout<<"-----------------------------------------------"<<endl;

}


int main()
{
	int N;
	char ans;
	cout<<"Number of Students= ";
	cin>>N;
	student *I1=new student[N];
	per_info *I2=new per_info[N];
	do
	{
		cout<<"1.Input data \n2.Display data \n3.Copy constructor \n4.Default constructor \n5.Destructor"<<endl;
	    int choice;
	    cout<<"Select the option: ";
	    cin>>choice;
	    switch(choice)
	    {
            case 1://Input data
			{
			 	for(int i=0;i<N;i++)
			    {
			 		I1[i].create(I2[i]);
			 		I1[i].getcount();
				}
				
				cout<<"-----------------------------------------------"<<endl;
			}
			case 2://Disply data
			{
				I1[0].dis_count();
			 	for(int i=0;i<N;i++)
			    {
			 		I1[i].display(I2[i]);
			 		I1[i].getcount();
				}
				I1[N].dis_count();
				cout<<"-----------------------------------------------"<<endl;
					
			} 
			case 3://Copy Constructor
			{
				per_info(O1);
				student(O2);
				cout<<"-----------------------------------------------"<<endl;
			}
			case 4://Default Constructor
			{
				cout<<"constructor called"<<endl;
				per_info P1;
				student P2;
				P2.display(P1);
				cout<<"-----------------------------------------------"<<endl;
			}
			case 5://Destructor
			{
				delete [] I1;
				delete [] I2;
				cout<<"Destructor called"<<endl;
				cout<<"-----------------------------------------------"<<endl;	
			}
	    }
	    cout<<"To continue enter 'Y': ";
		cin>>ans;   
    }while(ans=='Y');
	
	return 0;
}
