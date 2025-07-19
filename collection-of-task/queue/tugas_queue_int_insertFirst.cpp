// create by   : Rama Adhi Saputra
// Location    : Semarang, Central Java, Indonesia
// github      : ramayy-do
// Program     : Queue
// last update : 2025-6-23

/*
    insert First, delete Last
    include:
        - maximum data
        - jumlah data
        - sisa ruang
        - insert after 

    max = 4
    1 4 5 6 
    9 gabisa masuk
    4 5 6
    4 9 5 6
*/

#include <iostream>
using namespace std;

// Struktur Node untuk queue
struct Qnode {
    int data;
    Qnode* next;
};


class antrian {
    private:
    struct List {
        Qnode* head;    //buat manggil
        Qnode* front;   // data pertama masuk
        Qnode* end;    // data terakhir masuk
    };
    
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

    // node -> node -> null
    // Enqueue insert first (menambahkan elemen di awal queue)
    void EnqueueFirst(int data) {
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
            queue.end = newNode;
        }

        jumlahData++;
        cout << "Enqueue: " << data << endl;
    }

    // dequeue delete last (menghapus elemen dari akhir queue)
    void DequeueLast() {
        if (IsEmpty()) {
            cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
            return;
        }

        if (queue.head->next == nullptr) { // Jika hanya ada satu elemen di queue
            cout << "Dequeued : " << queue.end->data << endl;
            Qnode* temp = queue.head;
            queue.head = nullptr;
            queue.end = nullptr;
            queue.front = nullptr;
        }
        else {
            Qnode* current = queue.head;
            while (current->next != nullptr) {
                queue.front = current;
                current = current->next;
            }
            Qnode* temp = current;
            cout << "Dequeued : " << current->data << endl;
            queue.front->next = nullptr;
            delete temp;
            jumlahData--; 
        }
    }

    // inset after
    void insertAfter (int target, int data) {
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
            cout << "Data tidak ditemukan" << endl;
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

    // Fungsi untuk menampilkan isi queue
    void displayQueue() {
        if (IsEmpty()) {
            cout << "Queue kosong" << endl;
            return;
        }
        Qnode* current = queue.head;
        cout << "Isi queue:" << endl;
        while (current != nullptr) {
            cout << "Front: " << queue.front->data << endl;
            cout << "end: " << queue.end->data << endl;
            cout << "Alamat: " << current << endl;
            cout << "Nilai: " << current->data << endl;
            cout << "Alamat next: " << current->next << endl << endl;
            current = current->next;
        }

        cout << "jumlah data    :" << jumlahData << endl;
        cout << "sisa ruang     :" << sisaRuang() << endl;
        cout << endl << "---------------------------------------" <<endl;
    }
};

int main() {
    antrian q;

    // Memastikan queue kosong
    if (q.IsEmpty()) {
        cout << "Queue baru saja diinisialisasi dan kosong." << endl;
    }
    q.EnqueueFirst(1);
    q.EnqueueFirst(4);
    q.EnqueueFirst(5);
    q.EnqueueFirst(6);
    q.EnqueueFirst(9);
    q.displayQueue();
    q.DequeueLast();
    q.displayQueue();
    q.insertAfter(5, 9);
    q.displayQueue();
    return 0;
}
