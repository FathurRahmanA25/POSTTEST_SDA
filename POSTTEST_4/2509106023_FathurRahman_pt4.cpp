#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Hewan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    string kondisi;
    string namaPemilik;
    int hargaPerawatan;
    Hewan* next;
};

struct Queue {
    Hewan* front;
    Hewan* rear;
    int size;
};

struct Stack {
    Hewan* top;
    int size;
};

void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
    q.size = 0;
}

void initStack(Stack& s) {
    s.top = nullptr;
    s.size = 0;
}

bool isQueueEmpty(Queue& q) { return q.front == nullptr; }
bool isStackEmpty(Stack& s) { return s.top == nullptr; }

void swapHewan(Hewan* a, Hewan* b) {
    int tmpId = a->idHewan;
    a->idHewan = b->idHewan;
    b->idHewan = tmpId;

    string tmpNama = a->namaHewan;
    a->namaHewan = b->namaHewan;
    b->namaHewan = tmpNama;

    string tmpJenis = a->jenisHewan;
    a->jenisHewan = b->jenisHewan;
    b->jenisHewan = tmpJenis;

    string tmpKond = a->kondisi;
    a->kondisi = b->kondisi;
    b->kondisi = tmpKond;

    string tmpPemil = a->namaPemilik;
    a->namaPemilik = b->namaPemilik;
    b->namaPemilik = tmpPemil;

    int tmpHarga = a->hargaPerawatan;
    a->hargaPerawatan = b->hargaPerawatan;
    b->hargaPerawatan = tmpHarga;
}

void tampilSemua(Hewan* arr, int n) {
    if (n == 0) { cout << "\n[!] Belum ada data.\n"; return; }
    cout << "\n======== DAFTAR HEWAN ========\n";
    for (int i = 0; i < n; i++) {
        Hewan* p = arr + i;
        cout << "[" << i << "] "
             << p->namaHewan << " | ID: " << p->idHewan
             << " | Jenis: " << p->jenisHewan << " | Kondisi: " << p->kondisi
             << " | Pemilik: " << p->namaPemilik << " | Biaya: Rp" << p->hargaPerawatan << "\n";
    }
}

void tambahHewan(Hewan* arr, int& n) {
    if (n >= MAX) { cout << "[!] Kapasitas penuh.\n"; return; }
    Hewan* p = arr + n;
    p->next = nullptr;
    cout << "\nID     : "; cin >> p->idHewan;
    cin.ignore();
    cout << "Nama   : "; getline(cin, p->namaHewan);
    cout << "Jenis  : "; getline(cin, p->jenisHewan);
    cout << "Kondisi: "; getline(cin, p->kondisi);
    cout << "Pemilik: "; getline(cin, p->namaPemilik);
    cout << "Biaya  : "; cin >> p->hargaPerawatan;
    n++;
    cout << "[+] Data berhasil ditambahkan.\n";
}

void linearSearch(Hewan* arr, int n, const string& key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        Hewan* p = arr + i;
        if (p->namaHewan.find(key) != string::npos) {
            cout << "  Ditemukan -> [" << i << "] " << p->namaHewan
                 << " | Biaya: Rp" << p->hargaPerawatan << "\n";
            found = true;
        }
    }
    if (!found) cout << "[!] Hewan tidak ditemukan.\n";
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if ((arr + j)->namaHewan > (arr + j + 1)->namaHewan)
                swapHewan(arr + j, arr + j + 1);
    cout << "[+] Diurutkan berdasarkan nama (A-Z).\n";
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if ((arr + j)->hargaPerawatan < (arr + minIdx)->hargaPerawatan)
                minIdx = j;
        swapHewan(arr + i, arr + minIdx);
    }
    cout << "[+] Diurutkan berdasarkan biaya (rendah ke tinggi).\n";
}

void enqueue(Queue& q, Hewan* src) {
    Hewan* node = new Hewan;
    *node = *src;
    node->next = nullptr;
    if (isQueueEmpty(q)) {
        q.front = q.rear = node;
    } else {
        q.rear->next = node;
        q.rear = node;
    }
    q.size++;
    cout << "[+] \"" << node->namaHewan << "\" masuk antrian (posisi " << q.size << ").\n";
}

bool dequeue(Queue& q, Hewan& hasil) {
    if (isQueueEmpty(q)) {
        cout << "[!] UNDERFLOW - antrian kosong.\n";
        return false;
    }
    Hewan* temp = q.front;
    hasil = *temp;
    hasil.next = nullptr;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete temp;
    q.size--;
    cout << "[-] Dipanggil: \"" << hasil.namaHewan << "\" | Pemilik: " << hasil.namaPemilik << "\n";
    return true;
}

void peekQueue(Queue& q) {
    if (isQueueEmpty(q)) {
        cout << "[!] UNDERFLOW - antrian kosong.\n";
        return;
    }
    cout << "[Peek Queue] Depan antrian: \"" << q.front->namaHewan
         << "\" | Pemilik: " << q.front->namaPemilik << "\n";
}

void tampilAntrian(Queue& q) {
    if (isQueueEmpty(q)) { cout << "[!] Antrian kosong.\n"; return; }
    cout << "\n====== ANTRIAN PERAWATAN (total: " << q.size << ") ======\n";
    Hewan* curr = q.front;
    int no = 1;
    while (curr != nullptr) {
        cout << "  " << no++ << ". " << curr->namaHewan
             << " | Pemilik: " << curr->namaPemilik
             << " | Kondisi: " << curr->kondisi
             << " | Biaya: Rp" << curr->hargaPerawatan << "\n";
        curr = curr->next;
    }
}

void push(Stack& s, Hewan* src) {
    Hewan* node = new Hewan;
    *node = *src;
    node->next = s.top;
    s.top = node;
    s.size++;
    cout << "[+] \"" << node->namaHewan << "\" disimpan ke riwayat.\n";
}

void pop(Stack& s) {
    if (isStackEmpty(s)) {
        cout << "[!] UNDERFLOW - riwayat kosong.\n";
        return;
    }
    Hewan* temp = s.top;
    cout << "[-] Dihapus dari riwayat: \"" << temp->namaHewan << "\"\n";
    s.top = s.top->next;
    delete temp;
    s.size--;
}

void peekStack(Stack& s) {
    if (isStackEmpty(s)) {
        cout << "[!] UNDERFLOW - riwayat kosong.\n";
        return;
    }
    cout << "[Peek Stack] Riwayat terakhir: \"" << s.top->namaHewan
         << "\" | Pemilik: " << s.top->namaPemilik << "\n";
}

void tampilRiwayat(Stack& s) {
    if (isStackEmpty(s)) { cout << "[!] Riwayat kosong.\n"; return; }
    cout << "\n====== RIWAYAT PERAWATAN (total: " << s.size << ") ======\n";
    Hewan* curr = s.top;
    int no = 1;
    while (curr != nullptr) {
        cout << "  " << no++ << ". " << curr->namaHewan
             << " | Pemilik: " << curr->namaPemilik
             << " | Kondisi: " << curr->kondisi
             << " | Biaya: Rp" << curr->hargaPerawatan << "\n";
        curr = curr->next;
    }
}

void freeQueue(Queue& q) {
    Hewan* curr = q.front;
    while (curr) { Hewan* tmp = curr->next; delete curr; curr = tmp; }
    initQueue(q);
}

void freeStack(Stack& s) {
    Hewan* curr = s.top;
    while (curr) { Hewan* tmp = curr->next; delete curr; curr = tmp; }
    initStack(s);
}

int main() {
    Hewan daftar[MAX];
    int n = 0;

    Queue antrian;
    Stack riwayat;
    initQueue(antrian);
    initStack(riwayat);

    daftar[n++] = {1, "Mochi", "Kucing",  "Sehat",  "Rina", 150000, nullptr};
    daftar[n++] = {2, "Buddy", "Anjing",  "Sakit",  "Budi", 300000, nullptr};
    daftar[n++] = {3, "Koko",  "Kelinci", "Sedang", "Sari", 200000, nullptr};

    int pilih;
    do {
        cout << "\n====== MENU KLINIK HEWAN ======\n";
        cout << " 1. Tampil Semua Hewan\n";
        cout << " 2. Tambah Hewan\n";
        cout << " 3. Cari Hewan\n";
        cout << " 4. Urutkan Nama  (Bubble Sort)\n";
        cout << " 5. Urutkan Biaya (Selection Sort)\n";
        cout << " 6. Enqueue  - Masuk Antrian\n";
        cout << " 7. Dequeue  - Panggil Antrian\n";
        cout << " 8. Tampil Antrian\n";
        cout << " 9. Tampil Riwayat\n";
        cout << "10. Pop      - Hapus Riwayat\n";
        cout << "11. Peek Antrian & Riwayat\n";
        cout << " 0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampilSemua(daftar, n);
                break;
            case 2:
                tambahHewan(daftar, n);
                break;
            case 3: {
                string key;
                cout << "Masukkan kata kunci nama: ";
                cin >> key;
                linearSearch(daftar, n, key);
                break;
            }
            case 4:
                bubbleSort(daftar, n);
                tampilSemua(daftar, n);
                break;
            case 5:
                selectionSort(daftar, n);
                tampilSemua(daftar, n);
                break;
            case 6: {
                tampilSemua(daftar, n);
                int idx;
                cout << "Pilih index hewan (0-" << n - 1 << "): ";
                cin >> idx;
                if (idx >= 0 && idx < n)
                    enqueue(antrian, daftar + idx);
                else
                    cout << "[!] Index tidak valid.\n";
                break;
            }
            case 7: {
                Hewan hasil;
                if (dequeue(antrian, hasil))
                    push(riwayat, &hasil);
                break;
            }
            case 8:
                tampilAntrian(antrian);
                break;
            case 9:
                tampilRiwayat(riwayat);
                break;
            case 10:
                pop(riwayat);
                break;
            case 11:
                peekQueue(antrian);
                peekStack(riwayat);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "[!] Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    freeQueue(antrian);
    freeStack(riwayat);

    return 0;
}