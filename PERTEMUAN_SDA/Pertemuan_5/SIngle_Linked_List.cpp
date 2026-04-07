#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
};

struct node{
    Mahasiswa mhs;
    node* next;
};

struct node*head=NULL;
struct node*last=NULL;

void addFirst(Node *&head, int databaru) {
    Node *nodeBaru = new Node;
    nodeBaru->data = databaru;
    nodeBaru->next = head;
    head = nodeBaru;
}

void addMiddle(Node *&head, int databaru, int posisi) {
    if (posisi <= 1) {
        addFirst(head, databaru);
        return;
    }
        Node *temp = head;
        int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr) {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" <<

        endl;

        return;
    } else {
        Node *nodeBaru = new Node;
        nodeBaru->data = databaru;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void addLast(Node *&head, int databaru) {
    Node *nodeBaru = new Node;
    nodeBaru->data = databaru;
    nodeBaru->next = nullptr;
    // jika linked list kosong
    if (head == nullptr){
        head = nodeBaru;
        return;
    }
    // jika tidak, traversal ke node terakhir
    Node *temp = head;
    while (temp->next != nullptr) {
    
    }
    temp->next = nodeBaru;
}