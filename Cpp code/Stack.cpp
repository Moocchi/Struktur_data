#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Stack
{
private:
    vector<string> items;

public:
    void push(const string &item)
    {
        items.push_back(item);
    }

    string pop()
    {
        if (!is_empty())
        {
            string item = items.back();
            items.pop_back();
            return item;
        }
        else
        {
            return "Tumpukan kosong";
        }
    }

    string peek() const
    {
        if (!is_empty())
        {
            return items.back();
        }
        else
        {
            return "Tumpukan kosong";
        }
    }

    bool is_empty() const
    {
        return items.empty();
    }

    size_t size() const
    {
        return items.size();
    }
};

void display_menu()
{
    system("clear");
    cout << "Menu:\n\n";
    cout << "1. Tambah buku ke tumpukan\n";
    cout << "2. Ambil buku dari tumpukan\n";
    cout << "3. Tampilkan ukuran tumpukan\n";
    cout << "4. Tampilkan buku paling atas\n";
    cout << "5. Periksa apakah tumpukan kosong\n";
    cout << "6. Q`i-Ron-Jou\n\n";
}

int main()
{
    Stack tumpukan_buku;
    string choice;

    while (true)
    {
        display_menu();
        cout << "Pilih menu (1-6): ";
        cin >> choice;
        cin.ignore();

        if (choice == "1")
        {
            system("clear");
            string buku;
            cout << "Masukkan nama buku: ";
            getline(cin, buku);
            tumpukan_buku.push(buku);
            system("clear");
            cout << "Buku " << buku << " ditambahkan ke tumpukan.\n";
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == "2")
        {
            system("clear");
            string buku = tumpukan_buku.pop();
            cout << "Buku " << buku << " diambil dari tumpukan.\n";
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == "3")
        {
            system("clear");
            cout << "Ukuran tumpukan buku: " << tumpukan_buku.size() << "\n";
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == "4")
        {
            system("clear");
            cout << "Buku paling atas: " << tumpukan_buku.peek() << "\n";
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == "5")
        {
            system("clear");
            if (tumpukan_buku.is_empty())
            {
                cout << "Tumpukan buku kosong.\n";
            }
            else
            {
                cout << "Tumpukan buku tidak kosong.\n";
            }
            printf("Press Enter to continue...");
            getchar();
        }
        else if (choice == "6")
        {
            system("clear");
            cout << "Q`i-Ron-Jou!\n";
            break;
        }
        else
        {
            system("clear");
            cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai.\n";
            printf("Press Enter to continue...");
            getchar();
        }
    }

    return 0;
}
