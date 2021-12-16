// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 30 September 2021
// Topik Praktikum  : ADT Queue
// Deskripsi        : Praktikum 7 - antrianKereta.c

#include "queue.h"

#include <stdio.h>

// Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong
float avgElmt (Queue Q)
{
    float total = 0;
    int l = length(Q);

    // printf("%d and %d", IDX_HEAD(Q), IDX_TAIL(Q));
    for (int i=IDX_HEAD(Q); i<=IDX_TAIL(Q); i++)
    {
        total += (float)Q.buffer[i];
    }

    // printf("%f", total / (float)l);

    return  total / (float)l;
}


int main()
{
    Queue q;
    CreateQueue(&q);

    while (true)
    {
        int cmd;
        int time;
        int temp;

        scanf("%d", &cmd);
        getchar();
        if (cmd==0)
        {
            break;
        }

        if (cmd==1)
        {
            scanf("%d", &time);
            getchar();
            if (isFull(q))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&q, time);
            }
        }
        if (cmd==2)
        {
            if (isEmpty(q))
            {
                printf("Queue kosong\n");
            }
            else
            {
                dequeue(&q, &temp);
            }
        }
    }
    // printf("out");
    if (length(q)==0)
    {
        printf("0\n");
        printf("Tidak bisa dihitung\n");
    }
    else
    {
        printf("%d\n", length(q));
        printf("%.2f\n", avgElmt(q));
    }

    return 0;
}
