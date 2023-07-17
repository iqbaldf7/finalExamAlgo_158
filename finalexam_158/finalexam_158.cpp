#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string namaProduk;
    int jumlahProduk;
    string tipeProduk;
    Node* next;
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore(); // Membersihkan buffer input
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        Node* newNode = new Node();
        newNode->namaProduk = nama;
        newNode->jumlahProduk = jumlah;
        newNode->tipeProduk = tipe;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            int counter = 1;
            while (current != NULL) {
                cout << "Produk " << counter << ":" << endl;
                cout << "Nama Produk: " << current->namaProduk << endl;
                cout << "Jumlah Produk: " << current->jumlahProduk << endl;
                cout << "Tipe Produk: " << current->tipeProduk << endl;
                cout << endl;
                current = current->next;
                counter++;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 1;
            bool ditemukan = false;

            while (current != NULL) {
                if (current->namaProduk == targetNama) {
                    cout << "Nama Produk: " << current->namaProduk << endl;
                    cout << "Jumlah Produk: " << current->jumlahProduk << endl;
                    cout << "Tipe Produk: " << current->tipeProduk << endl;
                    cout << "Posisi: " << posisi << endl;
                    cout << endl;
                    ditemukan = true;
                }
                current = current->next;
                posisi++;
            }

            if (!ditemukan) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        bool swapped;
        Node* current;
        Node* last = NULL;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->jumlahProduk < current->next->jumlahProduk) {
                    // Swap data produk
                    string tempNama = current->namaProduk;
                    int tempJumlah = current->jumlahProduk;
                    string tempTipe = current->tipeProduk;

                    current->namaProduk = current->next->namaProduk;
                    current->jumlahProduk = current->next->jumlahProduk;
                    current->tipeProduk = current->next->tipeProduk;

                    current->next->namaProduk = tempNama;
                    current->next->jumlahProduk = tempJumlah;
                    current->next->tipeProduk = tempTipe;

                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }
};

int main() {
    ManajemenProduk manajemenProduk;
    int pilihan;

    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan Nama" << endl;
        cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();

            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();

            break;
        case 3:
            manajemenProduk.cariProdukByNama();

            break;

        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            cout << "produk berhasil diurutkan berdasarkan jumlah." << endl;

            break;

        case 5:
            cout << "Terima kasih program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}


//2.singlelinkedlist