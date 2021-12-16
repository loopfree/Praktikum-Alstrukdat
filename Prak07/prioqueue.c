#include "prioqueue.h"
#include "boolean.h"

#include <stdlib.h>
#include <stdio.h>

// I.S. sembarang
// F.S. Sebuah pq kosong terbentuk dengan kondisi sbb:
// - Index head bernilai IDX_UNDEF
// - Index tail bernilai IDX_UNDEF
// Proses : Melakukan alokasi, membuat sebuah pq kosong
void CreatePrioQueue(PrioQueue *pq)
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

// Mengirim true jika pq kosong: lihat definisi di atas
boolean isEmpty(PrioQueue pq)
{
    return (IDX_HEAD(pq)==IDX_UNDEF && IDX_TAIL(pq)==IDX_UNDEF);
}

// Mengirim true jika tabel penampung elemen pq sudah penuh
// yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1
boolean isFull(PrioQueue pq)
{
    return (IDX_HEAD(pq)==0 && IDX_TAIL(pq)==CAPACITY-1);
}

// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong.
int length(PrioQueue pq)
{
    if (isEmpty(pq))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(pq) - IDX_HEAD(pq) + 1);
    }
}

// Proses: Menambahkan val pada pq dengan aturan FIFO
// I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh
// F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
//      Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
//      menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru
void enqueue(PrioQueue *pq, ElType val)
{
    if (isEmpty(*pq))
    {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    }
    else
    {
        //cari lokasi penempatan
        int placement_idx = 0;
        for(int i = IDX_TAIL(*pq); i >= IDX_HEAD(*pq); --i)
        {
            if(val.score < pq->buffer[i].score)
            {
                placement_idx = i;
            }
        }

        //shifting elemen
        for(int i = IDX_TAIL(*pq)+1; i > placement_idx; --i)
        {
            pq->buffer[i] = pq->buffer[i-1];
        }

        pq->buffer[placement_idx] = val;

        IDX_TAIL(*pq) += 1;
    }

    if (IDX_TAIL(*pq)==CAPACITY-1)
    {
        int mundur = IDX_HEAD(*pq);
        int temp = mundur;
        for (int i=0; i < length(*pq); i++)
        {
            (*pq).buffer[i] = (*pq).buffer[i+temp];
        }
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) -= mundur;
    }

}

// Proses: Menghapus val pada q dengan aturan FIFO
// I.S. pq tidak mungkin kosong
// F.S. val = nilai elemen HEAD pd
// I.S., HEAD dan IDX_HEAD "mundur";
// pq mungkin kosong
void dequeue(PrioQueue * pq, ElType *val)
{
    if (IDX_HEAD(*pq)==IDX_TAIL(*pq))
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
    {
        *val = HEAD(*pq);
        IDX_HEAD(*pq) += 1;
    }
}
