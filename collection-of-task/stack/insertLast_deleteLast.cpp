// create by   : Rama Adhi Saputra
// Location    : Semarang, Central Java, Indonesia
// github      : ramayy-do
// Program     : stack insert last delete last
// last update : 2025-6-26

#include <iostream>
using namespace std;

struct tElmtStack {
    int data;
    tElmtStack* next;
};

typedef tElmtStack Stack;

Stack* head = nullptr; // head = awal stack
Stack* TOP = nullptr;  // TOP = elemen terakhir

bool isEmpty() {
    return head == nullptr;
}

// Tambah di akhir (insert last)
void push(int data) {
    Stack* newNode = new Stack;
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        head = newNode;
    } else {
        Stack* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    TOP = newNode; // update TOP ke node terakhir
    cout << "Pushed: " << data << endl;
}

// Hapus dari akhir (delete last)
void pop() {
    if (isEmpty()) {
        cout << "Stack kosong, tidak ada yang di-pop" << endl;
        return;
    }

    if (head->next == nullptr) {
        // hanya satu elemen
        cout << "Popped: " << head->data << endl;
        delete head;
        head = nullptr;
        TOP = nullptr;
    } else {
        Stack* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        cout << "Popped: " << current->next->data << endl;
        delete current->next;
        current->next = nullptr;
        TOP = current; // update TOP
    }
}

// Tampilkan isi stack
void displayStack() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
        return;
    }
    Stack* current = head;
    cout << "Isi stack:" << endl;
    while (current != nullptr) {
        cout << "Alamat: " << current << endl;
        cout << "Nilai : " << current->data << endl;
        cout << "Next  : " << current->next << endl << endl;
        current = current->next;
    }
    if (TOP != nullptr) {
        cout << "TOP saat ini menunjuk ke: " << TOP << " (data = " << TOP->data << ")" << endl;
    }
    cout << "---------------------------------------" << endl;
}

int main() {
    if (isEmpty()) {
        cout << "Stack baru saja diinisialisasi dan kosong." << endl;
    }

    // Push elemen
    push(10);
    push(20);
    push(30);
    displayStack();

    // Pop elemen
    pop();
    displayStack();

    pop();
    displayStack();

    pop();
    displayStack();

    // Pop dari stack kosong
    pop();

    return 0;
}
