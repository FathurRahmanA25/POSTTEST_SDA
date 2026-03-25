#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Hewan {
    int    idHewan;
    string namaHewan;
    string jenisHewan;
    string kondisi;
    string namaPemilik;
    int    hargaPerawatan;
};

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilSemua(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n  [!] Belum ada data hewan.\n";
        return;
    }
    cout << "\n  ============================================================\n";
    cout << "            DATA HEWAN PELIHARAAN - PAWCARE\n";
    cout << "  ============================================================\n";
    for (int i = 0; i < n; i++) {
        Hewan* p = arr + i;                    // pointer aritmatika [SYARAT 3]
        cout << "  [" << i+1 << "] ID Hewan       : " << p->idHewan        << "\n";
        cout << "      Nama Hewan    : " << p->namaHewan      << "\n";
        cout << "      Jenis Hewan   : " << p->jenisHewan     << "\n";
        cout << "      Kondisi       : " << p->kondisi        << "\n";
        cout << "      Nama Pemilik  : " << p->namaPemilik    << "\n";
        cout << "      Biaya Perawatan: Rp " << p->hargaPerawatan << "\n";
        cout << "  ------------------------------------------------------------\n";
    }
}

void tambahHewan(Hewan* arr, int& n) {
    if (n >= MAX) {
        cout << "  [!] Data penuh, maksimum " << MAX << " hewan.\n";
        return;
    }
    Hewan* p = arr + n;
    cout << "\n  ============================================================\n";
    cout << "              TAMBAH DATA HEWAN BARU\n";
    cout << "  ============================================================\n";

    cout << "  ID Hewan         : "; cin >> p->idHewan;
    if (p->idHewan <= 0) {
        cout << "  [!] ID hewan harus lebih dari 0. Batal.\n";
        return;
    }
    cin.ignore();
    cout << "  Nama Hewan       : "; getline(cin, p->namaHewan);
    if (p->namaHewan.empty()) {
        cout << "  [!] Nama hewan tidak boleh kosong. Batal.\n";
        return;
    }
    cout << "  Jenis Hewan      : "; getline(cin, p->jenisHewan);
    cout << "  Kondisi Hewan    : "; getline(cin, p->kondisi);
    cout << "  Nama Pemilik     : "; getline(cin, p->namaPemilik);
    cout << "  Biaya Perawatan  : Rp "; cin >> p->hargaPerawatan;
    if (p->hargaPerawatan < 0) {
        cout << "  [!] Biaya tidak boleh negatif. Batal.\n";
        return;
    }

    n++;
    cout << "  [v] Data hewan berhasil ditambahkan!\n";
}

void linearSearch(Hewan* arr, int n, const string& keyword) {
    cout << "\n  === LINEAR SEARCH: Nama Hewan mengandung \""
         << keyword << "\" ===\n";

    if (n == 0) { cout << "  [!] Belum ada data hewan.\n"; return; }

    bool found = false;
    for (int i = 0; i < n; i++) {
        string nama = (arr+i)->namaHewan;

        bool cocok = false;
        if ((int)nama.size() >= (int)keyword.size()) {
            for (int j = 0; j <= (int)nama.size() - (int)keyword.size(); j++) {
                if (nama.substr(j, keyword.size()) == keyword) {
                    cocok = true;
                    break;
                }
            }
        }

        if (cocok) {
            cout << "  [v] DITEMUKAN di indeks [" << i << "]:\n";
            cout << "      ID Hewan        : " << (arr+i)->idHewan        << "\n";
            cout << "      Nama Hewan      : " << (arr+i)->namaHewan      << "\n";
            cout << "      Jenis Hewan     : " << (arr+i)->jenisHewan     << "\n";
            cout << "      Kondisi         : " << (arr+i)->kondisi        << "\n";
            cout << "      Nama Pemilik    : " << (arr+i)->namaPemilik    << "\n";
            cout << "      Biaya Perawatan : Rp " << (arr+i)->hargaPerawatan << "\n";
            cout << "  ------------------------------------------------------------\n";
            found = true;
        }
    }
    if (!found)
        cout << "  [x] Hewan dengan nama \"" << keyword << "\" tidak ditemukan.\n";
}

void fibonacciSearch(Hewan* arr, int n, int target) {
    cout << "\n  === FIBONACCI SEARCH: ID Hewan [" << target << "] ===\n";

    if (n == 0) { cout << "  [!] Belum ada data hewan.\n"; return; }

    Hewan temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = *(arr + i);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (temp[i].idHewan > temp[j].idHewan) {
                Hewan t = temp[i]; temp[i] = temp[j]; temp[j] = t;
            }

    cout << "  Data terurut berdasarkan ID:\n";
    for (int i = 0; i < n; i++)
        cout << "    [" << i << "] ID." << temp[i].idHewan
             << " - " << temp[i].namaHewan << "\n";
    cout << "\n";

    int fib2 = 0;
    int fib1 = 1;
    int fib  = 1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib  = fib1 + fib2;
    }

    cout << "  Fibonacci awal : fib=" << fib
         << ", fib1=" << fib1 << ", fib2=" << fib2 << "\n\n";

    int offset = -1;
    int iter   = 1;

    while (fib > 1) {
        int i = offset + fib2;
        if (i >= n) i = n - 1;

        cout << "  Iterasi " << iter++
             << " : fib=" << fib << " fib2=" << fib2
             << " | cek indeks [" << i << "] ID." << temp[i].idHewan;

        if (temp[i].idHewan == target) {
            cout << " == " << target << "  >> KETEMU!\n";
            cout << "  ------------------------------------------------------------\n";
            cout << "  ID Hewan        : " << temp[i].idHewan        << "\n";
            cout << "  Nama Hewan      : " << temp[i].namaHewan      << "\n";
            cout << "  Jenis Hewan     : " << temp[i].jenisHewan     << "\n";
            cout << "  Kondisi         : " << temp[i].kondisi        << "\n";
            cout << "  Nama Pemilik    : " << temp[i].namaPemilik    << "\n";
            cout << "  Biaya Perawatan : Rp " << temp[i].hargaPerawatan << "\n";
            return;
        } else if (temp[i].idHewan < target) {
            cout << " < " << target << "  | cari kanan, geser offset\n";
            fib  = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else {
            cout << " > " << target << "  | cari kiri, perkecil range\n";
            fib  = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 == 1 && (offset + 1) < n && temp[offset + 1].idHewan == target) {
        int i = offset + 1;
        cout << "  Iterasi " << iter
             << " [sisa] : cek indeks [" << i << "] ID."
             << temp[i].idHewan << " == " << target << "  >> KETEMU!\n";
        cout << "  ------------------------------------------------------------\n";
        cout << "  ID Hewan        : " << temp[i].idHewan        << "\n";
        cout << "  Nama Hewan      : " << temp[i].namaHewan      << "\n";
        cout << "  Jenis Hewan     : " << temp[i].jenisHewan     << "\n";
        cout << "  Kondisi         : " << temp[i].kondisi        << "\n";
        cout << "  Nama Pemilik    : " << temp[i].namaPemilik    << "\n";
        cout << "  Biaya Perawatan : Rp " << temp[i].hargaPerawatan << "\n";
        return;
    }

    cout << "  [x] ID hewan " << target << " tidak ditemukan.\n";
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if ((arr+j)->namaHewan > (arr+j+1)->namaHewan)
                swapHewan(arr + j, arr + j + 1);
        }
    }
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if ((arr+j)->hargaPerawatan < (arr+minIdx)->hargaPerawatan)
                minIdx = j;
        if (minIdx != i)
            swapHewan(arr + i, arr + minIdx);
    }
}

void cariTermurah(Hewan* arr, int n, Hewan*& hasil) {
    hasil = arr;
    for (int i = 1; i < n; i++)
        if ((arr+i)->hargaPerawatan < hasil->hargaPerawatan)
            hasil = arr + i;
}

int main() {
    Hewan daftar[MAX];
    int n = 0;

    daftar[n++] = {3, "Mochi",   "Kucing",  "Sehat",  "Rina",    150000};
    daftar[n++] = {1, "Buddy",   "Anjing",  "Sakit",  "Budi",    300000};
    daftar[n++] = {5, "Kiki",    "Burung",  "Sehat",  "Sinta",    75000};
    daftar[n++] = {2, "Nemo",    "Ikan",    "Sehat",  "Dito",     50000};
    daftar[n++] = {4, "Brownie", "Kelinci", "Luka",   "Ayu",     200000};

    int pilihan;
    do {
        cout << "\n  ============================================================\n";
        cout << "         PAWCARE PETSHOP - MANAJEMEN HEWAN PELIHARAAN\n";
        cout << "  ============================================================\n";
        cout << "    1. Tampil Semua Data Hewan\n";
        cout << "    2. Tambah Data Hewan Baru\n";
        cout << "    3. Cari Hewan berdasarkan Nama\n";
        cout << "    4. Cari Hewan berdasarkan ID\n";
        cout << "    5. Urutkan Nama Hewan A-Z\n";
        cout << "    6. Urutkan Biaya Termurah\n";
        cout << "    7. Tampilkan Hewan Biaya Termurah\n";
        cout << "    0. Keluar\n";
        cout << "  ------------------------------------------------------------\n";
        cout << "    Pilihan: "; cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "  [!] Input tidak valid! Masukkan angka 0-7.\n";
            continue;
        }

        if (pilihan < 0 || pilihan > 7) {
            cout << "  [!] Pilihan tidak valid! Pilih angka antara 0 sampai 7.\n";
            continue;
        }

        switch (pilihan) {

            case 1:
                tampilSemua(daftar, n);
                break;

            case 2:
                tambahHewan(daftar, n);
                break;

            case 3: {
                string keyword;
                cin.ignore();
                cout << "  Nama hewan yang dicari: "; getline(cin, keyword);
                if (keyword.empty()) {
                    cout << "  [!] Kata kunci tidak boleh kosong.\n";
                } else {
                    linearSearch(daftar, n, keyword);
                }
                break;
            }

            case 4: {
                int idCari;
                cout << "  ID hewan yang dicari: "; cin >> idCari;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "  [!] ID harus berupa angka.\n";
                } else if (idCari <= 0) {
                    cout << "  [!] ID hewan harus lebih dari 0.\n";
                } else {
                    fibonacciSearch(daftar, n, idCari);
                }
                break;
            }

            case 5:
                if (n > 1) bubbleSort(daftar, n);
                cout << "\n  [v] Data berhasil diurutkan berdasarkan Nama (A-Z)!\n";
                tampilSemua(daftar, n);
                break;

            case 6:
                if (n > 1) selectionSort(daftar, n);
                cout << "\n  [v] Data berhasil diurutkan berdasarkan Biaya (termurah)!\n";
                tampilSemua(daftar, n);
                break;

            case 7: {
                if (n == 0) { cout << "  [!] Belum ada data hewan.\n"; break; }
                Hewan* hasil = 0;
                cariTermurah(daftar, n, hasil);
                cout << "\n  === HEWAN DENGAN BIAYA PERAWATAN TERMURAH ===\n";
                cout << "  ID Hewan        : " << hasil->idHewan        << "\n";
                cout << "  Nama Hewan      : " << hasil->namaHewan      << "\n";
                cout << "  Jenis Hewan     : " << hasil->jenisHewan     << "\n";
                cout << "  Kondisi         : " << hasil->kondisi        << "\n";
                cout << "  Nama Pemilik    : " << hasil->namaPemilik    << "\n";
                cout << "  Biaya Perawatan : Rp " << hasil->hargaPerawatan << "\n";
                break;
            }

            case 0:
                cout << "\n  Terima kasih telah menggunakan Pawcare Petshop!\n\n";
                break;
        }

    } while (pilihan != 0);

    return 0;
}