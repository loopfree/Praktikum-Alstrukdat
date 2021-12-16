// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 4 November 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Pra Praktikum 11 - queue_linked.c

#include "queue_linked.h"
#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>

// Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
// atau
// NULL jika alokasi gagal
Address newNode(ElType x)
{
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

// Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL
boolean isEmpty(Queue q)
{
    return (ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL);
}

// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong
int length(Queue q)
{
    int len = 0;
    Address curr;

    if (!isEmpty(q))
    {
        curr = ADDR_HEAD(q);
        while (curr != NULL)
        {
            len += 1;
            curr = NEXT(curr);
        }
    }
    return len;
}

// I.S. sembarang
// F.S. Sebuah q kosong terbentuk
void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

// Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
//         jika alokasi berhasil; jika alokasi gagal q tetap
// Pada dasarnya adalah proses insertLast
// I.S. q mungkin kosong
// F.S. x menjadi Tail, Tail "maju"
void enqueue(Queue *q, ElType x)
{
    Address curr;
    curr = newNode(x);

    if (curr==NULL)
    {
        return;
    }

    if (curr != NULL)
    {
        if (isEmpty(*q))
        {
            ADDR_HEAD(*q) = curr;
        }
        else
        {
            NEXT(ADDR_TAIL(*q)) = curr;
        }
        ADDR_TAIL(*q) = curr;
    }
}

// Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD
// Pada dasarnya operasi deleteFirst
// I.S. q tidak mungkin kosong
// F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur"
void dequeue(Queue *q, ElType *x)
{
    Address curr;
    *x = HEAD(*q);
    curr = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));

    if (ADDR_HEAD(*q)==NULL)
    {
        ADDR_TAIL(*q) = NULL;
    }

    NEXT(curr) = NULL;
    free(curr);
}
