// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 25 November 2021
// Topik Praktikum  : ADT Tree
// Deskripsi        : Praktikum 13 - merkle.c

#include <stdio.h>
#include <math.h>
#include "bintree.h"

BinTree insertLevelOrder(int arr[], BinTree root, int i, int n)
{
    if (i < n)
    {
        BinTree temp = newTreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2*i+2, n);

        root->right = insertLevelOrder(arr, root->right, 2*i+1, n);
    }
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    if((n & (n-1)) != 0)
    {
        printf("Jumlah masukan tidak sesuai\n");
        return 0;
    }

    int size = pow(2, n+1);
    int arr[size];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int now = n, later = 0;
    while(now != later)
    {
        arr[now] = arr[later]+arr[later+1];
        later += 2;
        now++;
    }

    now--;
    int treeChild[size];

    int temp = 0;
    for(int i = now-1; i >= 0; i--)
    {
        treeChild[temp] = arr[i];
        temp++;
    }

    int next = 0;
    BinTree root;

    root = insertLevelOrder(treeChild, root, 0, now);
    printTree(root, 2);

}