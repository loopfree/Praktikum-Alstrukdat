// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 1 September 2021

// PraPraktikum 2
// Driver Point

#include "point.h"
#include <stdio.h>

int main()
{
    POINT titik1;
    POINT titik2;

    titik1 = MakePOINT(9, -5);
    printf("Diberikan Titik Pertama: ");
    TulisPOINT(titik1);
    printf("\n");
    printf("Titik Pertama berada pada kuadran ke-%d \n", Kuadran(titik1));

    printf("Masukkan Titik Kedua: ");
    BacaPOINT(&titik2);
    printf("Titik Kedua berada pada kuadran ke-%d \n", Kuadran(titik2));

    // Cek Apakah Kedua Titik Sama Atau Tidak Sama
    if (EQ(titik1,titik2))
    {
        printf("Kedua titik sama\n");
    }
    if (NEQ(titik1,titik2))
    {
        printf("Kedua titik tidak sama\n");
    }

    if (IsOrigin(titik2))
    {
        printf("Titik Kedua berada pada titik origin\n");
    }
    if (IsOnSbX(titik2))
    {
        printf("Titik kedua berada  pada sumbu X\n");
    }
    if (IsOnSbY(titik2))
    {
        printf("Titik kedua berada  pada sumbu Y");
    }

    // Salinan Tambah dan/atau Kurang Sumbu X dan/atau Sumbu Y
    printf("Salinan Titik Kedua apabila sumbu-Xnya ditambah 1: ");
    TulisPOINT(NextX(titik2));
    printf("\n");
    printf("Salinan Titik Kedua apabila sumbu-Ynya ditambah 1: ");
    TulisPOINT(NextY(titik2));
    printf("\n");
    printf("Salinan Titik Kedua apabila sumbu-X dan sumbu-Ynya dikurang 1: ");
    TulisPOINT(PlusDelta(titik2, -1, -1));
    printf("\n");

    // Salinan Pencerminan Titik Terhadap Sumbu X dan/atau Sumbu Y
    printf("Salinan pencerminan Titik Kedua terhadap sumbu-x: ");
    TulisPOINT(MirrorOf(titik2, true));
    printf("\n");
    printf("Salinan pencerminan Titik Kedua terhadap sumbu-y: ");
    TulisPOINT(MirrorOf(titik2, false));
    printf("\n");

    // Jarak Titik Dari Titik Origin
    printf("Jarak Titik Kedua dari titik (0,0): %f\n", Jarak0(titik2));

    // Panjang Antara 2 Buah Titik
    printf("Jarak Titik Pertama dengan Titik Kedua adalah: %f\n", Panjang(titik1,titik2));

    // Geser Titik Kedua
    Geser(&titik2, 3, 3);
    printf("Geser Titik Kedua sebesar 3\n");
    printf("Titik Kedua menjadi: ");
    TulisPOINT(titik2);
    printf("\n");

    // Mirror Titik Kedua
    Mirror(&titik2, true);
    printf("Titik Kedua di cerminkan terhadap sumbu-x\n");
    printf("Titik Kedua menjadi: ");
    TulisPOINT(titik2);
    printf("\n");

    // Putar Titik Kedua
    Putar(&titik2, 90);
    printf("Titik Kedua di putar 90 derajat\n");
    printf("Titik Kedua menjadi: ");
    TulisPOINT(titik2);
    printf("\n");

    // Contoh Test Case
    /*
        Ganti point.c ke point.h
        Diberikan Titik Pertama: (9.00,-5.00)
        Titik Pertama berada pada kuadran ke-4
        Masukkan Titik Kedua: 3 4
        Titik Kedua berada pada kuadran ke-1
        Kedua titik tidak sama
        Salinan Titik Kedua apabila sumbu-Xnya ditambah 1: (4.00,4.00)
        Salinan Titik Kedua apabila sumbu-Ynya ditambah 1: (3.00,5.00)
        Salinan Titik Kedua apabila sumbu-X dan sumbu-Ynya dikurang 1: (2.00,3.00)
        Salinan pencerminan Titik Kedua terhadap sumbu-x: (3.00,-4.00)
        Salinan pencerminan Titik Kedua terhadap sumbu-y: (-3.00,4.00)
        Jarak Titik Kedua dari titik (0,0): 5.000000
        Jarak Titik Pertama dengan Titik Kedua adalah: 10.816654
        Geser Titik Kedua sebesar 3
        Titik Kedua menjadi: (6.00,7.00)
        Titik Kedua di cerminkan terhadap sumbu-x
        Titik Kedua menjadi: (6.00,-7.00)
        Titik Kedua di putar 90 derajat
        Titik Kedua menjadi: (-7.01,-5.98)
    */

    return 0;
}
