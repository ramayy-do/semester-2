// create by: Rama Adhi Saputra
// date: 5-13-2025
// berikut adalah kumpulan beberapa fungsi dari double linked list

#include <iostream>
using namespace std;

// isi data
struct Node {
    string data;
    Node* next;
    Node* prev;
};

class antrian {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;

public:
    // create new Node
    Node* createNode(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    // fungsi untuk menampilkan informasi di setiap node
    void printList() {
        // jika node kosong
        if (head == nullptr) {
            cout << "node kosong.\n";
            return;
        }
        Node* current = head;
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "            DAFTAR INFORMASI            " << endl;
        cout << "----------------------------------------" << endl;
        while (current != nullptr) {
            cout << "   Alamat     : " << current << endl;
            cout << "   Nilai      : " << current->data << endl;
            cout << "   Alamat prev: " << current->prev << endl;
            cout << "   Alamat next: " << current->next << endl<<endl;
            current = current->next;
        }
        cout << "---------------------------------------" <<endl;
    }

    // Fungsi untuk menyisipkan node sebagai elemen pertama dalam linked list
    void insertFirst(string value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {  // Jika linked list kosong
            head = newNode; // Node baru menjadi head
        } else {
            newNode->next = head;
            head->prev = newNode; // Mengatur prev dari head menjadi node baru
            head = newNode; // Mengatur node baru sebagai head
        }
    }

    // Fungsi untuk menyisipkan node setelah node dengan nilai tertentu dalam linked list
    void insertBefore(Node* head, int valueToInsertBefore, int data) {
        // Mulai pencarian dari head
        Node* current = head;
        // Mencari node dengan nilai yang sesuai
        while (current != nullptr && current->data != valueToInsertBefore) {
            current = current->next;
        }
        // Jika node dengan nilai yang sesuai tidak ditemukan
        if (current == nullptr) {
            cout << "Node dengan nilai " << valueToInsertBefore << " tidak ditemukan" << endl;
            return;
        }
    
        Node* newNode = createNode(data);
        newNode->prev = current->prev; 
        newNode->next = current; 
        current->prev = newNode; 
    
        // menghubungkan next dari node sebelum newNode
        if (newNode->next != nullptr) {
            newNode->prev->next = newNode;
        }
    }


    // Fungsi untuk menyisipkan node setelah node dengan nilai tertentu dalam linked list
    void insertAfter(string valueToInsertAfter, string value) {
        // Mulai pencarian dari head
        Node* current = head;
        // Mencari node dengan nilai yang sesuai
        while (current != nullptr && current->data != valueToInsertAfter) {
            current = current->next;
        }
        // Jika node dengan nilai yang sesuai tidak ditemukan
        if (current == nullptr) {
            cout << "Node dengan nilai " << valueToInsertAfter << " tidak ditemukan" << endl;
            return;
        }
        // Membuat node baru
        Node* newNode = createNode(value);
        // Menyisipkan node baru setelah node dengan nilai yang sesuai
        newNode->next = current->next; // Mengatur next dari node baru
        newNode->prev = current; // Mengatur prev dari node baru
        current->next = newNode; // Mengatur next dari node yang sebelumnya menunjuk ke node baru
        // Mengatur prev dari node yang berada setelah node baru, jika ada
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    // fungsi untuk menambahkan node baru di akhir linked list
    void insertLast(string value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {  // Jika linked list kosong
            head = tail = current = newNode;  // node baru menjadi head
        } else {
            Node* current = head;
            // Mencari posisi terakhir dalam linked list
            while (current->next != nullptr) {
                current = current->next;
            }
            // Menyisipkan node baru setelah tail (posisi terakhir)
            tail->next = newNode;  // Mengatur next dari posisi terakhir menjadi node baru
            newNode->prev = tail;  // Mengatur prev dari node baru
            tail = newNode;        // Mengubah node baru menjadi tail
        }
        cout << "[+] Node " << value << " berhasil ditambahkan ke antrian" << endl;
    }

    // fungsi untuk menghapus node paling awal di linked list
    void deleteFirst() {
        if (head == nullptr) {
            cout << "Antrian kosong." << endl;
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
        // Hapus node pertama
        delete temp;
    }

    // fungsi untuk menghapus node setelah node tertentu
    void deleteAfter(string valueToDeleteAfter) {
        // Jika linked list kosong
        if (head == nullptr) {
            cout << "Linked list kosong, tidak ada yang dihapus" << endl;
            return;
        }
        Node* current = head;
        // Mencari node dengan nilai yang sesuai
        while (current != nullptr && current->data != valueToDeleteAfter) {
            current = current->next;
        }
        // Jika node dengan nilai yang sesuai tidak ditemukan
        if (current == nullptr || current->next == nullptr) {
            cout << "Node dengan nilai " << valueToDeleteAfter << " tidak ditemukan atau tidak memiliki node setelahnya" << endl;
            return;
        }
        // Simpan alamat node yang akan dihapus
        Node* temp = current->next;
        // Hubungkan node sebelumnya dengan node setelah yang akan dihapus
        current->next = temp->next;
        // Jika node setelah yang akan dihapus bukan node terakhir
        if (temp->next != nullptr) {
            temp->next->prev = current;
        }
        // Hapus node
        delete temp;
    }

    void deleteLast() {
        // Jika linked list kosong
        if (head == nullptr) {
            cout << "Linked list kosong, tidak ada yang dihapus" << endl;
            return;
        }
    
        // Jika linked list hanya memiliki satu node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
    
        // Mencari node terakhir dalam linked list
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
    
        // Simpan alamat node terakhir
        Node* temp = current->next;
    
        // Mengatur prev dari node sebelumnya menjadi nullptr
        current->next = nullptr;
    
        // Hapus node terakhir
        delete temp;
    }

    // delete target 
    void deleteTarget(string target) {
        Node* temp = head;

        // Jika node yang sesuai dengan nilai tidak ditemukan
        if (temp == nullptr) {
            cout << target << " tidak ditemukan.\n";
            return;
        }

        // mencari node sesuai target
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        

        // Jika node yang dihapus adalah head
        if (temp == head) {
            head = temp->next;
            if (head != nullptr) {
                    head->prev = nullptr;
                }
        }
        // Jika node yang dihapus adalah tail
        else if (temp == tail) {
            tail = temp->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        }
        // Jika node di tengah
        else {
            temp->prev->next = temp->next; // temp->prev = current.. current->next = temp->next
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << target << "berhasil dihapus." << endl; 
    }

    // Tampilkan produk saat ini
    void showCurrent() {
        if (current == nullptr) {
            cout << "Tidak ada node yang sedang ditampilkan." << endl;
            return;
        }
        cout << "Sekarang menampilkan: " << current->data << endl;
    }

     // Navigasi ke produk selanjutnya
     void nextProduct() {
        // Mengecek apakah current punya data dan apakah ada node setelahnya
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            showCurrent();
        } else {
            cout << "Tidak ada node setelah ini." << endl;
        }
    }

    // Navigasi ke produk sebelumnya
    void prevProduct() {
        // Mengecek apakah current punya data dan apakah ada node setelahnya
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            showCurrent();
        } else {
            cout << "Tidak ada node sebelumnya." << endl;
        }
    }

    // mencari data sesuai nama target yang diinginkan
    void searchData(string target) {
        Node* temp = head;
        int position = 1;
    
        cout << "----------------------------------------" << endl;
        cout << "         HASIL PENCARIAN DATA           " << endl;
        cout << "----------------------------------------" << endl;

        if (temp == nullptr) {
            cout << "Antrian kosong.\n";
            return;
        }

        while (temp != nullptr) {
            if (temp->data == target) {
                cout << "Pasien ditemukan di urutan ke- " << position << endl;
                cout << "Alamat node     : " << temp << endl;
                cout << "Value           : " << temp->data << endl;
                cout << "Alamat prev     : " << temp->prev << endl;
                cout << "Alamat next     : " << temp->next << endl;
                cout << "----------------------------------------" << endl;
                return;           
            }
            temp = temp->next;  
            position++;
        }
        cout << "Data dengan nama " << target << " tidak ditemukan." << endl;
    }
};
return 0;
}
