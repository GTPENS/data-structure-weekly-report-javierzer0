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

// Prosedur pengurutan metode gelembung dengan tampilan setiap iterasi
void BubbleSort()
{
    std::cout << "Proses Pengurutan Metode Gelembung:" << std::endl;
    for (int i = 1; i < MAX - 1; i++)
    {
        for (int j = MAX - 1; j >= i; j--)
        {
            if (Data[j - 1] > Data[j])
            {
                Tukar(Data[j - 1], Data[j]);
                // Menampilkan perubahan setiap iterasi
                for (int k = 0; k < MAX; k++)
                {
                    std::cout << Data[k] << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}

// Prosedur pengurutan metode Shell dengan tampilan setiap iterasi
void ShellSort()
{
    std::cout << "\nProses Pengurutan Metode Shell:" << std::endl;
    int Jarak, i, j;
    bool Sudah;
    Jarak = MAX;
    while (Jarak > 1)
    {
        Jarak = Jarak / 2;
        Sudah = false;
        while (!Sudah)
        {
            Sudah = true;
            for (j = 0; j < MAX - Jarak; j++)
            {
                i = j + Jarak;
                if (Data[j] > Data[i])
                {
                    Tukar(Data[j], Data[i]);
                    Sudah = false;
                    // Menampilkan perubahan setiap iterasi
                    for (int k = 0; k < MAX; k++)
                    {
                        std::cout << Data[k] << " ";
                    }
                    std::cout << std::endl;
                }
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
    ShellSort();

    // Data setelah terurut
    std::cout << "\nDATA SETELAH TERURUT" << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        std::cout << "Data ke " << i << " : " << Data[i] << std::endl;
    }

    return 0;
}
