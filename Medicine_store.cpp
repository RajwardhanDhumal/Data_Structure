#include <bits/stdc++.h>
using namespace std;

int num = 0;
class medicine
{
public:
    char name[20];
    float price;
    int quantity;

    void createInventory();
    void displayInventory(int srNo);
    void addInventory();
    void removeInventory(int);
    void searchMedicine();
    void modifyMedicine();
}m[20];

void medicine::createInventory()
{
    cout<< "\nEnter Name of medicine: \n";
    cin>> name;
    cout<< "Enter Price of medicine: \n";
    cin>> price;
    cout<< "Enter Quantity of medicine: \n";
    cin>> quantity;
}

void medicine::displayInventory(int srNo)
{
    cout<<"  "<<srNo+1<< "\t|\t"<< name<< "\t\t|\t$"<<price<< "\t\t|\t"<< quantity<<endl;
}

void medicine::addInventory()
{
    cout<< "Enter Name of medicine: \n";
    cin>> name;
    cout<< "Enter Price of medicine: \n";
    cin>> price;
    cout<< "Enter Quantity of medicine: \n";
    cin>> quantity;
    num++;
}

void medicine::removeInventory(int rem)
{
    for(int i = rem ; i < num; i++)
        {
            strcpy(m[i].name , m[i+1].name);
            m[i].price = m[i+1].price;
            m[i].quantity = m[i+1].quantity;
        }
    num--;
}

void medicine::searchMedicine()
{
    cout<< "\nAvailable :- YES\n\nNAME: "<< name<< "\nPRICE: "<<price<< "\nQUANTITY: "<< quantity<<endl;
}

void medicine::modifyMedicine()
{
    cout<< "Enter new Price of medicine: \n";
    cin>> price;
    cout<< "Enter new Quantity of medicine: \n";
    cin>> quantity;
}

int main()
{
    int q,rem;
    bool s = true;
    while(s)
    {
        cout<< "\n\n\n---------- MENU ----------\n\n1. Create Inventory\n2. Display Inventory\n3. Add Medicine\n4. Remove Medicine\n5. Search\n6. Modify Price and Quantity\n\n-------------------------\n0. EXIT\n\n";
        cin>>q;
        switch(q)
        {
        case 0:
            {
                s = false;
                break;
            }
        case 1:
            {
                cout<< "Enter num of medicines (max=20): \n";
                cin>>num;
                for(int i=0; i < num; i++)
                    {
                        m[i].createInventory();
                    }
                 break;
            }
        case 2:
            {
               cout<< "\nSR no.\t|\tNAME:\t\t|\tPRICE:\t\t|\tQUANTITY:\n";
               cout<<"--------|-----------------------|-----------------------|-------------------\n";
                for(int i=0; i < num; i++)
                    {
                        m[i].displayInventory(i);
                    }
                break;
            }
        case 3:
            {
                m[num].addInventory();
                break;
            }
        case 4:
            {
                char searchname[20];
                bool notavailabe = true;
                cout<< "Enter name of medicine to remove: \n";
                cin>> searchname;
                for(int i = 0; i<num ; i++)
                {
                    if(strcmp(searchname , m[i].name)==0)
                    {
                        m[i].removeInventory(i);
                        notavailabe = false;
                        break;
                    }
                }
                if (notavailabe)
                {
                    cout<< "NOT AVAILABLE!";
                }
                break;
            }
        case 5:
            {
                char searchname[20];
                bool notavailabe = true;
                cout<< "Enter name of medicine to search: \n";
                cin>> searchname;
                 for(int i = 0 ; i < num; i++)
                {
                  if (strcmp(searchname , m[i].name)==0)
                  {
                      m[i].searchMedicine();
                      notavailabe = false;
                      break;
                  }
                }
                if(notavailabe)
                {
                    cout<<"\nAvailable - NO\n";
                }

                break;
            }
        case 6:
            {
                char searchname[20];
                bool notavailabe = true;
                cout<< "Enter name of medicine to modify: \n";
                cin>> searchname;

                for(int i = 0 ; i < num; i++)
                {
                  if (strcmp(searchname , m[i].name)==0)
                  {
                      m[i].modifyMedicine();
                      notavailabe = false;
                      break;
                  }
                }
                if(notavailabe)
                {
                    cout<<"\nNOT AVAILABLE!\n";
                }

                break;
            }
        default:
            {
                cout<< "Invalid choice!!\n";
                break;
            }
        }
    }
    return 0;

}