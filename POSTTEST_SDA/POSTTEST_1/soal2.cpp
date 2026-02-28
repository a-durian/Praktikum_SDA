// Soal 2  
// Struct + Array Data Mahasiswa
// Buat program C++ menggunakan struct Mahasiswa yang memiliki 
    // field: nama (string), nim (string), dan ipk (float).
// Deklarasikan array of struct sesuai jumlah mahasiswa yang 
    // diminta, lakukan input data, lalu tampilkan hasil sesuai ketentuan.
 
// • Input data 5 mahasiswa (nama, NIM, IPK).
// • Cari dan tampilkan mahasiswa dengan IPK tertinggi.

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int jumlah_mahasiswa = 5;
    Mahasiswa mahasiswa[jumlah_mahasiswa];
    cout << "=== Program input data Mahasiswa dan menampilkan data Mahasiswa dengan nilai IPK tertinggi ==="
    // input data mahasiswa
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "Masukkan data Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore(); // membersihkan newline setelah input IPK
    }

    // Mencari mahasiswa dengan IPK tertinggi
    int indexTertinggi = 0;
    for (int i = 1; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].ipk > mahasiswa[indexTertinggi].ipk) {
            indexTertinggi = i;
        }
    }
    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mahasiswa[indexTertinggi].nama << endl;
    cout << "NIM: " << mahasiswa[indexTertinggi].nim << endl;
    cout << "IPK: " << mahasiswa[indexTertinggi].ipk << endl;
}