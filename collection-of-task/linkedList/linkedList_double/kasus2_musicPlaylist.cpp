// create by: Rama Adhi Saputra
// date: 2025-09-05
// last update: 2025-09-05
/*
Fitur yang tersedia:
1. Tambah Lagu
2. Hapus Lagu
3. Cari Lagu
4. Tampilkan Semua Lagu

==========================

Program Playlist Music:
1.  Tambah Lagu Baru ke playlist
    Tambahkan node ke akhir list (insertLast)
2.  Tampilkan Daftar Lagu
    Tampilkan semua lagu dari awal ke akhir (printList)
3.  Hapus Lagu Tertentu dari Playlist (deleteTarget)
4.  Cari Lagu Berdasarkan Judul (search)

== rencana penambahan =
1.  Putar Lagu Sebelumnya (prev)
    Navigasi mundur pakai prev pointer 
2.  Putar Lagu Berikutnya (next)
    Navigasi maju pakai next pointer
*/


#include <iostream>
using namespace std;

//isi node
struct Music {
    string title;
    string singer;
    Music* next;
    Music* prev;
};

class MusicList {
private:
    Music* head = nullptr;
    Music* tail = nullptr;
    Music* current = nullptr;

public:
    // create new node
    Music* createMusic (string title, string singer) {
        Music* newMusic = new Music;
        newMusic->title = title;
        newMusic->singer = singer;
        newMusic->next = nullptr;
        newMusic->prev = nullptr;
        return newMusic;
    }

    // Menampilkan isi playlist
    void printList() {
        if (head == nullptr) {
            cout << "\ndaftar playlist kosong.\n";
            return;
        }
        Music* current = head;
        int index = 1;
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "         DAFTAR PLAYLIST MUSIC          " << endl;
        cout << "----------------------------------------" << endl;
        while (current != nullptr) {
            cout << index++;
            cout << ". Judul    : " << current->title << endl;
            cout << "   Penyanyi : " << current->singer <<endl;
            cout << "----------------------------------------" << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menyisipkan node sebagai elemen terakhir dalam linked list
    void insertLast(string title, string singer) {
        Music* newMusic = createMusic(title, singer);
        if (head == nullptr) {
            head = newMusic; // Jika linked list kosong, node baru menjadi head
        } else {
            Music* current = head;
            // Mencari posisi terakhir dalam linked list
            while (current->next != nullptr) {
                current = current->next;
            }
            // Menyisipkan node baru setelah posisi terakhir
            current->next = newMusic; // Mengatur next dari posisi terakhir menjadi node baru
            newMusic->prev = current; // Mengatur prev dari node baru
            // current -> new music
            // current <- new music
            cout << "[+] Lagu " << title << " berhasil ditambahkan ke playlist" << endl;
        }
    }

    //fungsi untuk mencari lagu yang dituju
    void searchData(string target) {
        Music* current = head;
        int position = 1;
        
        cout << endl;
        cout << "Mencari lagu dengan judul \"" << target << "\"..." << endl;
        
        if (current == nullptr) {
            cout << "Daftar lagu kosong.\n";
            return;
        }

        while (current != nullptr) {
            if (current->title == target) {
                cout << "Lagu ditemukan di urutan ke-" << position << ":\n";
                cout << "Judul   : " << current->title << endl;
                cout << "Penyanyi: " << current->singer << endl;
                return;           
            }
            current = current->next;
            position++;
        }
        cout << "Lagu \"" << target << "\" tidak ditemukan dalam playlist.\n";
    }

    //delete target
    void deleteTarget (string target) {
        Music* temp = head;

        // Jika node dengan nilai yang sesuai tidak ditemukan
        if (temp == nullptr) {
            cout << "lagu \"" << target << "\" tidak ditemukan" << endl;
            return;
        }

        // mencari node yang sesuai target
        while (temp != nullptr && temp->title != target && temp->singer != target) {
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
        cout << "Lagu \"" << target << "\" berhasil dihapus.\n";
        }
    };

// fungsi tampilkan menu pilihan
void displayChoice() {
        cout << "\n==========  PLAYLIST MUSIC  ==========\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Hapus Lagu\n";
        cout << "3. Cari Lagu\n";
        cout << "4. Tampilkan Semua Lagu\n";
        cout << "5. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilihan Anda [1-5]: ";
    }

int main () {
    MusicList playlist;
    int choice;
    string title, singer;

    do {
        displayChoice();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Masukkan judul lagu: ";
            getline(cin, title);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, singer);
            playlist.insertLast(title, singer);
            break;

        case 2:
            cout << "Masukkan judul atau penyanyi yang ingin dihapus: ";
            getline(cin, title);
            playlist.deleteTarget(title);
            break;

        case 3:
            cout << "Masukkan judul lagu yang ingin dicari: ";
            getline(cin, title);
            playlist.searchData(title);
            break;

        case 4:
            playlist.printList();
            break;

        case 5:
            cout << "Keluar dari program. Terimakasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 5);
return 0;
}
