#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack *stack) {
    return stack->top == stack->size - 1;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack penuh. Push gagal.\n");
    }
}

// Fungsi untuk menghapus elemen dari stack
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack kosong. Pop gagal.\n");
        return -1; // Mengembalikan nilai negatif jika stack kosong
    }
}

// Fungsi untuk mengevaluasi ekspresi postfix
int evaluatePostfix(char postfix[]) {
    Stack stack = createStack(20); // Ukuran stack disesuaikan dengan jumlah karakter dalam postfix
    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // Jika karakter adalah digit, push ke stack sebagai operand
            push(&stack, postfix[i] - '0');
        } else {
            // Jika karakter adalah operator, pop dua operand dari stack, hitung, dan push hasilnya
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Operator tidak valid: %c\n", postfix[i]);
                    return -1; // Mengembalikan nilai negatif jika operator tidak valid
            }

            push(&stack, result);
        }
    }

    // Hasil akhir akan berada di atas stack
    return pop(&stack);
}

int main() {
    char postfixExpression[50];

    // Input ekspresi postfix dari pengguna
    printf("Masukkan ekspresi postfix (tanpa spasi): ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);

    if (result != -1) {
        printf("Hasil evaluasi: %d\n", result);
    }

    return 0;
}
