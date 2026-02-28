#include <iostream>
using namespace std;

// // Address-of Operator (&)
// int main() {
//     int angka = 50;
//     int *pAngka;
    
//     // Pointer menyimpan alamat variabel angka
//     pAngka = &angka;

//     // Menampilkan nilai dan alamat
//     cout << "Nilai variabel angka : " << angka << endl;
//     cout << "Alamat variabel angka : " << &angka << endl;
//     cout << "Alamat yang disimpan pointer : " << pAngka << endl;
//     cout << "Nilai yang diakses melalui pointer : " << *pAngka << endl;
//     return 0;
// }

// Deference Operator (*)
// int main() {
//     int nilai = 10; // Variabel integer
//     int *pNilai; // Deklarasi pointer

//     pNilai = &nilai; // Pointer menyimpan alamat variabel nilai

//     // Menampilkan nilai melalui pointer
//     cout << *pNilai << endl;

//     // Mengubah nilai variabel menggunakan pointer
//     *pNilai = 45;

//     // Menampilkan nilai variabel setelah diubah
//     cout << nilai << endl;
//     return 0;
// }


int main() {
    int data[5] = {10, 20, 30, 40, 50};
    int *p = data; // Pointer menunjuk ke elemen pertama array

    // Pointer bergerak selama masih berada dalam batas array
    while (p < data + 5) {
        cout << "Nilai: " << *p << ", Alamat: " << p << endl;
        p++; // Maju ke elemen berikutnya
    }
    return 0;
}