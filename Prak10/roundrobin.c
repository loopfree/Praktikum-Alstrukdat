// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 4 November 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Praktikum 10 - roundrobin.c

#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "list_circular.h"

// Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
// - jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
// - jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar
// Jika l kosong, cetak "List kosong"
// I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
// L terdefinisi, mungkin kosong.
// F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong.
void deleteRR (List *l, ElType tQ) {
    if(isEmpty(*l)) {
        printf("List kosong\n");
        return;
    }

    ElType lastData;
    deleteLast(l, &lastData);
    if(lastData > tQ) {
        insertFirst(l, lastData - tQ);
        printf("%d\n", tQ);
    } else {
        printf("%d\n", lastData);
    }
}

// Menghasilkan nilai rata-rata elemen l. l tidak kosong.
float average (List l) {
    float value = 0;
    float count = 0;
    Address temp = FIRST(l);
    if(temp != NULL) {
        value = INFO(temp);
        count++;
    }
    temp = NEXT(temp);
    while(temp != FIRST(l)) {
        value += INFO(temp);
        count++;
        temp = NEXT(temp);
    }

    return value / count;
}

int main() {
    List l;
    CreateList(&l);
    char op;
    ElType input;
    int tq;
    do
    {
        scanf("%d", &tq);
        getchar();
    }while(tq <= 0);
    do
    {
        scanf("%c", &op);
        getchar();
        switch(op) {
        case 'A':
            scanf("%d", &input);
            getchar();
            if(input > 0) {
                insertFirst(&l, input);
            }
            break;
        case 'D':
            deleteRR(&l, tq);
            break;
        case 'F':
            if(!isEmpty(l)) {
                printf("%.2f\n", average(l));
            } else {
                printf("Proses selesai\n");
            }
            break;
        default:
            printf("Kode salah\n");
        }
    }while(op != 'F');
}
