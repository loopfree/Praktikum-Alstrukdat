// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 9 September 2021
// Topik Praktikum  : ADT List
// Deskripsi        : Praktikum - mlistpos.c

#include "boolean.h"
#include "listpos.h"

#include <stdio.h>

int main()
{
    ListPos arr;
    CreateListPos(&arr);
    readList(&arr);
    int x;
    scanf("%d", &x);

    displayList(arr);
    printf("\n");
    if (indexOf(arr, x)==IDX_UNDEF)
    {
        printf("%d tidak ada\n", x);
    }
    if (indexOf(arr, x)!=IDX_UNDEF)
    {
        printf("%d\n", indexOf(arr, x));

        int maxi;
        int mini;
        extremes(arr, &maxi, &mini);
        if (x==maxi)
        {
            printf("maksimum\n");
        }
        if (x==mini)
        {
            printf("minimum\n");
        }

        sort(&arr, true);

        int median;
        if (length(arr)%2 != 0)
        {
            median = length(arr)/2;
        }
        if (length(arr)%2 == 0)
        {
            median = length(arr)/2;
            median -= 1;
        }

        if (x==arr.contents[median])
        {
            printf("median\n");
        }

    }

    return 0;
}
