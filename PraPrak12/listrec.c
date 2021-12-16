// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 11 November 2021
// Topik Praktikum  : ADT List Rekursif
// Deskripsi        : Pra Praktikum 12 - listrec.c

#include "boolean.h"
#include "listrec.h"

#include <stdio.h>
#include <stdlib.h>

// Mengirimkan address hasil alokasi sebuah elemen
// Jika alokasi berhasil, maka address tidak NULL, dan misalnya
// menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL
// Jika alokasi gagal, mengirimkan NULL
Address newNode(ElType x)
{
    Address newn;
    newn = (Address) malloc (sizeof(Node));

    if (newn != NULL)
    {
        INFO(newn) = x;
        NEXT(newn) = NULL;
    }

    return newn;
}

// Mengirimkan true jika l kosong dan false jika l tidak kosong
boolean isEmpty(List l)
{
    return l==NULL;
}

// Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong
int isOneElmt(List l)
{
    if (l!=NULL && NEXT(l)==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Mengirimkan elemen pertama sebuah list l yang tidak kosong
ElType head(List l)
{
    return INFO(l);
}

// Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong
List tail(List l)
{
    if (!isEmpty(l))
    {
        return NEXT(l);
    }
    else
    {
        return NULL;
    }
}

// Mengirimkan list l dengan tambahan e sebagai elemen pertamanya.
// e dialokasi terlebih dahulu.
// Jika alokasi gagal, mengirimkan l
List konso(List l, ElType e)
{
    Address front;
    front = newNode(e);
    if (front != NULL)
    {
        NEXT(front) = l;
        return front;
    }
    else
    {
        return l;
    }
}

// Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya
// e harus dialokasi terlebih dahulu
// Jika alokasi e gagal, mengirimkan L
List konsb(List l, ElType e)
{
    if (isEmpty(l))
    {
        return newNode(e);
    }
    else
    {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

// Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong
int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

// I.S. List l mungkin kosong
// F.S. Jika list tidak kosong, nilai list dicetak ke bawah
//      Dipisahkan dengan newline (\n) dan diakhiri dengan newline
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
//  1
//  20
//  30
// Jika list kosong, tidak menuliskan apa-apa
void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", INFO(l));
        displayList(tail(l));
    }
}
