#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int tgl;
    int bln;
    int th;
} Tanggal;

typedef struct {
    char noID[5];
    char nama[30];
    char jenis_kelamin; // 'L' atau 'P'
    Tanggal t;
} KTP;

typedef struct {
    KTP ktp;
    int jml;
} Data_KTP;

Data_KTP data_ktp;
Data_KTP *p;

void tambahData() {
    printf("Masukkan Nomor ID: ");
    scanf("%s", p->ktp.noID);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", p->ktp.nama);
    printf("Masukkan Jenis Kelamin (L/P): ");
    scanf(" %c", &p->ktp.jenis_kelamin);
    printf("Masukkan Tanggal Lahir (dd mm yyyy): ");
    scanf("%d %d %d", &p->ktp.t.tgl, &p->ktp.t.bln, &p->ktp.t.th);
    printf("Masukkan Jumlah: ");
    scanf("%d", &p->jml);

    printf("Data berhasil ditambahkan!\n");
}

void cariDataByTahun(int tahun) {
    if (p->ktp.t.th == tahun) {
        printf("No ID: %s\n", p->ktp.noID);
        printf("Nama: %s\n", p->ktp.nama);
        printf("Jenis Kelamin: %c\n", p->ktp.jenis_kelamin);
        printf("Tanggal Lahir: %d-%d-%d\n", p->ktp.t.tgl, p->ktp.t.bln, p->ktp.t.th);
        printf("Jumlah: %d\n", p->jml);
    }
}

void tampilkanDataByGender(char gender) {
    if (p->ktp.jenis_kelamin == gender) {
        printf("No ID: %s\n", p->ktp.noID);
        printf("Nama: %s\n", p->ktp.nama);
        printf("Jenis Kelamin: %c\n", p->ktp.jenis_kelamin);
        printf("Tanggal Lahir: %d-%d-%d\n", p->ktp.t.tgl, p->ktp.t.bln, p->ktp.t.th);
        printf("Jumlah: %d\n", p->jml);
    }
}

void editData() {
    printf("Masukkan Nomor ID yang akan diedit: ");
    char targetID[5];
    scanf("%s", targetID);

    if (strcmp(p->ktp.noID, targetID) == 0) {
        printf("Masukkan Nomor ID baru: ");
        scanf("%s", p->ktp.noID);
        printf("Masukkan Nama baru: ");
        scanf(" %[^\n]s", p->ktp.nama);
        printf("Masukkan Jenis Kelamin baru (L/P): ");
        scanf(" %c", &p->ktp.jenis_kelamin);
        printf("Masukkan Tanggal Lahir baru (dd mm yyyy): ");
        scanf("%d %d %d", &p->ktp.t.tgl, &p->ktp.t.bln, &p->ktp.t.th);
        printf("Masukkan Jumlah baru: ");
        scanf("%d", &p->jml);

        printf("Data berhasil diubah!\n");
    }
}

int main() {
    p = &data_ktp;

    int menu;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data berdasarkan Tahun Kelahiran\n");
        printf("3. Tampilkan Data berdasarkan Jenis Kelamin\n");
        printf("4. Edit Data\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                tambahData();
                break;
            case 2:
                {
                    int tahunCari;
                    printf("Masukkan tahun kelahiran untuk mencari data: ");
                    scanf("%d", &tahunCari);
                    cariDataByTahun(tahunCari);
                }
                break;
            case 3:
                {
                    char genderCari;
                    printf("Masukkan jenis kelamin (L/P) untuk menampilkan data: ");
                    scanf(" %c", &genderCari);
                    tampilkanDataByGender(genderCari);
                }
                break;
            case 4:
                editData();
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }

    } while (menu != 0);

    return 0;
}
