#include<iostream>
using namespace std;
#define MAX 100
int data[MAX][3];
int len;
int r,c,val,i,j,A[100][100];
void getdata()
{
    cout << "Enter the number of rows";
    cin >> r;
    cout << "Enter the number of columns the matrix : ";
    cin >>c;
    cout << "Enter the array elements : ";
    for(i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Matrix : \n ";
    for(i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        cout << A[i][j] << "  ";
        cout << "\n ";
    }
}

void insert(int r,int c,int val)
{
    data[len][0] = r;
    data[len][1] = c;
    data[len][2] = val;
    len++;
}
void print()
{
       cout << "\nSparse Matrix: \nRow Column Value\n";
    for (int i = 0; i < len; i++) 
    {
        cout << data[i][0] << " "<< data[i][1] << " "<< data[i][2] << "\n";
    }
}
int main()
{
    getdata();
    cout << "\nMatrix:\n";
    for (i = 0; i < r; i++) 
    {
        for (j = 0; j < c; j++)
        {
            cout << A[i][j] << " ";
        }
    cout << endl;
    }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
            if ( A[i][j] != 0)
                {
                    insert(i, j, A[i][j]);
                }
            }
        }

print();
return 0;
}
