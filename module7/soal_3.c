#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data identitas KTP
struct KTP {
    char nama[50];
    char alamat[100];
    char noKTP[20];
    struct KTP* next;
};

// Fungsi untuk menambahkan data identitas KTP ke dalam linked list
void addEntry(struct KTP** head, struct KTP* newEntry) {
    struct KTP* current = *head;
    struct KTP* prev = NULL;

    // Temukan posisi untuk memasukkan data baru agar terurut berdasarkan nomor KTP
    while (current != NULL && strcmp(current->noKTP, newEntry->noKTP) < 0) {
        prev = current;
        current = current->next;
    }

    // Masukkan data baru ke dalam linked list
    if (prev == NULL) {
        newEntry->next = *head;
        *head = newEntry;
    } else {
        prev->next = newEntry;
        newEntry->next = current;
    }
}

// Fungsi untuk menghapus data identitas KTP berdasarkan nomor KTP
void deleteEntry(struct KTP** head, char* noKTP) {
    struct KTP* current = *head;
    struct KTP* prev = NULL;

    // Temukan data yang akan dihapus
    while (current != NULL && strcmp(current->noKTP, noKTP) != 0) {
        prev = current;
        current = current->next;
    }

    // Hapus data jika ditemukan
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Data dengan nomor KTP %s telah dihapus.\n", noKTP);
    } else {
        printf("Data dengan nomor KTP %s tidak ditemukan.\n", noKTP);
    }
}

// Fungsi untuk mencari data identitas KTP berdasarkan nomor KTP
struct KTP* searchEntry(struct KTP* head, char* noKTP) {
    struct KTP* current = head;

    // Temukan data yang dicari
    while (current != NULL && strcmp(current->noKTP, noKTP) != 0) {
        current = current->next;
    }

    // Kembalikan pointer ke data yang ditemukan atau NULL jika tidak ditemukan
    return current;
}

// Fungsi untuk mencetak semua data identitas KTP dalam linked list
void printAllEntries(struct KTP* head) {
    struct KTP* current = head;

    printf("Daftar Semua Data Identitas KTP:\n");
    while (current != NULL) {
        printf("Nama: %s\n", current->nama);
        printf("Alamat: %s\n", current->alamat);
        printf("Nomor KTP: %s\n", current->noKTP);
        printf("-------------------------\n");

        current = current->next;
    }
}

// Fungsi untuk mencetak data identitas KTP berdasarkan nomor KTP
void printEntry(struct KTP* entry) {
    if (entry != NULL) {
        printf("Data Identitas KTP:\n");
        printf("Nama: %s\n", entry->nama);
        printf("Alamat: %s\n", entry->alamat);
        printf("Nomor KTP: %s\n", entry->noKTP);
        printf("-------------------------\n");
    } else {
        printf("Data tidak ditemukan.\n");
    }
}

// Fungsi untuk membebaskan memori yang digunakan oleh linked list
void freeList(struct KTP* head) {
    struct KTP* current = head;
    struct KTP* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct KTP* head = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("a. Input entry KTP\n");
        printf("b. Delete entry KTP\n");
        printf("c. Searching entry KTP\n");
        printf("d. Cetak semua entry KTP\n");
        printf("e. Cetak entry KTP tertentu\n");
        printf("f. Keluar\n");

        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                // Input entry KTP
                struct KTP* newEntry = (struct KTP*)malloc(sizeof(struct KTP));
                printf("Nama: ");
                scanf("%s", newEntry->nama);
                printf("Alamat: ");
                scanf("%s", newEntry->alamat);
                printf("Nomor KTP: ");
                scanf("%s", newEntry->noKTP);

                addEntry(&head, newEntry);
                printf("Data berhasil ditambahkan.\n");
                break;
            }
            case 'b': {
                // Delete entry KTP
                char noKTP[20];
                printf("Masukkan nomor KTP yang akan dihapus: ");
                scanf("%s", noKTP);
                deleteEntry(&head, noKTP);
                break;
            }
            case 'c': {
                // Searching entry KTP
                char noKTP[20];
                printf("Masukkan nomor KTP yang akan dicari: ");
                scanf("%s", noKTP);
                struct KTP* result = searchEntry(head, noKTP);
                printEntry(result);
                break;
            }
            case 'd':
                // Cetak semua entry KTP
                printAllEntries(head);
                break;
            case 'e': {
                // Cetak entry KTP tertentu
                char noKTP[20];
                printf("Masukkan nomor KTP yang akan dicetak: ");
                scanf("%s", noKTP);
                struct KTP* result = searchEntry(head, noKTP);
                printEntry(result);
                break;
            }
            case 'f':
                // Keluar dari program
                freeList(head);
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
    }

    return 0;
}
