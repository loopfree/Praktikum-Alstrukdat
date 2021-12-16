#include "list_linked.c"
#include "node.c"
#include <stdio.h>

int main()
{
    List l;
    CreateList(&l);
    insertLast(&l,100);
    insertLast(&l,4);
    insertLast(&l,3);
    insertLast(&l,2);
    insertLast(&l,1);
    insertLast(&l,5);
    insertAt(&l,10,2);
    displayList(l);
    printf("\n");
    printf("%d\n", length(l));
    printf("%d",indexOf(l,9));

    int del;
    deleteAt(&l,2,&del);
    printf("%d\n", del);
    displayList(l);
    printf("\n");
    setElmt(&l,3, 10000);
    displayList(l);
    printf("\n");

    List l2;
    CreateList(&l2);
    insertFirst(&l2,8);
    insertFirst(&l2,7);
    insertFirst(&l2,4);
    insertLast(&l2,9);
    insertAt(&l2,10,2);
    displayList(l2);
    printf("\n");
    printf("%d\n", length(l2));
    int del2;
    deleteAt(&l2,2,&del2);
    printf("%d\n", del2);
    displayList(l2);
    printf("\n");

    List l3;
    l3 = concat(l,l2);
    displayList(l3);
}
