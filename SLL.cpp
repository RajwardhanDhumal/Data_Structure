#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class SLL {
private:
    node* start, * p, * q, * r;

public:
    SLL() {
        start = NULL;
        q = NULL;
        r = NULL;
    }

    void createnode();
    void Insertionatfirst();
    void Insertionatlast();
    void Insertionatmiddle();
    void Deleteatfirst();
    void DeleteatMiddle();
    void Deleteatlast();
    void Search(int key);
    void Display();
};

void SLL::createnode() {
    int num;
    p = new node;
    cout << "\nEnter the node data: ";
    cin >> num;
    p->data = num;
    p->next = NULL;

    if (start == NULL) {
        start = p;
    }
    else {
        q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void SLL::Insertionatfirst() {
    p = new node;
    cout << "Enter Data: ";
    cin >> p->data;
    p->next = start;
    start = p;
    cout << "Node inserted at the beginning." << endl;
}

void SLL::Insertionatmiddle() {
    p = new node;
    cout << "\nEnter the node data: ";
    cin >> p->data;
    p->next = NULL;

    if (start == NULL) {
        start = p;
    }
    else {
        int pos;
        cout << "\nEnter the position where you want to insert a node: ";
        cin >> pos;
        q = start;
        for (int i = 1; i < pos - 1; i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}

void SLL::Insertionatlast() {
    p = new node;
    cout << "\nEnter the node data: ";
    cin >> p->data;
    p->next = NULL;

    if (start == NULL) {
        start = p;
    }
    else {
        q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void SLL::Deleteatfirst() {
    q = start;
    if (start == NULL) {
        cout << "\nList is empty. Deletion operation not possible." << endl;
    }
    else if (q->next == NULL) {
        start = NULL;
        delete q;
        cout << "First node is deleted!" << endl;
    }
    else {
        start = q->next;
        delete q;
        cout << "First node is deleted!" << endl;
    }
}

void SLL::DeleteatMiddle() {
    q = start;
    if (start == NULL) {
        cout << "\nList is empty. Deletion operation not possible." << endl;
    }
    else if (q->next == NULL) {
        start = NULL;
        delete q;
        cout << "Single node in the list, and it is deleted." << endl;
    }
    else {
        int pos;
        cout << "\nEnter the position of the node you want to delete: ";
        cin >> pos;
        for (int i = 1; i < pos - 1; i++) {
            q = q->next;
        }
        r = q->next;
        q->next = r->next;
        delete r;
    }
}

void SLL::Deleteatlast() {
    q = start;
    if (start == NULL) {
        cout << "\nList is empty. Deletion operation not possible." << endl;
    }
    else if (q->next == NULL) {
        start = NULL;
        delete q;
        cout << "Last node is deleted!" << endl;
    }
    else {
        while (q->next != NULL) {
            r = q;
            q = q->next;
        }
        r->next = NULL;
        delete q;
        cout << "Last node is deleted!" << endl;
    }
}

void SLL::Search(int key) {
    q = start;
    bool found = false;
    while (q != NULL) {
        if (key == q->data) {
            cout << "Key found!" << endl;
            found = true;
            break;
        }
        q = q->next;
    }
    if (!found) {
        cout << "Key not found." << endl;
    }
}

void SLL::Display() {
    if (start == NULL) {
        cout << "\nList is empty." << endl;
    }
    else {
        q = start;
        cout << "\nData in Linked List: ";
        while (q != NULL) {
            cout << q->data << " -> ";
            q = q->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    SLL v;
    int choice;
    while (true) {
        cout << "1. Create Node" << endl;
        cout << "2. Insertion at First" << endl;
        cout << "3. Insertion at Last" << endl;
        cout << "4. Insertion at Middle" << endl;
        cout << "5. Delete at First" << endl;
        cout << "6. Delete at Middle" << endl;
        cout << "7. Delete at Last" << endl;
        cout << "8. Search" << endl;
        cout << "9. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            v.createnode();
            break;
        case 2:
            v.Insertionatfirst();
            break;
        case 3:
            v.Insertionatlast();
            break;
        case 4:
            v.Insertionatmiddle();
            break;
        case 5:
            v.Deleteatfirst();
            break;
        case 6:
            v.DeleteatMiddle();
            break;
        case 7:
            v.Deleteatlast();
            break;
        case 8:
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            v.Search(key);
            break;
        case 9:
            v.Display();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}


//++++++++++++++++++++++++++++++
/*#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class SLL
{
    public:
    node *head,*last;
    void create();
    void traverse();
    Sll(){
        head=NULL;
    }
};
void SLL::create()
{
    node *temp;
    int val,userch;
    do{
	cout<<"\nEnter the node data";
    cin>>val;
    temp= new node;
	temp->data=val;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        last=temp;
    }
    else{
        last->next=temp;
        last=temp;
    }
    cout<<"Do you want to add more data (yes=1,NO=0)";
    cin>>userch;
}while(userch!=0);
}

void SLL::traverse()
{
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<"\t"<<temp->data;
        temp=temp->next;
    }
}

int main()
{
    SLL s;
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
*/