#include <iostream>
#include <string>
#include <algorithm>

struct Pegawai {
    int NIP;
    std::string NAMA;
};

bool CompareByNIP(const Pegawai& a, const Pegawai& b) {
    return a.NIP < b.NIP;
}

bool CompareByNama(const Pegawai& a, const Pegawai& b) {
    return a.NAMA < b.NAMA;
}

void TampilkanData(const Pegawai* data, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        std::cout << "NIP: " << data[i].NIP << ", Nama: " << data[i].NAMA << std::endl;
    }
}

int main() {
    const int JUMLAH_PEGAWAI = 5;
    Pegawai dataPegawai[JUMLAH_PEGAWAI] = {
        {123, "Rangga"},
        {456, "Marlon"},
        {789, "Ruben"},
        {234, "Andhika"},
        {567, "Jegel"}
    };

    int pilihanMetode;
    std::cout << "Pilih metode pengurutan:" << std::endl;
    std::cout << "1. Urut berdasarkan NIP" << std::endl;
    std::cout << "2. Urut berdasarkan Nama" << std::endl;
    std::cin >> pilihanMetode;

    int pilihanUrutan;
    std::cout << "Pilih urutan:" << std::endl;
    std::cout << "1. Urut naik" << std::endl;
    std::cout << "2. Urut turun" << std::endl;
    std::cin >> pilihanUrutan;

    switch (pilihanMetode) {
        case 1:
            if (pilihanUrutan == 1) {
                std::sort(dataPegawai, dataPegawai + JUMLAH_PEGAWAI, CompareByNIP);
            } else {
                std::sort(dataPegawai, dataPegawai + JUMLAH_PEGAWAI, CompareByNIP);
                std::reverse(dataPegawai, dataPegawai + JUMLAH_PEGAWAI);
            }
            break;
        case 2:
            if (pilihanUrutan == 1) {
                std::sort(dataPegawai, dataPegawai + JUMLAH_PEGAWAI, CompareByNama);
            } else {
                std::sort(dataPegawai, dataPegawai + JUMLAH_PEGAWAI, CompareByNama);
                std::reverse(dataPegawai, dataPegawai + JUMLAH_PEGAWAI);
            }
            break;
        default:
            std::cout << "Pilihan metode tidak valid." << std::endl;
            return 1;
    }

    std::cout << "\nData Pegawai setelah diurutkan:" << std::endl;
    TampilkanData(dataPegawai, JUMLAH_PEGAWAI);

    return 0;
}
