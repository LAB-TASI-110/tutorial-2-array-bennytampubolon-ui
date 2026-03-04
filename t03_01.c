#include <stdio.h>

int main() {
    int n;
    int nilai, min, max;

    // Membaca baris pertama: jumlah input (n)
    if (scanf("%d", &n) != 1) {
        return 1; // Keluar jika input tidak valid
    }

    // Membaca n baris berikutnya
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai);

        // Jika ini adalah angka pertama, inisialisasi min dan max dengan angka tersebut
        if (i == 0) {
            min = nilai;
            max = nilai;
        } else {
            // Perbarui nilai min jika angka yang baru lebih kecil
            if (nilai < min) {
                min = nilai;
            }
            // Perbarui nilai max jika angka yang baru lebih besar
            if (nilai > max) {
                max = nilai;
            }
        }
    }

    // Mencetak hasil sesuai spesifikasi
    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}