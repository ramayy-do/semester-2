// create by   : Rama Adhi Saputra
// Location    : Semarang, Central Java, Indonesia
// github      : ramayy-do
// Program     : Double linked list with insert before
// last update : 2025-6-26


#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menyisipkan node sebagai elemen pertama dalam linked list
void insertFirst(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi untuk menyisipkan node setelah node dengan nilai tertentu dalam linked list
void insertBefore(Node* head, int valueToInsertBefore, int data) {
    // Mulai pencarian dari head
    Node* current = head;
    // Mencari node dengan nilai yang sesuai
    while (current != nullptr && current->data != valueToInsertBefore) {
        current = current->next;
    }
    // Jika node dengan nilai yang sesuai tidak ditemukan
    if (current == nullptr) {
        cout << "Node dengan nilai " << valueToInsertBefore << " tidak ditemukan" << endl;
        return;
    }

    Node* newNode = createNode(data);
    newNode->prev = current->prev; 
    newNode->next = current; 
    current->prev = newNode; 

    // menghubungkan next dari node sebelum newNode
    if (newNode->next != nullptr) {
        newNode->prev->next = newNode;
    }
}



// Fungsi untuk menampilkan informasi tentang setiap node dalam linked list
void displayList(Node* head) {
    Node* current = head;
    cout << "Informasi tentang setiap node:" << endl;
    while (current != nullptr) {
        cout << "Alamat: " << current << endl;
        cout << "Nilai: " << current->data << endl;
        cout << "Alamat prev: " << current->prev << endl;
        cout << "Alamat next: " << current->next << endl <<endl ;
        current = current->next;
    }
        cout << "---------------------------------------" <<endl;

}

int main() {
    // Inisialisasi pointer simpul
    Node* head = nullptr;

    // Menambahkan satu node dengan nilai 10 ke linked list sebagai elemen terakhir
    insertFirst(head, 4);
    displayList(head);

    insertFirst(head, 3);
    displayList(head);

    insertFirst(head, 2);
    displayList(head);

    insertBefore(head, 4, 1);

    // Menampilkan informasi tentang setiap node dalam linked list
    displayList(head);

    return 0;
}
