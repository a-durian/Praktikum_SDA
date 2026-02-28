#include <iostream>
using namespace std;

void pertukaran_nilai(int* nilai_A, int* nilai_B) {
    int nilai_sementara = *nilai_A; // menyimpan nilai nilai_A sementara
    *nilai_A = *nilai_B; // menukar nilai nilai_A dengan nilai_B
    *nilai_B = nilai_sementara; // menukar nilai nilai_B dengan nilai_sementara (nilai_A yang asli)
}
int main() {
    int x, y;
    cout << "=== Soal 4 ===" << endl;
    cout << "=== Program pertukaran nilai dua variabel integer menggunakan pointer ===" << endl;
    cout << "Masukkan nilai integer pertama (x): ";
    cin >> x;
    cout << "Masukkan nilai integer kedua (y): ";
    cin >> y;

    cout << "Sebelum pertukaran: x = " << x << ", y = " << y << endl;

    // memanggil fungsi pertukaran_nilai dengan alamat variabel x dan y
    pertukaran_nilai(&x, &y); 
    cout << "Setelah pertukaran: x = " << x << ", y = " << y << endl;
    return 0;
}