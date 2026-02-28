#include <iostream>
using namespace std;

// membuat struct Mahasiswa untuk menyimpan data mahasiswa
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
        getline(cin, mahasiswa[i].nama); // menggunakan getline untuk membaca nama yang mungkin mengandung spasi
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim); // menggunakan getline untuk membaca NIM yang mungkin mengandung spasi
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore(); // .ignor untuk membersihkan newline character dari input sebelumnya
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