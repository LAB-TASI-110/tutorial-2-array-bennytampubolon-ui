#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Untuk SHRT_MAX dan SHRT_MIN (nilai minimum dan maksimum short integer)

int main() {
    short n_plus_one_input; // Variabel untuk menyimpan input 'n'
    short num_to_read;      // Variabel untuk menyimpan jumlah input angka yang akan dibaca setelah 'n'
    short current_input;    // Variabel untuk menyimpan setiap input angka
    short min_val = SHRT_MAX; // Inisialisasi min_val dengan nilai short maksimum
    short max_val = SHRT_MIN; // Inisialisasi max_val dengan nilai short minimum

    // Meminta pengguna memasukkan nilai n
    if (scanf("%hd", &n_plus_one_input) != 1) {
        printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
        return 1; // Keluar dengan kode error
    }

    // Berdasarkan klarifikasi "nilai n tersebut merepresentasikan jumlah input yang akan kita masukkan selanjutnya",
    // kita asumsikan n_plus_one_input adalah jumlah input berikutnya.
    num_to_read = n_plus_one_input;

    if (num_to_read <= 0) {
        printf("Jumlah input harus lebih besar dari 0.\n");
        return 1;
    }

    printf("Masukkan %hd angka bilangan bulat pendek:\n", num_to_read);

    // Loop untuk menerima 'n' input angka dan mencari nilai min/max
    for (int i = 0; i < num_to_read; i++) {
        printf("%d: ", i + 1);
        if (scanf("%hd", &current_input) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1; // Keluar dengan kode error
        }

        // Membandingkan dan memperbarui nilai minimum dan maksimum
        if (current_input < min_val) {
            min_val = current_input;
        }
        if (current_input > max_val) {
            max_val = current_input;
        }
    }

    // Menampilkan hasil
    printf("%hd\n", min_val); // Nilai terkecil
    printf("%hd\n", max_val); // Nilai terbesar

    return 0;
} // KURUNG KURAWAL PENUTUP YANG HILANG SEBELUMNYA