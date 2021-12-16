// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 2 September 2021

// Praktikum 2
// Driver Garis

#include "garis.h"
#include <stdio.h>

int main()
{
    POINT titik1;
    POINT titik2;
    titik1 = MakePOINT(9, -5);
    printf("Diberikan Titik Pertama: ");
    TulisPOINT(titik1);
    printf("\n");
    titik2 = MakePOINT(9, -5);
    printf("Diberikan Titik Kedua: ");
    TulisPOINT(titik2);
    printf("\n");

    GARIS garis1;
    GARIS garis2;

    MakeGARIS(titik1, titik2, &garis1);
    printf("Garis Pertama Adalah: ");
    TulisGARIS(garis1);
    printf("\n");
    printf("Silahkan Masukkan 2 titik\n");
    BacaGARIS(&garis2);
    printf("Garis Kedua Adalah: ");
    TulisGARIS(garis2);
    printf("\n");

    printf("Panjang garis kedua adalah: %f\n", PanjangGARIS(garis2));
    printf("Gradien garis kedua adalah: %f\n", Gradien(garis2));

    printf("Garis kedua digeser +3 sumbu-x dan -1 sumbu-y\n");
    printf("Garis kedua menjadi: ");
    GeserGARIS(&garis2, 3, -1);
    TulisGARIS(garis2);
    printf("\n");

    if (IsTegakLurus(garis1, garis2))
    {
        printf("garis pertama tegak lurus dengan garis kedua.\n");
    }
    if (!IsTegakLurus(garis1, garis2))
    {
        printf("garis pertama tidak tegak lurus dengan garis kedua.\n");
    }

    if (IsSejajar(garis1,garis2))
    {
        printf("garis pertama sejajar dengan garis kedua.");
    }
    if (!IsSejajar(garis1,garis2))
    {
        printf("garis pertama tidak sejajar dengan garis kedua.");
    }

    /* Hasil Test Case Sendiri
        Diberikan Titik Pertama: (9.00,-5.00)
        Diberikan Titik Kedua: (9.00,-5.00)
        Garis Pertama Adalah: ((9.00,-5.00),(9.00,-5.00))
        Silahkan Masukkan 2 titik
        3 5
        5 9
        Garis Kedua Adalah: ((3.00,5.00),(5.00,9.00))
        Panjang garis kedua adalah: 4.472136
        Gradien garis kedua adalah: 2.000000
        Garis kedua digeser +3 sumbu-x dan -1 sumbu-y
        Garis kedua menjadi: ((6.00,4.00),(8.00,8.00))
        garis pertama tidak tegak lurus dengan garis kedua.
        garis pertama tidak sejajar dengan garis kedua.
    */

    return 0;
}
