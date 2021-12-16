// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 30 September 2021
// Topik Praktikum  : ADT Queue
// Deskripsi        : Pra Praktikum 7 - queue.h

#include "boolean.h"
#include "queue.h"

// I.S. sembarang
// F.S. Sebuah q kosong terbentuk dengan kondisi sbb:
// - Index head bernilai IDX_UNDEF
// - Index tail bernilai IDX_UNDEF
// Proses : Melakukan alokasi, membuat sebuah q kosong
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

// Mengirim true jika q kosong: lihat definisi di atas
boolean isEmpty(Queue q)
{
    return (IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF);
}

// Mengirim true jika tabel penampung elemen q sudah penuh
// yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1
boolean isFull(Queue q)
{
    return (IDX_HEAD(q)==0 && IDX_TAIL(q)==CAPACITY-1);
}

// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong.
int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

// Proses: Menambahkan val pada q dengan aturan FIFO
// I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh
// F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
//      Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
//      menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru
void enqueue(Queue *q, ElType val)
{
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else
    {
        IDX_TAIL(*q) += 1;
        TAIL(*q) = val;
    }

    if (IDX_TAIL(*q)==CAPACITY-1)
    {
        int mundur = IDX_HEAD(*q);
        int temp = mundur;
        for (int i=0; i < length(*q); i++)
        {
            (*q).buffer[i] = (*q).buffer[i+temp];
        }
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) -= mundur;
    }
}

// Proses: Menghapus val pada q dengan aturan FIFO
// I.S. q tidak mungkin kosong
// F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
//      q mungkin kosong
void dequeue(Queue *q, ElType *val)
{
    if (IDX_HEAD(*q)==IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        *val = HEAD(*q);
        IDX_HEAD(*q) += 1;
    }
}

// Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
// siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
// karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter
// I.S. q boleh kosong
// F.S. Jika q tidak kosong: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika Queue kosong : menulis []
void displayQueue(Queue q)
{
    printf("[");

    if (!isEmpty(q))
    {
        if (length(q)==1)
        {
            printf("%d", HEAD(q));
        }
        else
        {
            int idx = IDX_HEAD(q);
            while (idx < IDX_TAIL(q))
            {
                printf("%d,", q.buffer[idx]);
                idx += 1;
            }
            printf("%d", TAIL(q));
        }
    }

    printf("]");
}



