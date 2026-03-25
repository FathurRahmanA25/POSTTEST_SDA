#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    // Input data
    for(int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    // Cari IPK tertinggi
    int indexMax = 0;
    for(int i = 1; i < n; i++) {
        if(mhs[i].ipk > mhs[indexMax].ipk) {
            indexMax = i;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[indexMax].nama << endl;
    cout << "NIM: " << mhs[indexMax].nim << endl;
    cout << "IPK: " << mhs[indexMax].ipk << endl;

    return 0;
}