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
    cout << "=== Soal 2 ===" << endl;
    cout << "=== Program input data Mahasiswa dan menampilkan data Mahasiswa dengan nilai IPK tertinggi ===" << endl;
    // input data mahasiswa
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "Masukkan data Mahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore();
    }

    // Mencari mahasiswa dengan IPK tertinggi
    int index_tertinggi = 0;
    for (int i = 1; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].ipk > mahasiswa[index_tertinggi].ipk) {
            index_tertinggi = i;
        }
    }
    cout << "Mahasiswa dengan IPK tertinggi dari input tersebut yaitu:" << endl;
    cout << "Nama: " << mahasiswa[index_tertinggi].nama << endl;
    cout << "NIM: " << mahasiswa[index_tertinggi].nim << endl;
    cout << "IPK: " << mahasiswa[index_tertinggi].ipk << endl;
}