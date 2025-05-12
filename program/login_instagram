// create by : rama adhi saputra
// last update : 2025-5-12
// github : ramayy-do
// program login instagram sederhana 

#include <iostream>
using namespace std;

void tampilanAwal() {
    cout << endl;
    cout << "   PROGRAM LOGIN INSTAGRAM   \n";
    cout << "_____________________________\n";
}

void menuInput () {
    cout << "masukkan pilihan anda: \n";
    cout << "1. masuk\n"; 
    cout << "2. daftar\n";
    cout << "0. keluar\n";
    cout << "pilihan anda: ";
}

void tampilanAkhir() {
    cout << "\n== SELAMAT ANDA BERHASIL LOGIN KE INSTAGRAM ==\n";
    cout << "________________________________________________\n"; 
    cout << "berikut data akun instagram anda:\n";
}

class login {
private:
    string email;
    string username;
    string password;
    
public:
    void programMasuk () {
        cout << endl;
        cout << "masukan email anda    : "; getline(cin, email);
        cout << "masukan username anda : "; getline(cin, username);
        cout << "masukan password anda : "; getline(cin, password);
    }

    void dataView () {
        cout << "email    : " << email << endl;
        cout << "username : " << username << endl;
        cout << "password : " << password << endl;
        cout << "------------------------------------------------\n"; 
    }
};

int main () {
    login login, sign;
    int choice;

    tampilanAwal();
    menuInput();
    cin >> choice;
    cin.ignore(); // Membersihkan newline di buffer

    if (choice == 0) {
        cout << "\nkeluar dari program." << endl;
        return 0;
    }

    switch (choice)
    {
    case 1:
        login.programMasuk();
        tampilanAkhir();
        login.dataView();
        break;
    case 2:
        sign.programMasuk();    
        tampilanAkhir();
        sign.dataView();
        break;
    default:
        break;
    }

    return 0;
}
