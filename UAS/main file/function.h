#ifndef FUNCTION_H
#define FUNCTION_H

#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

MYSQL *connect_db();
void pause();
void menu_pustakawan();
void menu_admin();

// CRUD ALL CAN ACCESS
void tambah_buku();
void lihat_buku();
void hapus_buku();
void update_buku();

// CRUD ADMIN ONLY
void tambah_pustakawan();
void lihat_pustakawan();
void hapus_pustakawan();
void update_pustakawan();
void tambah_admin();
void lihat_admin();
void hapus_admin();
void update_admin();

//LOGIN LOGIC
void login_admin();
void login_pustakawan();
void login_guest();

#endif
