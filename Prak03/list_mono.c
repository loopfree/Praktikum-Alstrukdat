// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 9 September 2021
// Topik Praktikum  : ADT List
// Deskripsi        : Praktikum - list_mono.c

#include "boolean.h"
#include "listpos.h"

#include <stdio.h>

int main()
{
    ListPos arr;
    ListPos arr_mengecil;
    ListPos arr_membesar;
    CreateListPos(&arr);
    CreateListPos(&arr_mengecil);
    CreateListPos(&arr_membesar);
    readList(&arr);

    for (int i=0; i<length(arr); i++)
    {
        arr_mengecil.contents[i] = arr.contents[i];
        arr_membesar.contents[i] = arr.contents[i];
    }

    sort(&arr_mengecil, false);
    sort(&arr_membesar, true);

    int monotonic_non_des = 1; // kecil ke besar
    int monotonic_non_asc = 1; // besar ke kecil
    int statik = 1;
    int non_mono = 1;

    for  (int i=0; i<length(arr); i++)
    {
        if (arr.contents[i] != arr_mengecil.contents[i])
        {
            monotonic_non_asc = 0;
        }
        if (arr.contents[i] != arr_membesar.contents[i])
        {
            monotonic_non_des = 0;
        }
        if (i!=0 && arr.contents[i] != arr.contents[i-1])
        {
            statik = 0;
        }
    }
    // printf("%d %d %d %d\n", monotonic_non_des, monotonic_non_asc, statik, non_mono);

    if (monotonic_non_des || monotonic_non_asc || statik)
    {
        non_mono = 0;
    }
    // printf("%d %d %d %d\n", monotonic_non_des, monotonic_non_asc, statik, non_mono);

    if (non_mono)
    {
        printf("Non-monotonic List\n");
    }
    if (statik)
    {
        printf("Static Monotonic List\n");
    }
    else
    {
        if (monotonic_non_asc)
        {
            printf("Non-ascending Monotonic List\n");
        }
        if (monotonic_non_des)
        {
            printf("Non-descending Monotonic List\n");
        }
    }

    return 0;
}
