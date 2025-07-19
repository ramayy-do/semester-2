/*
// create by   : Rama Adhi Saputra
// Location    : Semarang, Central Java, Indonesia
// github      : ramayy-do
// Program     : Queue
// last update : 2025-6-20

program queue (antrian) combinasi dengan linked list, type string
include:
    - maximum data
    - jumlah data
    - sisa ruang
    - insert first 
    - insert last 
    - insert after
    - delete first
    - delete last
    - delete after
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Struktur Node untuk queue
struct node {
    string data;
    node* next;
};
typedef struct node Qnode;

class antrian {
    private:
    struct gerbong {
        Qnode* head;    // buat manggil
        Qnode* front;   // data pertama masuk
        Qnode* end;    // data terakhir masuk
    };
    typedef struct gerbong List;

    int maxData = 3;
    int jumlahData = 0;

public:
    // Inisialisasi queue
    List queue = {nullptr, nullptr, nullptr}; //head, front, end

    bool IsEmpty() {
        return queue.head == nullptr;
    }

    bool IsFull() {
        return jumlahData >= maxData;
    }

    int sisaRuang() {
        return maxData - jumlahData;
    }

    // null <- node <- node
    // Enqueue insert first (menambahkan elemen di awal queue)
    void enqueueFirst(string data) {
        if (IsFull()){
            cout << "Queue sudah penuh!\n" << endl;
            return;  
        }
        Qnode* newNode = new Qnode;
        newNode->data = data;
        newNode->next = queue.head;

        if (IsEmpty()) {
            queue.head = newNode;
            queue.front = newNode;
            queue.end = newNode;
        } else {
            queue.head = newNode;
        }

        jumlahData++;
        cout << "Enqueue (first): " << data << endl;
    }

    // node -> node -> null
    // Enqueue insert last (menambahkan elemen di akhir queue)
    void enqueueLast(string data) {
        if (IsFull()){
            cout << "Queue sudah penuh!" << endl;
            return;
        }

        Qnode* newNode = new Qnode;
        newNode->data = data;
        newNode->next = nullptr;

        if (IsEmpty()) {
            queue.head = newNode;
            queue.front = newNode;
            queue.end = newNode;
        } else {
            Qnode* current = queue.head;
            while(current->next != nullptr){
            current = current->next;
            }
            current->next = newNode;
            queue.end = newNode;
        }
        jumlahData++;
        cout << "Enqueue (Last): " << data << endl;
    }

    // inset after
    void enqueueAfter (string target, string data) {
        if (IsFull()) {
            cout << "Queue sudah penuh!" << endl;
            return;
        }
        
        if (IsEmpty()) {
            cout << "Queue kosong, tidak bisa insert after" << endl;
            return;
        }

        Qnode* current = queue.head;    
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data" << target << "tidak ditemukan" << endl;
            return;
        }

        Qnode* newNode = new Qnode;
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;

        if (current == queue.end) {
            queue.end = newNode;
        }

        jumlahData++;
        cout << "data: " << data << " berhasil disisipkan setelah data: " << target << endl;
    }

    
    // fungsi menghapus node paling depan 
    void dequeueFirst() {
        if (IsEmpty()) {
            cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
            return;
        }

        Qnode* temp = queue.head;
        queue.head = queue.head->next;
        if (queue.head == nullptr) { // Jika queue menjadi kosong setelah dequeue
            queue.end = nullptr;
            queue.front = nullptr;
        }else{
            queue.front = queue.head;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
        jumlahData--;
    }

    // fungsi menghapus node paling belakang
    void dequeueLast() {
        if (IsEmpty()) {
            cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
            return;
        }

       // Kasus 1: Hanya ada satu elemen
        if (queue.head->next == nullptr) {
            string dequeuedData = queue.head->data; // Ambil data sebelum dihapus
            delete queue.head; // Hapus node
            queue.head = nullptr;
            queue.front = nullptr;
            queue.end = nullptr;
            jumlahData--;
            cout << "Dequeued (Last): " << dequeuedData << endl;
        }
        // Kasus 2: Ada lebih dari satu elemen
        else {
            Qnode* current = queue.head;
            // mencari node sebelum node terakhir
            while (current->next != queue.end) {
                current = current->next;
            }
            string dequeuedData = queue.end->data; // Ambil data sebelum dihapus
            delete queue.end; 
            queue.end = current; 
            current->next = nullptr; 
            jumlahData--;
            cout << "Dequeued (Last): " << dequeuedData << endl;
        }    
    }
    
    void dequeueAfter(string target) {
        if (IsEmpty()) {
            cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
            return;
        }
    
        // cari node == value
        Qnode* current = queue.head;    
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Data tidak ditemukan" << endl;
            return;
        }

        if (current != nullptr && current->next != nullptr) {
            node* target = current->next;
            current->next = target->next;  // ptr current menuju node setelah target
            delete target;  // node yg akan dihapus
            jumlahData--;
        } else {
            cout << "Element '" << target << "' tidak ditemukan atau tidak punya node setelahnya.\n";
        }
    }

    void displayQueue1() {
        cout << "\n=======================================" << endl;
        cout << "   SYSTEM PEMANTAUAN PROSES CPU [FIFO]          " << endl;
        cout << "=======================================" << endl;

        if (IsEmpty()) {
            cout << "              Queue kosong             " << endl;
            cout << "---------------------------------------" << endl;
            cout << "Jumlah data  : " << jumlahData << endl;
            cout << "Sisa ruang   : " << sisaRuang() << endl;
            cout << "Maksimum data: " << maxData << endl;
            cout << "---------------------------------------" << endl;
            return;
        }

        Qnode* current = queue.head;

        cout << "Isi Queue (Depan -> Belakang):" << endl;
        cout << "---------------------------------------" << endl;
        while (current != nullptr) {
            cout << "Data: " << setw(5 ) << left << current->data << " alamat: "<< current;
            if (current == queue.front) {
                cout << " (FRONT)";
            } if (current == queue.end) {
                cout << " (END)";
            } else if (queue.head == queue.end && current == queue.head) {
                cout << " (FRONT/END)";
            }
            cout << endl;
            current = current->next;
        }
        cout << "---------------------------------------" << endl;
        cout << "Jumlah data  : " << jumlahData << endl;
        cout << "Sisa ruang   : " << sisaRuang() << endl;
        cout << "Maksimum data: " << maxData << endl;
        cout << "---------------------------------------" << endl;
    }

    // fungsi untuk menampilkan isi queue
    void displayQueue2() {
        cout << "\n=======================================" << endl;
        cout << "SYSTEM PEMANTAUAN PROSES CPU [Reversed]        " << endl;
        cout << "=======================================" << endl;

        if (IsEmpty()) {
            cout << "              Queue kosong             " << endl;
            cout << "---------------------------------------" << endl;
            cout << "Jumlah data  : " << jumlahData << endl;
            cout << "Sisa ruang   : " << sisaRuang() << endl;
            cout << "Maksimum data: " << maxData << endl;
            cout << "---------------------------------------" << endl;
            return;
        }

        Qnode* current = queue.head;

        cout << "Isi Queue (Depan -> Belakang):" << endl;
        cout << "---------------------------------------" << endl;
        while (current != nullptr) {
            cout << "Data: " << setw(5 ) << left << current->data << " alamat: "<< current;
            if (current == queue.head) {
                cout << " (END)";
            } if (current == queue.end) {
                cout << " (FRONT)";
            }  else if (queue.head == queue.end && current == queue.head) {
                cout << " (FRONT/END)";
            }
            cout << endl;
            current = current->next;
        }
        cout << "---------------------------------------" << endl;
        cout << "Jumlah data  : " << jumlahData << endl;
        cout << "Sisa ruang   : " << sisaRuang() << endl;
        cout << "Maksimum data: " << maxData << endl;
        cout << "---------------------------------------" << endl;
    }


    void displayQueue0() {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan\n";
        cout << "4. Enqueue After\n";
        cout << "5. Dequeue First\n";
        cout << "6. Dequeue After\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
    }

};


int main() {
    antrian q;
    int mode, pilihan;
    string data, target;

    
    cout << "Pilih mode queue:\n";
    cout << "1. Enqueue Last + Dequeue First (Normal FIFO)\n";
    cout << "2. Enqueue First + Dequeue Last (Reversed FIFO)\n";
    cout << "Pilihan: "; cin >> mode; 
    cout << endl;

    cout << "Nama : Rama Adhi Saputra\n";
    cout << "Nim  : A11.2024.15847\n";
    cout << "--------------------------";
    cout << endl;
    do {
        q.displayQueue0();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan data: "; getline(cin, data);
                if (mode == 1) {
                    q.enqueueLast(data);
                }
                else {
                    q.enqueueFirst(data);
                }
                break;
            case 2:
                if (mode == 1) {
                    q.dequeueFirst();
                }
                else { 
                    q.dequeueLast();
                }
                    break;
            case 3:
                if (mode == 1) {
                    q.displayQueue1();
                } else {
                    q.displayQueue2();
                }
                break;             
            case 4:
                cout << "Sisipkan setelah data (target): "; getline(cin, target);
                cout << "Data baru: "; getline(cin, data);
                q.enqueueAfter(target, data);
                break;
            case 5:
                q.dequeueFirst();
                break;
            case 6:
                cout << "Hapus node setelah data (target): "; getline(cin, target);
                q.dequeueAfter(target);
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}
