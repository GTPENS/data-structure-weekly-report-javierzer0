#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];

// Fungsi pengurutan penyisipan biner
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
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
    }
}

int main() {
    int i;
    srand(0);

    // memunculkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    BinaryInsertSort();

    // Memunculkan Data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }
    return 0;
}
