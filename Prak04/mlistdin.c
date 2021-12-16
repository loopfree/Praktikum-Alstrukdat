// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 16 September 2021
// Topik Praktikum  : ADT List Dinamis
// Deskripsi        : Praktikum 4 - mlistdin.c

#include "boolean.h"
#include "listdin.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cap;
    scanf("%d", &cap);

    ListDin arr;
    CreateListDin(&arr,cap);
    readList(&arr);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int op;
        scanf("%d", &op);

        /*
        program membaca num dan menambahkan num menjadi
        elemen terakhir list
        */
        if (op == 1)
        {
            int val;
            scanf("%d", &val);
            if (isFull(arr))
            {
                printf("list sudah penuh\n");
            }
            else
            {
                insertLast(&arr,val);
                printf("%d ", CAPACITY(arr));
                displayList(arr);
                printf("\n");
            }
        }

        /*
        program membaca num dan memperbesar list,
        bertambah sebesar num
        */
        if (op == 2)
        {
            int val;
            scanf("%d", &val);
            growList(&arr,val);
            printf("%d ", CAPACITY(arr));
            displayList(arr);
            printf("\n");
        }

        /*
        program membaca num dan mengecilkan list,
        berkurang sebesar num
        */
        if (op == 3)
        {
            int val;
            scanf("%d", &val);

            if (val > CAPACITY(arr))
            {
                printf("list terlalu kecil\n");
            }
            else
            {
                shrinkList(&arr,val);
                printf("%d ", CAPACITY(arr));
                displayList(arr);
                printf("\n");
            }
        }

        /*
        ubah kapasitas list menjadi sama dengan
        nEff list (compact)
        */
        if (op == 4)
        {
            compactList(&arr);
            printf("%d ", CAPACITY(arr));
            displayList(arr);
            printf("\n");
        }
    }
}
