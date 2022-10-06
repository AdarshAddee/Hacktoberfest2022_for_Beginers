#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int i){
            data = i;
            next = NULL;
        };
        Node(){
            data = -1;
            next = NULL;
        };
};


class Hash {
    public:
        int key;
        Node values[100];
        Hash(int key);
        int HashFunction(int value);
        void add(int value);
        void find(int value, bool add);
        void print();
};

Hash:: Hash(int key){
    this->key = key;
    for(int i = 0; i < key; i++){
        values[i] = Node();
    }
}


int Hash:: HashFunction(int value){
    return value % key;
}

void Hash:: add(int value){
    int index = HashFunction(value);
    Node *current = &values[index];
    while(current->next != NULL){
        if(current->data == value){
            cout<<"Value "<<value<<" already exists"<<endl;
            return;
        }
        current = current->next;
    }
    current->next = new Node();
    current->next->data = value;
    current->next->next = NULL;
}

void Hash:: find(int value, bool add){
    int index = HashFunction(value);
    Node *current = &values[index];
    while(current->next != NULL){
        if(current->data == value){
            cout<<"Value "<<value<<" found"<<endl;
            return;
        }
        current = current->next;
    }
    cout<<"Value "<<value<<" not found"<<endl;
    if(add){
        cout<<"Adding value "<<value<<endl;
        this->add(value);
    }
}

void Hash:: print(){
    cout<<"\nMy hash table with key "<<key<<':'<<endl;
    for(int i = 0; i < key; i++){
        cout<<i<<" [_] ->";
        Node *current = &values[i];
        while(current != NULL){
            if(current->data != -1){
                cout<<" "<<current->data<<" ->";
            }
            current = current->next;
        }
        cout<<" NULL"<<endl;
    }
}

int main(){
    string key = "";
    getline(cin, key);
    Hash hash(stoi(key));

    string second = "";
    getline(cin, second);
    int steps = stoi(second);

    for(int i = 0; i < steps; i++){
        string line = "";
        getline(cin, line);
        hash.add(stoi(line));
    }

    hash.find(6, true);
    hash.find(29, true);
    hash.find(32, false);

    hash.print();
}

// Tested with:
/*
    5
    6
    6
    41
    2
    33
    17
    6
    7
*/
// First line -> key
// Second line -> the amount of numbers to add to the hash table
// Next lines -> the numbers to add to the hash table on sequence