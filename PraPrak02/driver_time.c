// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 1 September 2021

// PraPraktikum 2
// Driver Time

#include "time.h"
#include <stdio.h>

int main()
{
    // Cek fungsi MakeTIME
    TIME uji_time;
    uji_time = MakeTIME(7,7,7);
    printf("Jam = %d \n", uji_time.HH);
    printf("Menit = %d \n", uji_time.MM);
    printf("Detik = %d \n", uji_time.SS);

    // Cek waktu yang valid
    int check;
    printf("Cek validasi waktu untuk 7 7 7: ");
    check = (IsTIMEValid(7,7,7)==1 ? 1 : 0);
    if (check == 1)
    {
        printf("Waktu Valid \n");
    }
    else
    {
        printf("Waktu tidak valid \n");
    }

    // Cek waktu yang tidak valid
    int check2;
    printf("Cek validasi waktu untuk 25 67 10: ");
    check2 = (IsTIMEValid(25, 67, 10)==1 ? 1 : 0);
    if (check2 == 1)
    {
        printf("Waktu Valid \n");
    }
    else
    {
        printf("Waktu tidak valid \n");
    }

    TIME waktu1;
    printf("Masukkan Waktu Pertama: ");
    BacaTIME(&waktu1);
    printf("Hasil jamnya apabila ditulis adalah: ");
    TulisTIME(waktu1);
    printf("\n");

    TIME waktu2;
    printf("Masukkan Waktu Kedua: ");
    BacaTIME(&waktu2);
    printf("Hasil jamnya apabila ditulis adalah: ");
    TulisTIME(waktu2);
    printf("\n");

    // Cek Durasi
    printf("Durasi dari Waktu Pertama dengan Waktu Kedua: ");
    printf("%li detik\n", Durasi(waktu1, waktu2));

    // Cek Operasi Terhadap Type
    if (TEQ(waktu1, waktu2))
    {
        printf("Waktu Pertama sama dengan Waktu Kedua \n");
    }
    if (TNEQ(waktu1, waktu2))
    {
        printf("Waktu Pertama tidak sama dengan Waktu Kedua \n");
    }
    if (TLT(waktu1, waktu2))
    {
        printf("Waktu Pertama < Waktu Kedua \n");
    }
    if (TGT(waktu1, waktu2))
    {
        printf("Waktu Pertama > Waktu Kedua \n");
    }

    // Cek fungsi tambah detik
    TIME plus_one;
    printf("Waktu Pertama apabila ditambah 1 detik: ");
    plus_one = NextDetik(waktu1);
    TulisTIME(plus_one);
    printf("\n");

    TIME plus_ten;
    printf("Waktu Pertama apabila ditambah  10 detik: ");
    plus_ten = NextNDetik(waktu1, 10);
    TulisTIME(plus_ten);
    printf("\n");

    // Cek fungsi kurang detik
    TIME minus_one;
    printf("Waktu Kedua apabila dikurang 1 detik: ");
    minus_one = PrevDetik(waktu2);
    TulisTIME(minus_one);
    printf("\n");

    TIME minus_ten;
    printf("Waktu Pertama apabila dikurang 10 detik: ");
    minus_ten = PrevNDetik(waktu2, 10);
    TulisTIME(minus_ten);
    printf("\n");

    // Konversi detik ke time
    long detik;
    printf("Masukkan angka yang ingin dikonversi ke format TIME: ");
    scanf("%li", &detik);
    TulisTIME(DetikToTIME(detik));
    printf("\n");

    /* Contoh Test Case */
    /*
        Jam = 7
        Menit = 7
        Detik = 7
        Cek validasi waktu untuk 7 7 7: Waktu Valid
        Cek validasi waktu untuk 25 67 10: Waktu tidak valid
        Masukkan Waktu Pertama: 12 0 0
        Hasil jamnya apabila ditulis adalah: 12:0:0
        Masukkan Waktu Kedua: 8 0 0
        Hasil jamnya apabila ditulis adalah: 8:0:0
        Durasi dari Waktu Pertama dengan Waktu Kedua: 72000 detik
        Waktu Pertama tidak sama dengan Waktu Kedua
        Waktu Pertama > Waktu Kedua
        Waktu Pertama apabila ditambah 1 detik: 12:0:1
        Waktu Pertama apabila ditambah  10 detik: 12:0:10
        Waktu Kedua apabila dikurang 1 detik: 7:59:59
        Waktu Pertama apabila dikurang 10 detik: 7:59:50
        Masukkan angka yang ingin dikonversi ke format TIME: 3601
        1:0:1
    */

    return 0;
}
