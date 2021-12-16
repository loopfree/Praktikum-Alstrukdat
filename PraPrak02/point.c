// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 1 September 2021

// PraPraktikum 2
// Implementasi Point


#include <stdio.h>
#include <math.h>
#include "point.h"

// Membentuk sebuah POINT dari komponen-komponennya.
POINT MakePOINT (float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

// Membaca nilai absis dan ordinat dari inputan pengguna
// lalu membentuk POINT P.
// Komponen X dan Y dibaca dalam 1 baris
// dengan perantara 1 spasi.
void BacaPOINT (POINT * P)
{
    float x;
    float y;
    scanf("%f %f", &x, &y);
    *P = MakePOINT(x,y);
}

// Nilai P ditulis ke layar dengan format "(X,Y)"
// tanpa adanya karakter lain di depan, belakang maupun tengah.
// X dan Y dituliskan dalam bilangan riil dengan 2
// angka di belakang koma.
void TulisPOINT (POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

// Mengirimkan true apabila absis dan ordinat P1 sama
// dengan absis dan ordinat P2
boolean EQ (POINT P1, POINT P2)
{
    return(Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));

}

// Mengirimkan true apabila absis dan ordinat P1
// tidak sama dengan absis dan ordinat P2
boolean NEQ (POINT P1, POINT P2)
{
    return (!EQ(P1,P2));
}

// Menghasilkan true apabila titik P adalah titik origin
boolean IsOrigin (POINT P)
{
    return (Absis(P)==0 && Ordinat(P)==0);
}

// Menghasilkan true apabila titik P terletak pada sumbu X
boolean IsOnSbX (POINT P)
{
    return (Ordinat(P)==0);
}

// Menghasilkan true apabila titik P terletak pada sumbu Y
boolean IsOnSbY (POINT P)
{
    return (Absis(P)==0);
}

// Menghasilkan kuadran dari titik P (1, 2, 3, 4)
// Prekondisi : P bukan titik origin dan terletak
// di salah satu sumbu
int Kuadran (POINT P)
{
    int ans;
    if (Absis(P)>0 && Ordinat(P)>0)
    {
        ans = 1;
    }
    if (Absis(P)>0 && Ordinat(P)<0)
    {
        ans = 4;
    }
    if (Absis(P)<0 && Ordinat(P)>0)
    {
        ans = 2;
    }
    if (Absis(P)<0 && Ordinat(P)<0)
    {
        ans = 3;
    }
    return ans;
}

// Mengirim salinan P dengan absis ditambah satu
POINT NextX (POINT P)
{
    // Deklarasi variabel baru karena hanya berupa
    // salinan dari P, bukan mengganti nilai P
    POINT ans;
    ans = P;
    Absis(ans) += 1;
    return (ans);
}

// Mengirim salinan P dengan ordinat ditambah satu
POINT NextY (POINT P)
{
    // Deklarasi variabel baru karena hanya berupa
    // salinan dari P, bukan mengganti nilai P
    POINT ans;
    ans = P;
    Ordinat(ans) += 1;
    return (ans);
}

// Mengirim salinan P yang absisnya adalah
// Absis(P) + deltaX dan ordinatnya adalah
// Ordinat(P) + deltaY
POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    // Deklarasi variabel baru karena hanya berupa
    // salinan dari P, bukan mengganti nilai P
    POINT ans;
    ans = P;
    Absis(ans) += deltaX;
    Ordinat(ans) += deltaY;
    return (ans);
}

// Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu
// Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
// Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y
POINT MirrorOf (POINT P, boolean SbX)
{
    // Deklarasi variabel baru karena hanya berupa
    // salinan dari P, bukan mengganti nilai P
    POINT ans;
    ans = P;
    if (SbX)
    {
        Ordinat(ans) = - Ordinat(ans);
    }
    else
    {
        Absis(ans) = - Absis(ans);
    }
    return (ans);
}

// Menghitung jarak titik P ke (0,0)
float Jarak0 (POINT P)
{
    float pk2x;
    float pk2y;

    pk2x = pow(Absis(P),2);
    pk2y = pow(Ordinat(P),2);

    return (sqrt(pk2x+pk2y));
}

// Menghitung panjang garis yang dibentuk P1 dan P2
float Panjang (POINT P1, POINT P2)
{
    float dx;
    float dy;
    float pk2dx;
    float pk2dy;

    dx = Absis(P1) - Absis(P2);
    dy = Ordinat(P1) - Ordinat(P2);

    pk2dx = pow(dx,2);
    pk2dy = pow(dy,2);

    return (sqrt(pk2dx+pk2dy));
}

// Menggeser absis titik P sebesar deltaX dan
// ordinatnya sebesar deltaY
void Geser (POINT *P, float deltaX, float deltaY)
{
    *P = PlusDelta(*P, deltaX, deltaY);
}

// Menggeser absis titik P hingga berada pada sumbu X
// dengan absis sama dengan absis semula
void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}

// Menggeser absis titik P hingga berada pada sumbu Y
// dengan ordinat sama dengan ordinat semula
void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}

// Titik P dicerminkan tergantung nilai SbX
// Jika SbX true maka dicerminkan terhadap sumbu X
// Jika SbX false maka dicerminkan terhadap sumbu
void Mirror (POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) = -Ordinat(*P);
    }
    else
    {
        Absis(*P) = - Absis(*P);
    }
}

// Titik P digeser sebesar Sudut derajat dengan sumbu titik (0,0)
void Putar (POINT *P, float Sudut)
{
    const float pi= 3.14;
    float helper1;
    float helper2;
    Sudut = 360 - Sudut;
    helper1 = Absis(*P);
    helper2 = Ordinat(*P);
	Absis(*P) = helper1*cos(Sudut/180 * pi) - helper2*sin(Sudut/180 * pi);
	Ordinat(*P) = helper1*sin(Sudut/180 * pi) + helper2*cos(Sudut/180 * pi);
}
