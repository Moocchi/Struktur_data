#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "123";
const char* dbname = "cpp_crud";
unsigned int port = 31235;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(0);
    if (conn) {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn) {
            cout << "Connected to the database successfully." << endl;
        } else {
            cerr << "Connection failed: " << mysql_error(conn) << endl;
        }
    } else {
        cerr << "mysql_init failed" << endl;
    }
    return conn;
}

void create_user(const string& name, const string& nim, const string& asal_kampus, const string& jurusan, const string& fakultas) {
    MYSQL* conn = connect_db();
    if (conn) {
        string query = "INSERT INTO mahasiswa (name, nim, asal_kampus, jurusan, fakultas) VALUES ('" + name + "', '" + nim + "', '" + asal_kampus + "', '" + jurusan + "', '" + fakultas + "')";
        if (mysql_query(conn, query.c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "User successfully added." << endl;
        }
        mysql_close(conn);
    }
}

void get_users() {
    MYSQL* conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM mahasiswa")) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << ", Name: " << row[1] << ", NIM: " << row[2] << ", Asal Kampus: " << row[3] << ", Jurusan: " << row[4] << ", Fakultas: " << row[5] << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

void update_user(int user_id, const string& name, const string& nim, const string& asal_kampus, const string& jurusan, const string& fakultas) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE mahasiswa SET name = '" << name << "', nim = '" << nim << "', asal_kampus = '" << asal_kampus << "', jurusan = '" << jurusan << "', fakultas = '" << fakultas << "' WHERE id = " << user_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "User successfully updated." << endl;
        }
        mysql_close(conn);
    }
}

void delete_user(int user_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "DELETE FROM mahasiswa WHERE id = " << user_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "DELETE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "User successfully deleted." << endl;
        }
        mysql_close(conn);
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Show All Users\n";
        cout << "3. Update User\n";
        cout << "4. Delete User\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, nim, asal_kampus, jurusan, fakultas;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter NIM: ";
            getline(cin, nim);
            cout << "Enter Asal Kampus: ";
            getline(cin, asal_kampus);
            cout << "Enter Jurusan: ";
            getline(cin, jurusan);
            cout << "Enter Fakultas: ";
            getline(cin, fakultas);
            create_user(name, nim, asal_kampus, jurusan, fakultas);
        } else if (choice == 2) {
            get_users();
        } else if (choice == 3) {
            int user_id;
            string name, nim, asal_kampus, jurusan, fakultas;
            cout << "Enter user ID to update: ";
            cin >> user_id;
            cin.ignore();
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new NIM: ";
            getline(cin, nim);
            cout << "Enter new Asal Kampus: ";
            getline(cin, asal_kampus);
            cout << "Enter new Jurusan: ";
            getline(cin, jurusan);
            cout << "Enter new Fakultas: ";
            getline(cin, fakultas);
            update_user(user_id, name, nim, asal_kampus, jurusan, fakultas);
        } else if (choice == 4) {
            int user_id;
            cout << "Enter user ID to delete: ";
            cin >> user_id;
            delete_user(user_id);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}