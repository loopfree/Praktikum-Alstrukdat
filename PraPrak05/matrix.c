// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 17 September 2021
// Topik Praktikum  : ADT Matrix
// Deskripsi        : Pra Praktikum 5 - matrix.c

#include "boolean.h"
#include "matrix.h"

#include <stdio.h>

// Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori
// I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat
// F.S. Matriks m sesuai dengan definisi di atas terbentuk
void CreateMatrix(int nRow, int nCol, Matrix *m)
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

// Mengirimkan true jika i, j adalah Index
// yang valid untuk matriks apa pun
boolean isIdxValid(int i, int j)
{
    return (i>=0  && i<ROW_CAP && j>=0 && j<COL_CAP);
}

// Mengirimkan Index baris terbesar m
Index getLastIdxRow(Matrix m)
{
    return (ROWS(m)-1);
}

// Mengirimkan Index kolom terbesar m
Index getLastIdxCol(Matrix m)
{
    return (COLS(m)-1);
}

// Mengirimkan true jika i, j adalah Index efektif bagi m
boolean isIdxEff(Matrix m, Index i, Index j)
{
    return (i>=0 && i<ROWS(m) && j>=0 && j<COLS(m));
}

// Mengirimkan elemen m(i,i)
ElType getElmtDiagonal(Matrix m, Index i)
{
    return (ELMT(m,i,i));
}

// Melakukan assignment MRes = MIn
void copyMatrix(Matrix mIn, Matrix *mRes)
{
    *mRes = mIn;
}

// I.S. isIdxValid(nRow,nCol)
// F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol
// Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya
// Selanjutnya membaca nilai elemen per baris dan kolom
// Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
/*
1 2 3
4 5 6
8 9 10
*/
void readMatrix(Matrix *m, int nRow, int nCol)
{
    CreateMatrix(nRow, nCol, m);

    for (int i=0; i<nRow; i++)
    {
        for (int j=0; j<nCol; j++)
        {
            scanf("%d", &ELMT(*m,i,j));
        }
    }
}

// I.S. m terdefinisi
// F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
// dipisahkan sebuah spasi
// Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom
// Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
/*
1 2 3
4 5 6
8 9 10
*/
void displayMatrix(Matrix m)
{
   for(int i=0; i<ROWS(m); i++)
   {
      for (int j=0; j<COLS(m); j++)
      {
         printf("%d", ELMT(m,i,j));
         if (j!=COLS(m)-1)
         {
             printf(" ");
         }
      }
      if (i!=ROWS(m)-1)
      {
          printf("\n");
      }
   }
}

// Prekondisi : m1 berukuran sama dengan m2
// Mengirim hasil penjumlahan matriks: m1 + m2
Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix ans;
    CreateMatrix(ROWS(m1),COLS(m1), &ans);

    for (int i=0; i<ROWS(m1); i++)
    {
        for (int j=0; j<COLS(m1); j++)
        {
            ELMT(ans,i,j) = ELMT(m1,i,j) + ELMT(m2,i,j);
        }
    }
    return ans;
}

// Prekondisi : m1 berukuran sama dengan m2
// Mengirim hasil pengurangan matriks: salinan m1 – m2
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix ans;
    CreateMatrix(ROWS(m1),COLS(m1), &ans);

    for (int i=0; i<ROWS(m1); i++)
    {
        for (int j=0; j<COLS(m1); j++)
        {
            ELMT(ans,i,j) = ELMT(m1,i,j) - ELMT(m2,i,j);
        }
    }
    return ans;
}

// Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2
// Mengirim hasil perkalian matriks: salinan m1 * m2
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix ans;
    CreateMatrix(ROWS(m1),COLS(m2), &ans);
    int temp=0;

    for (int i=0; i<ROWS(m1); i++)
    {
        for (int j=0; j<COLS(m2); j++)
        {
            for (int k=0; k<ROWS(m2); k++)
            {
                temp += ( ELMT(m1,i,k) * ELMT(m2,k,j) );
            }
            ELMT(ans,i,j) = temp;
            temp = 0;
        }
    }

    return ans;
}

// Mengirim hasil perkalian setiap elemen m dengan x
Matrix multiplyConst(Matrix m, ElType x)
{
    Matrix ans;
    CreateMatrix(ROWS(m),COLS(m), &ans);

    for (int i=0; i<ROWS(m); i++)
    {
        for (int j=0; j<COLS(m); j++)
        {
            ELMT(ans,i,j) = x * ELMT(m,i,j);
        }
    }
    return ans;
}

// I.S. m terdefinisi, k terdefinisi
// F.S. Mengalikan setiap elemen m dengan k
void pMultiplyConst(Matrix *m, ElType k)
{
    for (int i=0; i<ROWS(*m); i++)
    {
        for (int j=0; j<COLS(*m); j++)
        {
            ELMT(*m,i,j) = k * ELMT(*m,i,j);
        }
    }
}

// Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan
// untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j)
// Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2)
boolean isEqual(Matrix m1, Matrix m2)
{
    boolean result;
    result = ROWS(m1) == ROWS(m2);
    result = result && COLS(m1) == COLS(m2);
    if (result==true)
    {
        for (int i=0; i<ROWS(m1); i++)
        {
            for (int j=0; j<COLS(m2); j++)
            {
                if (ELMT(m1,i,j) != ELMT(m2,i,j))
                {
                    result = false;
                }
            }
        }
    }
    return result;
}

// Mengirimkan true jika m1 tidak sama dengan m2
boolean isNotEqual(Matrix m1, Matrix m2)
{
    return (!isEqual(m1,m2));
}

// Mengirimkan true jika ukuran efektif matriks m1
// sama dengan ukuran efektif m2
boolean isSizeEqual(Matrix m1, Matrix m2)
{
    return (ROWS(m1)==ROWS(m2) && COLS(m1)==COLS(m2));
}

// Mengirimkan banyaknya elemen m
int count(Matrix m)
{
    return (ROWS(m)*COLS(m));
}

// Mengirimkan true jika m adalah matriks dengan
// ukuran baris dan kolom sama
boolean isSquare(Matrix m)
{
    return (ROWS(m)==COLS(m));
}

// Mengirimkan true jika m adalah matriks simetri :
// isSquare(m) dan untuk setiap elemen m, m(i,j)=m(j,i)
boolean isSymmetric(Matrix m)
{
   boolean ans = isSquare(m);

   if (ans)
   {
       for (int i=0; i<ROWS(m); i++)
       {
           for (int j=0; j<COLS(m); j++)
           {
               if (ELMT(m,i,j)!=ELMT(m,j,i))
               {
                   ans = false;
               }
           }
       }
   }
   return ans;
}

// Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
// setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0
boolean isIdentity(Matrix m)
{
    boolean ans = isSquare(m);

    if (ans)
    {
        for  (int i=0; i<ROWS(m); i++)
        {
            for (int j=0; j<COLS(m); j++)
            {
                if (i==j)
                {
                    ans = ans && (ELMT(m,i,j)==1);
                }
                else
                {
                    ans = ans && (ELMT(m,i,j)==0);
                }
            }
        }
    }
    return ans;
}

// Mengirimkan true jika m adalah matriks sparse:
// matriks “jarang” dengan definisi:
// hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0
boolean isSparse(Matrix m)
{
    int ans=0;

    for (int i=0; i<ROWS(m); i++)
    {
        for (int j=0; j<COLS(m); j++)
        {
            if (ELMT(m,i,j)!=0)
            {
                ans += 1;
            }
        }
    }

    return ((float)ans/(float)count(m)*100.0 <= 5);
}

// Menghasilkan salinan m dengan setiap elemen "di-invers",
// yaitu dinegasikan (dikalikan -1)
Matrix inverse1(Matrix m)
{
    return (multiplyConst(m, -1));
}

// I.S. m terdefinisi
// F.S. m di-invers, yaitu setiap elemennya
// dinegasikan (dikalikan -1)
void pInverse1(Matrix *m)
{
    pMultiplyConst(m, -1);
}

// Prekondisi: isSquare(m)
// Menghitung nilai determinan m
float determinant(Matrix m)
{
    int help;
    int helper;
    int index;

    int ans = 1;
    int answer = 1;

    int n = ROWS(m);
    int temp[ROWS(m) + 1];

    for (int i = 0; i < n; i++)
    {
        index = i;

        while (ELMT(m,index,i) == 0 && index < n)
        {
            index += 1;
        }
        if (index == n)
        {
            continue;
        }
        if (index != i)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = ELMT(m,index,j);
                ELMT(m,index,j) = ELMT(m,i,j);
                ELMT(m,index,j) = temp;
            }
            int sign = -1;
            if(index - i % 2 == 0)
            {
                sign = 1;
            }
            else
            {
                sign = -1;
            }
            ans *= sign;
        }

        for (int j = 0; j < n; j++)
        {
            temp[j] = ELMT(m,i,j);
        }

        for (int j = i + 1; j < n; j++)
        {
            help = temp[i];
            helper = ELMT(m,j,i);

            for (int k = 0; k < n; k++)
            {
                ELMT(m,j,k) = (help * ELMT(m,j,k)) - (helper * temp[k]);
            }
            answer *= help;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans *= ELMT(m,i,i);
    }

    return (ans / answer);
}

// I.S. m terdefinisi dan isSquare(m)
// F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i)
void transpose(Matrix *m)
{
    Matrix ans;
    CreateMatrix(ROWS(*m),COLS(*m), &ans);

    for (int i=0; i<ROWS(*m); i++)
    {
        for (int j=0; j<COLS(*m); j++)
        {
            ELMT(ans,i,j) = ELMT(*m,j,i);
        }
    }
    *m = ans;
}
