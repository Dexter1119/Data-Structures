////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLLL.c
// Description : Building Doubly Linear Linked List
// Author     : Pradhumnya Changdev Kalsait
// Date       : 02/07/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
} NODE, *PNODE, **PPNODE;

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays the elements of the linked list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void Display(PNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|<=>", first->data);
        first = first->next;
    }
    printf("NULL");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DisplayRev
// Description   : Displays the elements in reverse order
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DisplayRev(PNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DisplayRev(PNODE first)
{
    while(first->next != NULL)
    {
        first = first->next;
    }
    while(first != NULL)
    {
        printf("|%d|<=>", first->data);
        first = first->prev;
    }
    printf("NULL");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Counts and returns the number of nodes
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int Count(PNODE first)
// Input Output  : (1 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int Count(PNODE first)
{
    int iCount = 0;
    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertFirst(PPNODE first, int iNo)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = *first;
    newn->prev = NULL;

    if(*first != NULL)
    {
        (*first)->prev = newn;
    }
    *first = newn;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertLast(PPNODE first, int iNo)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *first;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteFirst(PPNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    PNODE temp = *first;
    if(temp != NULL)
    {
        *first = temp->next;
        if(*first != NULL)
            (*first)->prev = NULL;
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteLast(PPNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first)
{
    PNODE temp = *first;

    if(temp == NULL)
        return;

    if(temp->next == NULL)
    {
        free(temp);
        *first = NULL;
        return;
    }

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at a specified position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertAtPos(PPNODE first, int iNo, int iPos)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    int iCount = Count(*first);
    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Position");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first, iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first, iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        PNODE temp = *first;
        int iCnt = 0;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
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
// Function Name : DeleteAtPos
// Description   : Deletes the node at a specified position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteAtPos(PPNODE first, int iPos)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, int iPos)
{
    int iCount = Count(*first);
    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Position");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        PNODE temp = *first;
        PNODE target = NULL;
        int iCnt = 0;

        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
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
// Function Name : main
// Description   : Entry point of the program
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    int iREt = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    DeleteFirst(&head);
    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    DeleteLast(&head);
    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    InsertAtPos(&head, 105, 3);
    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    DeleteAtPos(&head, 3);
    Display(head);
    iREt = Count(head);
    printf("\nThe number of elements in LL is: %d\n", iREt);

    printf("\nLinked List In reverse order\n");
    DisplayRev(head);

    return 0;
}
