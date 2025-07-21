////////////////////////////////////////////////////////////////////
//
// File Name :    Queue.c
// Description :  Buidling Queue Data Structure
// Author     :   Pradhumnya Changdev Kalsait   
// Date       :   14/07/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data ;
    struct node * next;

}NODE,*PNODE,**PPNODE;

void enqueue(PPNODE first,PPNODE  last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("UNable to allocate the memory for the new node");
        return;
    }



    newn -> data = no;
    newn -> next = NULL;

    if((NULL == *first) && (NULL == *last))
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        *last = newn;
    }
}


int Dequeue(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;

    temp = *first;
    iValue = temp -> data;

    *first = (*first) -> next;

    free(temp);
    return iValue;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|-",first->data);
        first = first -> next;
    }
    printf("\n");
}

int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = (first) -> next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    enqueue(&head,&tail,11);
    enqueue(&head,&tail,21);
    enqueue(&head,&tail,51);
    enqueue(&head,&tail,101);
    enqueue(&head,&tail,111);

    Display(head);
    iRet = Count(head);
    printf("The Number of elements in queue are :%d\n ",iRet);

    iRet = Dequeue(&head);
    printf("The Deleted element in queue is :%d\n ",iRet);

    iRet = Dequeue(&head);
    printf("The Deleted element in queue is :%d\n ",iRet);

    iRet = Dequeue(&head);
    printf("The Deleted element in queue is :%d\n ",iRet);

    Display(head);
    iRet = Count(head);
    printf("The Number of elements in queue are :%d\n ",iRet);

    return 0;
}