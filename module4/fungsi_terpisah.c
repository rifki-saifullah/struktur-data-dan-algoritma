#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definisi struktur untuk stack
typedef struct {
    int *data;
    int top;
    int size;
} Stack;

// Fungsi untuk membuat stack baru
Stack createStack(int size) {
    Stack stack;
    stack.data = (int *)malloc(size * sizeof(int));
    stack.top = -1;
    stack.size = size;
    return stack;
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
        printf("Push: %d\n", value);
    } else {
        printf("Stack penuh. Push gagal.\n");
    }
}

// Fungsi untuk menghapus elemen dari stack
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        int value = stack->data[stack->top--];
        printf("Pop: %d\n", value);
        return value;
    } else {
        printf("Stack kosong. Pop gagal.\n");
        return -1; // Mengembalikan nilai negatif jika stack kosong
    }
}

// Fungsi untuk menampilkan isi stack
void tampil(Stack *stack) {
    printf("Isi Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    int size, choice, value;
    
    printf("Masukkan ukuran stack: ");
    scanf("%d", &size);

    Stack stack = createStack(size);

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Tampilkan Stack\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nilai yang ingin di-push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                tampil(&stack);
                break;
            case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 0);

    free(stack.data); // Jangan lupa untuk membebaskan memori yang dialokasikan

    return 0;
}