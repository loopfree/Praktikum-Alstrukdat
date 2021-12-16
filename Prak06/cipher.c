// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 30 September 2021
// Topik Praktikum  : ADT Mesin Kata
// Deskripsi        : Praktikum 6 - cipher.c

#include <stdio.h>
#include <string.h>

char caesarCipher(char c, int key)
{
    int ascii = c;

    if(c < 65 || c > 90)
    {
        return c;
    }


    ascii += key;
    while(ascii > 90)
    {
        ascii -= 26;
    }
    char ans = ascii;

    return ans;
}

int main()
{
    char sentence[500];
    scanf("%[^.]", sentence);

    //cari panjang kalimat pertama
    int len = 0;
    while(sentence[len] != ' ')
    {
        len++;
    }

    int sentenceLen = strlen(sentence);

    for(int i = 0; i < sentenceLen; i++)
    {
        sentence[i] = caesarCipher(sentence[i], len);
    }

    printf("%s.\n", sentence);
}
