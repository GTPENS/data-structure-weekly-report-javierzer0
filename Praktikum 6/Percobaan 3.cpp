#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];

// Fungsi pertukaran bilangan
void Tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi pengurutan seleksi
void SelectionSort() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j]) {
                k = j;
            }
        }
        Tukar(&Data[i], &Data[k]);
    }
}

int main() {
    int i;
    srand(0);

    // Membangkitkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    SelectionSort();

    // Data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    return 0;
}
