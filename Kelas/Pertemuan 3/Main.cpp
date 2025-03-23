#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
    string kota;
    int nomor;
};

struct Mahasiswa {
    string nama;
    string nim;
    string prodi;
    float ipk;
    int angkatan;
    Alamat alamat;
};

int main() {
    Mahasiswa mhs[5];

    mhs[0].nama = "Dimas";
    mhs[0].nim = "2460";
    mhs[0].prodi = "Informatika";
    mhs[0].ipk = 4.1;
    mhs[0].angkatan = 2024;
    mhs[0].alamat.jalan = "Pramuka";
    mhs[0].alamat.kota = "Samarinda";
    mhs[0].alamat.nomor = 16;

    mhs[1].nama = "Dimas";
    mhs[1].nim = "2460";
    mhs[1].prodi = "Informatika";
    mhs[1].ipk = 4.1;
    mhs[1].angkatan = 2024;
    mhs[1].alamat.jalan = "Pramuka";
    mhs[1].alamat.kota = "Samarinda";
    mhs[1].alamat.nomor = 16;

    for (int i = 0; i < 5; i++) {

    // mhs2.nama = "Harahap";
    // mhs2.nim = "2465";
    // mhs2.prodi = "Sistem Informasi";
    // mhs2.ipk = 4.2;
    // mhs2.angkatan = 2024;

    cout << "Nama\t:" << mhs[i].nama << endl;
    cout << "NIM\t:" << mhs[i].nim << endl;
    cout << "Prodi\t:" << mhs[i].prodi << endl;
    cout << "IPK\t:" << mhs[i].ipk << endl;
    cout << "Angkatan:" << mhs[i].angkatan << endl;
    cout << "Jalan\t:" << mhs[i].alamat.jalan << endl;
    cout << "Kota\t:" << mhs[i].alamat.kota << endl;
    cout << "Nomor\t:" << mhs[i].alamat.nomor << endl;

    cout << endl;
    
    // cout << "Nama\t:" << mhs2.nama << endl;
    // cout << "NIM\t:" << mhs2.nim << endl;
    // cout << "Prodi\t:" << mhs2.prodi << endl;
    // cout << "IPK\t:" << mhs2.ipk << endl;
    // cout << "Angkatan:" << mhs2.angkatan << endl;
    // cout << "Jalan\t:" << mhs2.alamat.jalan << endl;
    // cout << "Kota\t:" << mhs2.alamat.kota << endl;
    // cout << "Nomor\t:" << mhs2.alamat.nomor << endl;
    }
    return 0;
}