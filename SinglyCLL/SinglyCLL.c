////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyCLL.c
// Description : Buidling Singly Circular Linked List 
// Author :      Pradhumnya Changdev Kalsait   
// Date :        02/07/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}NODE ,*PNODE,**PPNODE;


void Display(PNODE first,PNODE last)
{
    do
    {
        printf("|%d|->",first->data);
        first = first-> next;
    }while(first != (last-> next));
    printf("NULL");


}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first = first -> next;
    }while(first != (last-> next));
    return iCount;
    


}
void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
        (*last) -> next = *first;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
        (*last) -> next = *first;
    }
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
        (*last) -> next = *first;
    }
    else
    {
        // temp = *first;
        // while(temp != *last)
        // {
        //     temp = temp -> next;
        // }
        // temp -> next = newn;
        // *last = newn;
        // (*last) -> next = *first;

        temp = *last;
        temp -> next = newn;
        *last = newn;
        (*last) -> next = *first;

    }

}

void DeleteFrist(PPNODE first,PPNODE last)
{
    PNODE target = NULL;
    if((*first != NULL) && (*last != NULL))
    {
        target = *first;
        *first = target -> next;
        (*last) -> next = *first;
        free(target);

    }

}

void DeleteLast(PPNODE first,PPNODE last)
{
    
    PNODE target = NULL;
    PNODE temp = NULL;

    if((*first != NULL) && (*last != NULL))
    {

       temp = *first;
        do
        {
            temp = temp -> next;

        }while(temp -> next != *last);

        target = temp -> next;
        *last = temp;
        free(target);
        (*last) -> next = *first;

       
    }

}

void InsertAtPos(PPNODE first,PPNODE last,int no,int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iCount = 0;

    iCount = Count(*first,*last);
    if(iPos < 1 || iPos > iCount+1)
    {
        printf("Invalid Position");
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn )
        {
            printf("Unable to alocate the memory for new node");
            return ;
        }

        newn -> data = no;
        newn -> next = NULL;
        
        temp = *first;

        for(iCnt = 1; iCnt < iPos-1;iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int iPos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iCount = 0;

    iCount = Count(*first,*last);
    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position");
        return;
    }
    else if(iPos == 1)
    {
        DeleteFrist(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
       
        temp = *first;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        target  = temp -> next;
        temp -> next = target -> next;
        free (target);
    }
}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

     Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);


    DeleteFrist(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);


    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);

    InsertAtPos(&head,&tail,105,2);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);

    DeleteAtPos(&head,&tail,2);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("\nThe number of elements in linked list is:%d\n",iRet);





    return 0;
}