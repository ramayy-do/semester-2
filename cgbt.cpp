#include <iostream>
using namespace std;

// judul:   // saya ingin membuat sebuah program sll yg dapat:
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
        } else {
            node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        size++;
        cout << "Data '" << value << "' berhasil ditambahkan di akhir.\n";
    }

    void insertAfter(string key, string value) {
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

    void deleteData(string value) {
        if (head == nullptr) {
            cout << "List kosong.\n";
            return;
        }

        node* temp = head;
        node* prev = nullptr;

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data '" << value << "' tidak ditemukan.\n";
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        size--;
        cout << "Data '" << value << "' berhasil dihapus.\n";
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
        cout << "4. Hapus Data\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Keluar\n";
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
                cout << "Masukkan data yang ingin dihapus: ";
                getline(cin, data);
                list.deleteData(data);
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
