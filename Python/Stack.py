import os
import getpass

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return "Tumpukan kosong"

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            return "Tumpukan kosong"

    def is_empty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)


def display_menu():
    os.system("clear")
    print("Menu:\n")
    print("1. Tambah buku ke tumpukan")
    print("2. Ambil buku dari tumpukan")
    print("3. Tampilkan ukuran tumpukan")
    print("4. Tampilkan buku paling atas")
    print("5. Periksa apakah tumpukan kosong")
    print("6. Q`i-Ron-Jou\n")


tumpukan_buku = Stack()

while True:
    display_menu()
    choice = input("Pilih menu (1-6): ")

    if choice == "1":
        os.system("clear")
        buku = input("Masukkan nama buku: ")
        tumpukan_buku.push(buku)
        os.system('clear')
        print("Buku", buku, "ditambahkan ke tumpukan.")
        getpass.getpass("Press Enter to continue...")
    elif choice == "2":
        os.system("clear")
        buku = tumpukan_buku.pop()
        print("Buku", buku, "diambil dari tumpukan.")
        getpass.getpass("Press Enter to continue...")
    elif choice == "3":
        os.system("clear")
        print("Ukuran tumpukan buku:", tumpukan_buku.size())
        getpass.getpass("Press Enter to continue...")
    elif choice == "4":
        os.system("clear")
        print("Buku paling atas:", tumpukan_buku.peek())
        getpass.getpass("Press Enter to continue...")
    elif choice == "5":
        os.system("clear")
        if tumpukan_buku.is_empty():
            print("Tumpukan buku kosong.")
        else:
            print("Tumpukan buku tidak kosong.")
        getpass.getpass("Press Enter to continue...")
    elif choice == "6":
        os.system("clear")
        print("Terima kasih!")
        break
    else:
        os.system("clear")
        print("Pilihan tidak valid. Silakan pilih menu yang sesuai.")
        getpass.getpass("Press Enter to continue...")
