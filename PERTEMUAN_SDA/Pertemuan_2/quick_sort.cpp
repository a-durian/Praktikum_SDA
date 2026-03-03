#include <iostream>
#include <string>
using namespace std;
// Definisi Struct Mahasiswa
struct Mahasiswa {
string nim;
string nama;
};
// Fungsi untuk menukar dua objek Mahasiswa menggunakan pointer
void swap(Mahasiswa* a, Mahasiswa* b) {
Mahasiswa temp = *a;
*a = *b;
*b = temp;

}
// Fungsi Partition: Inti dari Quick Sort
int partition(Mahasiswa* arr, int low, int high) {
// Memilih elemen terakhir sebagai pivot
string pivot = (arr + high)->nim;
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
// Jika NIM saat ini lebih kecil dari pivot
if ((arr + j)->nim < pivot) {
i++;
swap((arr + i), (arr + j));
}
}
swap((arr + i + 1), (arr + high));
return (i + 1);
}
// Fungsi Utama Quick Sort
void quickSort(Mahasiswa* arr, int low, int high) {
if (low < high) {
// pi adalah index partisi, arr[pi] sudah di posisi yang benar
int pi = partition(arr, low, high);
// Sort elemen secara terpisah sebelum dan sesudah partisi
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void tampilkanData(Mahasiswa* arr, int n) {
cout << "NIM\t\tNama" << endl;
cout << "----------------------------" << endl;
for (int i = 0; i < n; i++) {
cout << (arr + i)->nim << "\t" << (arr + i)->nama << endl;
}
cout << endl;
}

int main() {
int n = 5;
Mahasiswa kelas[] = {
{"220910", "Budi"},
{"220901", "Ani"},
{"220915", "Citra"},
{"220905", "Dodi"},
{"220912", "Eka"}
};
cout << "=== DATA MAHASISWA (SEBELUM SORT) ===" << endl;
tampilkanData(kelas, n);
quickSort(kelas, 0, n - 1);
cout << "=== DATA MAHASISWA (SESUDAH QUICK SORT) ===" << endl;
tampilkanData(kelas, n);
return 0;
}