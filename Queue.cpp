#include<iostream>
using namespace std;
struct Node
{
  int prior,age;
  char Name[20],Gender[10];
  Node *next;  
};
class hospital
{
   Node *front,*temp,*p,*q,*r;
   public:
   hospital()
   {
      p=NULL;
      q=NULL;
      r=NULL;
      front=NULL;
   }
   public:
   void Enqueue();
   void Dequeue();
   void Display();
};
void hospital::Enqueue()
{
   Node *p=new Node;
   cout<<"Name of the patient:-"<<endl;
   cin>>p->Name;
   cout<<"age of the patient:-"<<endl;
    cin>>p->age;
    cout<<"Enter the priority of the patient:-"<<endl;
    cout<<"i)   Serious (top priority)              1"<<endl;
    cout<<"ii)  medium illness (medium priority)    2"<<endl;
    cout<<"iii) General (Least priority)            3"<<endl;
    cout<<"Enter your choice:-"<<endl;
    cin>>p->prior;
    cout<<"Enter the Gender of the patient:-"<<endl;
    cin>>p->Gender;
     if((front==NULL)|| (p->prior<front->prior))
    {
        p->next=front;
        front=p;
    }
    else
    {
        temp=front;
        while((temp->next!=NULL) && (temp->next->prior<=p->prior))
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    cout<<"Entry entered."<<endl;
    cout<<"\n\n"<<endl;
}
void hospital::Dequeue()
{
    struct Node *temp;
temp=front;
front=front->next;
temp->next=NULL;
cout<<"\n patient checked successfully \n "<<endl;
delete temp;
}
void hospital::Display()
{
    p=front;
    q=front;
    cout<<"Priority\t   Name of patient\t   Age of patient\t   Gender of patient"<<endl;
    while(q->next!=NULL)
    {
        cout<<"   "<<q->prior<<"\t\t\t"<<q->Name<<"\t\t\t"<<q->age<<"\t\t\t"<<q->Gender<<endl;
        q=q->next;
    }
    cout<<"   "<<q->prior<<"\t\t\t"<<q->Name<<"\t\t\t"<<q->age<<"\t\t\t"<<q->Gender<<endl;
    cout<<"\n\n"<<endl;
}
int main()
{
    hospital p;
    int choice;

    while(1)
    {
     cout<<"Enter the choice:"<<endl;
     cout<<"a> Enter the entry   [1]"<<endl;
     cout<<"b> Delete the entry  [2]"<<endl;
     cout<<"c> Display Entries [3]"<<endl;
     cout<<"d> Exit              [0]"<<endl;
     cout<<"Your choice:-"<<endl;
     cin>>choice;
     if(choice==1)
        p.Enqueue();
     else if(choice==2)
        p.Dequeue();
     else if(choice==3)
        p.Display();
     else if(choice==0)
        exit(0);
    }
}






/*
ASSIGNMENT NAME:= implement priority queue as ADT using singly link list for servising patient is an
hospital with priorities as 1.serious, 2.medium illness, 3.normal 
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
int data,prior;
char pnm[10],name[10];
struct node *next;
}*front,*rear;
class Queue
{
public:
int isempty();
void pq_insert(int prior,char name[10]);
 void display();
 void p_delete();
};
int Queue::isempty()
{
if((rear=front)==NULL)
{
return 1;
}
return 0;
}
struct node *createnode(int prior,char name[10])
{
 struct node *temp;
 temp=new node;
 strcpy(temp->pnm,name);
 temp->prior=prior;
 temp->next=NULL;
 return temp;
}
void Queue::pq_insert(int prior,char name[10])
{
int i;
struct node *temp;
temp=createnode(prior,name);
if(isempty())
{
front=rear=temp;
}
else if(front->prior > temp->prior)
{
 temp->next=front;
 front=temp;
}
else
{
rear=front;
while(rear->next!=NULL && temp->prior >= rear->next->prior)
{
rear=rear->next;
}
temp->next=rear->next;
rear->next=temp;
 }
}
void Queue::display()
{
struct node *temp;
cout<<"priority \t name \t\t patient name"<<endl;
for(temp=front;temp!='\0';temp=temp->next)
{
if(temp->prior==1)
 cout<<temp->prior<<"\t \t serious\t\t"<<temp->pnm<<endl;
if(temp->prior==2)
 cout<<temp->prior<<"\t \t medium \t \t"<<temp->pnm<<endl;
if(temp->prior==3)
 cout<<temp->prior<<"\t \t normal \t \t"<<temp->pnm<<endl;
}
}
void Queue::p_delete()
{
struct node *temp;
temp=front;
front=front->next;
temp->next=NULL;
cout<<"\n"<<temp->pnm<<" patient checked successfully \n "<<endl;
delete temp;
display();
}
int main()
{
int priority,i,ch,n;
int ans,patient_no;
char name[10];
Queue q;
do
{
cout<<"\n hospital history";
 cout<<"\n 1.enter the record u want";
 cout<<"\n 2.display";
 cout<<"\n 3.delete";
cout<<"\n enter ur choice";
cin>>ch;
switch(ch)
{
case 1:
 cout<<"\n 1.serious";
 cout<<"\n 2.medium";
 cout<<"\n 3.normal";
 cout<<"\n enter the no of patient";
 cin>>n;
for(i=0;i<n;i++)
{
cout<<"\n enter severity=";
 cin>>priority;
 cout<<"\n enter patient name=";
cin>>name;
 q.pq_insert(priority,name);
}
break;
case 2:
q.display();
break;
case 3:
q.p_delete();
break;
case 4:
 cout<<"\n wrong choice";
 cin>>ch;
 break;
}
cout<<"\n is any patient=?";
cin>>ans;
}while(ans==1);
return 0;
}
OUTPUT:
hospital history
1.enter the record u want
2.display
3.delete
enter ur choice1
1.serious
2.medium
3.normal
enter the no of patient3
enter severity=1
enter patient name=abc
enter severity=3
enter patient name=xyz
enter severity=2
enter patient name=pqr
is any patient=?1
hospital history
1.enter the record u want
2.display
3.delete
enter ur choice2
priority name patient name
1 serious abc
2 medium pqr
3 normal xyz
is any patient=?1
hospital history
1.enter the record u want
2.display
3.delete
enter ur choice3
abc patient checked successfully
priority name patient name
2 medium pqr
3 normal xyz
is any patient=?
*/