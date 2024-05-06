#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &shifts) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                shifts++;
            }
        }
    }
}

void shellSort(int arr[], int n, int &comparisons, int &shifts) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                comparisons++;
                shifts++;
            }
            arr[j] = temp;
            if (i != j) shifts++;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int bubbleComparisons = 0, bubbleShifts = 0;
    int shellComparisons = 0, shellShifts = 0;

    // Bubble Sort
    bubbleSort(arr, n, bubbleComparisons, bubbleShifts);
    cout << "Bubble Sorted array: \n";
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nJumlah perbandingan (Bubble Sort): " << bubbleComparisons << endl;
    cout << "Jumlah pergeseran (Bubble Sort): " << bubbleShifts << endl;

    // Reset array to unsorted state
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};

    // Shell Sort
    shellSort(arr2, n, shellComparisons, shellShifts);
    cout << "\nShell Sorted array: \n";
    for (int i=0; i<n; i++)
        cout << arr2[i] << " ";
    cout << "\nJumlah perbandingan (Shell Sort): " << shellComparisons << endl;
    cout << "Jumlah pergeseran (Shell Sort): " << shellShifts << endl;

    return 0;
}
