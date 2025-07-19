// create by   : Rama Adhi Saputra
// Location    : Semarang, Central Java, Indonesia
// github      : ramayy-do
// Program     : bubble sort dengan metode input array, pengurutan descending 
// last update : 2025-6-23


#include <iostream>
#include <utility>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "Langkah " << i + 1 << ":" << endl;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                cout << "    Tukar " << arr[j] << " (" << j << ") dan " << arr[j+1] << " (" << j+1 << "): ";
                swap(arr[j], arr[j+1]);
                printArray(arr, n);
            }
        }
    }
}

int main() {
    const int max = 100;
    int arr[max];
    int n;

    cout << "Masukkan jumlah elemen (maksimal " << max << "): ";
    cin >> n;

    if (n <= 0 || n > max) {
        cout << "Ukuran array tidak valid. Harap masukkan antara 1 dan " << max << "." << endl;
        return 1;
    }

    cout << "Masukkan " << n << " elemen angka satu per satu:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    cout << "\nProses Bubble Sort DESCENDING:\n";
    bubbleSortDescending(arr, n);

    cout << "\nArray setelah diurutkan (DESCENDING): ";
    printArray(arr, n);

    return 0;
}
