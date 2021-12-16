// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 26 September 2021
// Topik Praktikum  : ADT Mesin Kata
// Deskripsi        : Pra Praktikum 6 - wordmachine.c

#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"

#include <stdio.h>

/* Word Engine State */
boolean endWord;
Word currentWord;

/* Char Engine State */
char currentChar;
boolean eot;

// Mengabaikan satu atau beberapa BLANK
//   I.S. : currentChar sembarang
//   F.S. : currentChar ≠ BLANK atau currentChar = MARK
void ignoreBlank()
{
    while (currentChar==BLANK)
    {
        adv();
    }
}

// I.S. : currentChar sembarang
// F.S. : endWord = true, dan currentChar = MARK;
//        atau endWord = false, currentWord adalah kata
//        yang sudah diakuisisi, currentChar karakter
//        pertama sesudah karakter terakhir kata
void startWord()
{
    start();

    if (eot)
    {
        endWord = true;
    }
    else
    {
        ignoreBlank();
        endWord = false;
        copyWord();
    }
}

// I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
// F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
//        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
//        Jika currentChar = MARK, endWord = true.
//        Proses : Akuisisi kata menggunakan procedure copyWord
void advWord()
{
    if (currentChar==MARK && endWord==false)
    {
        endWord = true;
    }
    else
    {
        copyWord();
        ignoreBlank();
    }
}

// Mengakuisisi kata, menyimpan dalam currentWord
// I.S. : currentChar adalah karakter pertama dari kata
// F.S. : currentWord berisi kata yang sudah diakuisisi;
//        currentChar = BLANK atau currentChar = MARK;
//        currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//        Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong
void copyWord()
{
    int idx = 0;
    while (currentChar!=BLANK && currentChar!=MARK && idx<CAPACITY)
    {
        currentWord.contents[idx] = currentChar;
        adv();
        idx += 1;
    }
    if (idx < CAPACITY)
    {
        currentWord.length = idx;
    }
    else
    {
        currentWord.length = CAPACITY;
    }
}
