#include <stdio.h>
#include <string.h>

// Mendefinisikan struct untuk data buku
struct Buku {
    int kodeBuku;
    char namaBuku[100];
    int tahunTerbit;
    char pengarang[100];
    float harga;
};

// Fungsi untuk menambahkan buku ke dalam array
void tambahBuku(struct Buku daftarBuku[], int *jumlahBuku) {
    printf("Masukkan data untuk buku baru:\n");

    printf("Kode Buku: ");
    scanf("%d", &daftarBuku[*jumlahBuku].kodeBuku);

    printf("Nama Buku: ");
    scanf(" %[^\n]s", daftarBuku[*jumlahBuku].namaBuku);

    printf("Tahun Terbit: ");
    scanf("%d", &daftarBuku[*jumlahBuku].tahunTerbit);

    printf("Pengarang: ");
    scanf(" %[^\n]s", daftarBuku[*jumlahBuku].pengarang);

    printf("Harga: ");
    scanf("%f", &daftarBuku[*jumlahBuku].harga);

    (*jumlahBuku)++;
}

// Fungsi untuk mengedit buku berdasarkan kode buku
void editBuku(struct Buku daftarBuku[], int jumlahBuku) {
    int kodeBuku;
    printf("Masukkan kode buku yang ingin diedit: ");
    scanf("%d", &kodeBuku);

    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].kodeBuku == kodeBuku) {
            printf("Masukkan data yang baru untuk buku dengan kode %d:\n", kodeBuku);

            printf("Nama Buku: ");
            scanf(" %[^\n]s", daftarBuku[i].namaBuku);

            printf("Tahun Terbit: ");
            scanf("%d", &daftarBuku[i].tahunTerbit);

            printf("Pengarang: ");
            scanf(" %[^\n]s", daftarBuku[i].pengarang);

            printf("Harga: ");
            scanf("%f", &daftarBuku[i].harga);

            printf("Buku dengan kode %d berhasil diedit.\n", kodeBuku);
            return;
        }
    }

    printf("Buku dengan kode %d tidak ditemukan.\n", kodeBuku);
}

// Fungsi untuk menghapus buku berdasarkan kode buku
void hapusBuku(struct Buku daftarBuku[], int *jumlahBuku) {
    int kodeBuku;
    printf("Masukkan kode buku yang ingin dihapus: ");
    scanf("%d", &kodeBuku);

    for (int i = 0; i < *jumlahBuku; i++) {
        if (daftarBuku[i].kodeBuku == kodeBuku) {
            // Menggeser elemen array untuk menghapus buku
            for (int j = i; j < *jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }

            (*jumlahBuku)--;
            printf("Buku dengan kode %d berhasil dihapus.\n", kodeBuku);
            return;
        }
    }

    printf("Buku dengan kode %d tidak ditemukan.\n", kodeBuku);
}

// Fungsi untuk menampilkan data buku
void tampilkanBuku(struct Buku daftarBuku[], int jumlahBuku) {
    printf("\nDaftar Buku:\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("Buku ke-%d:\n", i + 1);
        printf("Kode Buku: %d\n", daftarBuku[i].kodeBuku);
        printf("Nama Buku: %s\n", daftarBuku[i].namaBuku);
        printf("Tahun Terbit: %d\n", daftarBuku[i].tahunTerbit);
        printf("Pengarang: %s\n", daftarBuku[i].pengarang);
        printf("Harga: %.2f\n", daftarBuku[i].harga);
        printf("\n");
    }
}

int main() {
    struct Buku daftarBuku[50]; // Misalnya, kita akan menyimpan data untuk 50 buku
    int jumlahBuku = 0;
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Edit Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Tampilkan Buku\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBuku(daftarBuku, &jumlahBuku);
                break;
            case 2:
                editBuku(daftarBuku, jumlahBuku);
                break;
            case 3:
                hapusBuku(daftarBuku, &jumlahBuku);
                break;
            case 4:
                tampilkanBuku(daftarBuku, jumlahBuku);
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}