#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

void login_menu();
void main_menu();

vector<string> user_name;
vector<string> password;
vector<int> wrong_attempts;
vector<struct Menu> menus;

struct Menu
{
    string nama;
    int harga;
};

void clear_screen()
{
    system("clear");
}

void register_user()
{
    clear_screen();
    cout << "Register\n\n";
    string username, pass;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> pass;
    user_name.push_back(username);
    password.push_back(pass);
    wrong_attempts.push_back(0);
    cout << "\nRegister Berhasil\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

bool login_user()
{
    clear_screen();
    cout << "Login\n\n";
    string username, pass;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> pass;

    for (size_t i = 0; i < user_name.size(); ++i)
    {
        if (username == user_name[i])
        {
            if (pass == password[i])
            {
                clear_screen();
                cout << "\nLogin Berhasil\n";
                cout << "\nSelamat datang, " << username << " !!!\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Tekan Enter untuk melanjutkan...";
                cin.get();
                wrong_attempts[i] = 0;
                return true;
            }
            else
            {
                wrong_attempts[i]++;
                if (wrong_attempts[i] >= 3)
                {
                    clear_screen();
                    cout << "Anda telah mencoba login dengan password yang salah sebanyak 3 kali. Akun Anda diblokir.\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.get();
                    exit(0);
                }
                else
                {
                    clear_screen();
                    cout << "Password Salah\n";
                    cout << "Anda telah mencoba login dengan password yang salah sebanyak " << wrong_attempts[i] << " kali\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.get();
                    return false;
                }
            }
        }
    }

    clear_screen();
    cout << "Username tidak terdaftar\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
    return false;
}

void buat_menu()
{
    clear_screen();
    cout << "Buat Menu\n\n";
    Menu menu;
    cout << "Masukkan nama menu  : ";
    cin.ignore();
    getline(cin, menu.nama);
    cout << "Masukkan harga menu : ";
    cin >> menu.harga;
    menus.push_back(menu);
    cout << "\nMenu berhasil dibuat\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

void lihat_menu()
{
    clear_screen();
    cout << "Lihat Menu\n\n";
    if (menus.empty())
    {
        cout << "Tidak ada menu.\n";
    }
    else
    {
        for (size_t i = 0; i < menus.size(); ++i)
        {
            cout << i + 1 << ". " << menus[i].nama << " - Rp" << menus[i].harga << endl;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void update_menu()
{
    clear_screen();
    cout << "Update Menu\n\n";
    lihat_menu();
    if (!menus.empty())
    {
        size_t index;
        cout << "\nMasukkan nomor menu yang ingin diupdate: ";
        cin >> index;
        index--;
        if (index < menus.size())
        {
            cout << "Masukkan nama menu baru  : ";
            cin.ignore();
            getline(cin, menus[index].nama);
            cout << "Masukkan harga menu baru : ";
            cin >> menus[index].harga;
            cout << "\nMenu berhasil diupdate\n";
        }
        else
        {
            cout << "Menu tidak ditemukan.\n";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

void hapus_menu()
{
    clear_screen();
    cout << "Hapus Menu\n\n";
    lihat_menu();
    if (!menus.empty())
    {
        size_t index;
        cout << "\nMasukkan nomor menu yang ingin dihapus: ";
        cin >> index;
        index--;
        if (index < menus.size())
        {
            menus.erase(menus.begin() + index);
            cout << "\nMenu berhasil dihapus\n";
        }
        else
        {
            cout << "Menu tidak ditemukan.\n";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Tekan Enter untuk melanjutkan...";
    cin.get();
}

void main_menu()
{
    while (true)
    {
        clear_screen();
        cout << "Warung Makan Q`i-Ron-Jou\n\n";
        cout << "1. Buat Menu\n";
        cout << "2. Lihat Menu\n";
        cout << "3. Update Menu\n";
        cout << "4. Hapus Menu\n";
        cout << "5. Logout\n";
        cout << "6. Exit\n";
        cout << "\nMasukkan pilihan: ";
        string choice;
        cin >> choice;
        if (choice == "1")
        {
            buat_menu();
        }
        else if (choice == "2")
        {
            lihat_menu();
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
        else if (choice == "3")
        {
            update_menu();
        }
        else if (choice == "4")
        {
            hapus_menu();
        }
        else if (choice == "5")
        {
            login_menu();
        }
        else if (choice == "6")
        {
            clear_screen();
            cout << "Q`i-Ron-Jou\n";
            exit(0);
        }
        else
        {
            clear_screen();
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
    }
}

void login_menu()
{
    while (true)
    {
        clear_screen();
        cout << "Selamat datang di Warung Q`i-Ron-Jou\n\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "\nMasukkan pilihan: ";
        string choice;
        cin >> choice;
        if (choice == "1")
        {
            register_user();
        }
        else if (choice == "2")
        {
            if (login_user())
            {
                main_menu();
                break;
            }
        }
        else if (choice == "3")
        {
            clear_screen();
            cout << "Q`i-Ron-Jou\n";
            exit(0);
        }
        else
        {
            clear_screen();
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
        }
    }
}

int main()
{
    login_menu();
    return 0;
}
