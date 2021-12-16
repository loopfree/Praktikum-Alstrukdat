// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 18 November 2021
// Topik Praktikum  : ADT List Rekursif
// Deskripsi        : Praktikum 12 - undian.c

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

int main()
{
    List l = NULL;
    char inpt = 'Q';
    int num;
    while(inpt != 'X')
    {
        scanf("%c", &inpt);
        if(inpt == 'F')
        {
           scanf("%d", &num);
           l = konso(l, num);
        }
        else if(inpt == 'B')
        {
            scanf("%d", &num);
            l = konsb(l, num);
        }
        else if(inpt == 'O')
        {
            List temp = NULL;
            Address temp2;
            Address toRecurse = l;
            while(toRecurse != NULL)
            {
                temp2 = toRecurse;
                temp = konsb(temp, INFO(toRecurse));
                toRecurse = NEXT(toRecurse);
                if(toRecurse != NULL)
                {
                    free(temp2);
                    temp2 = toRecurse;
                    toRecurse = NEXT(toRecurse);
                    free(temp2);
                }
            }
            l = temp;
        }
        else if(inpt == 'E')
        {
            List temp = NULL;
            Address temp2;
            Address toRecurse = NEXT(l);
            while(toRecurse != NULL)
            {
                temp2 = toRecurse;
                temp = konsb(temp, INFO(toRecurse));
                toRecurse = NEXT(toRecurse);
                if(toRecurse != NULL)
                {
                    free(temp2);
                    temp2 = toRecurse;
                    toRecurse = NEXT(toRecurse);
                    free(temp2);
                }
            }
            l = temp;
        }
        else if(inpt == 'R')
        {
            List temp = NULL;
            Address temp2;
            Address toRecurse = l;
            while(toRecurse != NULL)
            {
                temp2 = toRecurse;
                temp = konso(temp, INFO(toRecurse));
                toRecurse = NEXT(toRecurse);
                free(temp2);
            }
            l = temp;
        }
        else if(inpt == 'P')
        {
            scanf("%d", &num);
            List temp = NULL;
            Address temp2;
            Address toRecurse = l;
            while(toRecurse != NULL && INFO(toRecurse) != num)
            {
                temp2 = toRecurse;
                temp = konso(temp, INFO(toRecurse));
                toRecurse = NEXT(toRecurse);
                free(temp2);
            }
            l = temp;
        }
    }
    if(isEmpty(l))
    {
        printf("Semua gugur\n");
    }
    else
    {
        displayList(l);
    }
}
