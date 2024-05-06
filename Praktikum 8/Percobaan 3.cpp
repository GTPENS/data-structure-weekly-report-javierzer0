#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 10;
int Data[MAX];
int temp[MAX];

// Function to merge two sorted subarrays
void merge(int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        temp[i] = Data[left + i];
    for (j = 0; j < n2; j++)
        temp[n1 + j] = Data[mid + 1 + j];

    // Merge the temp arrays
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (temp[i] <= temp[j]) {
            Data[k] = temp[i];
            i++;
        } else {
            Data[k] = temp[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements
    while (i < n1) {
        Data[k] = temp[i];
        i++;
        k++;
    }

    while (j < n2) {
        Data[k] = temp[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // use time(0) for random seed

    std::cout << "DATA SEBELUM TERURUT : ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = static_cast<int>(rand() / 1000.0) + 1;
        std::cout << Data[i] << " ";
    }

    mergeSort(0, MAX - 1);

    std::cout << "\n\nDATA SETELAH TERURUT : ";
    for (int i = 0; i < MAX; i++)
        std::cout << Data[i] << " ";
    std::cout << std::endl;

    return 0;
}
