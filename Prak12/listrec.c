// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 18 November 2021
// Topik Praktikum  : ADT List Rekursif
// Deskripsi        : Praktikum 12 - listrec.c

#include "boolean.h"
#include "listrec.h"

#include <stdio.h>
#include <stdlib.h>

// Mengirimkan address hasil alokasi sebuah elemen
// Jika alokasi berhasil, maka address tidak NULL, dan misalnya
// menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL
// Jika alokasi gagal, mengirimkan NULL
Address newNode(ElType x)
{
    Address newn;
    newn = (Address) malloc (sizeof(Node));

    if (newn != NULL)
    {
        INFO(newn) = x;
        NEXT(newn) = NULL;
    }

    return newn;
}

// Mengirimkan true jika l kosong dan false jika l tidak kosong
boolean isEmpty(List l)
{
    return l==NULL;
}

// Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong
int isOneElmt(List l)
{
    if (l!=NULL && NEXT(l)==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Mengirimkan elemen pertama sebuah list l yang tidak kosong
ElType head(List l)
{
    return INFO(l);
}

// Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong
List tail(List l)
{
    if (!isEmpty(l))
    {
        return NEXT(l);
    }
    else
    {
        return NULL;
    }
}

// Mengirimkan list l dengan tambahan e sebagai elemen pertamanya.
// e dialokasi terlebih dahulu.
// Jika alokasi gagal, mengirimkan l
List konso(List l, ElType e)
{
    Address front;
    front = newNode(e);
    if (front != NULL)
    {
        NEXT(front) = l;
        return front;
    }
    else
    {
        return l;
    }
}

// Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya
// e harus dialokasi terlebih dahulu
// Jika alokasi e gagal, mengirimkan L
List konsb(List l, ElType e)
{
    if (isEmpty(l))
    {
        return newNode(e);
    }
    else
    {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

// Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong
int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

// I.S. List l mungkin kosong
// F.S. Jika list tidak kosong, nilai list dicetak ke bawah
//      Dipisahkan dengan newline (\n) dan diakhiri dengan newline
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
//  1
//  20
//  30
// Jika list kosong, tidak menuliskan apa-apa
void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", INFO(l));
        displayList(tail(l));
    }
}

/** Spek Tambahan **/
/** Spek Tambahan **/
/** Spek Tambahan **/
/** Spek Tambahan **/
/** Spek Tambahan **/

// Mengirimkan nilai INFO(p) yang maksimum
ElType maxList (List l)
{
    if (isOneElmt(l))
    {
        return INFO(l);
    }
    else
    {
        if (INFO(l) > maxList(tail(l)))
        {
            return INFO(l);
        }
        else
        {
            return  maxList(tail(l));
        }
    }
}

// Mengirimkan nilai INFO(p) yang minimum
ElType minList (List l)
{
    if (isOneElmt(l))
    {
        return INFO(l);
    }
    else
    {
        if (INFO(l) < minList(tail(l)))
        {
            return INFO(l);
        }
        else
        {
            return minList(tail(l));
        }
    }
}

// Mengirimkan total jumlah elemen List l
ElType sumList (List l)
{
    if (isOneElmt(l))
    {
        return INFO(l);
    }
    else
    {
        return INFO(l) + sumList(tail(l));
    }
}

// Mengirimkan nilai rata-rata elemen list l
float averageList (List l)
{
    float ans;
    ans = sumList(l) / length(l);
    return ans;
}

// Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
// Semua elemen list baru harus dialokasi
// Jika alokasi gagal, hasilnya list kosong
List inverseList (List l)
{
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        return konsb(inverseList(tail(l)), INFO(l));
    }
}

// I.S. l mungkin kosong
// F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2
// l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
// semua elemen l yang negatif; semua dengan urutan yang sama seperti di l
// l tidak berubah: Semua elemen l1 dan l2 harus dialokasi
// Jika l kosong, maka l1 dan l2 kosong
void splitPosNeg (List l, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        *l1 = NULL;
        *l2 = NULL;
    }
    else
    {
        splitPosNeg(tail(l), l1, l2);
        if (INFO(l) >= 0)
        {
            *l1 = konso(*l1, INFO(l));
        }
        if  (INFO(l) < 0)
        {
            *l2 = konso(*l2, INFO(l));
        }
    }
}

// I.S. l dan x terdefinisi, l1 dan l2 sembarang.
// F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
// kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
// l1, dengan urutan kemunculan yang sama.
void splitOnX (List l, ElType x, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        *l1 = NULL;
        *l2 = NULL;
    }
    else
    {
        splitOnX(tail(l), x, l1, l2);
        if (INFO(l) < x)
        {
            *l1 = konso(*l1, INFO(l));
        }
        else
        {
            *l2 = konso(*l2, INFO(l));
        }
    }
}

// Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2
// Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l:
// l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i]
// l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
// dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
// urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2|
// Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4]
// l1>l2: kebalikan dari l1<l2
int compareList (List l1, List l2)
{
    if (isEmpty(l1) && isEmpty(l2))
    {
        return 0;
    }
    if (isEmpty(l1) && !isEmpty(l2))
    {
        return -1;
    }
    if (!isEmpty(l1) && isEmpty(l2))
    {
        return 1;
    }

    else
    {
        if (INFO(l1) < INFO(l2))
        {
            return -1;
        }
        if (INFO(l1) > INFO(l2))
        {
            return 1;
        }
        else
        {
            return compareList(tail(l1),tail(l2));
        }
    }
}

boolean find (List l, ElType e)
{
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        if (INFO(l)==e)
        {
            return true;
        }
        return find(tail(l), e);
    }
}

// Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
// memperhatikan urutan ataupun banyaknya elemen).
// Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false.
boolean isAllExist (List l1, List l2)
{
    if (isEmpty(l1))
    {
        return false;
    }
    if (isOneElmt(l1))
    {
        return find(l2, INFO(l1));
    }
    return find(l2, INFO(l1)) && isAllExist(tail(l1), l2);
}

