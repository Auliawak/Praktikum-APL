        } else if (pilihan == "4") {
            if (pesanan.jumlahPesanan == 0) {
                cout << "Belum ada data untuk dihapus." << endl;
            } else {
                cout << "Daftar Pesanan Parfum:" << endl;
                for (int i = 0; i < pesanan.jumlahPesanan; i++) {
                    cout << "Pesanan " << (i + 1) << ":" << endl;
                    cout << "Nama Parfum: " << pesanan.daftarParfum[i].namaParfum << endl;
                    cout << "Jenis: " << pesanan.daftarParfum[i].jenisParfum << endl;
                    cout << "Harga: Rp. " << pesanan.daftarParfum[i].harga << endl;
                    cout << "------------------------" << endl;
                }
                int NoHapus;
                cout << "Masukkan nomor data yang akan dihapus: ";
                cin >> NoHapus;

                if (NoHapus > 0 && NoHapus <= pesanan.jumlahPesanan) {
                    for (int i = NoHapus - 1; i < pesanan.jumlahPesanan - 1; i++) {
                        pesanan.daftarParfum[i] = pesanan.daftarParfum[i + 1];
                    }
                    pesanan.jumlahPesanan--;
                    cout << "Data berhasil dihapus" << endl;
                } else {
                    cout << "Nomor data tidak valid" << endl;
                }
            }