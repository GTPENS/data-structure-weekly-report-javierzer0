#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

struct Pegawai {
    string NIP;
    string NAMA;
};

// Fungsi untuk membandingkan dua Pegawai berdasarkan NIP
bool compareByNIP(const Pegawai &a, const Pegawai &b) {
    return a.NIP < b.NIP; // Urut naik
}

// Fungsi untuk membandingkan dua Pegawai berdasarkan NAMA
bool compareByNAMA(const Pegawai &a, const Pegawai &b) {
    return a.NAMA < b.NAMA; // Urut naik
}

// Fungsi untuk mengurutkan array Pegawai
void sortPegawai(Pegawai arr[], int n, char metode, char urutan) {
    if (metode == 'N') {
        if (urutan == 'A') {
            sort(arr, arr + n, compareByNIP);
        } else {
            sort(arr, arr + n, [](const Pegawai &a, const Pegawai &b) {
                return a.NIP > b.NIP; // Urut turun
            });
        }
    } else if (metode == 'M') {
        if (urutan == 'A') {
            sort(arr, arr + n, compareByNAMA);
        } else {
            sort(arr, arr + n, [](const Pegawai &a, const Pegawai &b) {
                return a.NAMA > b.NAMA; // Urut turun
            });
        }
    }
}

int main() {
    Pegawai pegawai[] = {
        {"198203032003121001", "Dimas"},
        {"198103012003121002", "Elmo"},
        {"198303052003121003", "Toriq"},
        {"198503072003121004", "Jupri"}
    };
    int n = sizeof(pegawai) / sizeof(pegawai[0]);
    char metode, urutan;

    cout << "Pilih metode pengurutan (N untuk NIP, M untuk NAMA): ";
    cin >> metode;
    if (metode!= 'N' && metode!= 'M') {
        cout << "Metode pengurutan salah!" << endl;
        return -1;
    }

    cout << "Pilih urutan (A untuk naik, D untuk turun): ";
    cin >> urutan;
    if (urutan!= 'A' && urutan!= 'D') {
        cout << "Urutan salah!" << endl;
        return -1;
    }

    sortPegawai(pegawai, n, metode, urutan);

    cout << "Data Pegawai setelah diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << "NIP: " << pegawai[i].NIP << ", NAMA: " << pegawai[i].NAMA << endl;
    }

    return 0;
}
