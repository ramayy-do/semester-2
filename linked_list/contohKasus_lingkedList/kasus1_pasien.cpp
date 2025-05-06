/*
1. Tambah Pasien ke Antrian (enqueue)
   Menambahkan pasien ke akhir antrian.
   insert last => (add rama, add roni, add wilma) rama -> roni -> wilma

2. Panggil Pasien (dequeue)
   Menghapus pasien dari depan antrian.
   delete first => (delete rama) roni -> wilma

3. Tampilkan Seluruh Antrian
   Menampilkan semua pasien yang sedang mengantri.

4. Cari Pasien berdasarkan Nama
   Menampilkan detail jika pasien ditemukan.
   user input => nama pasien (rama) => detail pasien (nama: rama, umur: 25, alamat: jalan)
*/

#include <iostream>
using namespace std;

struct node {
    string data;
    node* next;
};

class antrian {
    public:
    node* patient = nullptr;
    int size = 0;

    node* createNode(string value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void insertLast(string value) {
        node* newNode = createNode(value);
        if (patient == nullptr) {
            patient = newNode;
        } else {
            node* temp = patient;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
        cout << "Pasien " << value << "' berhasil ditambahkan ke antrian\n";
    }

    void deleteFirst() {
        if (patient == nullptr) {
            cout << "List kosong.\n";
            return;
        }

        node* temp = patient;
        patient = patient->next;
        delete temp;
        size--;
        cout << "Pasien telah diperiksa";
    }

    void searchData(string target) {
        node* temp = patient;
        int potition = 1;
        bool found = false; // found = ditemukan
    
        while (temp != nullptr) {
            if (temp->data == target) {
                cout << "Data dengan nama \"" << target << "\" berada di urutan ke-" << potition << endl;
                found = true;
                break;
            }
            temp = temp->next;
            potition++;
        }
    
        if (!found) {
            cout << "Data dengan nama \"" << target << "\" tidak ditemukan." << endl;
        }
    }

    void printList() {
        if (patient == nullptr) {
            cout << "Data kosong.\n";
            return;
        }

        node* temp = patient;
        int index = 1;
        cout << "\nDaftar Antrian\n";
        while (temp != nullptr) {
            cout << index++ << ". " << temp->data << " (alamat: " << temp << ")\n";
            temp = temp->next;
        }
    }
};

int main () {
}




