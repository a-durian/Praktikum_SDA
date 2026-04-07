#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
};

struct node {
    Mahasiswa mhs;
    node* next;
};

bool isEmpty(node* head){
    return head == nullptr;
}

void addfirst(node *&head,string nama, string nim){
    node* newNode = new node;
    newNode->mhs.nama = nama;
    newNode->mhs.nim = nim;
    newNode->next = head;
    head = newNode;
    cout << "Data berhasil ditambahkan!" << endl;
}

void addspecific(node *&head, int pos, string nama, string nim){
    node* newNode = new node;
    newNode->mhs.nama = nama;
    newNode->mhs.nim = nim;
    newNode->next = nullptr;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Data berhasil ditambahkan!" << endl;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        delete newNode; // Menghindari memory leak
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Data berhasil ditambahkan!" << endl;
};

void addlast(node *&head, string nama, string nim){
    node* newNode = new node;
    newNode->mhs.nama = nama;
    newNode->mhs.nim = nim;
    newNode->next = nullptr;

    if (isEmpty(head)) {
        head = newNode;
        cout << "Data berhasil ditambahkan!" << endl;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Data berhasil ditambahkan!" << endl;
}

void deletefirst(node *&head){
    if (isEmpty(head)) {
        cout << "List kosong!" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    cout << "Data berhasil dihapus!" << endl;
}

void deletespecific(node *&head, int pos){
    if (isEmpty(head)) {
        cout << "List kosong!" << endl;
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus!" << endl;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Data berhasil dihapus!" << endl;
}

void deletelast(node *&head){
    if (isEmpty(head)) {
        cout << "List kosong!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Data berhasil dihapus!" << endl;
        return;
    }

    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << "Data berhasil dihapus!" << endl;
}

void display(node* head) {
    if (isEmpty(head)) {
        cout << "List kosong!" << endl;
        return;
    }
    node* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". Nama: " << temp->mhs.nama << ", NIM: " << temp->mhs.nim << endl;
        temp = temp->next;
        index++;
    }
}

void editspecific(node *&head, int pos, string nama, string nim){
    if (isEmpty(head)) {
        cout << "List kosong!" << endl;
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    temp->mhs.nama = nama;
    temp->mhs.nim = nim;
    cout << "Data berhasil diubah!" << endl;
}

int main (){
    node* head = nullptr;
    int choice, pos;
    string nama, nim;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Data (First)" << endl;
        cout << "2. Tambah Data (Specific)" << endl;
        cout << "3. Tambah Data (Last)" << endl;
        cout << "4. Hapus Data (First)" << endl;
        cout << "5. Hapus Data (Specific)" << endl;
        cout << "6. Hapus Data (Last)" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Edit Data (Specific)" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                addfirst(head, nama, nim);
                break;
            case 2:
                cout << "Masukkan posisi: ";
                cin >> pos;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                addspecific(head, pos, nama, nim);
                break;
            case 3:
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                addlast(head, nama, nim);
                break;
            case 4:
                deletefirst(head);
                break;
            case 5:
                cout << "Masukkan posisi: ";
                cin >> pos;
                deletespecific(head, pos);
                break;
            case 6:
                deletelast(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                cout << "Masukkan posisi: ";
                cin >> pos;
                cout << "Masukkan nama baru: ";
                cin >> nama;
                cout << "Masukkan NIM baru: ";
                cin >> nim;
                editspecific(head, pos, nama, nim);
                break;
            case 9:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
      }
    }

    while (choice != 9);
return 0;

}