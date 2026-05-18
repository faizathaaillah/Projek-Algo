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

void kembaliMenu() {
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void tambahData()
{

    system("cls");

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

    kembaliMenu();
}

void lihatData() {

    system("cls");

    if (head == NULL) {
        cout << "Belum ada data rental!\n";
        kembaliMenu();
        return;
    }

    Rental *bantu = head;

    cout << "===== DATA BOOKING PS =====\n";

    while (bantu != NULL) {

        cout << "\nID Booking      : " << bantu->id << endl;
        cout << "Nama            : " << bantu->nama << endl;
        cout << "Nomor Meja PS   : " << bantu->nomorMejaPS << endl;
        cout << "Jam Main        : " << bantu->jamMain << " Jam" << endl;
        cout << "Total Bayar     : Rp" << bantu->harga << endl;

        bantu = bantu->next;
    }

    kembaliMenu();
}

void cariData() {
    system("cls");
    if (head == NULL) {
        cout << "Data rental masih kosong!\n";
        kembaliMenu();
        return;
    }
    int cari;
    bool ketemu = false;
    cout << "Masukkan ID Booking : ";
    cin >> cari;
    Rental *bantu = head;
    while (bantu != NULL) {
        if (bantu->id == cari) {

            cout << "\n===== BOOKING DITEMUKAN =====\n";
            cout << "Nama            : " << bantu->nama << endl;
            cout << "Nomor Meja PS   : " << bantu->nomorMejaPS << endl;
            cout << "Jam Main        : " << bantu->jamMain << endl;
            cout << "Total Bayar     : Rp." << bantu->harga << endl;

            ketemu = true;
        }
        bantu = bantu->next;
    }
    if (!ketemu) {
        cout << "\nBooking tidak ditemukan!\n";
    }
    kembaliMenu();
}

void ubahData() {

    system("cls");

    if (head == NULL) {
        cout << "Data rental masih kosong!\n";
        kembaliMenu();
        return;
    }

    int edit;
    bool ketemu = false;

    cout << "Masukkan ID Booking yang ingin diubah : ";
    cin >> edit;
    cin.ignore();

    Rental *bantu = head;

    while (bantu != NULL) {

        if (bantu->id == edit) {

            cout << "\n===== UBAH DATA RENTAL =====\n";

            cout << "Nama Baru             : ";
            cin.getline(bantu->nama, 50);

            cout << "Nomor Meja PS Baru    : ";
            cin >> bantu->nomorMejaPS;

            cout << "Jam Main Baru         : ";
            cin >> bantu->jamMain;

            bantu->harga = bantu->jamMain * 5000;

            cout << "\nData rental berhasil diubah!\n";

            ketemu = true;
        }

        bantu = bantu->next;
    }

    if (!ketemu) {
        cout << "\nBooking tidak ditemukan!\n";
    }

    kembaliMenu();
}

void hapusBooking() {

    system("cls");

    if (head == NULL) {
        cout << "Data rental masih kosong!\n";
        kembaliMenu();
        return;
    }

    int hapus;

    cout << "Masukkan ID Booking yang ingin dihapus : ";
    cin >> hapus;

    Rental *hapusNode;
    Rental *bantu;

    if (head->id == hapus) {

        hapusNode = head;
        head = head->next;

        delete hapusNode;

        cout << "\nBooking berhasil dihapus!\n";

        kembaliMenu();
        return;
    }

    bantu = head;

    while (bantu->next != NULL && bantu->next->id != hapus) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "\nBooking tidak ditemukan!\n";
    }

    else {

        hapusNode = bantu->next;
        bantu->next = hapusNode->next;

        delete hapusNode;

        cout << "\nBooking berhasil dihapus!\n";
    }

    kembaliMenu();
}


int main()
{

    int pilih;

    do
    {

        system("cls");

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

        case 2:
            lihatData();
            break;

        case 3:
            cariData();
            break;

        case 4:
            ubahData();
            break;

        case 5:
            hapusBooking();
            break;

        case 8:
            cout << "\nProgram selesai\n";
            break;

        default:
            cout << "\nMenu tidak tersedia!";
        }

    } while (pilih != 8);

    return 0;
}