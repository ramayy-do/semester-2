// create by: Rama Adhi Saputra
// date: 2025-10-05
// last update: 2025-10-05

/*
== Program shopping cart == 

Deskripsi:
Pengguna bisa menambahkan, menelusuri, dan menghapus produk dari keranjang belanja. Navigasi bisa dilakukan maju-mundur.

Fitur:
1. Tambah produk
2. Lihat produk secara berurutan
3. Hapus produk tertentu
4. Telusuri produk sebelumnya/selanjutnya

===============================

1. Tambah Produk ke Keranjang (insertLast)
   Menambahkan produk ke akhir keranjang belanja.
   insert last => (add susu, add roti, add sabun) susu <-> roti <-> sabun

2. Hapus Produk Tertentu (deleteByName)
   Menghapus produk berdasarkan nama dari keranjang.
   delete "roti" => susu <-> sabun

3. Tampilkan Seluruh Produk
   Menampilkan semua produk yang ada di keranjang secara berurutan dari awal ke akhir.

4. Cari Produk Berdasarkan Nama
   Menampilkan detail jika produk ditemukan.
   user input => nama produk (susu) => detail produk (nama: susu, harga: 15000)

5. Telusuri Produk Berikutnya (next)
   Menampilkan produk setelah yang sedang ditunjuk.

6. Telusuri Produk Sebelumnya (prev)
   Menampilkan produk sebelum yang sedang ditunjuk.
*/

#include <iostream>
using namespace std;

// isi data dalam node 
struct Product {
    string name;
    string price;
    Product* next;
    Product* prev;
};

// beberapa fungsi doubly linked list
class ShoppingCart {
private:
    Product* head = nullptr;
    Product* tail = nullptr;
    Product* current = nullptr;

public:
    // create new node
    Product* createProduct (string name, string price) {
        Product* newProduct = new Product;
        newProduct->name = name;
        newProduct->price = price;
        newProduct->next = nullptr;
        newProduct->prev = nullptr;
        return newProduct;
    }

    // menampilkan isi keranjang
    void printList() {
        if (head == nullptr) {
            cout << "\nKeranjang belanja kosong.\n";
            return;
        }
        Product* current = head;
        int index = 1;
        cout << "\nDaftar Produk di Keranjang:\n";
        while (current != nullptr) {
            cout << index++ << ". " << current->name << " - Rp " << current->price << endl;
            current = current->next;
        }
    }

    // insert last
    void addProduct(string name, string price) {
        Product* newProduct = createProduct(name, price);
        if (head == nullptr) {
            head = tail = current = newProduct; // Jika linked list kosong, node baru menjadi head
        }
        else {
            // Mencari posisi terakhir dalam linked list
            while (current->next != nullptr) {
                current = current->next;
            }
            // Menyisipkan node baru setelah posisi terakhir
            tail->next = newProduct; // Mengatur next dari posisi terakhir menjadi node baru
            newProduct->prev = tail; // Mengatur prev dari node baru
            tail = newProduct; // Mengubah ode baru menjadi tail
            // tail -> new music
            // tail <- new music
            cout << "[+] Produk " << name << " berhasil ditambahkan ke playlist" << endl;
        }
    }

    // delete target 
    void deleteProduct(string target) {
        Product* temp = head;

        // Jika node yang sesuai dengan nilai tidak ditemukan
        if (temp == nullptr) {
            cout << "Produk \"" << target << "\" tidak ditemukan.\n";
            return;
        }

        // mencari node sesuai target
        while (temp != nullptr && temp->name != target) {
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
            temp->prev->next = temp->next; 
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << "Lagu \"" << target << "\" berhasil dihapus." << endl; 
    }

    // Tampilkan produk saat ini
    void showCurrent() {
        if (current == nullptr) {
            cout << "Tidak ada produk yang sedang ditampilkan." << endl;
            return;
        }
        cout << "Sekarang menampilkan: " << current->name << " - Rp" << current->price << endl;
    }

     // Navigasi ke produk selanjutnya
     void nextProduct() {
        // Mengecek apakah current punya data dan apakah ada node setelahnya
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            showCurrent();
        } else {
            cout << "Tidak ada produk selanjutnya." << endl;
        }
    }

    // Navigasi ke produk sebelumnya
    void prevProduct() {
        // Mengecek apakah current punya data dan apakah ada node setelahnya
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            showCurrent();
        } else {
            cout << "Tidak ada produk sebelumnya." << endl;
        }
    }
};

// fungsi tampilkan menu
void displayChoice() {
    cout << "\n=== Menu Keranjang Belanja ===\n";
    cout << "1. Tambah Produk\n";
    cout << "2. Tampilkan Semua Produk\n";
    cout << "3. Hapus Produk\n";
    cout << "4. Lihat Produk Sekarang\n";
    cout << "5. Produk Berikutnya\n";
    cout << "6. Produk Sebelumnya\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

// algoritma utama
int main() {
    ShoppingCart cart;
    int choice;
    string name;
    string price;

    do {
        displayChoice();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Produk  : ";
                getline(cin, name);
                cout << "Tetapkan Harga Produk : Rp ";
                cin >> price;
                cart.addProduct(name, price);
                break;
            case 2:
                cart.printList();
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                getline(cin, name);
                cart.deleteProduct(name);
                break;
            case 4:
                cart.showCurrent();
                break;
            case 5:
                cart.nextProduct();
                break;
            case 6:
                cart.prevProduct();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);

    return 0;
}
