#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk SHRT_MAX dan SHRT_MIN (nilai minimum dan maksimum short integer)
#include <float.h>    // Untuk DBL_MAX dan DBL_MIN (nilai maksimum dan minimum double)

int main() {
    short num_to_read;         // Variabel untuk menyimpan jumlah input angka yang akan dibaca
    short current_input;       // Variabel untuk menyimpan setiap input angka
    short min_val = SHRT_MAX;  // Inisialisasi min_val dengan nilai short maksimum
    short max_val = SHRT_MIN;  // Inisialisasi max_val dengan nilai short minimum

    // Meminta pengguna memasukkan nilai n (jumlah input berikutnya)
    printf("Masukkan nilai n (merepresentasikan jumlah input berikutnya): ");
    if (scanf("%hd", &num_to_read) != 1) {
        printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
        return 1; // Keluar dengan kode error
    }

    if (num_to_read <= 0) {
        printf("Jumlah input harus lebih besar dari 0.\n");
        return 1;
    }

    // Array untuk menyimpan semua input agar bisa menghitung rata-rata pasangan berturut
    // Catatan: Array ukuran variabel (VLA) seperti ini adalah fitur C99.
    // Jika kompiler Anda lebih ketat (misalnya C11 tanpa ekstensi GNU),
    // Anda mungkin perlu mengalokasikan memori secara dinamis menggunakan malloc.
    // Untuk saat ini, kita asumsikan VLA didukung.
    short inputs[num_to_read]; 

    printf("Masukkan %hd angka bilangan bulat pendek:\n", num_to_read);

    // Loop untuk menerima 'n' input angka, menyimpannya, dan mencari nilai min/max
    for (int i = 0; i < num_to_read; i++) {
        printf("Input ke-%d: ", i + 1);
        if (scanf("%hd", &current_input) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1; // Keluar dengan kode error
        }
        inputs[i] = current_input; // Simpan input ke dalam array

        // Membandingkan dan memperbarui nilai minimum dan maksimum
        if (current_input < min_val) {
            min_val = current_input;
        }
        if (current_input > max_val) {
            max_val = current_input;
        }
    }

    // Menampilkan hasil min dan max
    printf("Nilai terkecil: %hd\n", min_val);
    printf("Nilai terbesar: %hd\n", max_val);

    // Bagian perhitungan rata-rata terendah dan tertinggi dari pasangan berturut
    if (num_to_read < 2) {
        printf("Rata-rata pasangan berturut: Input tidak valid (jumlah input kurang dari dua).\n");
    } else {
        double min_avg = DBL_MAX; // Inisialisasi min_avg dengan nilai double maksimum
        double max_avg = DBL_MIN; // Inisialisasi max_avg dengan nilai double minimum
        
        for (int i = 0; i < num_to_read - 1; i++) {
            // Hitung rata-rata pasangan berturut
            double current_avg = (double)(inputs[i] + inputs[i+1]) / 2.0;
            
            // Perbarui min_avg jika ditemukan yang lebih kecil
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
            // Perbarui max_avg jika ditemukan yang lebih besar
            if (current_avg > max_avg) {
                max_avg = current_avg;
            }
        }
        // Menampilkan rata-rata terendah dengan 2 digit presisi
        printf("Rata-rata terendah dari 2 nilai berturut: %.2f\n", min_avg);
        // Menampilkan rata-rata tertinggi dengan 2 digit presisi
        printf("Rata-rata tertinggi dari 2 nilai berturut: %.2f\n", max_avg);
    }

    return 0;
}