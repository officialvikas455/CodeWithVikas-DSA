#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for (char c : key) {
            idx = (idx + c) % totSize; // Simplified hash function
        }
        return idx % totSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = totSize;

        totSize *= 2; // Double the size
        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }

        // Copy the old values
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            delete oldTable[i]; // Free old nodes
        }
        delete[] oldTable; // Free old table
    }

public:
    HashTable(int size = 5) {
        totSize = size;
        currSize = 0;

        table = new Node*[totSize];
        for (int i = 0; i < totSize; i++) {
            table[i] = NULL;
        }
    }

    ~HashTable() {
        for (int i = 0; i < totSize; i++) {
            delete table[i]; // Free each linked list
        }
        delete[] table; // Free the table
    }

    void insert(string key, int val) {
        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;
        double lambda = currSize / (double)totSize;
        if (lambda > 1) {
            rehash();
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }

    void remove(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    table[idx] = temp->next; // Remove head
                } else {
                    prev->next = temp->next; // Remove middle or end
                }
                delete temp; // Free memory
                currSize--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("Nepal", 10);
    ht.insert("US", 50);
    ht.insert("India", 20);

    if (ht.exists("Nepal")) {
        cout << "Nepal population: " << ht.search("Nepal") << endl;
    }

    return 0;
}
