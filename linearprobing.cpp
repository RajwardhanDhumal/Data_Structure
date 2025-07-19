#include <iostream>
using namespace std;

class Hashing
{
public:
    int matrix[5];
    int key;
    Hashing()
    {
        for (int i = 0; i < 5; i++)
        {
            matrix[i] = 0;
        }
    }

    void create();
    void insert(int key, int n);
    void display();
    void search(int key);
};

void Hashing::create()
{
    int n;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter number: ";
        cin >> n;
        key = n % 5;

        if (matrix[key] == 0)
        {
            matrix[key] = n;
        }
        else
        {
            insert((key + 1) % 5, n);
        }
    }
}

void Hashing::insert(int key, int n)
{
    if (matrix[key] == 0)
    {
        matrix[key] = n;
    }
    else
    {
        insert((key + 1) % 5, n);
    }
}

void Hashing::display()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i << " Key: " << matrix[i] << endl;
    }
}

void Hashing::search(int key)
{
    bool found = false;
    for (int i = 0; i < 5; i++)
    {
        if (matrix[i] == key)
        {
            cout << "Key " << key << " found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Key " << key << " not found in the hash table." << endl;
    }
}

int main()
{
    bool s = true;
    Hashing h;
    int option, searchKey;

    while (s)
    {
        cout << "----------HASH TABLE LINEAR PROBING----------" << endl;
        cout << "1: Create" << endl;
        cout << "2: Display" << endl;
        cout << "3: Search" << endl;
        cout << "4: Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Option :- ";
        cin >> option;

        switch (option)
        {
        case 1:
            h.create();
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> searchKey;
            h.search(searchKey);
            break;
        case 4:
            cout << "Exit" << endl;
            s = false;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}