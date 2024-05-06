#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 10;
const int MaxStack = 10;

int Data[MAX];

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Non-recursive Quick Sort function
void quickSortNonRecursive() {
    struct Stack {
        int left;
        int right;
    } stack[MaxStack];
    int top = 1;
    stack[1].left = 0;
    stack[1].right = MAX - 1;

    while (top!= 0) {
        int left = stack[top].left;
        int right = stack[top].right;
        top--;

        while (right > left) {
            int i = left;
            int j = right;
            int pivot = Data[(left + right) / 2];

            while (i <= j) {
                while (Data[i] < pivot)
                    i++;
                while (pivot < Data[j])
                    j--;
                if (i <= j) {
                    swap(Data[i], Data[j]);
                    i++;
                    j--;
                }
            }

            if (left < i) {
                top++;
                stack[top].left = i;
                stack[top].right = right;
            }
            right = j;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // use time(0) for random seed

    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++) {
        Data[i] = static_cast<int>(rand() / 1000.0) + 1;
        std::cout << "Data ke " << i << ": " << Data[i] << std::endl;
    }

    quickSortNonRecursive();

    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << ": " << Data[i] << std::endl;
    }

    return 0;
}
