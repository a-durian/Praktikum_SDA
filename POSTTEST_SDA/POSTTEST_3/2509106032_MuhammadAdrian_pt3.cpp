#include <iostream>
#include <iomanip> // untuk setw(), left, right
#include <string>
#include <cmath> // untuk sqrt() di Jump Search
using namespace std;

struct Kereta {
    string nomor_kereta, nama_kereta, asal, tujuan, jam_berangkat;
    int harga_tiket, kursi_tersedia;
};

struct Penumpang{
    string nama;
    string nomor_kereta;
};

struct Tiket {
    string nama_penumpang;
    string nomor_kereta;
    string nama_kereta;
    string asal, tujuan;
    int harga_tiket;
};

const int MAKS = 20;

// >>>> STRUCT QUEUE <<<<
struct Queue {
    Penumpang data[MAKS];
    int front;
    int rear;
    int ukuran;
};

void initQueue(Queue* q) {
    q->front = 0;
    q->rear  = -1;
    q->ukuran = 0;
};

bool isQueueEmpty(Queue* q) { return q->ukuran == 0; }
bool isQueueFull(Queue* q) { return q->ukuran == MAKS; }

// ambil penumpang ke belakang antrian
bool enqueue(Queue* q, Penumpang p) {
    if (isQueueFull(q)) return false;
    q->rear = (q->rear + 1) % MAKS; // circular array
    *(q->data + q->rear) = p;        // dereferensi pointer
    q->ukuran++;
    return true;
}

// ambil penumpang terdepan dalam antrian
bool dequeue(Queue* q, Penumpang* hasil) {
    if (isQueueEmpty(q)) return false;
    *hasil = *(q->data + q->front); // dereferensi pointer
    q->front = (q->front + 1) % MAKS; // circular array
    q->ukuran--;
    return true;
}

// peek front antrian
bool peekQueue(Queue* q, Penumpang* hasil) {
    if (isQueueEmpty(q)) return false;
    *hasil = *(q->data + q->front);
    return true;
}

// >>>> STRUCT STACK <<<
struct Stack {
    Tiket data[MAKS];
    int top;
};

void initStack(Stack* s) { s->top = -1; }

bool isStackEmpty(Stack* s) { return s->top == -1; }
bool isStackFull(Stack* s) { return s->top == MAKS - 1; }

// tambah tiket ke stack
bool push(Stack* s, Tiket t) {
    if (isStackFull(s)) return false;
    s->top++;
    *(s->data + s->top) = t;
    return true;
}

// peek top stack
bool peekStack(Stack* s, Tiket* hasil){
    if(isStackEmpty(s)) return false;
    *hasil = *(s->data + s->top);
    return true;
}

// hapus tiket teratas dari stack
bool pop(Stack* s, Tiket* hasil) {
    if(isStackEmpty(s)) return false; 
    *hasil = *(s->data + s->top); // dereferensi pointer
    s->top--;
    return true;
}

// >>> cari kereta berdasarkan nomor(Helper) <<<<
Kereta* cariKeretaByNomor(Kereta* arr, int n, string nomor) {
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nomor_kereta == nomor) {
            return arr + i; // pointer ke kereta yang ditemukan
        }
    }
    return nullptr; // tidak ditemukan
}

// Fungsi cetakkkkkkk
void cetakGaris() {
    cout << "+" << string(8, '-')
         << "+" << string(24, '-')
         << "+" << string(13, '-')
         << "+" << string(13, '-')
         << "+" << string(8, '-')
         << "+" << string(13, '-')
         << "+" << string(8, '-')
         << "+" << endl;
}

void cetakBaris(const Kereta* k) {
    cout << "| " << left << setw(7)  << k->nomor_kereta
         << "| " << setw(23) << k->nama_kereta
         << "| " << setw(12) << k->asal
         << "| " << setw(12) << k->tujuan
         << "| " << setw(7)  << k->jam_berangkat
         << "| Rp " << right << setw(9) << k->harga_tiket
         << "| " << left  << setw(7)  << k->kursi_tersedia
         << "|" << endl;
}

void cetakHeader() {
    cetakGaris();
    cout << "| " << left << setw(7)  << "No.KA"
         << "| " << setw(23) << "Nama Kereta"
         << "| " << setw(12) << "Asal"
         << "| " << setw(12) << "Tujuan"
         << "| " << setw(7)  << "Jam"
         << "| " << setw(12) << "Harga"
         << "| " << setw(7)  << "Kursi"
         << "|" << endl;
    cetakGaris();
}

// 1. Tampil jadwal semua kereta (menggunakan pointer)
void tampilkanJadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << endl << "  [!] Tidak ada data kereta." << endl;
        return;
    }

    cout << endl << ">>>==================================<<<" << endl;
    cout <<         ">>>         JADWAL KERETA API        <<<" << endl;
    cout <<         ">>>==================================<<<" << endl;

    cetakHeader();

    for (int i = 0; i < n; i++) {
        cetakBaris(arr + i);
    }

    cetakGaris();
    cout << " >>> Total kereta: " << n << endl << endl;
}

// 2. Tambah data kereta baru
void tambahKereta(Kereta* arr, int& n) {
    if (n >= MAKS) {
        cout << endl << "  [!!] Data kereta sudah penuh! Maksimal " << MAKS << " kereta." << endl;
        return;
    }

    cout << endl << ">>> Tambah Data Kereta Baru <<<" << endl;

    Kereta* baru = arr + n;

    cout << "> Nomor Kereta  : "; cin >> baru->nomor_kereta;
    cin.ignore();
    cout << "> Nama Kereta   : "; getline(cin, baru->nama_kereta);
    cout << "> Kota Asal     : "; getline(cin, baru->asal);
    cout << "> Kota Tujuan   : "; getline(cin, baru->tujuan);
    cout << "> Jam Berangkat : "; cin >> baru->jam_berangkat;
    cout << "> Harga Tiket   : Rp "; cin >> baru->harga_tiket;
    cout << "> Kursi Tersedia: "; cin >> baru->kursi_tersedia;

    n++;
    cout << endl << "  [+] Kereta berhasil ditambahkan! Total: " << n << " kereta." << endl;
}

// 3. Linear Search cari berdasarkan rute (asal & tujuan)
void linearSearchRute(Kereta* arr, int n) {
    string asal, tujuan;
    cin.ignore();
    cout << endl << ">>> Cari Kereta Berdasarkan Rute <<<" << endl;
    cout << "> Kota Asal   : "; getline(cin, asal);
    cout << "> Kota Tujuan : "; getline(cin, tujuan);

    // cout << endl << "[Proses Linear Search]" << endl;
    // cout << string(55, '-') << endl;

    bool ketemu = false;
    for (int i = 0; i < n; i++) {  //loop dari indeks 0 sampai n-1
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) { //cek apakah input user valid
            // ditemukan!
            ketemu = true; //menandai
            // loop masih tetap berjalan karena bisa saja ada kereta lain di rute yang sama
        } else {
            // tidak ditemukan
            // akan lanjut ke iterasi selanjutnya
        }
    }

    // cout << string(55, '-') << endl;

    if (ketemu) { // menampilkan hasil
        cout << endl << "[Hasil] Kereta dengan rute " << asal << " -> " << tujuan << ":" << endl;
        cetakHeader();
        for (int i = 0; i < n; i++) {
            if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
                cetakBaris(arr + i);
            }
        }
        cetakGaris();
    } else {
        cout << endl << "  [!] Tidak ditemukan kereta untuk rute tersebut." << endl;
    }
}

// mengurutkan sesuai nomor (bubble sort) untuk persiapan Jump Search
void swapKereta(Kereta* a, Kereta* b) { 
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void sortByNomor(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nomor_kereta > (arr + j + 1)->nomor_kereta) {
                swapKereta(arr + j, arr + j + 1);
            }
        }
    }
}

// 4. Jump Search cari berdasarkan nomor kereta
void jumpSearchNomor(Kereta* arr, int n){
    string target;
    cout << endl << ">>> Cari Kereta Beredasakan Nomor (Jump Search) <<<" << endl;
    cout << "> Nomor Kereta : "; cin >> target;

    // memastikan data terurut dulu
    cout << endl << "  [^] Mengurutkan data by nomor kereta terlebih dahulu..." << endl;
    sortByNomor(arr, n);

    // Implementasi Jump Search
    int step = sqrt(n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->nomor_kereta < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << endl << "  [!!] Kereta tidak ditemukan." << endl;
            return;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->nomor_kereta == target) {
            cout << endl << "  [+] Kereta ditemukan!" << endl << endl;
            cetakHeader();
            cetakBaris(arr + i);
            cetakGaris();
            return;
        }
    }

    cout << endl << "  [!!] Kereta tidak ditemukan." << endl;
}

// 5. Merge sort urutkan berdasarkan nama kereta (A-Z)
void merge(Kereta* arr, int kiri, int tengah, int kanan){
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    // arrray temporer
    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];
    for (int i = 0; i < n1; i++) L[i] = *(arr + kiri + i);
    for (int j = 0; j < n2; j++) R[j] = *(arr + tengah + 1 + j);

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i].nama_kereta <= R[j].nama_kereta) {
            *(arr + k) = L[i++];
        } else {
            *(arr + k) = R[j++];
        }
        k++;
    }
    while (i < n1) *(arr + k++) = L[i++];
    while (j < n2) *(arr + k++) = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Kereta* arr, int kiri, int kanan){
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

void urutkanNama(Kereta* arr, int n){
    cout << endl << "  [^] Mengurutkan kereta berdasarkan nama (A-Z)..." << endl;
    mergeSort(arr, 0, n - 1);
    cout << "  [+] Selesai diurutkan!" << endl;
    tampilkanJadwal(arr, n);
}

// 6. Selection Sort urutkan berdasarkan harga tiket (termurah)
void selectionSortHarga(Kereta* arr, int n){
    cout << endl << "  [^] Mengurutkan kereta berdasarkan harga tiket (termurah ke termahal)..." << endl;
    for (int i = 0; i < n-1; i++){
        int min_indeks = i;
        for (int j = i+1; j < n; j++){
            if ((arr + j)->harga_tiket < (arr + min_indeks)->harga_tiket){
                min_indeks = j;
            }
        }
        if(min_indeks != i) {
            swapKereta(arr + i, arr + min_indeks);
        }
    }
    cout << "  [+] Selesai diurutkan!" << endl;
    tampilkanJadwal(arr, n);
}

// tampilkan daftar kereta singkat agar penumpang bisa milih nantinya
void tampilkanDaftarNomorKereta(Kereta* arr, int n) {
    cout << endl;
    cetakHeader();
    for (int i = 0; i < n; i++) cetakBaris(arr + i);
    cetakGaris();
}

// 1. Antrian Beli Tiket - enqueue penumpang ke queue
void antrianBeliTiket(Kereta* arr, int n, Queue* q) {
    if (isQueueFull(q)) {
        cout << endl << " [!!] Antrian sudah penuh! Tidak bisa menambah penumpang." << endl;
        return;
    }
    cout << endl << ">>> Antrian Beli Tiket <<<" << endl;
    tampilkanDaftarNomorKereta(arr,n);

    Penumpang p;
    cin.ignore();
    cout << "> Nama Penumpang : "; getline(cin, p.nama);
    cout << "> Nomor Kereta : "; cin >> p.nomor_kereta;

    // validasi nomor kereta
    Kereta* k = cariKeretaByNomor(arr, n, p.nomor_kereta);
    if (k == nullptr) {
        cout << endl << " [!!] Nomor kereta tidak ditemukan. Antrian dibatalkan." << endl;
        return;
    }
    if (k->kursi_tersedia == 0) {
        cout << endl << "  [!!] Maaf, kursi untuk kereta " << k->nama_kereta << " sudah habis." << endl;
        return;
    }

    enqueue(q, p);
    cout << endl << "  [+] " << p.nama << " berhasil masuk antrian ke-" << q->ukuran << " unutk kereta " << k->nama_kereta << "." << endl;

}

// 2. Proses Tiket — dequeue dari Queue, push ke Stack
void prosesTiket(Kereta* arr, int n, Queue* q, Stack* s) {
    if (isQueueEmpty(q)) {
        cout << endl << "  [!!] Antrian kosong, tidak ada yang diproses." << endl;
        return;
    }
    if (isStackFull(s)) {
        cout << endl << "  [!!] Riwayat transaksi penuh!" << endl;
        return;
    }
 
    Penumpang p;
    dequeue(q, &p); // ambil dari front antrian
 
    Kereta* k = cariKeretaByNomor(arr, n, p.nomor_kereta);
    if (k == nullptr) {
        cout << endl << "  [!!] Data kereta tidak ditemukan (data rusak)." << endl;
        return;
    }
 
    // mengurangi kursi tersedia
    (k)->kursi_tersedia--;
 
    // buat record tiket lalu push ke stack
    Tiket t;
    t.nama_penumpang = p.nama;
    t.nomor_kereta = k->nomor_kereta;
    t.nama_kereta = k->nama_kereta;
    t.asal = k->asal;
    t.tujuan  = k->tujuan;
    t.harga_tiket = k->harga_tiket;
    push(s, t);
 
    cout << endl << "  [+] Tiket berhasil diproses!" << endl;
    cout << "  ------------------------------------------" << endl;
    cout << "  Penumpang : " << t.nama_penumpang<< endl;
    cout << "  Kereta    : " << t.nama_kereta << endl;
    cout << "  Rute      : " << t.asal << " -> " << t.tujuan << endl;
    cout << "  Harga     : Rp " << t.harga_tiket  << endl;
    cout << "  ------------------------------------------" << endl;
    cout << "  Sisa antrian: " << q->ukuran << " penumpang." << endl;
}

// 3. Batalkan Transaksi (pop dari stack)
void batalkanTransaksi(Stack* s) {
    if (isStackEmpty(s)) {
        cout << endl << "  [!!] UNDERFLOW: Riwayat kosong, tidak ada transaksi untuk dibatalkan." << endl;
        return;
    }
    Tiket t;
    pop(s, &t);
    cout << endl << "  [-] Transaksi terakhir dibatalkan:" << endl;
    cout << "  ------------------------------------------" << endl;
    cout << "  Penumpang : " << t.nama_penumpang            << endl;
    cout << "  Kereta    : " << t.nama_kereta               << endl;
    cout << "  Rute      : " << t.asal << " -> " << t.tujuan << endl;
    cout << "  Harga     : Rp " << t.harga_tiket            << endl;
    cout << "  ------------------------------------------" << endl;
}

// / 4. Peek( menampilkan front antrian & top stack)
void peek(Queue* q, Stack* s) {
    cout << endl << ">>> PEEK <<<" << endl;
 
    cout << endl << "  [Antrian] Penumpang terdepan:" << endl;
    if (isQueueEmpty(q)) {
        cout << "  Antrian kosong." << endl;
    } else {
        Penumpang p;
        peekQueue(q, &p);
        cout << "  Nama      : " << p.nama          << endl;
        cout << "  No. KA    : " << p.nomor_kereta  << endl;
    }
 
    cout << endl << "  [Riwayat] Transaksi terakhir:" << endl;
    if (isStackEmpty(s)) {
        cout << "  Riwayat kosong." << endl;
    } else {
        Tiket t;
        peekStack(s, &t);
        cout << "  Penumpang : " << t.nama_penumpang              << endl;
        cout << "  Kereta    : " << t.nama_kereta                 << endl;
        cout << "  Rute      : " << t.asal << " -> " << t.tujuan  << endl;
        cout << "  Harga     : Rp " << t.harga_tiket              << endl;
    }
}

// 5. Tampilkan semua penumpang (hasil transaksi dari stack)
void tampilkanPenumpang(Stack* s) {
    cout << endl << ">>> Daftar Penumpang (Tiket Diproses) <<<" << endl;
    if (isStackEmpty(s)) {
        cout << "  Belum ada tiket yang diproses." << endl;
        return;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "| " << left << setw(4) << "No"
         << "| " << setw(19) << "Nama Penumpang"
         << "| " << setw(11) << "No. KA"
         << "| " << setw(26) << "Rute"
         << "| " << setw(11) << "Harga"
         << "|" << endl;
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
 
    // iterasi dari bawah (index 0) ke top dengan pointer aritmatika
    for (int i = 0; i <= s->top; i++) {
        Tiket* t = s->data + i; // <<- pointer aritmatika
        string rute = t->asal + " -> " + t->tujuan;
        cout << "| " << left << setw(4) << (i + 1)
             << "| " << setw(19) << t->nama_penumpang
             << "| " << setw(11) << t->nomor_kereta
             << "| " << setw(26) << rute
             << "| Rp " << right << setw(8) << t->harga_tiket
             << "|" << endl;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "  Total tiket diproses: " << s->top + 1 << endl;
}

// 6. Tampilkan semua antrian
void tampilkanAntrian(Queue* q) {
    cout << endl << ">>> Daftar Antrian Pembelian Tiket <<<" << endl;
    if (isQueueEmpty(q)) {
        cout << "  Antrian kosong." << endl;
        return;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "| " << left << setw(4) << "No"
         << "| " << setw(19) << "Nama Penumpang"
         << "| " << setw(11) << "No. KA"
         << "|" << endl;
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-') << "+" << endl;
 
    // iterasi dari front ke rear dengan pointer aritmatika (circular array)
    for (int i = 0; i < q->ukuran; i++) {
        int idx = (q->front + i) % MAKS;
        Penumpang* p = q->data + idx; // <- pointer aritmatika
        cout << "| " << left << setw(4) << (i + 1)
             << "| " << setw(19) << p->nama
             << "| " << setw(11) << p->nomor_kereta
             << "|" << endl;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "  Total antrian: " << q->ukuran << endl;
}

// 7. Tampilkan semua riwayat 
void tampilkanRiwayat(Stack* s) {
    cout << endl << ">>> Riwayat Transaksi (Terbaru di Atas) <<<" << endl;
    if (isStackEmpty(s)) {
        cout << "  Riwayat kosong." << endl;
        return;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "| " << left << setw(4) << "No"
         << "| " << setw(19) << "Nama Penumpang"
         << "| " << setw(11) << "No. KA"
         << "| " << setw(26) << "Rute"
         << "| " << setw(11) << "Harga"
         << "|" << endl;
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
 
    // iterasi dari top ke bawah (riwayat terbaru di atas) dengan pointer aritmatika
    int nomor = 1;
    for (int i = s->top; i >= 0; i--) {
        Tiket* t = s->data + i; // <- pointer aritmatika
        string rute = t->asal + " -> " + t->tujuan;
        cout << "| " << left << setw(4) << nomor++
             << "| " << setw(19) << t->nama_penumpang
             << "| " << setw(11) << t->nomor_kereta
             << "| " << setw(26) << rute
             << "| Rp " << right << setw(8) << t->harga_tiket
             << "|" << endl;
    }
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(12,'-')
         << "+" << string(27,'-') << "+" << string(12,'-') << "+" << endl;
    cout << "  Total riwayat: " << s->top + 1 << endl;
}
 

// >>> MENU PEMBELIAN TIKETTTTT 
void menuPembelianTiket(Kereta* arr, int n, Queue* q, Stack* s){
    int pilihan;
    do{
     cout << endl << endl;
        cout << ">>>=========================================<<<" << endl;
        cout << ">>>     MENU PEMBELIAN TIKET KERETA API     <<<" << endl;
        cout << ">>>=========================================<<<" << endl;
        cout << "    1. Antrian Beli Tiket"                       << endl;
        cout << "    2. Proses Tiket"                             << endl;
        cout << "    3. Batalkan Transaksi"                       << endl;
        cout << "    4. Peek Antrian & Riwayat"                   << endl;
        cout << "    5. Tampilkan Penumpang"                      << endl;
        cout << "    6. Tampilkan Antrian"                        << endl;
        cout << "    7. Tampilkan Riwayat"                        << endl;
        cout << "    0. Kembali ke Menu Utama"                    << endl;
        cout << ">>>=========================================<<<" << endl;
        cout << "> Pilihan: "; cin  >> pilihan;

        switch(pilihan) {
            case 1:
                antrianBeliTiket(arr, n, q);
                break;
            case 2:
                prosesTiket(arr, n, q, s);
                break;
            case 3:
                batalkanTransaksi(s);
                break;
            case 4:
                peek(q, s);
                break;
            case 5:
                tampilkanPenumpang(s);
                break;
            case 6:
                tampilkanAntrian(q);
                break;
            case 7:
                tampilkanRiwayat(s);
                break;
            case 0:
                cout << endl << "[^] Kembali ke menu utama.." << endl << endl;
                break;
            default:
                cout << endl << "[!!] Pilihan tidak valid. Silakan coba lagi." << endl;
                menuPembelianTiket(arr, n, q, s);
                break;
        }
    }while (pilihan != 0);
}

// MAIN
int main(){
    Kereta data[MAKS] = {
        {"KA-101", "Argo Bromo Anggrek", "Surabaya",   "Jakarta",     "09:10", 470000, 50},
        {"KA-102", "Argo Lawu",          "Yogyakarta", "Jakarta",     "14:30", 350000, 60},
        {"KA-235", "Airlangga",          "Surabaya",   "Pasar Senen", "10:25", 104000, 106},
        {"KA-312", "Taksaka",            "Bandung ",   "Jakata",      "12:00", 74000,  80},
        {"KA-408", "Gajayana",           "Jakarta",    "Gambir",      "15:45", 67000,  106},
        {"KA-520", "Sancaka",            "Surabaya",   "Bandung",     "08:00", 550000, 90},
        {"KA-239", "Mutiara Selatan",    "Bekasi",     "Bandung",     "13:20", 94000,  85},
        {"KA-744", "Serayu",             "Bekasi",     "Jakarta",     "17:30", 230000, 80},
    };

    int n = 8;
    int pilihan;
    Queue antrian;
    Stack riwayat;
    initQueue(&antrian);
    initStack(&riwayat);

    do{
        cout << endl << endl;
        cout << ">>>==============================================<<<" << endl;
        cout << ">>>    SISTEM MANAJEMEN KEBERANGKATAN KERETA     <<<" << endl;
        cout << ">>>==============================================<<<" << endl;
        cout << "    1. Tampilkan Semua Jadwal Kereta"                << endl;
        cout << "    2. Tambah Data Kereta Baru"                      << endl;
        cout << "    3. Cari Berdasarkan Rute (Linear Search)"        << endl;
        cout << "    4. Cari Berdasarkan Nomor (Jump Search)"         << endl;
        cout << "    5. Urutkan Berdasarkan Nama (Merge Sort)"        << endl;
        cout << "    6. Urutkan Berdasarkan Harga (Selection Sort)"   << endl;
        cout << "    7. Menu Pembelian Tiket"                         << endl;
        cout << "    0. Keluar"                                       << endl;
        cout << ">>>==============================================<<<" << endl;
        cout << "> Pilihan: "; cin  >> pilihan;

        switch(pilihan) {
            case 1:
                tampilkanJadwal(data, n);
                break;
            case 2:
                tambahKereta(data, n);
                break;
            case 3:
                linearSearchRute(data, n);
                break;
            case 4:
                jumpSearchNomor(data, n);
                break;
            case 5:
                urutkanNama(data, n);
                break;
            case 6:
                selectionSortHarga(data, n);
                break;
            case 7:
                menuPembelianTiket(data, n, &antrian, &riwayat);
                break;
            case 0:
                cout << endl << "[^] Program dihentikan." << endl << endl;
                break;
            default:
                cout << endl << "[!!] Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);
    return 0;
}
