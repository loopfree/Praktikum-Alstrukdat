// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 21 Oktober 2021
// Topik Praktikum  : ADT Stack
// Deskripsi        : Praktikum 8 - bigint.c

#include "boolean.h"
#include "stack.h"

#include <stdio.h>
#include <string.h>

int main()
{
    Stack num1;
    CreateStack(&num1);

    Stack num2;
    CreateStack(&num2);

    Stack res;
    CreateStack(&res);

    char temp;

    //read first num
    do {
        scanf("%c", &temp);

        if(temp != '#')
        {
            int num = temp - '0';
            push(&num1, num);
        }
    }while(temp != '#');getchar();


    //read second num
    do {
        scanf("%c", &temp);

        if(temp != '#')
        {
            int num = temp - '0';
            push(&num2, num);
        }
    }while(temp != '#');

    int flag = 0;
    while(!isEmpty(num1) || !isEmpty(num2))
    {
        int tempNum1, tempNum2, ans;

        if(!isEmpty(num1))
        {
            pop(&num1, &tempNum1);
        }
        else
        {
            tempNum1 = 0;
        }

        if(!isEmpty(num2))
        {
            pop(&num2, &tempNum2);
        }
        else
        {
            tempNum2 = 0;
        }

        ans = tempNum1 + tempNum2;
        ans += flag;

        if(ans > 9)
        {
            ans %= 10;
            push(&res, ans);
            flag = 1;
        }

        else
        {
            push(&res, ans);
            flag = 0;
        }
    }

    if(flag == 1)
    {
        push(&res, flag);
    }

    while(!isEmpty(res))
    {
        int digit;
        pop(&res, &digit);
        printf("%d", digit);
    }
    printf("\n");

    return 0;
}
