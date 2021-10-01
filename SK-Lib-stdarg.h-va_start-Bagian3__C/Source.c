
#include <stdarg.h>
#include <stdio.h>
#include <conio.h>

/*
	Source by GeeksForGeeks
	Modified For Learn by RK
	I.D.E : VS2019
*/

int min(int arg_count, ...) {
	int i;
	int min, a;

	// va_list adalah tipe untuk menyimpan informasi tentang argumen variabel
	va_list ap;

	// va_start harus dipanggil sebelum mengakses daftar argumen variabel
	va_start(ap, arg_count);

	// Sekarang argumen dapat diakses satu per satu menggunakan makro va_arg. 
	// Inisialisasi min sebagai argumen pertama dalam daftar
	min = va_arg(ap, int);

	// melintasi sisa argumen untuk mencari tahu minimum
	for (i = 2; i <= arg_count; i++)
		if ((a = va_arg(ap, int)) < min)
			min = a;

	// va_end harus dieksekusi sebelum fungsi kembali setiap kali va_start telah 
	// digunakan sebelumnya dalam fungsi itu
	va_end(ap);

	return min;
}

// Driver code
int main() {
	int count = 5;
	printf("Minimum value is %d", min(count, 12, 67, 6, 7, 100));
	_getch();
	return 0;
}
