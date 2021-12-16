// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 2 September 2021

// Praktikum 2
// Implementasi Vector

#include "vector.h"
#include "math.h"
#include "boolean.h"

#include <stdio.h>

// Membentuk sebuah VECTOR dengan komponen absis x dan
// komponen ordinat y
VECTOR MakeVector(float x, float y)
{
    VECTOR V;
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;
    return V;
}

// Nilai v ditulis ke layar dengan format "<X,Y>"
// tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
// Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
void TulisVector(VECTOR v)
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

// Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2)
float Magnitude(VECTOR v)
{
    float x = AbsisComponent(v);
    float y = OrdinatComponent(v);
    float x2 = pow(x,2);
    float y2 = pow(y,2);
    return (sqrt(x2+y2));
}

// Menghasilkan sebuah vector yang merupakan hasil a + b.
// Komponen absis vector hasil adalah vector pertama
// ditambah vector kedua, begitu pula dengan ordinatnya
VECTOR Add(VECTOR a, VECTOR b)
{
    return MakeVector(AbsisComponent(a)+AbsisComponent(b), OrdinatComponent(a)+OrdinatComponent(b));
}

// Menghasilkan sebuah vector yang merupakan hasil a + b.
// Komponen absis vector hasil adalah vector pertama
// dikurang vector kedua, begitu pula dengan ordinatnya
VECTOR Substract(VECTOR a, VECTOR b)
{
    return MakeVector(AbsisComponent(a)-AbsisComponent(b), OrdinatComponent(a)-OrdinatComponent(b));
}

// Menghasilkan perkalian dot vector
// yakni a.x * b.x + a.y * b.y
float Dot(VECTOR a, VECTOR b)
{
    float absis = AbsisComponent(a) * AbsisComponent(b);
    float ordinat = OrdinatComponent(a) * OrdinatComponent(b);
    return (absis+ordinat);
}

// Menghasilkan perkalian skalar vector dengan s, yakni
// (s * a.x, s * a.y)
VECTOR Multiply(VECTOR v, float s)
{
    VECTOR ans;
    AbsisComponent(ans) = s * AbsisComponent(v);
    OrdinatComponent(ans) = s * OrdinatComponent(v);
}
