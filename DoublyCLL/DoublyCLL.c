////////////////////////////////////////////////////////////////////
//
// File Name   : DoublyCLL.c
// Description : Buidling Doubly Circular Linked List
// Author      : Pradhumnya Changdev Kalsait   
// Date        : 03/07/25
// 
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE,*PNODE,**PPNODE;


void Display(PNODE first,PNODE last)
{
    if (first == NULL && last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|<=>",first->data);
        first = first-> next;

    } while (first != last-> next);
    

}

int Count(PNODE first,PNODE last)
{
    if (first == NULL && last == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    int iCount = 0;


    do
    {
        iCount++;
        first = first-> next;
        
    } while (first != last-> next);

    return iCount;
    

}

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return ;
    }

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(NULL == *first && NULL == *last)
    {
        *first = newn;
        *last = newn;
        newn -> next = newn;
        newn -> prev = newn;
    }
    else
    {
        newn -> next = *first;
        newn -> next -> prev = newn;
        *first = newn;
        (*last) -> next = *first;
    }



}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return;
    }

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(NULL == *first && NULL == *last)
    {
        *first = newn;
        *last = newn;
        newn -> next = newn;
        newn -> prev = newn;
    }
    else
    {
        newn -> next = *first;
        
        newn -> prev = *last;

        (*first) -> prev = newn;
        (*last) -> next = newn;

        *last = newn;
    }
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    if(NULL == *first && NULL == *last)
    {
        return;
    }
    else if (*first == *last)
    {
        
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        *first = temp -> next;

        (*first) -> prev = *last;
        (*last) -> next = *first;

        free(temp);
    }

}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;
    
    if ((*first == NULL) && (*last == NULL)) 
    {
        return;
    }
    else if (*first == *last) 
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *last;
        *last = (*last)->prev;
        (*last)->next = *first;
        (*first)->prev = *last;
        free(temp);
    }

}

void DeleteAtPos(PPNODE first,PPNODE last,int iPos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iRet = 0;
    iRet = Count(*first, *last);

    if(iPos < 1 || iPos > (iRet ))
    {
        printf("Invalid position\n");
        return;
    }

    if( iPos == 1)
    {
        DeleteFirst(first, last);
    }
    else if( iPos == iRet )
    {
        DeleteLast(first, last);
    }
    else
    {
       

        temp = *first;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;

        target -> next -> prev = temp;

        free(target);

       
    }

}

void InsertAtPos(PPNODE first,PPNODE last,int iPos, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iRet = 0;
    iRet = Count(*first, *last);

    if(iPos < 1 || iPos > (iRet + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if( iPos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if( iPos == iRet + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn)
        {
            printf("Unable to allocate the memory for new node");
            return;
        }

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> prev = temp;

        temp -> next = newn;
        newn -> next -> prev = newn;
       
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iREt = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);


    DeleteFirst(&head,&tail);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);


    DeleteLast(&head,&tail);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);

    InsertAtPos(&head,&tail,3,75);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);

    DeleteAtPos(&head,&tail,3);

    Display(head,tail);
    iREt = Count(head,tail);
    printf("\nThe number of elelments in Linked List are:%d\n",iREt);



    return 0;
}