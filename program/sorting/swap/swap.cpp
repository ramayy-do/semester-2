#include <iostream>
#include <utility>  // Untuk menggunakan fungsi swap bawaan
using namespace std;

// deskripsi:   tampilan yang diharapkan 50, 60, 65, 100, 100


// Fungsi untuk menampilkan array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Cetak setiap elemen array
    }
    cout << endl;
}

int main() {
    int arr[] = {100, 60, 100, 65, 50};  // Array yang akan digunakan
    int n = sizeof(arr)/sizeof(arr[0]); // Hitung ukuran array

    cout << "Array sebelum penukaran: ";
    printArray(arr, n);  // Tampilkan array sebelum penukaran

    // Menukar elemen ke-2 (indeks 1) dan elemen ke-4 (indeks 3)
    int index1 = 0, index2 = 1, index3 = 2, index4 = 3, index5 = 4;

    // cout << "\nMenukar elemen ke-" << index1 + 1 << " (" << arr[index1] << ") dan elemen ke-" << index2 + 1 << " (" << arr[index2] << ")\n";
    // // elemen ke-2 (20) dan elemen ke-4 (40)

    swap(arr[index1], arr[index5]);  // Gunakan fungsi swap bawaan 100 -> 50
    swap(arr[index3], arr[index4]);  // Gunakan fungsi swap bawaan 100 -> 65

    cout << "\nArray setelah penukaran: ";
    printArray(arr, n);  // Tampilkan array setelah penukaran 

    return 0;
}
