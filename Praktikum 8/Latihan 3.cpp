#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Pegawai {
    string NIP;
    string NAMA;
};

bool compareByNIPAsc(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}

bool compareByNIPDesc(const Pegawai& a, const Pegawai& b) {
    return a.NIP > b.NIP;
}

bool compareByNamaAsc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA < b.NAMA;
}

bool compareByNamaDesc(const Pegawai& a, const Pegawai& b) {
    return a.NAMA > b.NAMA;
}

void printPegawai(const vector<Pegawai>& pegawai) {
    for (const auto& p : pegawai) {
        cout << "NIP: " << p.NIP << ", NAMA: " << p.NAMA << endl;
    }
}

int main() {
    vector<Pegawai> pegawai = {
        {"19820304", "Dicky"},
        {"19810602", "Ibnu"},
        {"19850708", "Adit"},
        {"19830910", "Dandi"}
    };

    int metodeSort, jenisSort;
    cout << "Pilih metode sort (1 untuk NIP, 2 untuk NAMA): ";
    cin >> metodeSort;
    cout << "Pilih jenis sort (1 untuk Ascending, 2 untuk Descending): ";
    cin >> jenisSort;

    if (metodeSort == 1) {
        if (jenisSort == 1) {
            sort(pegawai.begin(), pegawai.end(), compareByNIPAsc);
        } else {
            sort(pegawai.begin(), pegawai.end(), compareByNIPDesc);
        }
    } else {
        if (jenisSort == 1) {
            sort(pegawai.begin(), pegawai.end(), compareByNamaAsc);
        } else {
            sort(pegawai.begin(), pegawai.end(), compareByNamaDesc);
        }
    }

    cout << "Data Pegawai setelah diurutkan:" << endl;
    printPegawai(pegawai);

    return 0;
}
