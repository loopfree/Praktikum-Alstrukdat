#include "listdin.c"

#include<stdio.h>

int main()
{
    ListDin test;
    CreateListDin(&test,5);
    readList(&test);
    displayList(test);

    /*
    int val;
    deleteLast(&test,&val);
    displayList(test);
    printf("\n");
    printf("%d", val);

    ListDin test2;
    CreateListDin(&test2,5);
    readList(&test2);
    displayList(test2);
    printf("\n");

    displayList(plusMinusList(test,test2,true));
    */

    return 0;
}
