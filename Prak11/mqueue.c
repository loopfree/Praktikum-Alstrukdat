// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 11 November 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Praktikum 11 - mqueue.c

#include <stdio.h>
#include "queue_linked.h"

int main()
{
    int tc;
    scanf("%d", &tc);
    Queue q;
    CreateQueue(&q);
    while(tc--)
    {
        int second;
        scanf("%d", &second);
        enqueue(&q, second);
        while(HEAD(q) < second-300)
        {
            int x;
            dequeue(&q, &x);
        }
        printf("%d\n", length(q));
    }
}
