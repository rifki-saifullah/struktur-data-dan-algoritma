#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definisi struktur untuk stack
typedef struct {
    int top;
    char items[50];
} CharStack;

// Fungsi untuk menambahkan karakter ke dalam stack
void charPush(CharStack *s, char value) {
    if (s->top < 50 - 1) {
        s->items[++(s->top)] = value;
    } else {
        printf("CharStack overflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Fungsi untuk menghapus karakter dari stack
char charPop(CharStack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("CharStack underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Fungsi untuk menentukan prioritas operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Fungsi untuk mengonversi infix menjadi postfix
void infixToPostfix(char infix[], char postfix[]) {
    CharStack operatorStack;
    operatorStack.top = -1;

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            charPush(&operatorStack, infix[i++]);
        } else if (infix[i] == ')') {
            while (operatorStack.top != -1 && operatorStack.items[operatorStack.top] != '(') {
                postfix[j++] = charPop(&operatorStack);
            }

            if (operatorStack.top != -1 && operatorStack.items[operatorStack.top] == '(') {
                charPop(&operatorStack);
            } else {
                printf("Error: Unmatched parentheses\n");
                exit(EXIT_FAILURE);
            }

            i++;
        } else {
            while (operatorStack.top != -1 && precedence(operatorStack.items[operatorStack.top]) >= precedence(infix[i])) {
                postfix[j++] = charPop(&operatorStack);
            }

            charPush(&operatorStack, infix[i++]);
        }
    }

    while (operatorStack.top != -1) {
        if (operatorStack.items[operatorStack.top] == '(') {
            printf("Error: Unmatched parentheses\n");
            exit(EXIT_FAILURE);
        }

        postfix[j++] = charPop(&operatorStack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[50];
    printf("Masukkan ekspresi aritmatika (contoh: 2+3*4/2): ");
    scanf("%s", infix);

    // Konversi infix menjadi postfix
    char postfix[50];
    infixToPostfix(infix, postfix);
    printf("Notasi Postfiks: %s\n", postfix);

    return 0;
}
