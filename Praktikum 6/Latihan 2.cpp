#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];
int perbandingan = 0;
int pergeseran = 0;

void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TampilkanData() {
    for (int i = 0; i < MAX; i++) {
        std::cout << Data[i] << " ";
    }
    std::cout << std::endl;
}

void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
            perbandingan++;
            pergeseran++;
        }
        Data[j + 1] = x;
        pergeseran++;
        TampilkanData();
    }
}

void BinaryInsertSort() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
            perbandingan++;
        }
        for (j = i - 1; j >= l; j--) {
            Data[j + 1] = Data[j];
            pergeseran++;
        }
        Data[l] = x;
        pergeseran++;
        TampilkanData();
    }
}

void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
            perbandingan++;
        }
        Tukar(&Data[i], &Data[k]);
        pergeseran++;
        TampilkanData();
    }
}

int main() {
    srand(0);

    // Membangkitkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    std::cout << "\nPengurutan dengan Penyisipan Langsung:" << std::endl;
    StraightInsertSort();
    std::cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << std::endl;

    std::cout << "\nPengurutan dengan Penyisipan Biner:" << std::endl;
    BinaryInsertSort();
    std::cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << std::endl;

    std::cout << "\nPengurutan dengan Seleksi:" << std::endl;
    SelectionSort();
    std::cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << std::endl;

    return 0;
}
