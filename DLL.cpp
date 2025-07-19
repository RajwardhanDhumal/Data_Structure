#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *prev;
};

class DLL {
public:
    node *head, *last;
    DLL() {
        head = NULL;
        last = NULL;
    }
    void create();
    void traverse();
};

void DLL::create() {
    node *temp;
    int val, userch;
    do {
        cout << "\nEnter the node data: ";
        cin >> val;
        temp = new node;
        temp->data = val;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
        cout << "Do you want to add more data (yes=1, NO=0): ";
        cin >> userch;
    } while (userch != 0);
}

void DLL::traverse() {
    node *temp;
    temp = head;
    while (temp != NULL) {
        cout << "\t" << temp->data;
        temp = temp->next;
    }
}
int main() {
    DLL s;
    int ch;
    do {
        cout << "\nWelcome to the DLL Operation:";
        cout << "\n1. Create";
        cout << "\n2. Traverse";
        cout << "\n3. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                s.create();
                break;
            case 3:
                s.traverse();
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
    return 0;
}
