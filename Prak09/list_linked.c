// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 28 Oktober 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Praktikum 9 - list_linked.c

#include "boolean.h"
#include "list_linked.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>

// I.S. sembarang
// F.S. Terbentuk list kosong
void CreateList(List *l)
{
    FIRST(*l) = NULL;
}

// Mengirim true jika list kosong
boolean isEmpty(List l)
{
    return FIRST(l)==NULL;
}

// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Mengembalikan nilai elemen l pada indeks idx
ElType getElmt(List l, int idx)
{
    Address curr = FIRST(l);
    int i = 0;
    while (curr != NULL)
    {
        if (i == idx)
        {
            return INFO(curr);
        }
        i += 1;
        curr = NEXT(curr);
    }
}

// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Mengubah elemen l pada indeks ke-idx menjadi val
void setElmt(List *l, int idx, ElType val)
{
    Address curr = FIRST(*l);
    int i = 0;
    while (curr != NULL)
    {
        if (i == idx)
        {
            INFO(curr) = val;
        }
        i += 1;
        curr = NEXT(curr);
    }
}

// I.S. l, val terdefinisi
// F.S. Mencari apakah ada elemen list l yang bernilai val
// Jika ada, mengembalikan indeks elemen pertama l yang bernilai val
// Mengembalikan IDX_UNDEF jika tidak ditemukan
int indexOf(List l, ElType val)
{
    Address curr= FIRST(l);
    boolean found = false;
    int ans = IDX_UNDEF;
    if (isEmpty(l))
    {
        return ans;
    }
    else
    {
        int i = 0;
        while (curr != NULL && !found)
        {
            if (INFO(curr)==val)
            {
                ans = i;
                found = true;
            }
            i += 1;
            curr = NEXT(curr);
        }
        return ans;
    }
}

// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen pertama dengan nilai val jika alokasi berhasil.
// Jika alokasi gagal: I.S.= F.S.
void insertFirst(List *l, ElType val)
{
    Address head = newNode(val);
    if (head != NULL)
    {
        NEXT(head) = *l;
        FIRST(*l) = head;
    }
    else
    {
        FIRST(*l) = head;
    }
}

// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen list di akhir: elemen terakhir yang baru
// bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
void insertLast(List *l, ElType val)
{
    Address curr;
    Address last;

    if (isEmpty(*l))
    {
        insertFirst(l,val);
    }
    else
    {
        curr = newNode(val);
        if (curr!=NULL)
        {
            last = FIRST(*l);
            while (NEXT(last)!=NULL)
            {
                last = NEXT(last);
            }
            NEXT(last) = curr;
        }
    }
}

// I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. Melakukan alokasi sebuah elemen dan
// menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i)
// yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.
void insertAt(List *l, ElType val, int idx)
{
    int i = 0;
    Address curr;
    Address temp;
    if (idx==0)
    {
        insertFirst(l,val);
    }
    else
    {
        curr = newNode(val);
        if (curr!=NULL)
        {
            temp = FIRST(*l);
            while (i<idx-1)
            {
                i += 1;
                temp = NEXT(temp);
            }
            NEXT(curr) = NEXT(temp);
            NEXT(temp) = curr;
        }
    }
}

// I.S. List l tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada x
//      dan alamat elemen pertama di-dealokasi
void deleteFirst(List *l, ElType *val)
{
    Address curr = FIRST(*l);
    *val = INFO(curr);
    FIRST(*l) = NEXT(curr);
    free(curr);
}

// I.S. list tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada x
//      dan alamat elemen terakhir di-dealokasi
void deleteLast(List *l, ElType *val)
{
    Address curr = FIRST(*l);
    if(NEXT(curr) == NULL) {
        *val = INFO(curr);
        free(curr);
        *l = NULL;
    }
    else
    {
        while(NEXT(NEXT(curr)) != NULL)
        {
            curr = NEXT(curr);
        }
        *val = INFO(NEXT(curr));
        free(NEXT(curr));
        NEXT(curr) = NULL;
    }
}

// I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l)
// F.S. val diset dengan elemen l pada indeks ke-idx.
//      Elemen l pada indeks ke-idx dihapus dari l
void deleteAt(List *l, int idx, ElType *val)
{
    int i = 0;
    Address help;
    Address curr = FIRST(*l);
    if  (idx == 0)
    {
        deleteFirst(l,val);
    }
    else
    {
        while (i<idx-1)
        {
            i += 1;
            curr = NEXT(curr);
        }
        help = NEXT(curr);
        *val = INFO(help);
        NEXT(curr) = NEXT(help);
    }
}

void displayList(List l)
{
    printf("[");
    if (!isEmpty(l))
    {
        Address  curr = FIRST(l);
        while (curr != NULL)
        {
            printf("%d", INFO(curr));
            curr = NEXT(curr);

            if (curr != NULL)
            {
                printf(",");
            }
        }
    }
    printf("]");
}

// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong
int length(List l)
{
    int len = 0;
    if (isEmpty(l))
    {
        return len;
    }
    else
    {
        Address check = FIRST(l);
        while (check != NULL)
        {
            len += 1;
            check = NEXT(check);
        }
        return len;
    }
}

/** Spek Tambahan **/
/** Spek Tambahan **/
/** Spek Tambahan **/

// Mencari apakah ada elemen list yang beralamat P
// Mengirimkan true jika ada, false jika tidak ada
boolean fSearch(List L, Address P)
{
    Address curr = FIRST(L);
    while (curr != NULL)
    {
        if (curr == P)
        {
            return true;
        }
        curr = NEXT(curr);
    }
    return false;
}

// Mengirimkan address elemen sebelum elemen yang nilainya=X
// Mencari apakah ada elemen list dengan Info(P)=X
// Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X.
// Jika tidak ada, mengirimkan Nil
// Jika P adalah elemen pertama, maka Prec=Nil
// Search dengan spesifikasi seperti ini menghindari
// traversal ulang jika setelah Search akan dilakukan operasi lain
Address searchPrec(List L, ElType X)
{
    List ans = NULL;
    List prev = NULL;
    List temp = L;
    while(temp != NULL)
    {
        if(INFO(temp) == X)
        {
            ans = prev;
            break;
        }
        prev = temp;
        temp = NEXT(temp);
    }
    return ans;
}

// Mengirimkan nilai info(P) yang maksimum
ElType max(List l)
{
    List temp = l;
    ElType result = INFO(temp);
    temp = NEXT(temp);
    while(temp != NULL)
    {
        if(INFO(temp) > result)
        {
            result = INFO(temp);
        }
        temp = NEXT(temp);
    }
    return result;
}

// Mengirimkan address P, dengan info(P) yang bernilai maksimum
Address adrMax(List l)
{
    List temp = l;
    List result = temp;
    temp = NEXT(temp);
    while(temp != NULL)
    {
        if(INFO(temp) > INFO(result))
        {
            result = temp;
        }
        temp = NEXT(temp);
    }
    return result;
}

// Mengirimkan nilai info(P) yang minimum
ElType min(List l)
{
    List temp = l;
    ElType result = INFO(temp);
    temp = NEXT(temp);
    while(temp != NULL)
    {
        if(INFO(temp) < result)
        {
            result = INFO(temp);
        }
        temp = NEXT(temp);
    }
    return result;
}

// Mengirimkan address P, dengan info(P) yang bernilai minimum
Address adrMin(List l)
{
    List temp = l;
    List result = temp;
    temp = NEXT(temp);
    while(temp != NULL)
    {
        if(INFO(temp) < INFO(result))
        {
            result = temp;
        }
        temp = NEXT(temp);
    }
    return result;
}

// Mengirimkan nilai rata-rata info(P)
float average(List l)
{
    int count = 0;
    ElType total = 0;
    List temp = l;
    while(temp != NULL)
    {
        total += INFO(temp);
        temp = NEXT(temp);
        count++;
    }
    return (float) total / (float) count;
}

/** End of Spek Tambahan **/
/** End of Spek Tambahan **/
/** End of Spek Tambahan **/

// I.S. l1 dan l2 sembarang
// F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2
// (Koreksi: l1 dan l2 tidak dikosongkan setelah proses)
// Konkatenasi dua buah list : l1 dan l2
// menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan).
// Tidak ada alokasi/dealokasi pada prosedur ini
List concat(List l1, List l2)
{
    List l3;
    CreateList(&l3);
    Address head;
    head = FIRST(l1);
    while (head!=NULL)
    {
        insertLast(&l3, INFO(head));
        head = NEXT(head);
    }
    head = FIRST(l2);
    while (head!=NULL)
    {
        insertLast(&l3, INFO(head));
        head = NEXT(head);
    }
    return l3;
}

/** Spek Tambahan **/
/** Spek Tambahan **/
/** Spek Tambahan **/

// Delete semua elemen list dan alamat elemen di-dealokasi
void delAll(List *l)
{
    int len = length(*l);
    int val;
    int i = 0;

    while (i < len){
        deleteFirst(l , &val);
        i++;
    }
}

// I.S. sembarang.
// F.S. elemen list dibalik :
// Elemen terakhir menjadi elemen pertama, dan seterusnya.
// Membalik elemen list, tanpa melakukan alokasi/dealokasi.
void inverseList(List *l)
{
    Address helper1;
    Address helper2;
    Address helper3;

    helper1 = FIRST(*l);
    helper2 = NEXT(*l);
    helper3 = NEXT(helper2);

    NEXT(helper1) = NULL;

    while (helper3 != NULL){
        NEXT(helper2) = helper1;
        helper1 = helper2;
        helper2 = helper3;
        helper3 = NEXT(helper3);
    }
    NEXT(helper2) = helper1;

    FIRST(*l) = helper2;
}

// Mengirimkan list baru, hasil invers dari L
// dengan menyalin semua elemn list. Alokasi mungkin gagal.
// Jika alokasi gagal, hasilnya list kosong
// dan semua elemen yang terlanjur di-alokasi, harus didealokasi
List fInverseList(List l)
{
    List rev = l;
    inverseList(&rev);
    return rev;
}

// I.S. L1 sembarang. F.S. L2=L1
// L1 dan L2 "menunjuk" kepada list yang sama.
// Tidak ada alokasi/dealokasi elemen
void copyList(List *l1, List *l2)
{
    FIRST(*l2) = FIRST(*l1);
}

// Mengirimkan list yang merupakan salinan L
// dengan melakukan alokasi.
// Jika ada alokasi gagal, hasilnya list kosong dan
// semua elemen yang terlanjur di-alokasi, harus didealokasi
List fCopyList(List l)
{
    List result;
    List temp = l;
    int prevLen = 0;
    boolean fail = false;

    CreateList(&result);

    while(temp != NULL)
    {
        prevLen = length(result);
        insertLast(&result , INFO(temp));
        if (length(result) == prevLen)
        {
            fail = true;
            break;
        }
        temp = NEXT(temp);
    }

    if(fail)
    {
        delAll(&result);
    }

    return result;
}

// I.S. lIn sembarang.
// F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn
// Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi
// dengan melakukan alokasi elemen.
// lOut adalah list kosong jika ada alokasi elemen yang gagal
void cpAllocList(List lIn, List *lOut)
{
    *lOut = fCopyList(lIn);
}

// I.S. l mungkin kosong
// F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2
// L tidak berubah: untuk membentuk l1 dan l2 harus alokasi
// l1 berisi separuh elemen L dan l2 berisi sisa elemen L
// Jika elemen L ganjil, maka separuh adalah length(L) div 2
void splitList(List *l1, List *l2, List l)
{
    CreateList(l1);
    CreateList(l2);

    int len = length(l);
    int first_limit = (int) (len / 2);
    List temp = l;
    int index = 0;
    while(temp != NULL)
    {
        if(index > first_limit - 1)
        {
            insertLast(l2, INFO(temp));
        }
        else
        {
            insertLast(l1, INFO(temp));
        }
        temp = NEXT(temp);

        index++;
    }
}

/** End of Spek Tambahan **/
/** End of Spek Tambahan **/
/** End of Spek Tambahan **/
