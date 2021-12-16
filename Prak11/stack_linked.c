// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 4 November 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Pra Praktikum 11 - stack_linked.c

#include "stack_linked.h"
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

// Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL
boolean isEmpty(Stack s)
{
    return ADDR_TOP(s)==NULL;
}

// I.S. sembarang
// F.S. Membuat sebuah stack s yang kosong
void CreateStack(Stack *s)
{
    ADDR_TOP(*s) = NULL;
}

// Menambahkan x sebagai elemen Stack s
// I.S. s mungkin kosong, x terdefinisi
// F.S. x menjadi Top yang baru jika alokasi x berhasil,
//      jika tidak, s tetap
// Pada dasarnya adalah operasi insertFirst pada list linier
void push(Stack *s, ElType x)
{
    Address curr;
    curr = newNode(x);

    if (curr != NULL)
    {
        NEXT(curr) = ADDR_TOP(*s);
        ADDR_TOP(*s) = curr;
    }
}

// Menghapus Top dari Stack s
// I.S. s tidak kosong
// F.S. x adalah nilai elemen Top yang lama,
//      elemen Top yang lama didealokasi
// Pada dasarnya adalah operasi deleteFirst pada list linier
void pop(Stack *s, ElType *x)
{
    Address curr;
    *x = TOP(*s);
    curr = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(curr) = NULL;
    free(curr);
}
