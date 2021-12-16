// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 2 September 2021

// Praktikum 2
// Driver Vector

#include "vector.h"
#include <stdio.h>

int main()
{
    VECTOR v1;
    VECTOR v2;

    printf("Vektor Pertama adalah: ");
    v1 = MakeVector(1,2);
    TulisVector(v1);
    printf("\n");

    printf("Magnitude Vektor Pertama adalah: ");
    printf("%f\n", v1);

    printf("Vektor Kedua adalah: ");
    v2 = MakeVector(5,9);
    TulisVector(v2);
    printf("\n");

    printf("Vektor Pertama tambah Vektor Kedua adalah: ");
    TulisVector(Add(v1,v2));
    printf("\n");
    printf("Vektor Pertama kurang Vektor Kedua adalah: ");
    TulisVector(Substract(v1,v2));
    printf("\n");
    printf("Vektor Pertama dot Vektor Kedua adalah: ");
    printf("%f", Dot(v1,v2));
    printf("\n");

    printf("Vektor Kedua apabila di kalikan 3 adalah: ");
    TulisVector(Multiply(v2, 3));
    printf("\n");

    /* Hasil Test Case Sendiri
        Vektor Pertama adalah: <1.00,2.00>
        Magnitude Vektor Pertama adalah: 2.000000
        Vektor Kedua adalah: <5.00,9.00>
        Vektor Pertama tambah Vektor Kedua adalah: <6.00,11.00>
        Vektor Pertama kurang Vektor Kedua adalah: <-4.00,-7.00>
        Vektor Pertama dot Vektor Kedua adalah: 23.000000
        Vektor Kedua apabila di kalikan 3 adalah: <5.00,9.00>
    */

    return 0;
}
