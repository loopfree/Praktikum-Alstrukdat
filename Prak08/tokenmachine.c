// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 30 September 2021
// Topik Praktikum  : ADT Mesin Kata
// Deskripsi        : Praktikum 6 - tokenmachine.c

#include "boolean.h"
#include "charmachine.h"
#include "tokenmachine.h"

#include <stdio.h>

/* Token Machine State */
boolean endToken;
Token currentToken;

// Mengabaikan satu atau beberapa BLANK
//   I.S. : currentChar sembarang
//   F.S. : currentChar ≠ BLANK atau currentChar = MARK
void ignoreBlank()
{
    while(currentChar == BLANK && currentChar!=MARK)
    {
        adv();
    }
}

// I.S. : currentChar sembarang
// F.S. : endToken = true, dan currentChar = MARK;
//        atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
//        currentChar karakter pertama sesudah karakter terakhir Token
void startToken()
{
    start();
    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else
    {
        ignoreBlank();
        endToken = false;
        salinToken();
    }
}

// I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
// F.S. : currentToken adalah Token terakhir yang sudah diakuisisi,
//        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
//        Jika currentChar = MARK, maka endToken = true
// Proses : Akuisisi kata menggunakan procedure salinToken
void advToken()
{
    ignoreBlank();
    if (currentChar==MARK && endToken==false)
    {
        endToken = true;
    }
    else
    {
        // apabila currentChar bukan MARK, salin token
        salinToken();

        // abaikan BLANK apabila char selanjutnya adalah BLANK
        ignoreBlank();
    }
}

// Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
//  I.S. : currentChar adalah karakter pertama dari Token
//  F.S. : currentToken berisi Token yang sudah diakuisisi;
//         currentChar = BLANK atau currentChar = MARK;
//         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//         Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
void salinToken()
{
    int temp;
    int n = 0;

    // sesuai soal
    int tokenVal = -1;

    // menghitung panjang dari suatu kumpulan char
    int length = 0;

    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else if (currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/' || currentChar=='^')
    {
        currentToken.tkn = currentChar;
        currentToken.val = tokenVal;
        adv();
    }
    else
    {
        // Membaca 1 per 1 dari suatu string lalu konversi ke angka
        currentToken.tkn = 'b';
        while (currentChar!=BLANK && currentChar!=MARK && length<CAPACITY)
        {
            temp = currentChar - '0';
            n = n*10 + temp;
            length += 1;
            adv();
        }
        currentToken.val = n;
    }
}

