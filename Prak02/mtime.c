// Nama     : Steven
// NIM      : 13520131
// Tanggal  : 2 September 2021

// Praktikum 2
// mtime.c

#include "time.h"
#include <stdio.h>

int main()
{
    int times;
    int start = 1;

    long mini = 86400; // memanfaatkan constraint
    long maks = -1; // memanfaatkan constraint

    scanf("%d", &times);

    while (times--)
    {
        printf("[%d]\n", start);
        start += 1;

        TIME jam1;
        TIME jam2;
        BacaTIME(&jam1);
        BacaTIME(&jam2);

        if (TIMEToDetik(jam1) < mini)
        {
            mini = TIMEToDetik(jam1);
        }
        if (TIMEToDetik(jam2) < mini)
        {
            mini = TIMEToDetik(jam2);
        }
        if (TIMEToDetik(jam1) > maks)
        {
            maks = TIMEToDetik(jam1);
        }
        if (TIMEToDetik(jam2) > maks)
        {
            maks = TIMEToDetik(jam2);
        }

        if (TLT(jam1,jam2))
        {
            long ans = Durasi(jam1, jam2);
            printf("%li\n", ans);
        }
        if (TGT(jam1, jam2))
        {
            long ans = Durasi(jam2, jam1);
            printf("%li\n", ans);
        }
        if (TEQ(jam1,jam2))
        {
            long ans = 0;
            printf("%li\n", ans);
        }

    }

    TulisTIME(DetikToTIME(mini));
    printf("\n");
    TulisTIME(DetikToTIME(maks));
    printf("\n");

    /* Hasil Test Case
        3
        [1]
        1 0 0
        3 0 0
        7200
        [2]
        4 0 0
        2 0 0
        7200
        [3]
        -1 0 0
        Jam tidak valid
        1 0 0
        1 0 0
        0
        1:0:0
        4:0:0
    */
    return 0;
}
