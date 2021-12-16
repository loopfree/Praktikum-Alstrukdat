// NIM              : 13520131
// Nama             : Steven
// Tanggal          : 11 November 2021
// Topik Praktikum  : ADT Linked List
// Deskripsi        : Praktikum 11 - backspace.c

#include <stdio.h>
#include "stack_linked.h"

int main()
{
    int s1, s2;
    scanf("%d %d", &s1, &s2);

    Stack stack1;
    CreateStack(&stack1);

    Stack stack2;
    CreateStack(&stack2);

    for(int i = 0; i < s1; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp != 0)
        {
            push(&stack1, temp);
        }
        else
        {
            if (!isEmpty(stack1))
            {
                pop(&stack1, &temp);
            }
        }
    }

    for(int i = 0; i < s2; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp != 0)
        {
            push(&stack2, temp);
        }
        else
        {
            if (!isEmpty(stack2))
            {
                pop(&stack2, &temp);
            }
        }
    }

    int ans = 1;
    while(!isEmpty(stack1))
    {
        int temp1 = -1;
        int temp2 = -1;
        if ((isEmpty(stack1)&& !isEmpty(stack2)) || !isEmpty(stack1) && isEmpty(stack2))
        {
            ans = 0;
            break;
        }
        pop(&stack1, &temp1);
        pop(&stack2, &temp2);

        if(temp1 != temp2)
        {
            ans = 0;
            break;
        }
    }

    if(ans)
        printf("Sama\n");
    else
        printf("Tidak sama\n");
}
