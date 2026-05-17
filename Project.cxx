#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct Rental {
    int id;
    char nama[50];
    int nomorMejaPS;
    int jamMain;
    int harga;
    Rental *next;
};

Rental *head = NULL;

int main() {

    int pilih;

    do {

        system("clear");

        cout << "===================================";
        cout << "\n   SISTEM MANAJEMEN RENTAL PS";
        cout << "\n===================================";
        cout << "\n1. Tambah Booking";
        cout << "\n2. Lihat Data Rental";
        cout << "\n3. Cari Pelanggan";
        cout << "\n4. Ubah Data Rental";
        cout << "\n5. Hapus Booking";
        cout << "\n6. Urutkan Harga Rental";
        cout << "\n7. Simpan Data";
        cout << "\n8. Keluar";
        cout << "\n===================================";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                cout << "\nMenu tambah booking";
                break;

            case 8:
                cout << "\nProgram selesai\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!";
        }

        cin.ignore();
        cin.get();

    } while (pilih != 8);

    return 0;
}