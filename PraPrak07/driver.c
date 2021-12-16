#include "queue.c"

#include<stdio.h>

int main()
{
    Queue q;
    CreateQueue(&q);

    printf("%d\n", isEmpty(q));
    printf("%d\n", isFull(q));

    enqueue(&q,1);
    enqueue(&q,3);
    enqueue(&q,5);
    enqueue(&q,6);

    int test;
    dequeue(&q,&test);
    printf("test: %d\n", test);

    printf("length: %d\n", length(q));

    displayQueue(q);

}
