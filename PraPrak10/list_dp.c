// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 29 Oktober 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Pra Praktikum 10 - list_dp.c

#include "list_dp.h"
#include "boolean.h"

#include <stdio.h>
#include <stdlib.h>

/// Definisi list :
/// List kosong : First(L) = NULL dan Last(L) = NULL
/// Setiap elemen dengan Address P dapat diacu INFO(P), Next(P), Prev(P)
/// Elemen terakhir list: Last(L)

// Mengirim true jika list kosong. Lihat definisi di atas.
boolean isEmpty (List l){
    return (FIRST(l) == NULL) && (LAST(l) == NULL);
}

// I.S. l sembarang
// F.S. Terbentuk list kosong. Lihat definisi di atas.
void CreateList(List *l)
{
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

// Mengirimkan address hasil alokasi sebuah elemen
// Jika alokasi berhasil, maka address tidak NULL.
// Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL
// Jika alokasi gagal, mengirimkan NULL.
Address allocate(ElType val)
{
    Address ans;
    ans = (Address) malloc (sizeof(Node));
    if (ans != NULL)
    {
        INFO(ans) = val;
        NEXT(ans) = NULL;
        PREV(ans) = NULL;
    }
    return ans;
}

// I.S. p terdefinisi
// F.S. p dikembalikan ke sistem
// Melakukan dealokasi/pengembalian Address P
void deallocate (Address p)
{
    free(p);
}

// Mencari apakah ada elemen list dengan INFO(P)=val
// Jika ada, mengirimkan Address elemen tersebut.
// Jika tidak ada, mengirimkan NULL
Address search(List l, ElType val)
{
    Address curr = FIRST(l);
    while (curr != NULL && INFO(curr)!=val)
    {
        curr = NEXT(curr);
    }
    return curr;
}

// I.S. List l terdefinisi
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen pertama dengan nilai X jika alokasi berhasil
void insertFirst(List *l, ElType val)
{
    Address curr = allocate(val);
    if (curr != NULL)
    {
        // NEXT(curr) = FIRST(*l);
        if (!isEmpty(*l))
        {
            PREV(FIRST(*l)) = curr;
        }
        else
        {
            LAST(*l) = curr;
        }
        NEXT(curr) = FIRST(*l);
        FIRST(*l) = curr;
    }
}

// I.S. List l terdefinisi
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen list di akhir: elemen terakhir yang baru
// bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
void insertLast(List *l, ElType val)
{
    Address curr = allocate(val);
    if (curr != NULL)
    {
        // PREV(curr) = LAST(*l);
        if (!isEmpty(*l))
        {
            NEXT(LAST(*l)) = curr;
        }
        else
        {
            FIRST(*l) = curr;
        }
        PREV(curr) = LAST(*l);
        LAST(*l) = curr;
    }
}

// I.S. pRec pasti elemen list; p sudah dialokasi
// F.S. Insert p sebagai elemen sesudah elemen beralamat pRec
void insertAfter(List *L, Address p, Address pRec)
{
    if (pRec == LAST(*L))
    {
        insertLast(L,p);
    }
    else
    {
        NEXT(p) = NEXT(pRec);
        PREV(NEXT(pRec)) = p;
        PREV(p) = pRec;
        NEXT(pRec) = p;
    }
}

// I.S. List l tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada val
//      dan alamat elemen pertama di-dealokasi
void deleteFirst(List *l, ElType *val)
{
    Address curr;
    curr = FIRST(*l);
    *val = INFO(curr);
    if (FIRST(*l)==LAST(*l))
    {
        LAST(*l) = NULL;
    }
    else
    {
        PREV(NEXT(FIRST(*l))) = NULL;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    free(curr);
}

// I.S. list l tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada val
//      dan alamat elemen terakhir di-dealokasi
void deleteLast(List *l, ElType *val)
{
    Address curr;
    curr = LAST(*l);
    *val = INFO(curr);
    if (FIRST(*l)==LAST(*l))
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(PREV(LAST(*l))) = NULL;
    }
    LAST(*l) = PREV(LAST(*l));
    free(curr);
}

// I.S. List tidak kosong. pRec adalah anggota list.
//      NEXT(pRec)!=NULL
// F.S. Menghapus NEXT(pRec):
void deleteAfter(List *l, Address *pDel, Address pRec)
{
    *pDel = NEXT(pRec);
    if ((*pDel)==FIRST(*l))
    {
        *pDel = FIRST(*l);
        FIRST(*l) = NEXT(*pDel);
        if (FIRST(*l)==NULL)
        {
            LAST(*l) = NULL;
        }
        else
        {
            PREV(FIRST(*l)) = NULL;
        }
    }
    else if ((*pDel)==LAST(*l))
    {
        *pDel = LAST(*l);
        LAST(*l) = PREV(*pDel);
        if (LAST(*l)==NULL)
        {
            FIRST(*l) = NULL;
        }
        else
        {
            NEXT(LAST(*l)) = NULL;
        }
    }
    else
    {
        PREV(NEXT(*pDel)) = pRec;
        NEXT(pRec) = NEXT(*pDel);
    }
}

// I.S. List mungkin kosong
// F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama
// ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika list kosong : menulis []
// Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah
void displayList(List l)
{
    printf("[");
    if (!isEmpty(l))
    {
        Address curr = FIRST(l);
        while (curr != NULL)
        {
            printf("%d", INFO(curr));
            curr = NEXT(curr);

            if (curr != NULL)
            {
                printf(",");
            }
        }
    }
    printf("]");
}

// I.S. List mungkin kosong
// F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir
// ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1]
// Jika list kosong : menulis []
// Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah
void displayListBackwards(List l)
{
    printf("[");
    if (!isEmpty(l))
    {
        Address curr = LAST(l);
        while (curr != NULL)
        {
            printf("%d", INFO(curr));
            curr = PREV(curr);

            if (curr != NULL)
            {
                printf(",");
            }
        }
    }
    printf("]");
}

