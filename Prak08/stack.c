// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 16 Oktober 2021
// Topik Praktikum  : ADT Stack
// Deskripsi        : Pra Praktikum 8 - stack.c

#include "boolean.h"
#include "stack.h"

#include <stdio.h>

// I.S. sembarang;
// F.S. Membuat sebuah stack S kosong dengan kondisi sbb:
// - Index top bernilai IDX_UNDEF
// Proses : Melakukan alokasi, membuat sebuah s kosong
void CreateStack(Stack *s)
{
    Stack makeStack;
    IDX_TOP(makeStack) = IDX_UNDEF;

    *s = makeStack;
}

// Mengirim true jika s kosong: lihat definisi di atas
boolean isEmpty(Stack s)
{
    return (IDX_TOP(s)==IDX_UNDEF);
}

// Mengirim true jika tabel penampung nilai s stack penuh
boolean isFull(Stack s)
{
    return (IDX_TOP(s)==CAPACITY-1);
}

// Menambahkan val sebagai elemen Stack s
// I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh
// F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1
void push(Stack *s, ElType val)
{
    IDX_TOP(*s) += 1;
    TOP(*s) = val;
}

// Menghapus val dari Stack s
// I.S. s tidak mungkin kosong
// F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1
void pop(Stack *s, ElType *val)
{
    *val = TOP(*s);
    IDX_TOP(*s) -= 1;
}
