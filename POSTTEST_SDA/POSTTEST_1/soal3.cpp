#include <iostream>
using namespace std;

void reverseArray(int* prima, int n) {
    int* pPrima = prima + n - 1; // pointer mulai dari elemen terakhir
    
    // menampilkan array setelah dibalik
    cout << "Array setelah dibalik: [ ";
    for (int i = 0; i < n; i++) {
        cout << *(pPrima - i) << " ";
    }
    cout << "]" << endl << endl;
    cout << "Nilai dan alamat array setelah dibalik: " << endl;
    // menampilkan nilai dan alamat arraynya kembali setelah dibalik
    while (pPrima >= prima) {
        cout << "Nilai: " << *pPrima << ", Alamat: " << pPrima << endl;
        pPrima--; // mundur ke elemen sebelumnya
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int *pPrima = prima;
    cout << "=== Soal 3 ===" << endl;
    cout << endl;
    // menampilkan array sebelum dibalik
    cout << "Array sebelum dibalik: [ ";
    for (int i = 0; i < 7; i++) {
        cout << *(prima + i) << " ";
    }
    cout << "]" << endl << endl;
    // mnampilkan nilai dan alamat array prima[7] sebelum dibalik
    cout << "Nilai dan alamat array sebelum dibalik: " << endl;
    while (pPrima < prima + 7) {
        cout << "Nilai: " << *pPrima << ", Alamat: " << pPrima << endl;
        pPrima++;
    }
    cout << endl;
    // menampilkan nilai dan alamat arraynya kembali setelah dibalik
    
    reverseArray(prima, 7);
    return 0;
}