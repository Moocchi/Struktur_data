#include "function.h"

const char *hostname = "127.0.0.1";
const char *user = "root";
const char *pass = "123";
const char *dbname = "Perpustakaan";
unsigned int port = 31235;
const char *unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(0);
    if (conn) {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
    }
    return conn;
}

void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.get();
}

void menu_pustakawan() {
    system("clear");
    cout << "Menu Pustakawan\n" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Lihat Buku" << endl;
    cout << "3. Update Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Keluar" << endl;
}

void menu_admin() {
    system("clear");
    cout << "Menu Admin\n" << endl;
    cout << "1. Tambah Buku" << endl;
    cout << "2. Lihat Buku" << endl;
    cout << "3. Update Buku" << endl;
    cout << "4. Hapus Buku" << endl;
    cout << "5. Tambah Pustakawan" << endl;
    cout << "6. Lihat Pustakawan" << endl;
    cout << "7. Update Pustakawan" << endl;
    cout << "8. Hapus Pustakawan" << endl;
    cout << "9. Tambah Admin" << endl;
    cout <<"10. Lihat Admin" << endl;
    cout <<"11. Update Admin" << endl;
    cout <<"12. Hapus Admin" << endl;
    cout <<"13. Keluar" << endl;
}

// NORMAL CRUD ALL CAN ACCESS

void tambah_buku() {
    system("clear");
    string judul_buku, pengarang, penerbit, tahun_terbit, jumlah_halaman, lokasi_rak;
    cout << "Judul Buku     : ";
    getline(cin, judul_buku);
    cout << "Pengarang      : ";
    getline(cin, pengarang);
    cout << "Penerbit       : ";
    getline(cin, penerbit);
    cout << "Tanggal Terbit : ";
    getline(cin, tahun_terbit);
    cout << "Jumlah halaman : ";
    getline(cin, jumlah_halaman);
    cout << "Lokasi rak     : ";
    getline(cin, lokasi_rak);

    MYSQL *conn = connect_db();
    if (conn) {
        stringstream query;
        query << "INSERT INTO book (judul_buku, pengarang, penerbit, tanggal_terbit, jumlah_halaman, lokasi_rak) VALUES ('"
        << judul_buku << "', '" << pengarang << "', '" << penerbit << "', '" << tahun_terbit << "', '" << jumlah_halaman << "', '" << lokasi_rak << "')";
        if (mysql_query(conn, query.str().c_str()) == 0) {
            cout << "\nBuku berhasil ditambahkan." << endl;
            pause();
        } else {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void lihat_buku() {
    MYSQL *conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM book") == 0) {
            MYSQL_RES *res = mysql_store_result(conn);
            if (res) {
                MYSQL_ROW row;
                if (mysql_num_rows(res) == 0) {
                    cout << "Tidak ada buku" << endl;
                } else {
                    while ((row = mysql_fetch_row(res))) {
                        cout << "ID             : " << row[0] << endl;
                        cout << "Judul buku     : " << row[1] << endl;
                        cout << "Pengarang      : " << row[2] << endl;
                        cout << "Penerbit       : " << row[3] << endl;
                        cout << "Tanggal Terbit : " << row[4] << endl;
                        cout << "Jumlah Halaman : " << row[5] << endl;
                        cout << "Lokasi Rak     : " << row[6] << endl;
                        cout << endl;
                    }
                }
                mysql_free_result(res);
            }
        } else {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void update_buku() {
    system("clear");
    lihat_buku();
    int id;
    string judul_buku, pengarang, penerbit, tahun_terbit, jumlah_halaman, lokasi_rak;
    cout << "ID Buku yang ingin diupdate : ";
    cin >> id;
    cin.ignore();
    cout << "\njudul Buku   : ";
    getline(cin, judul_buku);
    cout << "Pengarang      : ";
    getline(cin, pengarang);
    cout << "Penerbit       : ";
    getline(cin, penerbit);
    cout << "Tanggal Terbit : ";
    getline(cin, tahun_terbit);
    cout << "Jumlah halaman : ";
    getline(cin, jumlah_halaman);
    cout << "Lokasi rak     : ";
    getline(cin, lokasi_rak);

    MYSQL *conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE book SET judul_buku = '" << judul_buku << "', pengarang = '" << pengarang << "', penerbit = '" << penerbit << "', tanggal_terbit = '" << tahun_terbit << "', jumlah_halaman = '" << jumlah_halaman << "', lokasi_rak = '" << lokasi_rak << "' WHERE id = " << id;
        if (mysql_query(conn, query.str().c_str()) == 0) {
            cout << "\nBuku berhasil diupdate." << endl;
        } else {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        }
        pause();
        mysql_close(conn);
    }
}

void hapus_buku() {
    system("clear");
    lihat_buku();
    int id;
    cout << "ID Buku yang ingin dihapus : ";
    cin >> id;

    MYSQL *conn = connect_db();
    if (conn) {
        stringstream query;
        query << "DELETE FROM book WHERE id = " << id;
        if (mysql_query(conn, query.str().c_str()) == 0) {
            cout << "\nBuku berhasil dihapus." << endl;
        } else {
            cerr << "DELETE failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

// ADMIN CRUD ONLY ADMIN CAN ACCESS
void tambah_pustakawan()
{
    system("clear");
    string nama, tanggal_masuk, username, password;
    cout << "Nama Pustakawan : ";
    getline(cin, nama);
    cout << "Tanggal Masuk   :";
    getline(cin, tanggal_masuk);
    cout << "Username        : ";
    getline(cin, username);
    cout << "Password        : ";
    getline(cin, password);

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "INSERT INTO pustakawan (nama, tanggal_masuk, username, password) VALUES ('" 
        << nama << "', '" << tanggal_masuk << "', '" << username << "', '" << password << "')";
        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nPustakawan berhasil ditambahkan." << endl;
        }
        else
        {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void lihat_pustakawan()
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        if (mysql_query(conn, "SELECT * FROM pustakawan") == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (res)
            {
                MYSQL_ROW row;
                if (mysql_num_rows(res) == 0) {
                    cout << "Table kosong" << endl;
                } else {
                    while ((row = mysql_fetch_row(res)))
                    {
                        cout << "ID            : " << row[0] << endl;
                        cout << "Nama          : " << row[1] << endl;
                        cout << "Tanggal Masuk : " << row[2] << endl;
                        cout << "Username      : " << row[3] << endl;
                        cout << "Password      : " << row[4] << endl;
                        cout << endl;
                    }
                }
                mysql_free_result(res);
            }
        }
        else
        {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void update_pustakawan()
{
    system("clear");
    lihat_pustakawan();
    int id;
    string nama, tanggal_masuk, username, password;
    cout << "ID Pustakawan yang akan diupdate : ";
    cin >> id;
    cin.ignore();

    cout << "\nNama Baru        : ";
    getline(cin, nama);

    cout << "Tanggal Masuk Baru : ";
    getline(cin, tanggal_masuk);

    cout << "Username Baru      : ";
    getline(cin, username);

    cout << "Password Baru      : ";
    getline(cin, password);

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "UPDATE pustakawan SET nama='" << nama << "', tanggal_masuk='" << tanggal_masuk << "', username='" << username << "', password='" << password << "' WHERE id=" << id;

        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nData pustakawan berhasil diperbarui." << endl;
        }
        else
        {
            cerr << "Update failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void hapus_pustakawan()
{
    system("clear");
    lihat_pustakawan();
    int id;
    cout << "ID Pustakawan yang akan dihapus : ";
    cin >> id;

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "DELETE FROM pustakawan WHERE id=" << id;

        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nPustakawan berhasil dihapus." << endl;
        }
        else
        {
            cerr << "Delete failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

// ADMIN CONTROL

void tambah_admin()
{
    system("clear");
    string username, password;
    cout << "Username : ";
    getline(cin, username);
    cout << "Password : ";
    getline(cin, password);

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "INSERT INTO admin (username, password) VALUES ('" << username << "', '" << password << "')";
        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nAdmin berhasil ditambahkan." << endl;
        }
        else
        {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void lihat_admin()
{
    MYSQL *conn = connect_db();
    if (conn)
    {
        if (mysql_query(conn, "SELECT * FROM admin") == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (res)
            {
                MYSQL_ROW row;
                if (mysql_num_rows(res) == 0) {
                    cout << "Table kosong" << endl;
                } else {
                    while ((row = mysql_fetch_row(res)))
                    {
                        cout << "ID       : " << row[0] << endl;
                        cout << "Username : " << row[1] << endl;
                        cout << "Password : " << row[2] << endl;
                        cout << endl;
                    }
                }
                mysql_free_result(res);
            }
        }
        else
        {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

void update_admin()
{
    system("clear");
    lihat_admin();
    int id;
    string username, password;
    cout << "ID Admin yang akan diupdate: ";
    cin >> id;
    cin.ignore();

    if (id == 1) {
        cout << "\nAdmin 1 tidak dapat di. Silakan coba admin lain." << endl;
        return;
    }

    cout << "\nUsername Baru : ";
    getline(cin, username);

    cout << "Password Baru : ";
    getline(cin, password);

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "UPDATE admin SET username='" << username << "', password='" << password << "' WHERE id=" << id;

        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nData admin berhasil diperbarui." << endl;
        }
        else
        {
            cerr << "Update failed: " << mysql_error(conn) << endl;
        }

        mysql_close(conn);
    }
}

void hapus_admin()
{
    system("clear");
    lihat_admin();
    int id;
    cout << "ID Admin yang akan dihapus: ";
    cin >> id;
    cin.ignore();

    if (id == 1) {
        cout << "\nAdmin 1 tidak dapat dihapus. Silakan coba admin lain." << endl;
        return;
    }

    MYSQL *conn = connect_db();
    if (conn)
    {
        stringstream query;
        query << "DELETE FROM admin WHERE id=" << id;

        if (mysql_query(conn, query.str().c_str()) == 0)
        {
            cout << "\nAdmin berhasil dihapus." << endl;
        }
        else
        {
            cerr << "Delete failed: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
    }
}

// LOGIN LOGIC
void login_admin() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;
    bool success = false;
    string username, password;

    while (attempts < MAX_ATTEMPTS && !success) {
        cout << "Username : ";
        getline(cin, username);
        cout << "Password : ";
        getline(cin, password);
        system("clear");
        
        MYSQL *conn = connect_db();
        if (conn) {
            stringstream query;
            query << "SELECT id FROM admin WHERE username='" << username << "' AND password='" << password << "'";
            if (mysql_query(conn, query.str().c_str()) == 0) {
                MYSQL_RES *res = mysql_store_result(conn);
                if (res) {
                    if (mysql_num_rows(res) > 0) {
                        MYSQL_ROW row = mysql_fetch_row(res);
                        if (row) {
                            cout << "Login Berhasil! dengan ID: " << row[0] << endl;
                            success = true;
                            pause();
                        }
                    } else {
                        cout << "Login failed! Attempt " << (attempts + 1) << " of " << MAX_ATTEMPTS << endl;
                        attempts++;
                    }
                    mysql_free_result(res);
                } else {
                    cerr << "Failed to store result: " << mysql_error(conn) << endl;
                }
            } else {
                cerr << "Query failed: " << mysql_error(conn) << endl;
            }
            mysql_close(conn);
        } else {
            cerr << "Connection to database failed" << endl;
            exit(1);
        }

        if (!success) {
            pause();
            system("clear");
        }
    }

    if (!success) {
        cout << "Too many failed attempts. Exiting program." << endl;
        exit(1);
    }
}

void login_pustakawan() {
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;
    bool success = false;
    string username, password;

    while (attempts < MAX_ATTEMPTS && !success) {
        cout << "Username : ";
        getline(cin, username);
        cout << "Password : ";
        getline(cin, password);
        system("clear");

        MYSQL *conn = connect_db();
        if (conn) {
            stringstream query;
            query << "SELECT id, nama FROM pustakawan WHERE username='" << username << "' AND password='" << password << "'";
            if (mysql_query(conn, query.str().c_str()) == 0) {
                MYSQL_RES *res = mysql_store_result(conn);
                if (res) {
                    if (mysql_num_rows(res) > 0) {
                        MYSQL_ROW row = mysql_fetch_row(res);
                        if (row) {
                            cout << "Login Berhasil! Hallo : " << row[1] << endl;
                            success = true;
                            pause();
                        }
                    } else {
                        cout << "Login failed! Attempt " << (attempts + 1) << " of " << MAX_ATTEMPTS << endl;
                        attempts++;
                    }
                    mysql_free_result(res);
                } else {
                    cerr << "Failed to store result: " << mysql_error(conn) << endl;
                }
            } else {
                cerr << "Query failed: " << mysql_error(conn) << endl;
            }
            mysql_close(conn);
        } else {
            cerr << "Connection to database failed" << endl;
            exit(1);
        }

        if (!success) {
            pause();
            system("clear");
        }
    }

    if (!success) {
        cout << "Too many failed attempts. Exiting program." << endl;
        exit(1);
    }
}

void login_guest(){
    cout << "Login Sebagai Guest\n\n";
}