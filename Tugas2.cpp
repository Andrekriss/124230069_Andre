#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

//  menyimpan data pesanan
struct Pesanan {
    string namaPembeli;
    string jenisRoti;
    double totalHarga;
};

// menampilkan isi pesanan
void tampilkanPesanan(const Pesanan& p) {
    cout << "Nama Pembeli : " << p.namaPembeli << endl;
    cout << "Jenis Roti   : " << p.jenisRoti << endl;
    cout << "Total Harga  : Rp" << p.totalHarga << endl;
    cout << "-------------------------------\n";
}

int main() {
    queue<Pesanan> antrean;
    stack<Pesanan> riwayat;

    int pilihan;

    do {
        cout << "\n=== Sistem Antrean Toko Roti 'Manis Lezat' ===\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan Riwayat Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();  

        if (pilihan == 1) {
            Pesanan p;
            cout << "Masukkan nama pembeli: ";
            getline(cin, p.namaPembeli);
            cout << "Masukkan jenis roti  : ";
            getline(cin, p.jenisRoti);
            cout << "Masukkan total harga : Rp";
            cin >> p.totalHarga;
            cin.ignore();
            antrean.push(p);
            cout << "Pesanan berhasil ditambahkan ke antrean.\n";
        } else if (pilihan == 2) {
            if (!antrean.empty()) {
                Pesanan dilayani = antrean.front();
                antrean.pop();
                riwayat.push(dilayani);
                cout << "Pesanan dilayani:\n";
                tampilkanPesanan(dilayani);
            } else {
                cout << "Antrean kosong, tidak ada pesanan yang bisa dilayani.\n";
            }
        } else if (pilihan == 3) {
            if (antrean.empty()) {
                cout << "Tidak ada pesanan dalam antrean.\n";
            } else {
                cout << "\nDaftar Pesanan dalam Antrean:\n";
                queue<Pesanan> temp = antrean;
                while (!temp.empty()) {
                    tampilkanPesanan(temp.front());
                    temp.pop();
                }
            }
        } else if (pilihan == 4) {
            if (!antrean.empty()) {
                queue<Pesanan> temp;
                while (antrean.size() > 1) {
                    temp.push(antrean.front());
                    antrean.pop();
                }
                cout << "Pesanan terakhir berhasil dibatalkan:\n";
                tampilkanPesanan(antrean.front());
                antrean.pop();  //  Fungsi untuk hapus pesanan terakhir
                antrean = temp;
            } else {
                cout << "Tidak ada pesanan yang bisa dibatalkan.\n";
            }
        } else if (pilihan == 5) {
            if (riwayat.empty()) {
                cout << "Belum ada pesanan yang dilayani.\n";
            } else {
                cout << "\nRiwayat Pesanan yang Sudah Dilayani:\n";
                stack<Pesanan> temp = riwayat;
                while (!temp.empty()) {
                    tampilkanPesanan(temp.top());
                    temp.pop();
                }
            }
        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan sistem antrean.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}

