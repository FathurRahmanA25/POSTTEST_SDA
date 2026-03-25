#include <iostream>
using namespace std;

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    for(int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    cout << endl;

    reverseArray(arr, 7);

    cout << "Array sesudah dibalik: ";
    for(int i = 0; i < 7; i++)
        cout << arr[i] << " ";

    cout << endl;

    cout << "\nAlamat memori tiap elemen:" << endl;
    for(int i = 0; i < 7; i++)
        cout << "arr[" << i << "] = " << &arr[i] << endl;

    return 0;
}