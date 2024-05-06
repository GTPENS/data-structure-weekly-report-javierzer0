#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

int main() {
    int i;
    srand(0);

    // Memunculkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    StraightInsertSort();

    // Memunculkan Data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    return 0;
}
