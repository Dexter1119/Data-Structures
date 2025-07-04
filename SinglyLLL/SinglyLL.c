////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLL.c
// Description : Buidling Singly Linear Linked List
// Author :      Pradhumnya Changdev Kalsait   
// Date :        25/06/25
//
////////////////////////////////////////////////////////////////////



/*
|11|->|21|->|51|->
Number of nodes are : 3
|11|->|21|->|51|->|101|->|111|->
Number of nodes are : 5
|21|->|51|->|101|->|111|->
Number of nodes are : 4
|21|->|51|->|101|->
Number of nodes are : 3
|21|->|51|->|105|->|101|->
Number of nodes are : 4
|21|->|51|->|101|->
Number of nodes are : 3

time required - 38 mins 
error -3 
(*first = NULL rather *first == NULL)
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;


void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|->",first-> data);
        first = first -> next;
    }
}
int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;

}
void InsertFirst(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("Unble To allocate the memory");
        return;
    }

    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("Unble To allocate the memory");
        return;
    }

    newn -> data = iNo;
    newn -> next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }

}

void InsertAtPos(PPNODE first , int iNo, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iCount = 0;
    
    iCount = Count(*first);
    if(iPos < 1 || iPos > iCount+1)
    {
        printf("Invalid Position");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if( iPos == iCount+1)
    {
        InsertLast(first,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn )
        {
            printf("Unble To allocate the memory");
            return;
        }   


        newn ->data = iNo;
        newn -> next = NULL;

        temp = *first;
        for(iCnt = 1; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else
    {
        temp = *first;
        *first = temp -> next;
        free(temp);
    }

}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if( (*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp->next = NULL;
    }


}
void DeleteAtPos(PPNODE first, int iPos)
{
   
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;
    int iCount = 0;

    iCount = Count(*first);
    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if( iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(iCnt = 1 ; iCnt < iPos-1;iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp ->next = target -> next;
        free(target);
    }
}
int main()
{
    PNODE head = NULL;
    int iREt = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);

    InsertLast(&head,101);
    InsertLast(&head,111);    
    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);

    DeleteFirst(&head);
    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);

    DeleteLast(&head);
    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);

    InsertAtPos(&head,105,3);
    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);

    DeleteAtPos(&head,3);
    Display(head);
    iREt = Count(head);
    printf("\nNumber of nodes are : %d\n",iREt);



    return 0;
}