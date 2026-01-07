#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX = 5;
    string buku[MAX] = {
        "Algoritma dan Pemrograman",
        "Struktur Data",
        "Basis Data",
        "Pemrograman C++",
        "Sistem Operasi"
    };
    bool dipinjam[MAX] = {false};

    int pilihan, no;
    char ulang;

    do {
        cout << "\n===== SISTEM PERPUSTAKAAN =====\n";
        cout << "1. Lihat Daftar Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nDaftar Buku:\n";
            for (int i = 0; i < MAX; i++) {
                cout << i + 1 << ". " << buku[i]
                     << (dipinjam[i] ? " (Dipinjam)" : " (Tersedia)") << endl;
            }

        } else if (pilihan == 2) {
            cout << "Masukkan nomor buku: ";
            cin >> no;

            if (no >= 1 && no <= MAX && !dipinjam[no - 1]) {
                dipinjam[no - 1] = true;
                cout << "Buku berhasil dipinjam.\n";
            } else {
                cout << "Buku tidak tersedia.\n";
            }

        } else if (pilihan == 3) {
            cout << "Masukkan nomor buku: ";
            cin >> no;

            if (no >= 1 && no <= MAX && dipinjam[no - 1]) {
                dipinjam[no - 1] = false;
                cout << "Buku berhasil dikembalikan.\n";
            } else {
                cout << "Buku tidak sedang dipinjam.\n";
            }

        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan sistem perpustakaan.\n";
            break;

        } else {
            cout << "Pilihan tidak valid.\n";
        }

        cout << "\nKembali ke menu? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
