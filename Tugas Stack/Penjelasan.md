# Implementasi Stack dalam C++

Program ini mengimplementasikan struktur data stack dan antarmuka berbasis menu untuk berinteraksi dengannya. Berikut adalah penjelasan dari setiap fungsi beserta kodenya.

## Kelas Stack
```cpp
class Stack
{
private:
    vector<string> items;
```
Pada bagian ini, kita mendeklarasikan sebuah variabel anggota items yang bertipe `vector<string>`.

Variabel anggota items ini bertujuan untuk menyimpan elemen-elemen yang ada dalam tumpukan `(stack)`. Dalam konteks ini, `vector<string>` digunakan sebagai struktur data yang akan menyimpan elemen-elemen dalam tumpukan.

### Fungsi `push`

Fungsi `push` menambahkan item ke bagian atas stack.

<<<<<<< HEAD

=======
>>>>>>> f259f9336f056939ab30b9e2bc920f680615b0a3
```cpp
void push(const string &item)
{
    items.push_back(item);
}
```

### Fungsi `pop`

Fungsi pop menghapus dan mengembalikan item dari bagian atas stack. Jika stack kosong, fungsi ini mengembalikan "Tumpukan kosong".

```cpp
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
```
Fungsi pop ini digunakan untuk menghapus elemen dari bagian atas stack. Pertama, fungsi ini memeriksa apakah stack kosong atau tidak dengan memanggil fungsi is_empty(). Jika stack tidak kosong, fungsi ini akan mengambil elemen terakhir dari vektor items dan menghapusnya dari vektor dengan menggunakan fungsi pop_back(). Kemudian, fungsi ini mengembalikan elemen yang baru saja dihapus.

Namun, jika stack kosong (yaitu, jika is_empty() mengembalikan true), fungsi ini akan mengembalikan string "Tumpukan kosong". Ini berarti bahwa tidak ada elemen yang bisa dihapus dari stack karena stack sudah kosong.

### Fungsi `Peek`
```cpp
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
```
Fungsi`peek` ini digunakan untuk melihat elemen teratas dari stack tanpa menghapusnya. Pertama, fungsi ini memeriksa apakah stack kosong atau tidak dengan memanggil fungsi `is_empty()`. Jika stack tidak kosong, fungsi ini akan mengambil elemen terakhir dari vektor `items` dan mengembalikannya.
    
Namun, jika stack kosong (yaitu, jika `is_empty()` mengembalikan `true`), fungsi ini akan mengembalikan string "Tumpukan kosong". Ini berarti bahwa tidak ada elemen yang bisa dilihat di stack karena stack sudah kosong

### Fungsi `is_empty`
```cpp
bool is_empty() const
{
    return items.empty();
}
```

Fungsi `is_empty` ini digunakan untuk memeriksa apakah stack kosong atau tidak. Fungsi ini mengembalikan hasil dari fungsi `empty()` yang dipanggil pada vektor `items`. Jika items`` kosong (yaitu, tidak ada elemen di dalamnya), fungsi empty() akan mengembalikan `true` dan begitu juga dengan fungsi `is_empty()`

```cpp
size_t size() const
{
    return items.size();
}
```
Fungsi `size` ini digunakan untuk mendapatkan jumlah elemen yang ada di dalam stack. Fungsi ini mengembalikan hasil dari fungsi `size()` yang dipanggil pada vektor `items`, yang mengembalikan jumlah elemen di dalam vektor.

### Fungsi `display_menu`
```cpp
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
```

Fungsi `display_menu` ini digunakan untuk menampilkan menu ke pengguna. Pertama, fungsi ini membersihkan layar dengan perintah `system("clear")`. Kemudian, fungsi ini menampilkan menu dengan enam opsi yang dapat dipilih oleh pengguna. Opsi-opsi tersebut adalah:

- Tambah buku ke tumpukan
- Ambil buku dari tumpukan
- Tampilkan ukuran tumpukan
- Tampilkan buku paling atas
- Periksa apakah tumpukan kosong
- Q`i-Ron-Jou (keluar dari program)

# int main

### `Loop utama`
```cpp
while (true)
{
    display_menu();
    cout << "Pilih menu (1-6): ";
    cin >> choice;
    cin.ignore();
```
Loop utama program menampilkan menu menggunakan `display_menu`, meminta pengguna untuk memilih opsi, dan membaca input pengguna.

## Opsi 1: Tambah Buku ke Tumpukan
```cpp
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
```
Jika pengguna memilih opsi 1, program akan meminta nama buku, menambahkannya ke tumpukan menggunakan `push`, dan menampilkan pesan konfirmasi.

## Opsi 2: Ambil Buku dari Tumpukan
```cpp
else if (choice == "2")
{
    system("clear");
    string buku = tumpukan_buku.pop();
    cout << "Buku " << buku << " diambil dari tumpukan.\n";
    printf("Press Enter to continue...");
    getchar();
}

```
Jika pengguna memilih opsi 2, program akan mengambil buku dari tumpukan menggunakan `pop` dan menampilkan buku yang diambil.

## Opsi 3: Tampilkan Ukuran Tumpukan
```cpp
else if (choice == "3")
{
    system("clear");
    cout << "Ukuran tumpukan buku: " << tumpukan_buku.size() << "\n";
    printf("Press Enter to continue...");
    getchar();
}

```
Jika pengguna memilih opsi 3, program akan menampilkan ukuran tumpukan menggunakan `size`.

## Opsi 4: Tampilkan Buku Paling Atas
```cpp
else if (choice == "4")
{
    system("clear");
    cout << "Buku paling atas: " << tumpukan_buku.peek() << "\n";
    printf("Press Enter to continue...");
    getchar();
}

```
Jika pengguna memilih opsi 4, program akan menampilkan buku paling atas di tumpukan menggunakan `peek`.

## Opsi 5: Periksa Apakah Tumpukan Kosong
```cpp
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

```
Jika pengguna memilih opsi 5, program akan memeriksa apakah tumpukan kosong menggunakan `is_empty` dan menampilkan hasilnya.

## Opsi 6: Keluar dari Program
```cpp
else if (choice == "6")
{
    system("clear");
    cout << "Q`i-Ron-Jou!\n";
    break;
}
```
Jika pengguna memilih opsi 6, program akan menampilkan pesan selamat tinggal dan keluar dari loop utama.

# Penanganan Pilihan Tidak Valid
```cpp
else
{
    system("clear");
    cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai.\n";
    printf("Press Enter to continue...");
    getchar();
}
```
Jika pengguna memasukkan pilihan yang tidak valid, program akan menampilkan pesan kesalahan dan meminta pengguna untuk mencoba lagi.

<div align="center">

<h1 style="color:#e2a754;">Terima Kasih !!!</h1>

</div>

<div align="center">

![Link to GIF](/%20Gif%20and%20Image/lolk.gif)

</div>
