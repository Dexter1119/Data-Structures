////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLL.c
// Description : Buidling Singly Linear Linked List
// Author     :   Pradhumnya Changdev Kalsait   
// Date       :   25/06/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Description   :   Displays all elements of the singly linked list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void Display(PNODE first)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|->", first->data);
        first = first->next;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Description   :   Counts the number of nodes in the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   int Count(PNODE first)
// Input Output  :   (1 input, 1 output)
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
// Function Name :   InsertFirst
// Description   :   Inserts a node at the beginning of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void InsertFirst(PPNODE first, int iNo)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate memory");
        return;
    }

    newn->data = iNo;
    newn->next = *first;
    *first = newn;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Description   :   Inserts a node at the end of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void InsertLast(PPNODE first, int iNo)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn)
    {
        printf("Unable to allocate memory");
        return;
    }

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Description   :   Inserts a node at a specific position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void InsertAtPos(PPNODE first, int iNo, int iPos)
// Input Output  :   (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iCount = Count(*first);

    if(iPos < 1 || iPos > iCount+1)
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
        newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn)
        {
            printf("Unable to allocate memory");
            return;
        }

        newn->data = iNo;
        newn->next = NULL;

        temp = *first;
        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Description   :   Deletes the first node from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void DeleteFirst(PPNODE first)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }

    temp = *first;
    *first = temp->next;
    free(temp);
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Description   :   Deletes the last node from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void DeleteLast(PPNODE first)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Description   :   Deletes the node at a specific position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   void DeleteAtPos(PPNODE first, int iPos)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, int iPos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCnt = 0;
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
        temp = *first;
        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   main
// Description   :   Driver function to test linked list operations
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   25/06/25
// Prototype     :   int main()
// Input Output  :   (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    InsertAtPos(&head, 105, 3);
    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    DeleteAtPos(&head, 3);
    Display(head);
    iRet = Count(head);
    printf("\nNumber of nodes are : %d\n", iRet);

    return 0;
}
