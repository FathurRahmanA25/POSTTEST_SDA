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
};

struct Queue {
    Hewan data[MAX];
    int front, rear;
};

struct Stack {
    Hewan data[MAX];
    int top;
};

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tampilSemua(Hewan* arr, int n) {
    if (n == 0) {
        cout << "\n[!] Belum ada data.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        Hewan* p = arr + i;
        cout << "\n[" << i << "] " << p->namaHewan
             << " | ID: " << p->idHewan
             << " | Biaya: " << p->hargaPerawatan;
    }
}

void tambahHewan(Hewan* arr, int& n) {
    if (n >= MAX) return;

    Hewan* p = arr + n;
    cout << "\nID: "; cin >> p->idHewan;
    cin.ignore();
    cout << "Nama: "; getline(cin, p->namaHewan);
    cout << "Jenis: "; getline(cin, p->jenisHewan);
    cout << "Kondisi: "; getline(cin, p->kondisi);
    cout << "Pemilik: "; getline(cin, p->namaPemilik);
    cout << "Biaya: "; cin >> p->hargaPerawatan;

    n++;
}

void linearSearch(Hewan* arr, int n, string key) {
    for (int i = 0; i < n; i++) {
        if ((arr+i)->namaHewan.find(key) != string::npos) {
            cout << "\nDitemukan: " << (arr+i)->namaHewan;
        }
    }
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if ((arr+j)->namaHewan > (arr+j+1)->namaHewan)
                swapHewan(arr+j, arr+j+1);
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if ((arr+j)->hargaPerawatan < (arr+min)->hargaPerawatan)
                min = j;
        swapHewan(arr+i, arr+min);
    }
}

void enqueue(Queue& q, Hewan h) {
    if (q.rear == MAX-1) {
        cout << "[!] Antrian penuh\n"; return;
    }
    if (q.front == -1) q.front = 0;
    q.data[++q.rear] = h;
}

bool dequeue(Queue& q, Hewan& h) {
    if (q.front == -1 || q.front > q.rear) {
        cout << "[!] Antrian kosong\n"; return false;
    }
    h = q.data[q.front++];
    cout << "Dipanggil: " << h.namaHewan << endl;
    return true;
}

void tampilAntrian(Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        cout << "[!] Kosong\n"; return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        Hewan* p = q.data + i;
        cout << p->namaHewan << " ";
    }
}

void peekQueue(Queue q) {
    if (q.front != -1)
        cout << "Depan: " << (q.data+q.front)->namaHewan << endl;
}

void push(Stack& s, Hewan h) {
    if (s.top == MAX-1) return;
    s.data[++s.top] = h;
}

void pop(Stack& s) {
    if (s.top == -1) {
        cout << "[!] Kosong\n"; return;
    }
    cout << "Hapus: " << s.data[s.top].namaHewan << endl;
    s.top--;
}

void tampilRiwayat(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        Hewan* p = s.data + i;
        cout << p->namaHewan << endl;
    }
}

void peekStack(Stack s) {
    if (s.top != -1)
        cout << "Terakhir: " << (s.data+s.top)->namaHewan << endl;
}

int main() {
    Hewan daftar[MAX];
    int n = 0;

    Queue antrian = {{}, -1, -1};
    Stack riwayat = {{}, -1};

    daftar[n++] = {1,"Mochi","Kucing","Sehat","Rina",150000};
    daftar[n++] = {2,"Buddy","Anjing","Sakit","Budi",300000};

    int pilih;
    do {
        cout << "\n1.Tampil\n2.Tambah\n3.Cari\n4.Sort Nama\n5.Sort Biaya\n";
        cout << "6.Enqueue\n7.Dequeue\n8.Lihat Antrian\n";
        cout << "9.Lihat Riwayat\n10.Pop Riwayat\n11.Peek\n0.Keluar\n";
        cin >> pilih;

        switch(pilih) {
            case 1: tampilSemua(daftar,n); break;
            case 2: tambahHewan(daftar,n); break;
            case 3: {
                string k; cin >> k;
                linearSearch(daftar,n,k);
                break;
            }
            case 4: bubbleSort(daftar,n); break;
            case 5: selectionSort(daftar,n); break;

            case 6: {
                int i; cin >> i;
                if (i>=0 && i<n)
                    enqueue(antrian, *(daftar+i));
                break;
            }

            case 7: {
                Hewan h;
                if (dequeue(antrian,h))
                    push(riwayat,h);
                break;
            }

            case 8: tampilAntrian(antrian); break;
            case 9: tampilRiwayat(riwayat); break;
            case 10: pop(riwayat); break;

            case 11:
                peekQueue(antrian);
                peekStack(riwayat);
                break;
        }

    } while(pilih != 0);

    return 0;
}