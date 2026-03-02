#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {

    // Array 8 elemen Fibonacci
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);

    cout << "Array: ";
    for(int i = 0; i < 8; i++) {
        cout << A[i] << " ";
    }

    cout << "\nNilai minimum : " << minimum << endl;
    cout << "Indeks minimum: " << indexMin << endl;

    return 0;
}


/*
=============================================
ANALISIS KOMPLEKSITAS WAKTU ALGORITMA FindMin
=============================================

Pseudocode:

min ← A[0]
for i ← 1 to n-1 do
    if A[i] < min then
        min ← A[i]
return min

------------------------------------
ANALISIS JUMLAH OPERASI (COST MODEL)
------------------------------------

Misalkan:
n = jumlah elemen array

1. Inisialisasi
   min = A[0]                → 1 operasi

2. Perulangan
   i dari 1 sampai n-1       → (n-1) iterasi

3. Perbandingan
   A[i] < min                → (n-1) kali

4. Assignment (jika kondisi benar)
   min = A[i]                → tergantung kasus

-----------------------------------------------------------
BEST CASE (Tmin)

Terjadi ketika:
Tidak pernah terjadi perubahan nilai minimum
(contoh: array sudah terurut naik)

Operasi:
1 (inisialisasi)
+ (n-1) perbandingan
+ 0 assignment tambahan

Tmin(n) = 1 + (n-1)
        = n

-----------------------------------------------------------
WORST CASE (Tmax)

Terjadi ketika:
Setiap elemen lebih kecil dari sebelumnya
(contoh: array terurut menurun)

Operasi:
1 (inisialisasi)
+ (n-1) perbandingan
+ (n-1) assignment

Tmax(n) = 1 + (n-1) + (n-1)
        = 2n - 1

-----------------------------------------------------------
NOTASI ASYMPTOTIC (BIG-O)

Ambil suku dominan:

Tmin(n)  = n        → O(n)
Tmax(n)  = 2n - 1   → O(n)

Karena konstanta dan konstanta tambahan diabaikan
dalam notasi Big-O.

-----------------------------------------------------------
KESIMPULAN

Algoritma FindMin memiliki kompleksitas linear
karena jumlah operasi bertambah sebanding
dengan jumlah elemen array (n).

Kompleksitas waktu:
Best Case  : O(n)
Worst Case : O(n)

===========================================================
*/
