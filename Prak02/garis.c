// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 2 September 2021

// Praktikum 2
// Implementasi Garis

#include "boolean.h"
#include "point.h"
#include "garis.h"

#include <stdio.h>
#include <math.h>

// I.S. P1 dan P2 terdefinisi
// F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2
// Membentuk sebuah L dari komponen-komponennya
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

// Proses : mengulangi membaca dua buah nilai P1 dan P2
// sehingga dapat membentuk GARIS yang valid
// GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya
// Jika pembacaan garis tidak valid, diberikan pesan kesalahan:
// "Garis tidak valid
void BacaGARIS (GARIS * L)
{
    POINT P1;
    POINT P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    while(EQ(P1, P2))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&P1);
        BacaPOINT(&P2);
    }
    MakeGARIS(P1, P2, L);
}

// Format "((x1,y1),(x2,y2))
// tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
// termasuk spasi dan enter
void TulisGARIS (GARIS L)
{
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
}

// Menghitung panjang garis L
float PanjangGARIS (GARIS L)
{
    float x1 = Absis(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y1 = Ordinat(PAwal(L));
    float y2 = Ordinat(PAkhir(L));

    return (sqrt(pow((x2-x1),2)+ pow((y2-y1),2)));
}

// Mengembalikan Gradien (m) dari L
// Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1)
float Gradien (GARIS L)
{
    float x1 = Absis(PAwal(L));
    float x2 = Absis(PAkhir(L));
    float y1 = Ordinat(PAwal(L));
    float y2 = Ordinat(PAkhir(L));

    return ((y2-y1)/(x2-x1));
}

// L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Absis(PAwal(*L)) += deltaX;
    Absis(PAkhir(*L)) += deltaX;

    Ordinat(PAwal(*L)) += deltaY;
    Ordinat(PAkhir(*L)) +=  deltaY;
}

// Menghasilkan true jika L1 tegak lurus terhadap L2
// Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1
boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1)*Gradien(L2) == -1);
}

// Menghasilkan true jika L "sejajar" terhadap L1
// Dua garis saling sejajar jika memiliki gradien yang sama
boolean IsSejajar (GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}
