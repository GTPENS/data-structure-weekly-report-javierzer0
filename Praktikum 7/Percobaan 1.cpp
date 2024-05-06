#include <iostream>
#include <cstdlib>
#define MAX 10

int Data[MAX];

// Prosedur menukar data
void Tukar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Prosedur pengurutan metode gelembung
void BubbleSort()
{
    for (int i = 1; i < MAX - 1; i++)
    {
        for (int j = MAX - 1; j >= i; j--)
        {
            if (Data[j - 1] > Data[j])
            {
                Tukar(Data[j - 1], Data[j]);
            }
        }
    }
}

int main()
{
    srand(0);

    // Membangkitkan bilangan acak
    std::cout << "DATA SEBELUM TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        Data[i] = rand() % 1000 + 1;
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    BubbleSort();

    // Data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    return 0;
}
