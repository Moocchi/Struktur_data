import os

user_name = []
password = []
wrong_attempts = {}
menus = []

def register():
    os.system("clear")
    print("Register\n")
    user_name.append(input("Masukkan username: "))
    password.append(input("Masukkan password: "))
    print("\nRegister Berhasil")
    input("Tekan Enter untuk melanjutkan...")
    
def login():
    os.system("clear")
    print("Login\n")
    user = input("Masukkan username: ")
    passw = input("Masukkan password: ")
    
    if user in user_name:
        if passw == password[user_name.index(user)]:
            os.system("clear")
            print("\nLogin Berhasil")
            print(f"\nSelamat datang, {user} !!!")
            input("Tekan Enter untuk melanjutkan...")
            wrong_attempts[user] = 0
            return True
        else:
            wrong_attempts[user] = wrong_attempts.get(user, 0) + 1
            if wrong_attempts[user] >= 3:
                os.system("clear")
                print("Anda telah mencoba login dengan password yang salah sebanyak 3 kali. Akun Anda diblokir.")
                input("Tekan Enter untuk melanjutkan...")
                exit()
            else:
                os.system("clear")
                print("Password Salah")
                print(f"Anda telah mencoba login dengan password yang salah sebanyak {wrong_attempts[user]} kali")
                input("\nTekan Enter untuk melanjutkan...")
                return False
    else:
        os.system("clear")
        print("Username tidak terdaftar")
        input("\nTekan Enter untuk melanjutkan...")
        return False

def buat_menu():
    os.system("clear")
    print("Buat Menu\n")
    nama_menu = input("Masukkan nama menu  : ")
    harga_menu = int(input("Masukkan harga menu : "))
    menus.append({"nama": nama_menu, "harga": harga_menu})
    print("\nMenu berhasil dibuat")
    input("Tekan Enter untuk melanjutkan...")

def lihat_menu():
    os.system("clear")
    print("Lihat Menu\n")
    if not menus:
        print("Tidak ada menu.")
    else:
        for i, menu in enumerate(menus):
            print(f"{i + 1}. {menu['nama']} - Rp{menu['harga']:,d}")


def update_menu():
    os.system("clear")
    print("Update Menu\n")
    lihat_menu()
    if menus:
        index = int(input("\nMasukkan nomor menu yang ingin diupdate: ")) - 1
        if 0 <= index < len(menus):
            menus[index]['nama'] = input("\nMasukkan nama menu baru  : ")
            menus[index]['harga'] = int(input("Masukkan harga menu baru : "))
        else:
            print("Menu tidak ditemukan.")
    input("\nTekan Enter untuk melanjutkan...")

def hapus_menu():
    os.system("clear")
    print("Hapus Menu\n")
    lihat_menu()
    if menus:
        index = int(input("\nMasukkan nomor menu yang ingin dihapus: ")) - 1
        if 0 <= index < len(menus):
            menus.pop(index)
            print("\nMenu berhasil dihapus")
        else:
            print("Menu tidak ditemukan.")
    input("Tekan Enter untuk melanjutkan...")

def login_menu():
    while True:
        os.system("clear")
        print("Selamat datang di Warung Q`i-Ron-Jou\n")
        print("1. Register")
        print("2. Login")
        print("3. Exit")
        choice = input("\nMasukkan pilihan: ")
        if choice == '1':
            register()
        elif choice == '2':
            if login():
                main_menu()
                break
        elif choice == '3':
            os.system("clear")
            print("Q`i-Ron-Jou")
            exit()
        else:
            os.system("clear")
            print("Pilihan tidak valid. Silakan coba lagi.")

def main_menu():
    while True:
        os.system("clear")
        print("Warung Makan Q`i-Ron-Jou\n")
        print("1. Buat Menu")
        print("2. Lihat Menu")
        print("3. Update Menu")
        print("4. Hapus Menu")
        print("5. Logout")
        print("6. Exit")
        choice = input("\nMasukkan pilihan: ")
        if choice == '1':
            buat_menu()
        elif choice == '2':
            lihat_menu()
            input("\nTekan Enter untuk melanjutkan...")
        elif choice == '3':
            update_menu()
        elif choice == '4':
            hapus_menu()
        elif choice == '5':
            login_menu()
        elif choice == '6':
            os.system("clear")
            print("Q`i-Ron-Jou")
            exit()
        else:
            os.system("clear")
            print("Pilihan tidak valid. Silakan coba lagi.")

login_menu()