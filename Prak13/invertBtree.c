// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 25 November 2021
// Topik Praktikum  : ADT Tree
// Deskripsi        : Praktikum 13 - invertBtree.c

#include "bintree.h"

// void invertBtree(BinTree *p)
// I.S. Pohon p terdefinisi
// F.S. Pohon p diflip secara vertikal
//      Contoh:
/*
           1
         2   5
        3 4 6
*/
//      Menjadi:
/*
           1
         5   2
          6 4 3
*/

void invertBtree(BinTree *p)
{
    if (!isTreeEmpty(*p))
    {
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
        // Switch dari kiri ke kanan dan sebaliknya
        *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
    }
}
