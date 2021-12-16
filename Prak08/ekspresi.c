// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 21 Oktober 2021
// Topik Praktikum  : ADT Stack
// Deskripsi        : Praktikum 8 - ekspresi.c

#include "boolean.h"
#include "stack.h"
#include "tokenmachine.h"

#include <stdio.h>
#include <string.h>

int main()
{
    Stack s;
    CreateStack(&s);

    char temp;
        int number = 0;
    do
    {
        scanf("%c", &temp);

        if(temp == '.')
        {

            if(isEmpty(s))
            {
                printf("Ekspresi kosong\n");
                return 0;
            }

            int res;
            pop(&s, &res);
            printf("Hasil=%d\n", res);
            return 0;
        }

        if(temp == ' ')
        {
            push(&s, number);
            printf("%d\n", number);
            number = 0;
            continue;
        }

        if(temp != '*' && temp != '/' && temp != '+' && temp != '-' && temp != '^')
        {
            number *= 10;
            number += temp-'0';


            continue;
        }
        else
        {
            int num1, num2, res;
            pop(&s, &num1);
            pop(&s, &num2);
            printf("%d %c %d\n", num2, temp, num1);
            if(temp == '+')
                res = num2+num1;
            else if(temp == '-')
                res = num2-num1;
            else if(temp == '*')
                res = num2*num1;
            else if(temp == '/')
                res = num2/num1;
            else if(temp == '^')
            {
                res = 1;
                for(int i = 0; i < num1; i++)
                {
                    res *= num2;
                }
            }
            printf("%d\n", res);
            push(&s, res);
            scanf("%c", &temp);
            if(temp == '.')
            {
                int temporary;
                pop(&s, &temporary);
                printf("Hasil=%d\n", temporary);
                return 0;
            }
        }
    }while(temp != '.');

    return 0;
}
