// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 24 Oktober 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Pra Praktikum 9 - list_linked.c

#include "boolean.h"
#include "list_linked.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>

// I.S. sembarang
// F.S. Terbentuk list kosong
void CreateList(List *l)
{
    FIRST(*l) = NULL;
}

// Mengirim true jika list kosong
boolean isEmpty(List l)
{
    return FIRST(l)==NULL;
}

// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Mengembalikan nilai elemen l pada indeks idx
ElType getElmt(List l, int idx)
{
    Address curr = FIRST(l);
    int i = 0;
    while (curr != NULL)
    {
        if (i == idx)
        {
            return INFO(curr);
        }
        i += 1;
        curr = NEXT(curr);
    }
}

// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Mengubah elemen l pada indeks ke-idx menjadi val
void setElmt(List *l, int idx, ElType val)
{
    Address curr = FIRST(*l);
    int i = 0;
    while (curr != NULL)
    {
        if (i == idx)
        {
            INFO(curr) = val;
        }
        i += 1;
        curr = NEXT(curr);
    }
}

// I.S. l, val terdefinisi
// F.S. Mencari apakah ada elemen list l yang bernilai val
// Jika ada, mengembalikan indeks elemen pertama l yang bernilai val
// Mengembalikan IDX_UNDEF jika tidak ditemukan
int indexOf(List l, ElType val)
{
    Address curr= FIRST(l);
    boolean found = false;
    int ans = IDX_UNDEF;
    if (isEmpty(l))
    {
        return ans;
    }
    else
    {
        int i = 0;
        while (curr != NULL && !found)
        {
            if (INFO(curr)==val)
            {
                ans = i;
                found = true;
            }
            i += 1;
            curr = NEXT(curr);
        }
        return ans;
    }
}

// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen pertama dengan nilai val jika alokasi berhasil.
// Jika alokasi gagal: I.S.= F.S.
void insertFirst(List *l, ElType val)
{
    Address head = newNode(val);
    if (head != NULL)
    {
        NEXT(head) = *l;
        FIRST(*l) = head;
    }
    else
    {
        FIRST(*l) = head;
    }
}

// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen list di akhir: elemen terakhir yang baru
// bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
void insertLast(List *l, ElType val)
{
    Address curr;
    Address last;

    if (isEmpty(*l))
    {
        insertFirst(l,val);
    }
    else
    {
        curr = newNode(val);
        if (curr!=NULL)
        {
            last = FIRST(*l);
            while (NEXT(last)!=NULL)
            {
                last = NEXT(last);
            }
            NEXT(last) = curr;
        }
    }
}

// I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Melakukan alokasi sebuah elemen dan
// menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i)
// yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
void insertAt(List *l, ElType val, int idx)
{
    int i = 0;
    Address curr;
    Address temp;
    if (idx==0)
    {
        insertFirst(l,val);
    }
    else
    {
        curr = newNode(val);
        if (curr!=NULL)
        {
            temp = FIRST(*l);
            while (i<idx-1)
            {
                i += 1;
                temp = NEXT(temp);
            }
            NEXT(curr) = NEXT(temp);
            NEXT(temp) = curr;
        }
    }
}

// I.S. List l tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada x
//      dan alamat elemen pertama di-dealokasi
void deleteFirst(List *l, ElType *val)
{
    Address curr = FIRST(*l);
    *val = INFO(curr);
    FIRST(*l) = NEXT(curr);
    free(curr);
}

// I.S. list tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada x
//      dan alamat elemen terakhir di-dealokasi
void deleteLast(List *l, ElType *val)
{
    Address curr = FIRST(*l);
    if(NEXT(curr) == NULL) {
        *val = INFO(curr);
        free(curr);
        *l = NULL;
    }
    else
    {
        while(NEXT(NEXT(curr)) != NULL)
        {
            curr = NEXT(curr);
        }
        *val = INFO(NEXT(curr));
        free(NEXT(curr));
        NEXT(curr) = NULL;
    }
}

// I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. val diset dengan elemen l pada indeks ke-idx.
//      Elemen l pada indeks ke-idx dihapus dari l
void deleteAt(List *l, int idx, ElType *val)
{
    int i = 0;
    Address help;
    Address curr = FIRST(*l);
    if  (idx == 0)
    {
        deleteFirst(l,val);
    }
    else
    {
        while (i<idx-1)
        {
            i += 1;
            curr = NEXT(curr);
        }
        help = NEXT(curr);
        *val = INFO(help);
        NEXT(curr) = NEXT(help);
    }
}

// I.S. List mungkin kosong
// F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika list kosong : menulis []
// Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah
void displayList(List l)
{
    printf("[");
    if (!isEmpty(l))
    {
        Address  curr = FIRST(l);
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

// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong
int length(List l)
{
    int len = 0;
    if (isEmpty(l))
    {
        return len;
    }
    else
    {
        Address check = FIRST(l);
        while (check != NULL)
        {
            len += 1;
            check = NEXT(check);
        }
        return len;
    }
}

// I.S. l1 dan l2 sembarang
// F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2
// (Koreksi: l1 dan l2 tidak dikosongkan setelah proses)
// Konkatenasi dua buah list : l1 dan l2
// menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan).
// Tidak ada alokasi/dealokasi pada prosedur ini
List concat(List l1, List l2)
{
    List l3;
    CreateList(&l3);
    Address head;
    head = FIRST(l1);
    while (head!=NULL)
    {
        insertLast(&l3, INFO(head));
        head = NEXT(head);
    }
    head = FIRST(l2);
    while (head!=NULL)
    {
        insertLast(&l3, INFO(head));
        head = NEXT(head);
    }
    return l3;
}
