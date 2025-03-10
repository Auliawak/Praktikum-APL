#include <iostream>
using namespace std;

const string PIN = "6069";
const int Maksimal = 3;

int Login() {
    string PinInput;
    int Minimal = 0;

    while (Minimal < Maksimal) {
        cout << "Masukkan PIN Anda: ";
        cin >> PinInput;

        if (PinInput == PIN) {
            return true;
        } else {
            cout << "PIN salah. Silakan coba lagi." << endl;
            Minimal++;
        }
    }
    return false;
}

void MenuUtama() {
    cout << "MENU ATM" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Setor Tunai" << endl;
    cout << "3. Tarik Tunai" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih opsi: ";
}

void InfoSaldo(int Saldo) {
    cout << "Saldo Anda saat ini: Rp. " << Saldo << endl;
}

void Setor(int &Saldo) {
    int Setor;
    while (true) {
        cout << "Masukkan jumlah uang yang ingin disetor: ";
        cin >> Setor;

        if (Setor < 0) {
            cout << "Mohon maaf, angka yang dimasukkan harus positif" << endl;
        } else if (Setor < 100000) {
            cout << "Mohon maaf, minimal saldo yang harus disetor adalah RP. 100000" << endl;

        } else {
            Saldo += Setor;
            cout << "Setor tunai berhasil!" << endl;
            break; 
        }
    }
}

void Tarik(int &Saldo) {
    int Tarik;
    while (true) {
        cout << "Masukkan jumlah uang yang ingin ditarik tunai: ";
        cin >> Tarik;
        if (Tarik < 0) {
            cout << "Mohon maaf, angka yang dimasukkan harus positif." << endl;
        } else if (Tarik < 100000) {
            cout << "Mohon maaf, Minimal saldo yang harus ditarik adalah RP. 100000." << endl;
        } else if (Tarik > Saldo) {
            cout << "Mohon maaf, Saldo anda tidak mencukupi." << endl;
        
        } else {
            Saldo -= Tarik;
            cout << "Penarikan tunai berhasil!" << endl;
            break;
        }
    }     
}

void Lanjut() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls");
}

int main() {
    int Saldo = 5000000; // Saldo awal

    if (!Login()) {
        cout << "Anda telah gagal login sebanyak 3 kali. Silakan coba lagi nanti." << endl;
        return 0;
    }

    string Pilihan;
    while (true) {
        MenuUtama();
        cin >> Pilihan;
        Lanjut();

        if (Pilihan == "1") {
            InfoSaldo(Saldo);
            Lanjut();
        } else if (Pilihan == "2") {
            Setor(Saldo);
            Lanjut();
        } else if (Pilihan == "3") {
            Tarik(Saldo);
            Lanjut();
        } else if (Pilihan == "4") {
            cout << "Terima kasih telah menggunakan program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Pastikan memilih angka yang ada di menu." << endl;
        }
    }
    return 0;
}