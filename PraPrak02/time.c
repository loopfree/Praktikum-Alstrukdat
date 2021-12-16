// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 1 September 2021

// PraPraktikum 2
// Implementasi Time

#include "time.h"
#include <stdio.h>

// Mengirim true jika H,M,S dapat membentuk T yang valid
boolean IsTIMEValid (int H, int M, int S)
{
    return (H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59);
}

// Membentuk sebuah TIME dari HH, MM, SS yang valid
// untuk membentuk TIME
TIME MakeTIME (int HH, int MM, int SS)
{
    TIME T;
    Hour(T) = HH;
    Minute(T) = MM;
    Second(T) = SS;
    return T;
}

// I.S. : T tidak terdefinisi
// F.S. : T terdefinisi dan merupakan jam yang valid
// Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid"
// Pembacaan diulangi hingga didapatkan jam yang valid
void BacaTIME (TIME * T)
{
    int HH;
    int MM;
    int SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (!IsTIMEValid(HH,MM,SS))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    *T = MakeTIME(HH,MM,SS);
}

// I.S. : T sembarang
// F.S. : Nilai T ditulis dg format HH:MM:SS
//        tanpa karakter apa pun di depan atau belakangnya.
void TulisTIME (TIME T)
{
    printf("%d:%d:%d", Hour(T),  Minute(T), Second(T));
}

// Rumus : detik = 3600*HH + 60*MM + SS
long TIMEToDetik (TIME T)
{
    long ans;
    ans = 3600*T.HH + 60*T.MM + T.SS;
    return ans;
}

// Mengirim  konversi detik ke TIME
TIME DetikToTIME (long N)
{
    // Edge case
    N %= 86400;
    // End

    long jam  = N / 3600;
    N %= 3600;
    long menit = N / 60;
    N %= 60;
    long detik = N;
    return(MakeTIME(jam,menit,detik));
}

// Mengirimkan true jika T1=T2, false jika tidak
boolean TEQ (TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) ==  TIMEToDetik(T2));
}

// boolean TNEQ (TIME T1, TIME T2)
boolean TNEQ (TIME T1, TIME T2)
{
    return (!TEQ(T1,T2));
}

// Mengirimkan true jika T1<T2, false jika tidak
boolean TLT (TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

// Mengirimkan true jika T1>T2, false jika tidak
boolean TGT (TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

// Mengirim 1 detik setelah T dalam bentuk TIME
TIME NextDetik (TIME T)
{
    long total_detik = TIMEToDetik(T);
    total_detik += 1;
    total_detik %= 86400;
    return (DetikToTIME(total_detik));
}

// Mengirim N detik setelah T dalam bentuk TIME
TIME NextNDetik (TIME T, int N)
{
    long total_detik = TIMEToDetik(T);
    total_detik += N;
    total_detik %=  86400;
    return (DetikToTIME(total_detik));
}

// Mengirim 1 detik sebelum T dalam bentuk TIME
TIME PrevDetik (TIME T)
{
    long total_detik = TIMEToDetik(T);
    total_detik -= 1;
    total_detik %= 86400;
    return (DetikToTIME(total_detik));
}

// Mengirim N detik sebelum T dalam bentuk TIME
TIME PrevNDetik (TIME T, int N)
{
    long total_detik = TIMEToDetik(T);
    total_detik -= N;
    total_detik %= 86400;
    return (DetikToTIME(total_detik));
}

// Mengirim TAkh-TAw dlm Detik, dengan kalkulasi
// Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw
long Durasi (TIME TAw, TIME TAkh)
{
    long start;
    long end;
    long ans;

    start = TIMEToDetik(TAw);
    end = TIMEToDetik(TAkh);

    ans = end - start + 86400;
    ans %= 86400;
    return ans;
}
