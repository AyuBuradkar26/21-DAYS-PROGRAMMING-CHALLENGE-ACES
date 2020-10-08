#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	string data1,data2,data3;
	struct node *next;
}*head=NULL;

class Club
{
	private:
		node *head;
	public:
		Club(){
			head=NULL;
		}
		node *gethead(){
 	        return head;
        }
		void insert(string,string,string);
		void display(node *);
		void count();
		node *del(node *,string);
		void concatenate(node*,node*);
};

void Club::insert(string prn,string name,string type)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p= new node;
	p->data1=prn;
	p->data2=name;
	p->data3=type;
	p->next=NULL;
	if (head == NULL)
    {
        head = p;
    }
    else if (p->data3 == "President")
    {
        p->next = head;
        head = p;
    }
    else if (p->data3 == "Secretary")
    {
        struct node *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    else
    {
        struct node *q = head;
        q = q->next;
        p->next = q;
        head->next = p;
    }
}

void Club::display(node *head)
{
    if(head != NULL)
    {
        cout << head->data2 << endl;
        display(head->next);
    }

}

void Club::count()
{
	struct node*p=head;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	cout<<"Total members= "<<count<<endl;
}

node *Club::del(node *currP, string name)
{
  if (currP == NULL){
  	return NULL;
    }
  if (currP->data2 == name) {
    node *tempNextP;
    tempNextP = currP->next;

    free(currP);

    return tempNextP;
    }
  currP->next = del(currP->next, name);
  return currP;
}

void Club::concatenate(node *a,node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    }
    else
    {
        cout << "Either a or b is NULL\n";
    }
}

int main()
{
	Club C;
	cout<<"Div A: "<<endl;
	C.insert("72016712P","Anil","Member");
	C.insert("72018019V","Ajay","Secretary");
	C.insert("72017918B","Ayush","President");
	C.insert("72017912C","Aman","Member");
	C.insert("72016718H","Anjali","Member");
	C.count();
	C.display(C.gethead());
	cout<<"----------------------------------------------"<<endl;
	
	cout<<"Member name: "
	string name;
	cin>>name;
	C.del(C.gethead(),name);
	C.count();
	C.display(C.gethead());
	cout<<"-----------------------------------------------"<<endl;
	
	Club D;
	cout<<"Div B: "<<endl;
	D.insert("72018019V","Avi","Member");
	D.insert("72018019V","AJ","Member");
	D.insert("72018019V","AK","Member");
	D.count();
	D.display(D.gethead());
	cout<<"-----------------------------------------------"<<endl;
	
	Club A;
	cout<<"Div (A+B): "<<endl;
	A.concatenate(C.gethead(),D.gethead());
	C.count();
	A.display(C.gethead());
	return 0;
	
}
