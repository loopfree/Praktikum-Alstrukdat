// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 16 September 2021
// Topik Praktikum  : ADT List Dinamis
// Deskripsi        : Praktikum 4 - listdinpos.c

#include "boolean.h"
#include "listdinpos.h"

#include <stdio.h>
#include <stdlib.h>

// I.S. l sembarang, capacity > 0
// F.S. Terbentuk list l kosong dengan kapasitas capacity + 1. Note (tidak ada + 1) typo: perubahan dari asisten
// Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF
void CreateListDin(ListDin *l, int capacity)
{
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int *) malloc(capacity * sizeof(int));
    for (int i=0; i<capacity; i++)
    {
        ELMT(*l,i) = VAL_UNDEF;
    }
}

// I.S. l terdefinisi;
// F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0
void dealocate(ListDin *l)
{
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}

// Mengirimkan banyaknya elemen efektif list
// Mengirimkan nol jika list kosong
int length(ListDin l)
{
    int ans;
    int i;
    ans = 0;
    i = 0;

    while(i<CAPACITY(l) && ELMT(l,i)!=VAL_UNDEF)
    {
        ans += 1;
        i += 1;
    }
    return ans;
}

// Prekondisi : List l tidak kosong
// Mengirimkan indeks elemen l terakhir
IdxType getLastIdx(ListDin l)
{
    return (length(l)-1);
}

// Mengirimkan true jika i adalah indeks yang
// valid utk ukuran list
// yaitu antara indeks yang terdefinisi utk container
boolean isIdxValid(ListDin l, IdxType i)
{
    return (i>=0 && i<CAPACITY(l));
}

// Mengirimkan true jika i adalah indeks yang
// terdefinisi utk list
// yaitu antara 0..getLastIdx(l)
boolean isIdxEff(ListDin l, IdxType i)
{
    return (i>=0 && i<=getLastIdx(l));
}

// Mengirimkan true jika list l kosong,
// mengirimkan false jika tidak
boolean isEmpty(ListDin l)
{
    return (length(l)==0);
}

// Mengirimkan true jika list l penuh,
// mengirimkan false jika tidak
boolean isFull(ListDin l)
{
    return (length(l)==CAPACITY(l));
}

// I.S. l sembarang dan sudah dialokasikan sebelumnya
// F.S. List l terdefinisi
// Proses : membaca banyaknya elemen l dan mengisi nilainya
// 1. Baca banyaknya elemen diakhiri enter, misalnya N
//    Pembacaan diulangi sampai didapat N yang benar yaitu
//    0 <= N <= CAPACITY(l)
//    Jika N tidak valid, tidak diberikan pesan kesalahan
// 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali:
//    Baca elemen mulai dari indeks
//    IdxMin satu per satu diakhiri enter
//    Jika N = 0; hanya terbentuk l kosong
void readList(ListDin *l)
{
    int N;
    N = -1;

    while (!(0<=N && N<=CAPACITY(*l)))
    {
        scanf("%d",&N);
    }

    if  (N>0)
    {
        for (int i=0; i<N; i++)
        {
            scanf("%d", &ELMT(*l,i));
        }
    }
    /*
    else
    {
        length(*l) = 0;
    }
    */

    return;
}

// Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
// antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
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
        for (int i=0; i<length(l); i++)
        {
            printf("%d", ELMT(l, i));

            if (i!=length(l)-1)
            {
                printf(",");
            }
        }
    }
    printf("]");
    return;
}

// Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong
//              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0
// Jika plus = true, mengirimkan  l1+l2,
// yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan
// Jika plus = false, mengirimkan l1-l2,
// yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    ListDin l3;
    CreateListDin(&l3, CAPACITY(l1));

    if (plus==true)
    {
        for (int i=0; i<length(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    if (plus==false)
    {
        for (int i=0; i<length(l1); i++)
        {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return l3;
}

// Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama
boolean isListEqual(ListDin l1, ListDin l2)
{
    boolean ans = (length(l1)==length(l2));

    if (ans)
    {
        for (int i=0; i<length(l1); i++)
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

// Search apakah ada elemen list l yang bernilai val
// Jika ada, menghasilkan indeks i terkecil,
// dengan elemen ke-i = val
// Jika tidak ada, mengirimkan VAL_UNDEF
// Menghasilkan indeks tak terdefinisi (VAL_UNDEF)
// jika list l kosong
// Skema Searching yang digunakan bebas
IdxType indexOf(ListDin l, ElType val)
{
    int ans = VAL_UNDEF;
    if (!isEmpty(l))
    {
        for (int i=0; i<length(l); i++)
        {
            if (ELMT(l,i) == val)
            {
                ans = i;
                break;
            }
        }
    }
    return ans;
}

// I.S. List l tidak kosong
// F.S. max berisi nilai maksimum l;
//      min berisi nilai minimum l
void extremes(ListDin l, ElType *max, ElType *min)
{
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (int i=0; i<length(l); i++)
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
// F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama)
// Proses : Menyalin isi lIn ke lOut
void copyList(ListDin lIn, ListDin *lOut)
{
    ListDin (ans);
    CreateListDin(&ans, CAPACITY(lIn));

    for (int i=0; i<length(lIn); i++)
    {
        ELMT(ans,i) = ELMT(lIn,i);
    }
    dealocate(lOut);
    *lOut = ans;
}

// Menghasilkan hasil penjumlahan semua elemen l
ElType sumList(ListDin l)
{
    int ans = 0;
    if (!isEmpty(l))
    {
        for (int i=0; i<length(l); i++)
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
        for (int i=0; i<length(l); i++)
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
    for (int i=0; i<length(l); i++)
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
// Proses : Mengurutkan l dengan salah satu algoritma sorting,
// algoritma bebas
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

// Proses: Menambahkan X sebagai elemen terakhir list
// I.S. List l boleh kosong, tetapi tidak penuh
// F.S. val adalah elemen terakhir l yang baru
void insertLast(ListDin *l, ElType val)
{
    ELMT(*l, length(*l)) = val;
}

// Proses : Menghapus elemen terakhir list
// I.S. List tidak kosong
// F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
//      Banyaknya elemen list berkurang satu
//      List l mungkin menjadi kosong
void deleteLast(ListDin *l, ElType *val)
{
    *val = ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1) = VAL_UNDEF;
    return;
}

// Proses : Menambahkan kapasitas sebanyak num
// I.S. List sudah terdefinisi
// F.S. Ukuran list bertambah sebanyak num
void growList(ListDin *l, int num)
{
    CAPACITY(*l) += num;
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}

// Proses : Mengurangi kapasitas sebanyak num
// I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num.
// F.S. Ukuran list berkurang sebanyak num.
void shrinkList(ListDin *l, int num)
{
    CAPACITY(*l) -= num;
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}

// Proses : Mengurangi kapasitas sehingga nEff = Capacity
// I.S. List tidak kosong
// F.S. Ukuran Capacity = nEff
void compactList(ListDin *l)
{
    CAPACITY(*l) = length(*l);
    BUFFER(*l) = (int *) realloc (BUFFER(*l), sizeof(int) *  CAPACITY(*l));
}
