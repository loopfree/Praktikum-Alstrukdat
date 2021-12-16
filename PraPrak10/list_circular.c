// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 29 Oktober 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Pra Praktikum 10 - list_circular.c

#include "boolean.h"
#include "list_circular.h"

#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(ElmtList));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/// Definisi List Circular :
/// List kosong : FIRST(l) = NULL
/// Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P)
/// Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l)

// Mengirim true jika list kosong. Lihat definisi di atas.
boolean isEmpty(List l)
{
    return (FIRST(l)==NULL);
}

// I.S. l sembarang
// F.S. Terbentuk list kosong. Lihat definisi di atas.
void CreateList(List *l)
{
    FIRST(*l) = NULL;
}

// Mengirimkan Address hasil alokasi sebuah elemen
// Jika alokasi berhasil, maka Address tidak NULL, dan misalnya
// menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL
// Jika alokasi gagal, mengirimkan NULL
Address allocate(ElType val)
{
    Address curr;
    curr = (Address) malloc (sizeof(ElmtList));
    if (curr != NULL)
    {
        INFO(curr) = val;
        NEXT(curr) = NULL;
    }
    return curr;
}

// I.S. P terdefinisi
// F.S. P dikembalikan ke sistem
// Melakukan dealokasi/pengembalian Address P
void deallocate(Address P)
{
    free(P);
}

// Mencari apakah ada elemen list dengan INFO(P)= val
// Jika ada, mengirimkan Address elemen tersebut.
// Jika tidak ada, mengirimkan NULL
Address search(List l, ElType val)
{
    Address curr = FIRST(l);
    if (curr == NULL)
    {
        return NULL;
    }

    while (NEXT(curr) != FIRST(l) && INFO(curr) != val)
    {
        curr = NEXT(curr);
    }

    if (INFO(curr) == val)
    {
        return curr;
    }

    return NULL;
}

// Mencari apakah ada elemen list l yang beralamat p
// Mengirimkan true jika ada, false jika tidak ada
boolean addrSearch(List l, Address p)
{
    Address curr = FIRST(l);
    boolean ans = false;
    if (curr == NULL)
    {
        return ans;
    }

    while (NEXT(curr) != FIRST(l) && curr != p)
    {
        curr = NEXT(curr);
    }

    if (curr == p)
    {
        ans = true;
    }

    return ans;
}

// I.S. List l terdefinisi, mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen pertama dengan nilai val jika alokasi berhasil
// Elemen terakhir list menunjuk ke address dari elemen pertama baru list
void insertFirst(List *l, ElType val)
{
    Address curr;
    Address end;
    curr = newNode(val);
    if (curr != NULL)
    {
        if (isEmpty(*l))
        {
            NEXT(curr) = curr;
        }
        else
        {
            end = FIRST(*l);
            while (NEXT(end) != FIRST(*l))
            {
                end = NEXT(end);
            }
            NEXT(curr) = FIRST(*l);
            NEXT(end) = curr;
        }
        FIRST(*l) = curr;
    }
}

// I.S. List l terdefinisi, mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen list di akhir: elemen terakhir yang baru
// bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
// Elemen terakhir baru list menunjuk ke address dari elemen pertama list
void insertLast(List *l, ElType val)
{
    Address curr;
    Address end;

    if (isEmpty(*l))
    {
        insertFirst(l,val);
    }
    else
    {
        curr = newNode(val);
        if (curr != NULL)
        {
            end =  FIRST(*l);
            while (NEXT(end) != FIRST(*l))
            {
                end = NEXT(end);
            }
            NEXT(end) = curr;
            NEXT(curr) = FIRST(*l);
        }
    }
}

// I.S. List l tidak kosong
// F.S. val adalah elemen pertama List l sebelum penghapusan
//      Elemen list berkurang satu (mungkin menjadi kosong)
//      First element yg baru adalah suksesor elemen pertama yang lama
//      Jika list baru tidak kosong, Last element menunjuk ke First element baru
//      Jika list baru kosong, maka FIRST(*l) = NULL
//      Alamat elemen pertama list lama di-dealokasi
void deleteFirst(List *l, ElType * val)
{
    Address curr;
    Address end;

    curr = FIRST(*l);
    *val = INFO(curr);

    if (NEXT(FIRST(*l))==FIRST(*l))
    {
        FIRST(*l) = NULL;
    }
    else
    {
        end = FIRST(*l);
        while (NEXT(end)!=FIRST(*l))
        {
            end = NEXT(end);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(end) = FIRST(*l);
    }
    free(curr);
}

// I.S. List l tidak kosong
// F.S. val adalah elemen terakhir list sebelum penghapusan
//      Elemen list berkurang satu (mungkin menjadi kosong)
//      Last element baru adalah predesesor elemen terakhir yg lama, jika ada
//      Jika list baru tidak kosong, Last element baru menunjuk ke First element
//      Jika list baru kosong, maka FIRST(*l) = NULL
//      Alamat elemen terakhir list lama di-dealokasi
void deleteLast(List *l, ElType * val)
{
    Address end;
    Address prevEnd;

    end = FIRST(*l);
    prevEnd = NULL;

    while (NEXT(end)!=FIRST(*l))
    {
        prevEnd = end;
        end = NEXT(end);
    }

    if (prevEnd==NULL)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(prevEnd) = FIRST(*l);
    }
    *val = INFO(end);
    free(end);
}

// I.S. List l mungkin kosong
// F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika list kosong : menulis []
// Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah
void displayList(List l)
{
    printf("[");
    if (!isEmpty(l))
    {
        Address curr = FIRST(l);
        printf("%d", INFO(curr));

        while (NEXT(curr) != FIRST(l))
        {
            curr = NEXT(curr);
            printf(",%d", INFO(curr));
        }
    }
    printf("]");
}

