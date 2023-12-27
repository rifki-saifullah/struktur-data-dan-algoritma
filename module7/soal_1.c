#include <stdio.h>
#include <stdlib.h>

// Struktur simpul dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menampilkan isi dari linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    if (head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("head\n");
}

// Fungsi untuk menambah simpul baru di antara dua simpul tertentu
void insertBetween(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Simpul sebelumnya tidak boleh NULL\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Fungsi untuk menghapus simpul berdasarkan data
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // Cari simpul yang akan dihapus
    while (current->data != key) {
        prev = current;
        current = current->next;

        // Jika sudah kembali ke simpul awal
        if (current == *head)
            break;
    }

    // Jika simpul tidak ditemukan
    if (current == *head && current->data != key) {
        printf("Simpul dengan data %d tidak ditemukan\n", key);
        return;
    }

    // Jika simpul yang dihapus adalah simpul pertama
    if (current == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        prev->next = current->next;
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Fungsi untuk menghapus semua simpul dalam linked list
void deleteAllNodes(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    if (*head == NULL) {
        printf("List kosong\n");
        return;
    }

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Membuat linked list awal
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 50;
    head->next = head;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 40;
    second->next = head;
    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 30;
    third->next = head;
    second->next = third;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 20;
    fourth->next = head;
    third->next = fourth;

    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    fifth->data = 10;
    fifth->next = head;
    fourth->next = fifth;

    // a. Membaca data dari seluruh simpul dengan menggunakan perulangan
    printf("a. Membaca data dari seluruh simpul:\n");
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n\n");

    // b. Menambah simpul baru dengan data 5 di antara data 30 dan data 20
    printf("b. Menambah simpul baru dengan data 5 di antara data 30 dan data 20:\n");
    struct Node* node30 = head->next->next;
    insertBetween(node30, 5);
    displayList(head);
    printf("\n");

    // c. Menghapus simpul dengan data 20 tanpa merusak senarai
    printf("c. Menghapus simpul dengan data 20:\n");
    deleteNode(&head, 20);
    displayList(head);
    printf("\n");

    // d. Menghapus semua simpul menggunakan variabel bantu dengan perulangan
    printf("d. Menghapus semua simpul:\n");
    deleteAllNodes(&head);
    displayList(head);

    return 0;
}
