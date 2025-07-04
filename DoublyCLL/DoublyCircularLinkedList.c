////////////////////////////////////////////////////////////////////
//
// File Name   : DoublyCLL.c
// Description : Building Doubly Circular Linked List
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

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays the elements of the doubly circular linked list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void Display(PNODE first, PNODE last)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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
        first = first->next;

    } while (first != last->next);
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Counts the number of elements in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : int Count(PNODE first, PNODE last)
// Input Output  : (2 inputs, 1 output)
//
////////////////////////////////////////////////////////////////////
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
        first = first->next;
        
    } while (first != last->next);

    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a node at the beginning of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void InsertFirst(PPNODE first, PPNODE last, int no)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = *last = newn;
        newn->next = newn->prev = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;
        (*first)->prev = newn;
        (*last)->next = newn;
        *first = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a node at the end of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void InsertLast(PPNODE first, PPNODE last, int no)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = *last = newn;
        newn->next = newn->prev = newn;
    }
    else
    {
        newn->next = *first;
        newn->prev = *last;
        (*last)->next = newn;
        (*first)->prev = newn;
        *last = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void DeleteFirst(PPNODE first, PPNODE last)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = *last = NULL;
    }
    else
    {
        PNODE temp = *first;
        *first = temp->next;
        (*first)->prev = *last;
        (*last)->next = *first;
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void DeleteLast(PPNODE first, PPNODE last)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first,PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if (*first == *last)
    {
        free(*first);
        *first = *last = NULL;
    }
    else
    {
        PNODE temp = *last;
        *last = temp->prev;
        (*last)->next = *first;
        (*first)->prev = *last;
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node at a given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first,PPNODE last,int iPos)
{
    int iRet = Count(*first, *last);
    if(iPos < 1 || iPos > iRet)
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(iPos == iRet)
    {
        DeleteLast(first, last);
    }
    else
    {
        PNODE temp = *first;
        PNODE target = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        free(target);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at a specific position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void InsertAtPos(PPNODE first, PPNODE last, int iPos, int no)
// Input Output  : (4 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first,PPNODE last,int iPos, int no)
{
    int iRet = Count(*first, *last);
    if(iPos < 1 || iPos > iRet + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if(iPos == iRet + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn)
        {
            printf("Unable to allocate memory for new node");
            return;
        }

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = *first;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point for the program
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
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
