#include <stdio.h>

int main() {
    int n;
    int nilai, prev_nilai, min, max;
    double min_avg, current_avg;

    // Membaca jumlah baris masukan
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Membaca baris-baris masukan
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai);

        if (i == 0) {
            // Jika ini angka pertama
            min = nilai;
            max = nilai;
        } else {
            // Cek nilai minimum dan maksimum
            if (nilai < min) min = nilai;
            if (nilai > max) max = nilai;

            // Hitung rata-rata dua angka berurutan
            current_avg = (prev_nilai + nilai) / 2.0;

            if (i == 1) {
                // Inisialisasi rata-rata terendah di pasangan pertama
                min_avg = current_avg;
            } else {
                // Update jika ketemu rata-rata yang lebih rendah
                if (current_avg < min_avg) {
                    min_avg = current_avg;
                }
            }
        }
        
        // Simpan angka untuk dipasangkan di perulangan berikutnya
        prev_nilai = nilai; 
    }

    // Menampilkan 3 baris keluaran
    printf("%d\n", min);
    printf("%d\n", max);
    
    if (n >= 2) {
        printf("%.2f\n", min_avg);
    }

    return 0;
}