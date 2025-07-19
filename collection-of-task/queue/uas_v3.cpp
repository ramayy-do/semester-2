/*
create by: rama adhi saputra
date: 20/06/2025
github: ramayy-do
location: semarang city
program queue (antrian) combinasi dengan linked list
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
    int data;
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

    int maxData = 4;
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
    void enqueueFirst(int data) {
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
            // queue.end = newNode;
        }

        jumlahData++;
        cout << "Enqueue: " << data << endl;
    }

    // node -> node -> null
    // Enqueue insert last (menambahkan elemen di akhir queue)
    void enqueueLast(int data) {
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
    void enqueueAfter (int target, int data) {
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
            int dequeuedData = queue.head->data; // Ambil data sebelum dihapus
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
            // Sekarang 'current' adalah node sebelum 'end'
            int dequeuedData = queue.end->data; // Ambil data sebelum dihapus
            delete queue.end; // Hapus node terakhir
            queue.end = current; // Update 'end' ke node 'current'
            current->next = nullptr; // Node 'current' sekarang jadi node terakhir, next-nya null
            jumlahData--;
            cout << "Dequeued (Last): " << dequeuedData << endl;
        }    
    }
    
    void dequeueAfter(int target) {
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

    // fungsi untuk menampilkan isi queue
    void displayQueue1() {
        cout << "\n=======================================" << endl;
        cout << "            STATUS QUEUE             " << endl;
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
        int count = 0;

        cout << "Isi Queue (Depan -> Belakang):" << endl;
        cout << "---------------------------------------" << endl;
        while (current != nullptr) {
            cout << "  [" << count++ << "] Data: " << setw(5) << left << current->data;
            if (current == queue.head) {
                cout << " (FRONT/HEAD)";
            }
            if (current == queue.end) { // Hindari (END) jika hanya 1 elemen
                cout << " (END)";
            } else if (queue.head == queue.end && current == queue.head) {
                 cout << " (FRONT/END)"; // Untuk kasus 1 elemen
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

    void displayQueue2() {
        cout << "\n==== MENU QUEUE ====\n";
        cout << "1. Enqueue First\n";
        cout << "2. Enqueue Last\n";
        cout << "3. Enqueue After\n";
        cout << "4. Dequeue First\n";
        cout << "5. Dequeue Last\n";
        cout << "6. Dequeue After\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Keluar\n";
        cout << "Pilihan Anda: ";
    }
};

int main() {
    antrian q;
    int choice;
    int data, target;
    
    // Memastikan queue kosong
    if (q.IsEmpty()) {
        cout << "Queue baru saja diinisialisasi dan kosong." << endl;
    }

        do {
        q.displayQueue2();
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                cout << "Masukkan Angka: "; cin >> data;
                q.enqueueFirst(data); 
                break;
            case 2:
                cout << "Masukkan Angka: "; cin >> data;
                q.enqueueLast(data); 
                break;
            case 3:
                cout << "Sisipkan setelah data (target): "; cin >> target;
                cout << "Masukkan data baru: "; cin >> data;
                q.enqueueAfter(target, data); 
                break;
            case 4:
                q.dequeueFirst();
                break;
            case 5:
                q.dequeueLast();
                break;
            case 6:
                cout << "Hapus data setelah (target): "; cin >> target;
                cout << "Data setelah " << target << " akan dihapus";
                q.dequeueAfter(target); 
                break;
            case 7:
                q.displayQueue1();
                break;
            case 8:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 8);
return 0;
}
