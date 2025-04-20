#include <iostream>
using namespace std;

    struct Node{
        char data;
        Node* next;
    };
    struct Node *head, *last;
    typedef struct Node node;

    
    node* createNode(char value){
        node* newNode = new node;
        newNode->data= value;
        newNode-> next = nullptr;
        return newNode;
    }

    void insertFirst(char value){
        node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    void insertLast(char value){
        node* newNode = createNode(value);
        newNode-> next = nullptr;
        
        if (head == nullptr){
            head = newNode;
            return; //keluar
        }
        node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void insertAfter(node* prevNode, char value){
        
        if (head == nullptr){
            cout << "Node sebelumnya tidak boleh NULL." << endl;
            return;
        }

        node* newNode = createNode(value);
        newNode->next= prevNode->next;
        prevNode->next = newNode;
    }
    void deleteFirst(){
        if (head == nullptr){
            cout << "list kosong" << endl;
            return;
        }

        if (head){
            node* temp = head; 
            head = head->next;
            delete temp;
        }
    }

    void printList(){
        if (head ==nullptr){
            cout << "List kosong" << endl;
            return;
        }

        node* temp = head;
        cout << "Isi list: ";
        while (temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
int main (){
    int pilihan;
    char data;
    do {
        cout << "Menu single linked list" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Insert First " << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Insert After " << endl;
        cout << "0. Out" << endl;
        cout << "Pilih (contoh 1): ";
        cin >> pilihan;
        switch (pilihan){

            case 1:
                cout << "Masukkan data: "; cin >> data;
                insertFirst(data);
                break;
            case 2:
                cout << "Masukkan data: "; cin >> data;
                insertLast(data);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                printList();
                break;
            case 5:
                char target;
                cout << "Masukkan data node yang mau disisipkan setelah: ";
                cin >> target;       
                cout << "Masukkan data: "; 
                cin >> data;

                node* temp = head;
                while (temp != nullptr && temp->data != target){
                    temp = temp->next;
                } 
                if (temp == nullptr){
                    cout << "List kosong " << endl;
                }
                else {
                    insertAfter(temp, data);
                }
                break;
           
        }
    }
    while (pilihan != 0);
    return 0;
}