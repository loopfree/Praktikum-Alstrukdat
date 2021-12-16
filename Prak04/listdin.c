// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 14 September 2021
// Topik Praktikum  : ADT List Dinamis
// Deskripsi        : Pra Praktikum 4 - listdin.c

#include "boolean.h"
#include "listdin.h"

#include <stdio.h>
#include <stdlib.h>

// I.S. l sembarang, capacity > 0
// F.S. Terbentuk list dinamis l kosong
//      dengan kapasitas capacity
void CreateListDin(ListDin *l, int capacity)
{
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int *) malloc(capacity * sizeof(int));
    return;
}

// I.S. l terdefinisi;
// F.S. (l) dikembalikan ke system, CAPACITY(l)=0;
//      NEFF(l)=0
void dealocate(ListDin *l)
{
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

// Mengirimkan banyaknya elemen efektif list
// Mengirimkan nol jika list l kosong
int length(ListDin l)
{
    return (NEFF(l));
}

// Prekondisi : List l tidak kosong
// Mengirimkan indeks elemen l terakhir
IdxType getLastIdx(ListDin l)
{
    return (NEFF(l)-1);
}

// Mengirimkan true jika i adalah
// indeks yang valid utk kapasitas list l
// yaitu antara indeks yang terdefinisi utk container
boolean isIdxValid(ListDin l, int i)
{
    return (i>=0 && i<CAPACITY(l));
}

// Mengirimkan true jika i adalah indeks yang
// terdefinisi utk list
// yaitu antara 0..NEFF(l)
boolean isIdxEff(ListDin l, IdxType i)
{
    return (i>=0 && i<NEFF(l));
}

// Mengirimkan true jika list l kosong,
// mengirimkan false jika tidak
boolean isEmpty(ListDin l)
{
    return (NEFF(l) == 0);
}

// Mengirimkan true jika list l penuh,
// mengirimkan false jika tidak
boolean isFull(ListDin l)
{
    return (NEFF(l) == CAPACITY(l));
}

// I.S. l sembarang dan sudah dialokasikan sebelumnya
// F.S. List l terdefinisi
// Proses : membaca banyaknya elemen l dan mengisi nilainya
// 1. Baca banyaknya elemen diakhiri enter, misalnya N
//    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l)
//    Jika N tidak valid, tidak diberikan pesan kesalahan
// 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
//    0 satu per satu diakhiri enter
//    Jika N = 0; hanya terbentuk l kosong
void readList(ListDin *l)
{
    int N;
    int valid = 0;

    while (valid==0)
    {
        scanf("%d", &N);
        //printf("\n");
        if (N>=0 && N<=CAPACITY(*l))
        {
            valid = 1;
        }
    }

    if (N > 0)
    {
        NEFF(*l) = N;
        for (int i=0; i < NEFF(*l); i++)
        {
            scanf("%d", &ELMT(*l, i));
            //printf("\n");
        }
    }
    else
    {
        NEFF(*l) = 0;
    }
}

// Proses : Menuliskan isi list dengan traversal,
// list ditulis di antara kurung siku;
// antara dua elemen dipisahkan dengan separator "koma",
// tanpa tambahan karakter di depan,
// di tengah, atau di belakang, termasuk spasi dan enter
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30
// akan dicetak: [1,20,30]
// Jika list kosong : menulis []
void displayList(ListDin l)
{
    printf("[");
    if (!isEmpty(l))
    {
        for (int i=0; i<NEFF(l); i++)
        {
            printf("%d", ELMT(l, i));

            if (i!=NEFF(l)-1)
            {
                printf(",");
            }
        }
    }
    printf("]");
    return;
}

// Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong
// Jika plus = true, mengirimkan  l1+l2, yaitu setiap
// elemen l1 dan l2 pada indeks yang sama dijumlahkan
// Jika plus = false, mengirimkan l1-l2, yaitu setiap
// elemen l1 dikurangi elemen l2 pada indeks yang sama
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin l3;
    CreateListDin(&l3, CAPACITY(l1));
    NEFF(l3) = NEFF(l1);

    if (plus==true)
    {
        for (int i=0; i<NEFF(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    if (plus==false)
    {
        for (int i=0; i<NEFF(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return l3;
}

// Mengirimkan true jika l1 sama dengan l2 yaitu
// jika nEff l1 = l2 dan semua elemennya sama
boolean isListEqual(ListDin l1, ListDin l2)
{
    boolean ans = (NEFF(l1)==NEFF(l2));

    if (ans)
    {
        for (int i=0; i<NEFF(l1); i++)
        {
            if (ELMT(l1,i) != ELMT(l2,i))
            {
                ans = false;
                break;
            }
        }
    }

    return ans;
}

// Search apakah ada elemen List l yang bernilai val
// Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val
// Jika tidak ada, mengirimkan IDX_UNDEF
// Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong
// Skema Searching yang digunakan bebas
IdxType indexOf(ListDin l, ElType val)
{
    int ans = IDX_UNDEF;

    if (isEmpty(l))
    {
        return ans;
    }

    for (int i=0; i<NEFF(l); i++)
    {
        if ((ELMT(l,i)==val))
        {
            ans = i;
            break;
        }
    }
    return ans;
}

// I.S. List l tidak kosong
// F.S. max berisi nilai maksimum l;
//      min berisi nilai minimum l
void extremes(ListDin l, ElType *max, ElType *min)
{
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (int i=0; i<NEFF(l); i++)
    {
        if (ELMT(l,i) > *max)
        {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min)
        {
            *min = ELMT(l,i);
        }
    }
    return;
}

// I.S. lIn terdefinisi tidak kosong, lOut sembarang
// F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama)
// Proses : Menyalin isi lIn ke lOut
void copyList(ListDin lIn, ListDin *lOut)
{
    ListDin ans;
    CreateListDin(&ans, CAPACITY(lIn));
    NEFF(ans) = NEFF(lIn);

    for (int i=0; i<NEFF(ans); i++)
    {
        ELMT(ans,i) = ELMT(lIn,i);
    }
    dealocate(lOut);
    *lOut = ans;
}

// Menghasilkan hasil penjumlahan semua elemen l
// Jika l kosong menghasilkan 0
ElType sumList(ListDin l)
{
    int ans = 0;
    if (!isEmpty(l))
    {
        for (int i=0; i<NEFF(l); i++)
        {
            ans += ELMT(l,i);
        }
    }
    return ans;
}

// Menghasilkan berapa banyak kemunculan val di l
// Jika l kosong menghasilkan 0
int countVal(ListDin l, ElType val)
{
    int ans = 0;
    if (!isEmpty(l))
    {
        for (int i=0; i<NEFF(l); i++)
        {
            if (ELMT(l,i)==val)
            {
                ans += 1;
            }
        }
    }
    return ans;
}

// Menghailkan true jika semua elemen l genap.
// l boleh kosong
boolean isAllEven(ListDin l)
{
    for (int i=0; i<NEFF(l); i++)
    {
        if (ELMT(l,i)%2!=0)
        {
            return false;
        }
    }
    return true;
}

// I.S. l boleh kosong
// F.S. Jika asc = true, l terurut membesar
//      Jika asc = false, l terurut mengecil
// Proses : Mengurutkan l dengan salah satu algoritma
//          sorting, algoritma bebas
void sort(ListDin *l, boolean asc)
{
    // Menggunakan bubble sort
    if (asc)
    {
        for (int i=0; i<length(*l)-1; i++)
        {
            for (int j=0; j<length(*l)-i-1; j++)
            {
                if (ELMT(*l,j) > ELMT(*l,j+1))
                {
                    ElType temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
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
                if (ELMT(*l,j) < ELMT(*l,j+1))
                {
                    ElType temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }
        }
    }

    return;
}

// Proses: Menambahkan val sebagai elemen terakhir list
// I.S. List l boleh kosong, tetapi tidak penuh
// F.S. val adalah elemen terakhir l yang baru
void insertLast(ListDin *l, ElType val)
{
    ELMT(*l,NEFF(*l)) = val;
    NEFF(*l) +=1 ;
    return;
}

// Proses : Menghapus elemen terakhir list
// I.S. List tidak kosong
// F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
//      Banyaknya elemen list berkurang satu
//      List l mungkin menjadi kosong
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l,NEFF(*l)-1);
    NEFF(*l) -= 1;
    return;
}

// Proses : Menambahkan capacity l sebanyak num
// I.S. List sudah terdefinisi
// F.S. Ukuran list bertambah sebanyak num
void growList(ListDin *l, int num)
{
    CAPACITY(*l) += num;
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}

// Proses : Mengurangi capacity sebanyak num
// I.S. List sudah terdefinisi, ukuran capacity > num,
//      dan nEff < capacity - num.
// F.S. Ukuran list berkurang sebanyak num.
void shrinkList(ListDin *l, int num)
{
    CAPACITY(*l) -= num;
    if (NEFF(*l) > CAPACITY(*l))
    {
        NEFF(*l) = CAPACITY(*l);
    }
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}

// Proses : Mengurangi capacity sehingga nEff = capacity
// I.S. List lidak kosong
// F.S. Ukuran nEff = capacity
void compactList(ListDin *l)
{
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}
