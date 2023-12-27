#include <stdio.h>
#include <string.h>

// Mendefinisikan struct untuk data film
struct Film {
    int kodeFilm;
    char judul[100];
    int tahunRilis;
    char genre[100];
    float rating;
};

// Fungsi untuk menambahkan film ke dalam array
void tambahFilm(struct Film daftarFilm[], int *jumlahFilm) {
    printf("Masukkan data untuk film baru:\n");

    printf("Kode Film: ");
    scanf("%d", &daftarFilm[*jumlahFilm].kodeFilm);

    printf("Judul: ");
    scanf(" %[^\n]s", daftarFilm[*jumlahFilm].judul);

    printf("Tahun Rilis: ");
    scanf("%d", &daftarFilm[*jumlahFilm].tahunRilis);

    printf("Genre: ");
    scanf(" %[^\n]s", daftarFilm[*jumlahFilm].genre);

    printf("Rating: ");
    scanf("%f", &daftarFilm[*jumlahFilm].rating);

    (*jumlahFilm)++;
}

// Fungsi untuk mengedit film berdasarkan kode film
void editFilm(struct Film daftarFilm[], int jumlahFilm) {
    int kodeFilm;
    printf("Masukkan kode film yang ingin diedit: ");
    scanf("%d", &kodeFilm);

    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].kodeFilm == kodeFilm) {
            printf("Masukkan data yang baru untuk film dengan kode %d:\n", kodeFilm);

            printf("Judul: ");
            scanf(" %[^\n]s", daftarFilm[i].judul);

            printf("Tahun Rilis: ");
            scanf("%d", &daftarFilm[i].tahunRilis);

            printf("Genre: ");
            scanf(" %[^\n]s", daftarFilm[i].genre);

            printf("Rating: ");
            scanf("%f", &daftarFilm[i].rating);

            printf("Film dengan kode %d berhasil diedit.\n", kodeFilm);
            return;
        }
    }

    printf("Film dengan kode %d tidak ditemukan.\n", kodeFilm);
}

// Fungsi untuk menghapus film berdasarkan kode film
void hapusFilm(struct Film daftarFilm[], int *jumlahFilm) {
    int kodeFilm;
    printf("Masukkan kode film yang ingin dihapus: ");
    scanf("%d", &kodeFilm);

    for (int i = 0; i < *jumlahFilm; i++) {
        if (daftarFilm[i].kodeFilm == kodeFilm) {
            // Menggeser elemen array untuk menghapus film
            for (int j = i; j < *jumlahFilm - 1; j++) {
                daftarFilm[j] = daftarFilm[j + 1];
            }

            (*jumlahFilm)--;
            printf("Film dengan kode %d berhasil dihapus.\n", kodeFilm);
            return;
        }
    }

    printf("Film dengan kode %d tidak ditemukan.\n", kodeFilm);
}

// Fungsi untuk menampilkan data film
void tampilkanFilm(struct Film daftarFilm[], int jumlahFilm) {
    printf("\nDaftar Film:\n");
    for (int i = 0; i < jumlahFilm; i++) {
        printf("Film ke-%d:\n", i + 1);
        printf("Kode Film: %d\n", daftarFilm[i].kodeFilm);
        printf("Judul: %s\n", daftarFilm[i].judul);
        printf("Tahun Rilis: %d\n", daftarFilm[i].tahunRilis);
        printf("Genre: %s\n", daftarFilm[i].genre);
        printf("Rating: %.2f\n", daftarFilm[i].rating);
        printf("\n");
    }
}

int main() {
    struct Film daftarFilm[50]; // Misalnya, kita akan menyimpan data untuk 50 film
    int jumlahFilm = 0;
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Tambah Film\n");
        printf("2. Edit Film\n");
        printf("3. Hapus Film\n");
        printf("4. Tampilkan Film\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahFilm(daftarFilm, &jumlahFilm);
                break;
            case 2:
                editFilm(daftarFilm, jumlahFilm);
                break;
            case 3:
                hapusFilm(daftarFilm, &jumlahFilm);
                break;
            case 4:
                tampilkanFilm(daftarFilm, jumlahFilm);
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
