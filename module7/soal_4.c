#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan waktu (jam, menit, detik)
struct Time {
    int hours;
    int minutes;
    int seconds;
    struct Time* next;
};

// Fungsi untuk mengonversi jumlah detik menjadi jam, menit, dan detik
struct Time* convertSecondsToTime(int totalSeconds) {
    struct Time* time = (struct Time*)malloc(sizeof(struct Time));

    time->hours = totalSeconds / 3600;
    time->minutes = (totalSeconds % 3600) / 60;
    time->seconds = totalSeconds % 60;
    time->next = NULL;

    return time;
}

// Fungsi untuk mencetak waktu yang disimpan dalam linked list
void printTime(struct Time* time) {
    printf("Waktu: %02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

// Fungsi untuk membebaskan memori yang digunakan oleh linked list waktu
void freeTime(struct Time* time) {
    free(time);
}

int main() {
    int totalSeconds;

    // Meminta input dari pengguna
    printf("Masukkan jumlah detik: ");
    scanf("%d", &totalSeconds);

    // Mengonversi jumlah detik ke dalam linked list waktu
    struct Time* timeList = convertSecondsToTime(totalSeconds);

    // Mencetak waktu dari linked list
    printTime(timeList);

    // Membebaskan memori
    freeTime(timeList);

    return 0;
}
