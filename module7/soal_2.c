#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk simpul dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambah simpul baru pada linked list
struct Node* tambahSimpul(struct Node* head, int nilai) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Error: Alokasi memori gagal.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = nilai;
    newNode->next = head; // Menghubungkan ke head untuk membuat linked list menjadi circular

    // Jika linked list masih kosong, maka simpul baru adalah head
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Menghubungkan simpul ke dirinya sendiri
    } else {
        // Jika linked list tidak kosong, maka mengupdate next dari simpul terakhir ke simpul baru
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Simpul dengan nilai %d ditambahkan.\n", nilai);
    return head;
}

// Fungsi untuk menampilkan semua data dalam linked list
void bacaSemua(struct Node* head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node* current = head;
    printf("Data dalam linked list:\n");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head); // Loop hingga kembali ke head

    printf("\n");
}

// Fungsi untuk menghapus simpul dengan nilai tertentu
struct Node* hapusSimpul(struct Node* head, int nilai) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    // Mencari simpul dengan nilai yang sesuai
    while (current->data != nilai) {
        if (current->next == head) {
            printf("Simpul dengan nilai %d tidak ditemukan.\n", nilai);
            return head;
        }
        prev = current;
        current = current->next;
    }

    // Jika simpul yang dihapus adalah head, mengupdate head
    if (current == head) {
        // Jika linked list hanya memiliki satu simpul
        if (current->next == head) {
            free(current);
            head = NULL;
        } else {
            // Jika linked list memiliki lebih dari satu simpul
            struct Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
            free(current);
        }
    } else {
        // Jika simpul yang dihapus bukan head
        prev->next = current->next;
        free(current);
    }

    printf("Simpul dengan nilai %d dihapus.\n", nilai);
    return head;
}

// Fungsi untuk menghapus semua simpul dalam linked list
struct Node* hapusSemua(struct Node* head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);

    printf("Semua simpul dalam linked list dihapus.\n");
    return NULL;
}

int main() {
    struct Node* head = NULL;
    int pilihan, nilai;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Simpul Baru\n");
        printf("2. Baca Semua Data\n");
        printf("3. Hapus Simpul dengan Nilai Tertentu\n");
        printf("4. Hapus Semua Simpul\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai untuk simpul baru: ");
                scanf("%d", &nilai);
                head = tambahSimpul(head, nilai);
                break;
            case 2:
                bacaSemua(head);
                break;
            case 3:
                printf("Masukkan nilai simpul yang akan dihapus: ");
                scanf("%d", &nilai);
                head = hapusSimpul(head, nilai);
                break;
            case 4:
                head = hapusSemua(head);
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }

    } while (pilihan != 0);

    return 0;
}
