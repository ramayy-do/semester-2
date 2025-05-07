// Judul: Program Single Linked List (SLL) dengan class dan typedef
// Oleh: Rama Adhi Saputra || 14-4-2025

#include <iostream>
using namespace std;

// Struktur Node menggunakan typedef
struct Node {
    char data;
    Node* next;
};
typedef struct Node node;

class LinkedList {
private:
    node* head = nullptr;
    int size = 0;
    const int MAX = 4;
    
public:
    node* createNode(char value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void insertFirst(char value) {
        if (size >= MAX) {
            cout << "Data sudah penuh!\n";
            return;
        }

        node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan di awal.\n";
    }

    void insertLast(char value) {
        if (size >= MAX) {
            cout << "Data sudah penuh!\n";
            return;
        }

        node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan di akhir.\n";
    }

    void insertAfter(char key, char value) {
        if (size >= MAX) {
            cout << "Data sudah penuh!\n";
            return;
        }

        node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data '" << key << "' tidak ditemukan.\n";
            return;
        }

        node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan setelah '" << key << "'.\n";
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }

        node* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Data pertama berhasil dihapus.\n";
    }

    void deleteAfter(char value) {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }

        node* prev = head;
        while (prev != nullptr && prev->data != value) {
            prev = prev->next;
        }

        if (prev != nullptr && prev->next != nullptr) {
            node* target = prev->next;
            prev->next = target->next;
            delete target;
            size--;
            cout << "Node setelah '" << value << "' berhasil dihapus.\n";
        } else {
            cout << "Element '" << value << "' tidak ditemukan atau tidak punya node setelahnya.\n";
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "Data kosong.\n";
            return;
        }

        node* temp = head;
        int index = 1;
        cout << "\nIsi Linked List:\n";
        while (temp != nullptr) {
            cout << index++ << ". " << temp->data << " (alamat: " << temp << ")\n";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int pilihan;
    char data, after;

    do {
        cout << "\n==== MENU LINKED LIST ====\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After\n";
        cout << "4. Delete First\n";
        cout << "5. Delete After\n";
        cout << "6. Tampilkan Data\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Buang newline sisa input

        switch (pilihan) {
            case 1:
                cout << "Masukkan huruf: "; cin >> data;
                list.insertFirst(data); 
                break;
            case 2:
                cout << "Masukkan huruf: "; cin >> data;
                list.insertLast(data); 
                break;
            case 3:
                cout << "Setelah huruf: "; cin >> after;
                cout << "Huruf baru: "; cin >> data;
                list.insertAfter(after, data); 
                break;
            case 4:
                list.deleteFirst();
                break;
            case 5:
                cout << "Setelah huruf: "; cin >> data;
                list.deleteAfter(data); 
                break;
            case 6:
                list.printList();
                break;
            case 7:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

return 0;
}
