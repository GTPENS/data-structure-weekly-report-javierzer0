#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 10;

int Data[MAX];

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive Quick Sort function
void quickSortRecursive(int left, int right) {
    if (left <= right) {
        int pivotIndex = (left + right) / 2;
        int pivot = Data[pivotIndex];
        int i = left;
        int j = right;

        while (i <= j) {
            while (Data[i] < pivot)
                i++;
            while (Data[j] > pivot)
                j--;
            if (i <= j) {
                swap(Data[i], Data[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quickSortRecursive(left, j);
        if (i < right)
            quickSortRecursive(i, right);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // use time(0) for random seed

    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++) {
        Data[i] = static_cast<int>(rand() / 1000.0) + 1;
        std::cout << "Data ke " << i << ": " << Data[i] << std::endl;
    }

    quickSortRecursive(0, MAX - 1);

    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << ": " << Data[i] << std::endl;
    }

    return 0;
}
