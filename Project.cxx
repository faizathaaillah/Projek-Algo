#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct Rental
{
    int id;
    char nama[50];
    int nomorMejaPS;
    int jamMain;
    int harga;
    Rental *next;
};

Rental *head = NULL;

void tambahData()
{

    system("clear");

    Rental *baru = new Rental;

    cout << "===== TAMBAH BOOKING =====\n";

    cout << "Masukkan ID Booking     : ";
    cin >> baru->id;
    cin.ignore();

    cout << "Masukkan Nama           : ";
    cin.getline(baru->nama, 50);

    cout << "Nomor Meja PS           : ";
    cin >> baru->nomorMejaPS;

    cout << "Jam Main                : ";
    cin >> baru->jamMain;

    baru->harga = baru->jamMain * 5000;

    baru->next = NULL;

    if (head == NULL)
    {
        head = baru;
    }

    else
    {

        Rental *bantu = head;

        while (bantu->next != NULL)
        {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    cout << "\nBooking berhasil ditambahkan!\n";

    cin.ignore();
    cin.get();
}

int main()
{

    int pilih;

    do
    {

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

        switch (pilih)
        {

        case 1:
            tambahData();
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