/*
Program antrian pasien:
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
    node* head = nullptr;

    node* createNode(string value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void insertLast(string value) {
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
        cout << "[+] Pasien " << value << " berhasil ditambahkan ke antrian\n";
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Antrian kosong. Tidak ada pasien yang bisa dipanggil.\n";
            return;
        }

        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Pasien" << temp->data << " telah diperiksa.\n";
    }

    void searchData(string target) {
        node* temp = head;
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
        if (head == nullptr) {
            cout << "Antrian kosong.\n";
            return;
        }

        node* temp = head;
        int index = 1;
        cout << endl;
        cout << "----------------------------------------\n";
        cout << "         DAFTAR ANTRIAN PASIEN\n";
        cout << "----------------------------------------\n";
        while (temp != nullptr) {
            cout << index++ << ". " << temp->data << " (alamat node: " << temp << ")\n";
            temp = temp->next;
        }
        cout << "----------------------------------------\n";
    }
};

int main () {
    antrian klinik;
    int choice;
    string name;

    do {
        cout << "\n=== SISTEM ANTRIAN KLINIK ===\n";
        cout << "1. Tambah Pasien ke Antrian\n";
        cout << "2. Panggil Pasien (Hapus dari Antrian)\n";
        cout << "3. Tampilkan Seluruh Antrian\n";
        cout << "4. Cari Pasien berdasarkan Nama\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu [1-5]: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan nama pasien: ";
                getline(cin, name);
                klinik.insertLast(name);
                break;
            case 2:
                klinik.deleteFirst();
                break;
            case 3:
                klinik.printList();
                break;
            case 4:
                cout << "Masukkan nama yang ingin dicari: ";
                getline(cin, name);
                klinik.searchData(name);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem antrian.\n";
                break;
            default:
                cout << "choice tidak valid. Silakan pilih 1-5.\n";
        }
    } while (choice != 5);

return 0;
}
