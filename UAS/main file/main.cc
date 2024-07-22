#include "function.h"

void handle_pustakawan_menu() {
    string pilihan;
    bool exit = false;

    while (!exit) {
        system("clear");
        menu_pustakawan();

        cout << "\nMasukkan Pilihan : ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            tambah_buku();
        } else if (pilihan == "2") {
            system("clear");
            lihat_buku();
            pause();
        } else if (pilihan == "3") {
            update_buku();
        } else if (pilihan == "4") {
            hapus_buku();
            pause();
        } else if (pilihan == "5") {
            system("clear");
            cout << "Terima kasih telah menggunakan aplikasi ini. Salam Q`i-Ron-Jou" << endl;
            pause();
            exit = true;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}

void handle_admin_menu() {
    string pilihan;
    bool exit = false;

    while (!exit) {
        system("clear");
        menu_admin();

        cout << "\nMasukkan Pilihan : ";
        getline(cin, pilihan);

        if (pilihan == "1") {
            tambah_buku();
        } else if (pilihan == "2") {
            system("clear");
            lihat_buku();
            pause();
        } else if (pilihan == "3") {
            update_buku();
        } else if (pilihan == "4") {
            hapus_buku();
            pause();
        } else if (pilihan == "5") {
            tambah_pustakawan();
            pause();
        } else if (pilihan == "6") {
            system("clear");
            lihat_pustakawan();
            pause();
        } else if (pilihan == "7") {
            update_pustakawan();
            pause();
        } else if (pilihan == "8") {
            hapus_pustakawan();
            pause();
        } else if (pilihan == "9") {
            tambah_admin();
            pause();
        } else if (pilihan == "10") {
            system("clear");
            lihat_admin();
            pause();
        } else if (pilihan == "11") {
            update_admin();
            pause();
        } else if (pilihan == "12") {
            hapus_admin();
            pause();
        } else if (pilihan == "13") {
            system("clear");
            cout << "Terima kasih telah menggunakan aplikasi ini. Salam Q`i-Ron-Jou" << endl;
            pause();
            exit = true; 
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
}

int main() {
    string login;
    bool running = true;
    while (running) {
        system("clear");
        cout << "Selamat Datang\n" << endl;
        cout << "Pilih Login Sebagai.\n" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pustakawan" << endl;
        cout << "3. Guest" << endl;
        cout << "4. Keluar" << endl;
        cout << "\nMasukkan Pilihan : ";
        getline(cin, login);

        if (login == "1") {
            system("clear");
            login_admin();
            handle_admin_menu();
        } else if (login == "2") {
            system("clear");
            login_pustakawan();
            handle_pustakawan_menu();
        } else if (login == "3") {
            system("clear");
            login_guest();
            lihat_buku();
            pause();
        } else if (login == "4") {
            system("clear");
            cout << "Terima kasih telah menggunakan aplikasi ini. Salam Q`i-Ron-Jou" << endl;
            running = false;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
