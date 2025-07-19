// Judul: Program Single Linked List (SLL)
// Oleh: Rama Adhi Saputra || 22-4-2025

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

        // fungsi untuk menambahkan data di awal antrian
        void insertFirst(char value) {
            if (size >= MAX) {
                cout << "Data sudah penuh!\n";
                return;
            }
    
            node* newNode = createNode(value);
            newNode->next = head;   // ptr newNode menuju ke head
            head = newNode;         // newNode dijadikan head
            size++;
            cout << "Data '" << value << "' berhasil ditambahkan di awal.\n";
        }

        // fungsi untuk menambahkan data setelah data yg dipilih (target)
        void insertAfter(char key, char value) {
            if (size >= MAX) {
                cout << "Data sudah penuh!\n";
                return;
            }
    
            // mencari key
            node* temp = head;
            while (temp != nullptr && temp->data != key) {
                temp = temp->next;
            }
    
            if (temp == nullptr) {
                cout << "Data '" << key << "' tidak ditemukan.\n";
                return;
            }
    
            node* newNode = createNode(value);
            newNode->next = temp->next;     // ptr newNode menuju ke node setelah temp
            temp->next = newNode;           // ptr temp menuju newNode
            size++;
            cout << "Data '" << value << "' berhasil ditambahkan setelah '" << key << "'.\n";
        }

        // fungsi untuk menghapus node di awal antrian
        void deleteFirst() {
            if (head == nullptr) {
                cout << "List kosong.\n";
                return;
            }
    
            node* temp = head;
            head = head->next;  //node setelah head dijadikan newHead
            delete temp;
            size--;
            cout << "Data pertama berhasil dihapus.\n";
        }

        // fungsi untuk menghapus data setelah data yg dipilih (target)
        void deleteAfter(char value) {
            if (head == nullptr) {
                cout << "List kosong.\n";
                return;
            }
    
            // cari node == value
            node* prev = head;
            while (prev != nullptr && prev->data != value) {
                prev = prev->next;
            }

            if (prev != nullptr && prev->next != nullptr) {
                node* target = prev->next;
                prev->next = target->next;  // ptr prev menuju node setelah target
                delete target;  // node yg akan dihapus
                size--;
                cout << "Node setelah '" << value << "' berhasil dihapus.\n";
            } else {
                cout << "Element '" << value << "' tidak ditemukan atau tidak punya node setelahnya.\n";
            }
        }

        // untuk menampilkan isi linked list
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
        cout << "2. Insert After\n";
        cout << "3. Delete First\n";
        cout << "4. Delete After\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan huruf: "; cin >> data;
                list.insertFirst(data); 
                break;
            case 2:
                cout << "Setelah huruf: "; cin >> after;
                cout << "Huruf baru: "; cin >> data;
                list.insertAfter(after, data); 
                break;
            case 3:
                list.deleteFirst();
                break;
            case 4:
                cout << "Setelah huruf: "; cin >> data;
                list.deleteAfter(data); 
                break;
            case 5:
                list.printList();
                break;
            case 6:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

return 0;
}
