#include <iostream>
#include <string>
using namespace std;

const string Nama = "AuliaNurRachman";
const string NIM = "2409106069";
const int MAX_PESANAN = 100;

struct Parfum {
    string namaParfum;
    string jenisParfum;
    double harga;
};

struct Pesanan {
    Parfum daftarParfum[MAX_PESANAN];
    int jumlahPesanan;
};

void buatPesanan(Pesanan *pesanan) {
    if (pesanan->jumlahPesanan >= MAX_PESANAN) {
        cout << "Kapasitas penuh! Tidak bisa menambah pesanan lagi." << endl;
    } else {
        cout << "Masukkan nama parfum: ";
        cin >> pesanan->daftarParfum[pesanan->jumlahPesanan].namaParfum;
        cout << "Masukkan jenis parfum: ";
        cin >> pesanan->daftarParfum[pesanan->jumlahPesanan].jenisParfum;
        cout << "Masukkan harga parfum: ";
        cin >> pesanan->daftarParfum[pesanan->jumlahPesanan].harga;

        pesanan->jumlahPesanan++;
        cout << "Pesanan parfum berhasil dibuat!" << endl;
    }
}

void tampilkanPesanan(Pesanan *pesanan) {
    if (pesanan->jumlahPesanan == 0) {
        cout << "Tidak ada data pesanan yang tersedia." << endl;
    } else {
        cout << "Daftar Pesanan Parfum:" << endl;
        for (int i = 0; i < pesanan->jumlahPesanan; i++) {
            cout << "Pesanan " << (i + 1) << ":" << endl;
            cout << "Nama Parfum: " << pesanan->daftarParfum[i].namaParfum << endl;
            cout << "Jenis: " << pesanan->daftarParfum[i].jenisParfum << endl;
            cout << "Harga: Rp. " << pesanan->daftarParfum[i].harga << endl;
            cout << "------------------------" << endl;
        }
    }
}

void perbaruiPesanan(Pesanan *pesanan) {
    int index;
    if (pesanan->jumlahPesanan == 0) {
        cout << "Tidak ada data pesanan yang tersedia." << endl;
    } else {
        tampilkanPesanan(pesanan);
        cout << "Pilih nomor pesanan yang ingin diperbarui: ";
        cin >> index;

        if (index < 1 || index > pesanan->jumlahPesanan) {
            cout << "Nomor tidak valid." << endl;
        } else {
            cout << "Masukkan nama parfum baru (kosongkan untuk tidak mengubah): ";
            string namaBaru;
            cin.ignore();
            getline(cin, namaBaru);
            if (!namaBaru.empty()) {
                pesanan->daftarParfum[index - 1].namaParfum = namaBaru;
            }

            cout << "Masukkan jenis parfum baru (kosongkan untuk tidak mengubah): ";
            string jenisBaru;
            getline(cin, jenisBaru);
            if (!jenisBaru.empty()) {
                pesanan->daftarParfum[index - 1].jenisParfum = jenisBaru;
            }

            cout << "Masukkan harga parfum baru (kosongkan untuk tidak mengubah): ";
            string hargaBaru;
            getline(cin, hargaBaru);
            if (!hargaBaru.empty()) {
                pesanan->daftarParfum[index - 1].harga = stod(hargaBaru);
            }

            cout << "Data pesanan berhasil diperbarui!" << endl;
        }
    }
}

void hapusPesanan(Pesanan *pesanan) {
    if (pesanan->jumlahPesanan == 0) {
        cout << "Belum ada data untuk dihapus." << endl;
    } else {
        tampilkanPesanan(pesanan);
        int NoHapus;
        cout << "Masukkan nomor data yang akan dihapus: ";
        cin >> NoHapus;

        if (NoHapus > 0 && NoHapus <= pesanan->jumlahPesanan) {
            for (int i = NoHapus - 1; i < pesanan->jumlahPesanan - 1; i++) {
                pesanan->daftarParfum[i] = pesanan->daftarParfum[i + 1];
            }
            pesanan->jumlahPesanan--;
            cout << "Data berhasil dihapus" << endl;
        } else {
            cout << "Nomor data tidak valid" << endl;
        }
    }
}

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

    Pesanan pesanan;
    pesanan.jumlahPesanan = 0;
    string pilihan;

    while (true) {
        cout << "\nMENU CRUD PEMESANAN PARFUM" << endl;
        cout << "1. Buat Pesanan Parfum" << endl;
        cout << "2. Tampilkan Data Pesanan" << endl;
        cout << "3. Perbarui Data Pesanan" << endl;
        cout << "4. Hapus Data Pesanan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == "1") {
            buatPesanan(&pesanan);
        } else if (pilihan == "2") {
            tampilkanPesanan(&pesanan);
        } else if (pilihan == "3") {
            perbaruiPesanan(&pesanan);
        } else if (pilihan == "4") {
            hapusPesanan(&pesanan);
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