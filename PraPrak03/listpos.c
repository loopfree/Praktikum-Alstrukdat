// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 7 September 2021
// Topik Praktikum  : ADT List
// Deskripsi        : PraPraktikum - listpos.c

#include "boolean.h"
#include "listpos.h"

#include <stdio.h>

// I.S. l sembarang
// F.S. Terbentuk List l kosong dengan kapasitas CAPACITY
// Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF
void CreateListPos(ListPos *l)
{
    for (int i=0; i<CAPACITY; i++)
    {
        (*l).contents[i] = VAL_UNDEF;
    }
}

// Mengirimkan banyaknya elemen efektif List
// Mengirimkan nol jika List kosong
int length(ListPos l)
{
    int ans = 0;
    for (int i=0; i<CAPACITY; i++)
    {
        if (l.contents[i] != VAL_UNDEF)
        {
            ans += 1;
        }
        else
        {
            return ans;
        }
    }
    return CAPACITY;
}

// Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l
// yaitu antara indeks yang terdefinisi utk container
boolean isIdxValid(ListPos l, int i)
{
    return (i>=0 && i<=CAPACITY-1);
}

// Mengirimkan true jika i adalah indeks yang terdefinisi utk List l
// yaitu antara 0..length(l)-1
boolean isIdxEff(ListPos l, int i)
{
    return (i>=0 && i<=length(l)-1);
}

// Mengirimkan true jika List l kosong, mengirimkan false jika tidak
boolean isEmpty(ListPos l)
{
    return (length(l)==0);
}

// Mengirimkan true jika List l penuh, mengirimkan false jika tidak
boolean isFull(ListPos l)
{
    return (length(l)==CAPACITY);
}

// Proses: membaca banyaknya elemen l dan mengisi nilainya
// 1. Baca banyaknya elemen diakhiri enter, misalnya n
//    Pembacaan diulangi sampai didapat n yang benar yaitu
//    0 <= n <= CAPACITY
//    Jika n tidak valid, tidak diberikan pesan kesalahan
// 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
//    Baca elemen mulai dari indeks 0 satu per satu diakhiri enter
//    Jika n = 0; hanya terbentuk List kosong
void readList(ListPos *l)
{
    CreateListPos(l);
    int n;
    do
    {
        scanf("%d", &n);
    }while (!(n>=0 && n<CAPACITY));

    if (n > 0)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d", &(*l).contents[i]);
        }
    }

}

// Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
// siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
// karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika List kosong : menulis []
void displayList(ListPos l)
{
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");

        for(int i=0; i<length(l); i++)
        {
            printf("%d", l.contents[i]);
            if (i<length(l)-1)
            {
                printf(",");
            }
        }

        printf("]");
    }
}

// Prekondisi : l1 dan l2 berukuran sama dan tidak kosong
// Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
// indeks yang sama dijumlahkan
// Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
// elemen l2 pada indeks yang sama
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
{
    ListPos ans;
    if (plus)
    {
        for (int i=0; i<length(l1); i++)
        {
            if (l1.contents[i] != VAL_UNDEF || l2.contents[i] != VAL_UNDEF)
            {
                ans.contents[i] = l1.contents[i] + l2.contents[i];
            }
        }
    }
    else
    {
        for (int i=0; i<length(l1); i++)
        {
            if (l1.contents[i] != VAL_UNDEF || l2.contents[i] != VAL_UNDEF)
            {
                ans.contents[i] = l1.contents[i] - l2.contents[i];
            }
        }
    }
    return ans;
}

// Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2
// dan semua elemennya sama
boolean isListEqual(ListPos l1, ListPos l2)
{
    if (length(l1)!=length(l2))
    {
        return false;
    }
    else
    {
        for (int i=0; i<length(l1); i++)
        {
            if (l1.contents[i]!=l2.contents[i])
            {
                return false;
            }
        }
    }
    return true;
}

// Search apakah ada elemen List l yang bernilai val
// Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val
// Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF
// Skema Searching yang digunakan bebas
int indexOf(ListPos l, ElType val)
{
    if (length(l)==0)
    {
        return IDX_UNDEF;
    }
    else
    {
        for (int i=0; i<length(l); i++)
        {
            if (l.contents[i] == val)
            {
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

// I.S. List l tidak kosong
// F.S. Max berisi nilai terbesar dalam l
//      Min berisi nilai terkecil dalam l
void extremes(ListPos l, ElType *max, ElType *min)
{
    *max = l.contents[0];
    *min = l.contents[0];
    for (int i=0; i<length(l); i++)
    {
        if (*max < l.contents[i])
        {
            *max = l.contents[i];
        }
        if (*min > l.contents[i])
        {
            *min = l.contents[i];
        }
    }
    return;
}

// Menghailkan true jika semua elemen l genap
boolean isAllEven(ListPos l)
{
    for (int i=0; i<length(l); i++)
    {
        if (l.contents[i]%2 != 0)
        {
            return false;
        }
    }
    return true;
}

// I.S. l boleh kosong
// F.S. Jika asc = true, l terurut membesar
//      Jika asc = false, l terurut mengecil
// Proses : Mengurutkan l dengan salah satu
// algoritma sorting, algoritma bebas
void sort(ListPos *l, boolean asc)
{
    // Menggunakan bubble sort
    if (asc)
    {
        for (int i=0; i<length(*l)-1; i++)
        {
            for (int j=0; j<length(*l)-i-1; j++)
            {
                if ((*l).contents[j] > (*l).contents[j+1])
                {
                    ElType temp = (*l).contents[j];
                    (*l).contents[j] = (*l).contents[j+1];
                    (*l).contents[j+1] = temp;
                }
            }
        }
    }

    else
    {
        for (int i=0; i<length(*l)-1; i++)
        {
            for (int j=0; j<length(*l)-i-1; j++)
            {
                if ((*l).contents[j] < (*l).contents[j+1])
                {
                    ElType temp = (*l).contents[j];
                    (*l).contents[j] = (*l).contents[j+1];
                    (*l).contents[j+1] = temp;
                }
            }
        }
    }

    return;
}

// Proses: Menambahkan val sebagai elemen terakhir List
// I.S. List l boleh kosong, tetapi tidak penuh
// F.S. val adalah elemen terakhir l yang baru
void insertLast(ListPos *l, ElType val)
{
    if (isFull(*l)) // Jaga-jaga
    {
        return;
    }
    (*l).contents[length(*l)] = val;
    return;
}

// Proses : Menghapus elemen terakhir List
// I.S. List tidak kosong
// F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
//      Banyaknya elemen List berkurang satu
//      List l mungkin menjadi kosong
void deleteLast(ListPos *l, ElType *val)
{
    if (isEmpty(*l)) // Jaga-jaga
    {
        return;
    }

    *val = (*l).contents[length(*l)-1];
    (*l).contents[length(*l)-1] = VAL_UNDEF;
    return;
}

