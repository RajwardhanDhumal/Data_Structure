#include<iostream>
using namespace std;
class graph
{
   public:
   int n,e,v1,v2;
   int adjmatrix[20][20];
    
   void create();
   void display();

   graph()
   {
      for(int i=0;i<20;i++)
         {
            for(int j=0;j<20;j++)
            {
               adjmatrix[i][j]=0;
            }
         }
   };
};

void graph::create()
{
   cout<<"\n Enter the number of vertex:";
   cin >>n;
   cout<<"\n Enter the number of edge:";
   cin>>e;
   for(int i=0;i<e;i++)
   {
    cout<<"\nEnter an Edge(Start and End Vertex):";
    cin>>v1>>v2;
    adjmatrix[v1][v2]=1;
    adjmatrix[v2][v1]=1;
   }
}
void graph::display()
{
   cout<<"\n The Adjacent Matrix Is:";
   for(int i=1;i<=n;i++)
   {
      cout<<"\n";
      for(int j=1;j<=n;j++)
      {
         cout<<""<<adjmatrix[i][j];
      }
   }
}
int main()
{
   int ch;
   graph h;
   do
   {
      cout<<"Welcome TO Graph!";
      cout<<"\n1. Create or Read a graph:";
      cout<<"\n2. Display:";
      cout<<"\n3.Exit";
      cout<<"\nEnter your choice:";
      cin>>ch;
      switch(ch)
      {
         case 1:
         h.create();
         break;
         case 2:
         h.display();
         break;
            
      }
   }
   while(ch!=3);
   return 0;
}