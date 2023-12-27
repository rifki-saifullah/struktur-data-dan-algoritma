#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[50];
    char prodi[30];
};

// Struktur data untuk simpul dalam antrian
struct Node {
    struct Mahasiswa data;
    struct Node* next;
};

// Fungsi untuk menambahkan mahasiswa ke dalam antrian
void enqueue(struct Node** front, struct Node** rear, struct Mahasiswa mhs) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = mhs;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Mahasiswa dengan NIM %s telah ditambahkan ke dalam antrian.\n", mhs.nim);
}

// Fungsi untuk menghapus mahasiswa dari antrian
void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;

    free(temp);
}

// Fungsi untuk menampilkan seluruh antrian
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("Antrian Registrasi UKDW:\n");
    while (front != NULL) {
        printf("NIM: %s, Nama: %s, Prodi: %s\n", front->data.nim, front->data.nama, front->data.prodi);
        front = front->next;
    }
}

// Fungsi untuk menampilkan urutan antrian berdasarkan NIM
void displayQueueOrder(struct Node* front, char targetNIM[]) {
    if (front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    int urutan = 1;
    while (front != NULL) {
        if (strcmp(front->data.nim, targetNIM) == 0) {
            printf("Mahasiswa dengan NIM %s berada pada urutan ke-%d dalam antrian.\n", targetNIM, urutan);
            return;
        }
        front = front->next;
        urutan++;
    }

    printf("Mahasiswa dengan NIM %s tidak ditemukan dalam antrian.\n", targetNIM);
}

// Fungsi untuk menampilkan urutan antrian berdasarkan prodi
void displayQueueByProdi(struct Node* front, char targetProdi[]) {
    if (front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    int urutan = 1;
    while (front != NULL) {
        if (strcmp(front->data.prodi, targetProdi) == 0) {
            printf("Mahasiswa dengan NIM %s (Prodi %s) berada pada urutan ke-%d dalam antrian.\n",
                   front->data.nim, targetProdi, urutan);
        }
        front = front->next;
        urutan++;
    }
}

// Fungsi untuk melakukan POP dengan melompati urutan
void popSkip(struct Node** front, int skipCount) {
    if (*front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }

    for (int i = 0; i < skipCount - 1; ++i) {
        if ((*front)->next == NULL) {
            printf("Jumlah elemen dalam antrian kurang dari jumlah yang ingin dilewati.\n");
            return;
        }
        *front = (*front)->next;
    }

    struct Node* temp = (*front)->next;
    (*front)->next = temp->next;

    free(temp);
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    // Menambahkan beberapa mahasiswa ke dalam antrian
    struct Mahasiswa mhs1 = {"123456789", "John Doe", "Teknik Informatika"};
    struct Mahasiswa mhs2 = {"234567890", "Jane Smith", "Sistem Informasi"};
    struct Mahasiswa mhs3 = {"345678901", "Bob Johnson", "Manajemen Informatika"};

    enqueue(&front, &rear, mhs1);
    enqueue(&front, &rear, mhs2);
    enqueue(&front, &rear, mhs3);

    // Menampilkan antrian
    displayQueue(front);

    // Menampilkan urutan antrian berdasarkan NIM
    char targetNIM[15];
    printf("Masukkan NIM untuk mengetahui urutan antrian: ");
    scanf("%s", targetNIM);
    displayQueueOrder(front, targetNIM);

    // Menampilkan urutan antrian berdasarkan prodi
    char targetProdi[30];
    printf("Masukkan Prodi untuk mengetahui urutan antrian: ");
    scanf("%s", targetProdi);
    displayQueueByProdi(front, targetProdi);

    // Melakukan POP dengan melompati urutan
    int skipCount;
    printf("Masukkan jumlah urutan yang ingin dilewati (POP): ");
    scanf("%d", &skipCount);
    popSkip(&front, skipCount);

    // Menampilkan antrian setelah POP
    displayQueue(front);

    return 0;
}
