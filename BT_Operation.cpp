#include <iostream>

using namespace std;

class node 
{
public:
    int data;
    node *left;
    node *right;
};

class BT 
{
public:
    node *root;
    BT() 
    {
        root = NULL;
    }
    void create();
    void traverse();
    void insert(int);
    void Preorder(node *);
    void Inorder(node *);
    void Postorder(node *);
    void leaf();
    int depth();
    node* copyTree(node*);
};

void BT::create() 
{
    node *temp;
    int val, userch;
    do 
    {
        cout << "\nEnter the node data: ";
        cin >> val;
        insert(val);
        cout << "\nDo you want to add more data (YES=1, NO=0):";
        cin >> userch;
    } while (userch != 0);
}

void BT::insert(int val) 
{
    node *temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL) 
    {
        root = temp;
    } 
    else 
    {
        node* current = root;
        node* parent;
        while(current != NULL)
        {
            parent = current;
            if(val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if(val < parent->data)
            parent->left = temp;
        else
            parent->right = temp;
    }
}

void BT::traverse() 
{
    int op;
    do 
    {
        cout << "\nWelcome To Tree Traversal";
        cout << "\n1. Preorder:";
        cout << "\n2. Inorder:";
        cout << "\n3. Postorder:";
        cout << "\n4. Leaf Nodes To Display:";
        cout << "\n5. Exit";
        cout << "\nEnter your choice:";
        cin >> op;
        switch (op) 
        {
        case 1:
            Preorder(root);
            break;
        case 2:
            Inorder(root);
            break;
        case 3:
            Postorder(root);
            break;
        case 4:
            leaf();
            break;
        case 5:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (op != 5);
}

void BT::leaf() 
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    cout << "Leaf Nodes: ";
    node* current = root;
    while (current != NULL)
    {
        if (current->left == NULL && current->right == NULL)
        {
            cout << current->data << " ";
        }
        if (current->right != NULL)
        {
            current = current->right;
        }
        else if (current->left != NULL)
        {
            current = current->left;
        }
        else
        {
            current = NULL;
        }
    }
    cout << endl;
}

void BT::Preorder(node *temp) 
{
    if (temp != NULL) 
    {
        cout << "\t" << temp->data;
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void BT::Inorder(node *temp) 
{
    if (temp != NULL) 
    {
        Inorder(temp->left);
        cout << "\t" << temp->data;
        Inorder(temp->right);
    }
}

void BT::Postorder(node *temp) 
{
    if (temp != NULL) 
    {
        Postorder(temp->left);
        Postorder(temp->right);
        cout << "\t" << temp->data;
    }
}

int BT::depth() 
{
    if (root == NULL)
        return 0;

    int left_depth = 0;
    int right_depth = 0;
    node* current = root;
    while (current->left != NULL || current->right != NULL)
    {
        if (current->left != NULL)
        {
            left_depth++;
            current = current->left;
        }
        else if (current->right != NULL)
        {
            right_depth++;
            current = current->right;
        }
    }
    return max(left_depth, right_depth) + 1;
}

node* BT::copyTree(node* root)
{
    if (root == NULL)
        return NULL;
    node* new_root = new node;
    new_root->data = root->data;
    new_root->left = copyTree(root->left);
    new_root->right = copyTree(root->right);
    return new_root;
}

int main() 
{
    BT b;
    int ch;
    node* copy_root = nullptr; // Declare copy_root outside the switch block
    do {
        cout << "\nWelcome to the Binary Tree Operation:";
        cout << "\n1. Create";
        cout << "\n2. Traverse";
        cout << "\n3. Depth of the tree";
        cout << "\n4. Create a copy of the tree";
        cout << "\n5. Display Leaf Nodes";
        cout << "\n6. Insert";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;
        switch (ch) 
        {
            case 1:
                b.create();
                break;
            case 2:
                b.traverse();
                break;
            case 3:
                cout << "Depth of the tree is: " << b.depth() << endl;
                break;
            case 4:
                cout << "Creating a copy of the tree..." << endl;
                copy_root = b.copyTree(b.root); // Assign copy_root here
                cout << "Copy of the tree created." << endl;
                break;
            case 5:
                b.leaf();
                break;
            case 6:
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                b.insert(val);
                cout << "Value " << val << " inserted into the tree." << endl;
                break;
            case 7:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 7);
    return 0;
}

