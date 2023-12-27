#include <stdio.h>
#include <string.h>

// Mendefinisikan struct untuk data pemain bola
struct PemainBola {
    int nomorPunggung;
    char nama[100];
    int umur;
    char posisi[100];
    float rating;
};

// Fungsi untuk menambahkan pemain bola ke dalam array
void tambahPemainBola(struct PemainBola daftarPemain[], int *jumlahPemain) {
    printf("Masukkan data untuk pemain bola baru:\n");

    printf("Nomor Punggung: ");
    scanf("%d", &daftarPemain[*jumlahPemain].nomorPunggung);

    printf("Nama: ");
    scanf(" %[^\n]s", daftarPemain[*jumlahPemain].nama);

    printf("Umur: ");
    scanf("%d", &daftarPemain[*jumlahPemain].umur);

    printf("Posisi: ");
    scanf(" %[^\n]s", daftarPemain[*jumlahPemain].posisi);

    printf("Rating: ");
    scanf("%f", &daftarPemain[*jumlahPemain].rating);

    (*jumlahPemain)++;
}

// Fungsi untuk mengedit pemain bola berdasarkan nomor punggung
void editPemainBola(struct PemainBola daftarPemain[], int jumlahPemain) {
    int nomorPunggung;
    printf("Masukkan nomor punggung pemain bola yang ingin diedit: ");
    scanf("%d", &nomorPunggung);

    for (int i = 0; i < jumlahPemain; i++) {
        if (daftarPemain[i].nomorPunggung == nomorPunggung) {
            printf("Masukkan data yang baru untuk pemain bola dengan nomor punggung %d:\n", nomorPunggung);

            printf("Nama: ");
            scanf(" %[^\n]s", daftarPemain[i].nama);

            printf("Umur: ");
            scanf("%d", &daftarPemain[i].umur);

            printf("Posisi: ");
            scanf(" %[^\n]s", daftarPemain[i].posisi);

            printf("Rating: ");
            scanf("%f", &daftarPemain[i].rating);

            printf("Pemain bola dengan nomor punggung %d berhasil diedit.\n", nomorPunggung);
            return;
        }
    }

    printf("Pemain bola dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}

// Fungsi untuk menghapus pemain bola berdasarkan nomor punggung
void hapusPemainBola(struct PemainBola daftarPemain[], int *jumlahPemain) {
    int nomorPunggung;
    printf("Masukkan nomor punggung pemain bola yang ingin dihapus: ");
    scanf("%d", &nomorPunggung);

    for (int i = 0; i < *jumlahPemain; i++) {
        if (daftarPemain[i].nomorPunggung == nomorPunggung) {
            // Menggeser elemen array untuk menghapus pemain bola
            for (int j = i; j < *jumlahPemain - 1; j++) {
                daftarPemain[j] = daftarPemain[j + 1];
            }

            (*jumlahPemain)--;
            printf("Pemain bola dengan nomor punggung %d berhasil dihapus.\n", nomorPunggung);
            return;
        }
    }

    printf("Pemain bola dengan nomor punggung %d tidak ditemukan.\n", nomorPunggung);
}

// Fungsi untuk menampilkan data pemain bola
void tampilkanPemainBola(struct PemainBola daftarPemain[], int jumlahPemain) {
    printf("\nDaftar Pemain Bola:\n");
    for (int i = 0; i < jumlahPemain; i++) {
        printf("Pemain Bola ke-%d:\n", i + 1);
        printf("Nomor Punggung: %d\n", daftarPemain[i].nomorPunggung);
        printf("Nama: %s\n", daftarPemain[i].nama);
        printf("Umur: %d\n", daftarPemain[i].umur);
        printf("Posisi: %s\n", daftarPemain[i].posisi);
        printf("Rating: %.2f\n", daftarPemain[i].rating);
        printf("\n");
    }
}

int main() {
    struct PemainBola daftarPemain[50]; // Misalnya, kita akan menyimpan data untuk 50 pemain bola
    int jumlahPemain = 0;
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Tambah Pemain Bola\n");
        printf("2. Edit Pemain Bola\n");
        printf("3. Hapus Pemain Bola\n");
        printf("4. Tampilkan Pemain Bola\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahPemainBola(daftarPemain, &jumlahPemain);
                break;
            case 2:
                editPemainBola(daftarPemain, jumlahPemain);
                break;
            case 3:
                hapusPemainBola(daftarPemain, &jumlahPemain);
                break;
            case 4:
                tampilkanPemainBola(daftarPemain, jumlahPemain);
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
