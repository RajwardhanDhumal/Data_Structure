#include<iostream>
using namespace std;
int main()
{
   int city=2,week=7,i,j;
   int Temperature[city][week];
   cout << "The Temperature Of The City Per Week is:-" << endl;
   for(i=0;i<city;++i)
   {
      for(j=0;j<week;++j)
      {
         cout << "City:-" <<i+1<<"Week:-"<<j+1 << ":";
         cin >> Temperature[i][j];
      }
   }
   cout << "Displaying The Values:-";
   for(i=0;i<city;++i)
   {
      for(j=0;j<week;++j)
      {
         cout << "City:-" <<i+1<<"Week:-"<<j+1 << "=" << Temperature[i][j]<<endl ;
      }
   }
   return 0;
} 