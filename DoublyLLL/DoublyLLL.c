////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLLL.c
// Description : Buidling Singly Linear Linked List
// Author :      Pradhumnya Changdev Kalsait   
// Date :        02/07/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>


typedef struct node 
{
    int data;
    struct node * next;
    struct node *prev;
    
}NODE,*PNODE,**PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|<=>", first->data);
        first = first -> next;
    }
    printf("NULL");

}

void DisplayRev(PNODE first)
{
    while(first->next != NULL)
    {
        first = first -> next;
    }
    while(first  != NULL)
    {
        printf("|%d|<=>", first->data);
        first = first -> prev;
    }
    printf("NULL");
    
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

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
        newn -> next -> prev = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
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
        newn -> prev = temp;
    }
}
void DeleteFirst(PPNODE first )
{
    PNODE temp = NULL;
    if(NULL != *first)
    {   
        temp = *first;
        *first = (*first) -> next;
        (*first) -> prev = NULL;
        free(temp);

    }
}
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;
    if(NULL == *first)
    {
        return;
    }
    else
    {
        temp = *first;
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
    


}
void InsertAtPos(PPNODE first, int iNo, int iPos)
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
    if (iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if (iPos == iCount+1)
    {
        InsertLast(first, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data =iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        temp -> next = newn;

    }
}
void DeleteAtPos(PPNODE first,int iPos)
{
    PNODE target = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iCount = 0;

    iCount = Count(*first);
    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position");
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst(first);
    }
    else if (iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        

        temp = *first;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;

        temp -> next = target -> next;
        target -> next -> prev = temp;

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
    printf("\nTHe number of elements in LL is:%d\n", iREt);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iREt = Count(head);
    printf("\nTHe number of elements in LL is:%d\n", iREt);

    DeleteFirst(&head);
    Display(head);
    iREt = Count(head);
    printf("\nTHe number of elements in LL is:%d\n", iREt);

    DeleteLast(&head);
    Display(head);
    iREt = Count(head);
    printf("\nTHe number of elements in LL is:%d\n", iREt);

    InsertAtPos(&head,105,3);
    Display(head);
    iREt = Count(head);
    printf("\nTHe number of elements in LL is:%d\n", iREt);



    DeleteAtPos(&head,3);
    Display(head);
    iREt = Count(head);
    printf("\nTHe number of elements in LL is:%d\n", iREt);


    printf("\nLinkd List In reverse order\n");
    DisplayRev(head);

    


    return 0;
}