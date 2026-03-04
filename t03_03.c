#include <stdio.h>

int main() {
    int n;
    int nilai, prev_nilai, min, max;
    double min_avg, max_avg, current_avg;

    // 1. Membaca jumlah baris masukan
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // 2. Memproses setiap baris masukan
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai);

        if (i == 0) {
            // Inisialisasi awal pada angka pertama
            min = nilai;
            max = nilai;
        } else {
            // Perbarui nilai minimum dan maksimum keseluruhan
            if (nilai < min) min = nilai;
            if (nilai > max) max = nilai;

            // Hitung rata-rata dua angka yang bersebelahan
            current_avg = (prev_nilai + nilai) / 2.0;

            if (i == 1) {
                // Inisialisasi rata-rata terendah dan tertinggi pada pasangan pertama
                min_avg = current_avg;
                max_avg = current_avg;
            } else {
                // Perbarui jika menemukan rata-rata yang lebih rendah atau lebih tinggi
                if (current_avg < min_avg) {
                    min_avg = current_avg;
                }
                if (current_avg > max_avg) {
                    max_avg = current_avg;
                }
            }
        }
        
        // Simpan nilai saat ini untuk dipasangkan pada iterasi berikutnya
        prev_nilai = nilai; 
    }

    // 3. Menampilkan 4 baris keluaran sesuai spesifikasi
    printf("%d\n", min);
    printf("%d\n", max);
    
    // Pastikan ada minimal 2 angka untuk bisa menampilkan rata-rata
    if (n >= 2) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    }

    return 0;
}