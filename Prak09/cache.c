// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 28 Oktober 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Praktikum 9 - cache.c

#include <stdio.h>
#include "list_linked.h"
#include "node.h"

int main()
{
    int len, n;
    scanf("%d %d", &len, &n);

    List l;
    CreateList(&l);

    for(int i = 0; i < len; i++)
    {
        insertLast(&l, i+1);
    }

    while(n--)
    {
        int temp;
        scanf("%d", &temp);

        int avaibility = indexOf(l, temp);

            int deleted;
        if(avaibility != IDX_UNDEF)
        {
            printf("hit ");
            deleteAt(&l, avaibility, &deleted);
            insertFirst(&l, deleted);
            displayList(l);
            puts("");
        }
        else
        {
            deleteLast(&l, &deleted);
            insertFirst(&l, temp);
            printf("miss ");
            displayList(l);
            puts("");
        }
    }
}
