#include <iostream>
#include <algorithm>
using namespace std;

class node 
{
public:
    int data;
    node *left;
    node *right;
};

class BST 
{
public:
    node *root;
    BST() 
    {
        root = NULL;
    }
    void create();
    void traverse();
    void insert(node *, node *);
    void Preorder(node *);
    void Inorder(node *);
    void Postorder(node *);
    void leaf(node *);
    int height(node *);
    void mirror(node *);
    bool search(node *, int);
    void Delete(int);

private:
    node* deleteNode(node*, int);
    node* minValueNode(node*);
};

void BST::create() 
{
    node *temp;
    int val, userch;
    do 
    {
        cout << "\nEnter the node data: ";
        cin >> val;
        temp = new node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        if (root == NULL) 
        {
            root = temp;
        } else
        {
            insert(root, temp);
        }
        cout << "\nDo you want to add more data (YES=1, NO=0):";
        cin >> userch;
    } while (userch != 0);
}

void BST::insert(node *root, node *temp) 
{
    if (temp->data < root->data) 
    {
        if (root->left == NULL) 
        {
            root->left = temp;
        } else 
        {
            insert(root->left, temp);
        }
    } else 
    {
        if (root->right == NULL) 
        {
            root->right = temp;
        } else 
        {
            insert(root->right, temp);
        }
    }
}

void BST::traverse() 
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
                leaf(root);
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (op != 5);
}

void BST::leaf(node *temp)
{
    if (temp != NULL) 
    {
        if (temp->left == NULL && temp->right == NULL) 
        {
            cout << "\t" << temp->data;
        }
        leaf(temp->left);
        leaf(temp->right);
    }
}

void BST::Preorder(node *temp) 
{
    if (temp != NULL) 
    {
        cout << "\t" << temp->data;
        Preorder(temp->left);
        Preorder(temp->right);
    }
}

void BST::Inorder(node *temp) 
{
    if (temp != NULL) 
    {
        Inorder(temp->left);
        cout << "\t" << temp->data;
        Inorder(temp->right);
    }
}

void BST::Postorder(node *temp) 
{
    if (temp != NULL) 
    {
        Postorder(temp->left);
        Postorder(temp->right);
        cout << "\t" << temp->data;
    }
}

int BST::height(node *root) 
{
    if (root == NULL)
        return 0;
    else 
    {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
    }
}

void BST::mirror(node *root) 
{
    if (root == NULL) 
    {
        return;
    }

    std::swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

bool BST::search(node *temp, int value) 
{
    if (temp == NULL) 
    {
        return false;
    }

    if (temp->data == value) 
    {
        return true;
    }

    return search(temp->left, value) || search(temp->right, value);
}

void BST::Delete(int value) 
{
    root = deleteNode(root, value);
}

node* BST::deleteNode(node *root, int value) 
{
    if (root == NULL) 
    {
        return root;
    }
    if (value < root->data) 
    {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) 
    {
        root->right = deleteNode(root->right, value);
    } else 
    {
        if (root->left == NULL) 
        {
            node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) 
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

node* BST::minValueNode(node *node) 
{
    while (node->left != NULL) 
    {
        node = node->left;
    }
    return node;
}

int main() 
{
    BST b;
    int ch;
    do 
    {
        cout << "\nWelcome to the Binary Search Tree Operation:";
        cout << "\n1. Create";
        cout << "\n2. Traverse";
        cout << "\n3. Mirror";
        cout << "\n4. Search";
        cout << "\n5. Delete";
        cout << "\n6. Height of the tree";
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
                b.mirror(b.root);
                break;
            case 4: 
            {
                int searchValue;
                cout << "Enter value to search: ";
                cin >> searchValue;
                if (b.search(b.root, searchValue)) 
                {
                    cout << "Value found in the tree." << endl;
                } else 
                {
                    cout << "Value not found in the tree." << endl;
                }
                break;
            }
            case 5: 
            {
                int deleteValue;
                cout << "Enter value to delete: ";
                cin >> deleteValue;
                b.Delete(deleteValue);
                cout << "Value " << deleteValue << " deleted from the tree." << endl;
                break;
            }
            case 6:
                cout << "Height of the tree is: " << b.height(b.root) << endl;
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

