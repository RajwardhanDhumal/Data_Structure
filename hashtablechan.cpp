#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* next;
};

class HashTable {
public:
    HashTable(int size) : TABLE_SIZE(size) {
        table = new Node*[TABLE_SIZE]();
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* currentNode = table[i];
            while (currentNode != nullptr) {
                Node* temp = currentNode;
                currentNode = currentNode->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node;
        newNode->key = key;
        newNode->next = table[index];
        table[index] = newNode;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* currentNode = table[index];
        while (currentNode != nullptr) {
            if (currentNode->key == key)
                return true;
            currentNode = currentNode->next;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* currentNode = table[index];
        Node* prevNode = nullptr;
        while (currentNode != nullptr && currentNode->key != key) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == nullptr)
            return;
        if (prevNode == nullptr)
            table[index] = currentNode->next;
        else
            prevNode->next = currentNode->next;
        delete currentNode;
    }

private:
    const int TABLE_SIZE;
    Node** table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
};

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable hashTable(size);
    int choice, key;

    do {
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Remove\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                cout << (hashTable.search(key) ? "Key found" : "Key not found") << endl;
                break;
            case 3:
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.remove(key);
                break;
            case 4:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
