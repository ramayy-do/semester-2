#include <iostream>
using namespace std;

// judul:   // create by : rama adhi saputra || 14-4-2025
            // saya ingin membuat sebuah program sll yg dapat:
            // 1. input data
            // 2. hapus data
            // 3. tampilkan data
            // menggunakan clas
            // menggunakan typedef

// Gunakan typedef untuk struktur Node
typedef struct Node {
    string data;
    Node* next;
} node;

class LinkedList {
private:
    node* head;
    int size;
    const int MAX = 4;

public:
    LinkedList() : head(nullptr), size(0) {}

    node* createNode(string value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void insertFirst(string value) {
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

    void insertLast(string value) {
        if (size >= MAX) {
            cout << "Data sudah penuh!\n";
            return;
        }

        node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; // sambungkan temp ke newNode
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan di akhir.\n";
    }

    void insertAfter(string key, string value) {
        if (size >= MAX) {
            cout << "Data sudah penuh!\n";
            return;
        }

        // mencari node hingga == key
        node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        // jika key tidak ditemukan
        if (temp == nullptr) {
            cout << "Data '" << key << "' tidak ditemukan.\n";
            return;
        }

        // membuat node baru & sambungkan dgn ke list
        node* newNode = createNode(value);
        newNode->next = temp->next; // hubungkan newNode ke node setelah temp
        temp->next = newNode; // sambungkan temp ke newNode
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan setelah '" << key << "'.\n";
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
            size--;
        }
    }


    void deleteAfter(string value) {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }
    
        node* prev = head;
        while (prev != nullptr && prev->data != value) { // Cari node dengan nilai value
            prev = prev->next;
        }
    
        if (prev != nullptr && prev->next != nullptr) { // Jika node dengan nilai value ditemukan dan memiliki node setelahnya
            node* target = prev->next;                  // Simpan node yang akan dihapus
            prev->next = target->next;                  // Hubungkan node sebelumnya dengan node setelah node yang akan dihapus
            delete target;
            size--;
            cout << "Node setelah '" << value << "' berhasil dihapus.\n";
        } else {
            cout << "Element dengan value '" << value << "' tidak ditemukan atau tidak memiliki node setelahnya.\n";
        }
    }
    
    void printList() {
        if (head == nullptr) {
            cout << "Data kosong.\n";
            return;
        }

        node* temp = head;
        cout << "\nIsi Linked List:\n";
        int index = 1;
        while (temp != nullptr) {
            cout << index++ << ". " << temp->data << " (alamat: " << temp << ")\n";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int pilihan;
    string data, dataSetelah;

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
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan data yang ingin ditambahkan di awal: ";
                getline(cin, data);
                list.insertFirst(data);
                break;
            case 2:
                cout << "Masukkan data yang ingin ditambahkan di akhir: ";
                getline(cin, data);
                list.insertLast(data);
                break;
            case 3:
                cout << "Data ingin disisipkan setelah data apa: ";
                getline(cin, dataSetelah);
                cout << "Masukkan data yang ingin ditambahkan: ";
                getline(cin, data);
                list.insertAfter(dataSetelah, data);
                break;
            case 4:
                list.deleteFirst();
                break;
            case 5:
                cout << "Masukkan data yang ingin dihapus setelah: ";
                getline(cin, data);
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

// halo