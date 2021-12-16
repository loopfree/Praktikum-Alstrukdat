// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 23 September 2021
// Topik Praktikum  : ADT Matrix
// Deskripsi        : Praktikum 5 - submatrix.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int matrixSize;
        scanf("%d", &matrixSize);

        // Menginisiasi Matrix
        int** matrix = (int**) malloc(sizeof(int*) * matrixSize);
        for(int i = 0; i < matrixSize; ++i)
        {
            // Menginisiasi baris
            matrix[i] = (int*) malloc(sizeof(int) * matrixSize);
        }

        // Menerima input Matrix
        for(int i = 0; i < matrixSize; ++i)
        {
            for(int j = 0; j < matrixSize; ++j)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        // Menerima input ukuran sub-Matrix
        int subMatrixSize;
        scanf("%d", &subMatrixSize);

        int ans = 0;
        int subMatrixTotal;
        int subMatrixAmountRow = (matrixSize - subMatrixSize) + 1;

        for(int i = 0; i < subMatrixAmountRow; ++i)
        {
            for(int j = 0; j < subMatrixAmountRow; ++j)
            {
                subMatrixTotal = 0;
                for(int k = 0; k < subMatrixSize; ++k)
                {
                    for(int l = 0; l < subMatrixSize; ++l)
                    {
                        subMatrixTotal += matrix[k+i][j+l];
                    }
                }
                if(subMatrixTotal > ans)
                {
                    ans = subMatrixTotal;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
