#include <iostream>
using namespace std;

const string Nama = "AuliaNurRachman";
const string NIM = "2409106069";
const int MAX_PESANAN = 100;
struct Pesanan {
    string namaParfum;
    string jenisParfum;
    double harga;
};

int main() {
    string Usn;
    string NoNIM;
    int Minimal = 0;
    int Maksimal = 3;
    bool loginBerhasil = false;

    while (Minimal < Maksimal) {
        cout << "Masukkan Nama Anda: ";
        cin >> Usn;
        cout << "Masukkan NIM Anda: ";
        cin >> NoNIM;

        if (Usn == Nama && NoNIM == NIM) {
            loginBerhasil = true;
            cout << "Login berhasil!" << endl;
            break;
        } else {
            cout << "Nama dan NIM tidak sesuai. Silakan coba lagi." << endl;
            Minimal++;
            cout << "Tersisa " << (Maksimal - Minimal) << " kesempatan login." << endl;
        }
    }
    
    if (!loginBerhasil) {
        cout << "Anda telah mencapai batas percobaan login. Program akan keluar." << endl;
        return 0;
    }

    Pesanan daftarPesanan[MAX_PESANAN];
    int jumlahPesanan = 0;
    string pilihan;

    while (true) {
        cout << "\nMENU CRUD PEMESANAN PARFUM" << endl;
        cout << "1. Buat Pesanan Parfum" << endl;
        cout << "2. Tampilkan Data Pesanan" << endl;
        cout << "3. Perbarui Data Pesanan" << endl;
        cout << "4. Hapus Seluruh Data Pesanan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == "1") {
            if (jumlahPesanan >= MAX_PESANAN) {
                cout << "Kapasitas penuh! Tidak bisa menambah pesanan lagi." << endl;
            } else {
                cout << "Masukkan nama parfum: ";
                cin >> daftarPesanan[jumlahPesanan].namaParfum;
                cout << "Masukkan jenis parfum: ";
                cin >> daftarPesanan[jumlahPesanan].jenisParfum;
                cout << "Masukkan harga parfum: ";
                cin >> daftarPesanan[jumlahPesanan].harga;

                jumlahPesanan++;
                cout << "Pesanan parfum berhasil dibuat!" << endl;
            }
        } else if (pilihan == "2") {
            if (jumlahPesanan == 0) {
                cout << "Tidak ada data pesanan yang tersedia." << endl;
            } else {
                cout << "Daftar Pesanan Parfum:" << endl;
                for (int i = 0; i < jumlahPesanan; i++) {
                    cout << i + 1 << ". Nama Parfum: " << daftarPesanan[i].namaParfum
                         << ", Jenis: " << daftarPesanan[i].jenisParfum
                         << ", Harga: Rp. " << daftarPesanan[i].harga << endl;
                }
            }
        } else if (pilihan == "3") {
            int index;
            if (jumlahPesanan == 0) {
                cout << "Tidak ada data pesanan yang tersedia." << endl;
            } else {
                cout << "Daftar Pesanan Parfum:" << endl;
                for (int i = 0; i < jumlahPesanan; i++) {
                    cout << i + 1 << ". Nama Parfum: " << daftarPesanan[i].namaParfum
                         << ", Jenis: " << daftarPesanan[i].jenisParfum
                         << ", Harga: Rp. " << daftarPesanan[i].harga << endl;
                }
                cout << "Pilih nomor pesanan yang ingin diperbarui: ";
                cin >> index;

                if (index < 1 || index > jumlahPesanan) {
                    cout << "Nomor tidak valid." << endl;
                } else {
                    cout << "Masukkan nama parfum baru (kosongkan untuk tidak mengubah): ";
                    string namaBaru;
                    cin.ignore();
                    getline(cin, namaBaru);
                    if (!namaBaru.empty()) {
                        daftarPesanan[index - 1].namaParfum = namaBaru;
                    }

                    cout << "Masukkan jenis parfum baru (kosongkan untuk tidak mengubah): ";
                    string jenisBaru;
                    getline(cin, jenisBaru);
                    if (!jenisBaru.empty()) {
                        daftarPesanan[index - 1].jenisParfum = jenisBaru;
                    }

                    cout << "Masukkan harga parfum baru (kosongkan untuk tidak mengubah): ";
                    string hargaBaru;
                    getline(cin, hargaBaru);
                    if (!hargaBaru.empty()) {
                        daftarPesanan[index - 1].harga = stod(hargaBaru);
                    }

                    cout << "Data pesanan berhasil diperbarui!" << endl;
                }
            }
        } else if (pilihan == "4") {
            if (jumlahPesanan == 0) {
                cout << "Belum ada data untuk dihapus." << endl;
            } else {
                cout << "Daftar Pesanan Parfum:" << endl;
                for (int i = 0; i < jumlahPesanan; i++) {
                    cout << i + 1 << ". Nama Parfum: " << daftarPesanan[i].namaParfum
                         << ", Jenis: " << daftarPesanan[i].jenisParfum
                         << ", Harga: Rp. " << daftarPesanan[i].harga << endl;
                }
                int NoHapus;
                cout << "Masukkan nomor data yang akan dihapus: ";
                cin >> NoHapus;
        
                if (NoHapus > 0 && NoHapus <= jumlahPesanan) {
                    for (int i = NoHapus - 1; i < jumlahPesanan - 1; i++) {
                        daftarPesanan[i] = daftarPesanan[i + 1];
                    }
                    jumlahPesanan--;
                    cout << "Data berhasil dihapus" << endl;
                } else {
                    cout << "Nomor data tidak valid" << endl;
                }
            }
        } else if (pilihan == "5") {
            cout << "Terima kasih telah menggunakan program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid! Pastikan memilih angka yang ada di menu." << endl;
        }

        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    return 0;
}