// create by: Rama Adhi Saputra
// date: 2025-08-05
// last update: 2025-09-05

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
#include <iomanip> // buat setw
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

class antrian {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // create new Node
    Node* createNode(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void printList() {
        Node* current = head;
        int index = 1;

        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "         DAFTAR ANTRIAN PASIEN          " << endl;
        cout << "----------------------------------------" << endl;
        if (current == nullptr) {
            cout << "Antrian kosong" << endl;
        }
        while (current != nullptr) {
            cout << setw(2) << index++ << ". " << current->data <<endl;
            current = current->next;
        }
        cout << "---------------------------------------" <<endl;
    }
    
    void insertLast(string value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode; // jika linked list kosong
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // menghubungkan node baru dengan node sAebelumnya (previous)
            current->next = newNode;
            newNode->prev = current;
        }
        cout << endl;
        cout << "[+] Pasien " << value << " berhasil ditambahkan ke antrian\n";
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "---------------------------------------" <<endl;
            cout << "Antrian kosong. Tidak ada pasien yang bisa dipanggil\n";
            cout << "---------------------------------------" <<endl;
            return;
        }
        // Simpan alamat node yang akan dihapus
        Node* temp = head;
        // Ubah head menjadi node setelahnya
        head = head->next;
        
        // Jika linked list head tidak null atau ada isinya
        if (head != nullptr) {
            head->prev = nullptr;
        }
        cout << "---------------------------------------" <<endl;
        cout << "Pasien dengan nama " << temp->data << " telah diperiksa\n";
        cout << "---------------------------------------" <<endl;
        // Hapus node pertama
        delete temp;
    }

    void searchData(string target) {
        Node* current = head;
        int position = 1;
    
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "         HASIL PENCARIAN PASIEN         " << endl;
        cout << "----------------------------------------" << endl;
        if (current == nullptr) {
            cout << "Daftar pasien kosong.\n";
            return;
        }
        while (current != nullptr) {
            if (current->data == target) {
                cout << "Pasien \"" << target << "\" ditemukan di urutan ke-" << position << endl;                cout << "----------------------------------------" << endl;
                return;           
            }
            current = current->next;
            position++;
        }
        cout << "Data dengan nama " << target << " tidak ditemukan." << endl;
    }
};

void displayChoice () {
    cout << "\n=== SISTEM ANTRIAN KLINIK ===\n";
    cout << "1. Tambah pasien ke antrian\n";
    cout << "2. Panggil pasien (hapus dari antrian)\n";
    cout << "3. Tampilkan seluruh sntrian\n";
    cout << "4. Cari pasien berdasarkan nama\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu [1-5]: ";
}

int main () {
    antrian klinik;
    int choice;
    string name;

    do {
        displayChoice();
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




