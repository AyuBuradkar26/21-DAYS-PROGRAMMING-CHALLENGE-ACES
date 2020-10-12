#include<iostream>
#include<string.h>
#include<iomanip>
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
		string Name,Class,Adrs;
		long long mob_No;
		char Div;
		int Roll_No;
		 
	public:
		student();
		student(student&);  
		static int cnt;
		void create(per_info&);
		void display1();
        void display2(per_info&);
		inline static void getcount()
		{
			cnt++;
		}
		inline static void dis_count()
		{
			cout<<"count= "<<cnt<<endl;
		}
		~student();
		   		
};

int student::cnt=0;

student::student()
{
	Name="XYZ";
	Roll_No=1000;
	Class="SE";
	Div='A';
	Adrs="Ak,Pune";
	mob_No= 9860025223;
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

void student::display1() 
{
    const char separator    = ' ';
    const int nameWidth     = 13;
    const int numWidth      = 15;
    
	cout << left << setw(nameWidth) << setfill(separator) << "Name";
	cout << left << setw(numWidth) << setfill(separator) << "Roll_No";
	cout << left << setw(nameWidth) << setfill(separator) << "Class";
	cout << left << setw(nameWidth) << setfill(separator) << "Division";
	cout << left << setw(nameWidth) << setfill(separator) << "Address";
	cout << left << setw(numWidth) << setfill(separator) << "Contact_number";
	cout << left << setw(numWidth) << setfill(separator) << "Date_of_birth";      
	cout << left << setw(nameWidth) << setfill(separator) << "Blood_group";
	cout << left << setw(nameWidth) << setfill(separator) << "License_number"<<endl;
	
}
void student:: display2(per_info& P)
{
    const char separator    = ' ';
    const int nameWidth     = 13;
    const int numWidth      = 15;
    
	cout << left << setw(nameWidth) << setfill(separator) << Name;
	cout << left << setw(numWidth) << setfill(separator) << Roll_No;
	cout << left << setw(nameWidth) << setfill(separator) << Class;
	cout << left << setw(nameWidth) << setfill(separator) << Div;
	cout << left << setw(nameWidth) << setfill(separator) << Adrs;
	cout << left << setw(numWidth) << setfill(separator) << mob_No;
	cout << left << setw(numWidth) << setfill(separator) << P.DOB;      
	cout << left << setw(nameWidth) << setfill(separator) << P.Blood_grp;
	cout << left << setw(nameWidth) << setfill(separator) << P.license_No<<endl;
	//cout<<"----------------------------------------------"<<endl;
}

void student::create(per_info& I)
{
	cout<<"-----------------------------------------------"<<endl;
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
student::~student()
{
	cout<<"destructor called"<<endl;
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
			break;
			case 2://Disply data
			{	
			    I1[0].dis_count();
	            I1[0].display1();
			 	for(int i=0;i<N;i++)
			    {
			 		I1[i].display2(I2[i]);
			 		cout<<'\n';
			 		I1[i].getcount();
				}
				I1[N].dis_count();
				cout<<"-----------------------------------------------"<<endl;
					
			} 
			break;
			case 3://Copy Constructor
			{
				student O1;
				per_info O2;
				O1.create(O2);
				student O3(O1);
				per_info O4(O2);
				cout<<"copy constructor called"<<endl;
				O1.display1();
				O3.display2(O4);
				cout<<"-----------------------------------------------"<<endl;
			}
			break;
			case 4://Default Constructor
			{
				cout<<"constructor called"<<endl;
				per_info P1;
				student P2;
				P2.display1();
				P2.display2(P1);
				cout<<"-----------------------------------------------"<<endl;
			}
			break;
			case 5://Destructor
			{
				delete [] I1;
				delete [] I2;
				cout<<"Destructor called"<<endl;
				cout<<"-----------------------------------------------"<<endl;	
			}
			break;
	    }
	    cout<<"To continue enter 'Y': ";
		cin>>ans;   
    }while(ans=='Y');
	
	return 0;
}
