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
} NODE, *PNODE, **PPNODE;

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays elements of the list from first to last
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void Display(PNODE first, PNODE last)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void Display(PNODE first, PNODE last)
{
    if (first == NULL && last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|<=>", first->data);
        first = first->next;

    } while (first != last->next);
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DisplayRev
// Description   : Displays elements of the list in reverse order
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void DisplayRev(PNODE first, PNODE last)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DisplayRev(PNODE first, PNODE last)
{
    if (first == NULL && last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    PNODE temp = last;

    do
    {
        printf("|%d|<=>", temp->data);
        temp = temp->prev;

    } while (temp != last->prev);

    printf("\n");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Counts the number of nodes in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : int Count(PNODE first, PNODE last)
// Input Output  : (2 inputs, 1 output)
//
////////////////////////////////////////////////////////////////////
int Count(PNODE first, PNODE last)
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
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if (NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL && *last == NULL)
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
void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    if (NULL == newn)
    {
        printf("Unable to allocate the memory for new node");
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*first == NULL && *last == NULL)
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
void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;
    if (*first == NULL && *last == NULL)
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
void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if (*first == NULL && *last == NULL)
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
        temp = *last;
        *last = (*last)->prev;
        (*last)->next = *first;
        (*first)->prev = *last;
        free(temp);
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iRet = Count(*first, *last);

    if (iPos < 1 || iPos > iRet)
    {
        printf("Invalid position\n");
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(first, last);
    }
    else if (iPos == iRet)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
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
// Description   : Inserts a node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void InsertAtPos(PPNODE first, PPNODE last, int iPos, int no)
// Input Output  : (4 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, PPNODE last, int iPos, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    int iRet = Count(*first, *last);

    if (iPos < 1 || iPos > (iRet + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(first, last, no);
    }
    else if (iPos == iRet + 1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        if (NULL == newn)
        {
            printf("Unable to allocate the memory for new node");
            return;
        }

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point for menu-driven Doubly Circular LL
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
    int iValue = 0;
    int iChoice = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-----------------------------------------------------------------\n");
    printf("-------------------Doubly Circular Linked List-------------------\n");
    printf("-----------------------------------------------------------------\n");

    while (1)
    {
        printf("-----------------------------------------------------------------\n");
        printf("1: Insert at First\t2: Insert at Last\n");
        printf("3: Insert at Position\t4: Delete First\n");
        printf("5: Delete Last\t\t6: Delete at Position\n");
        printf("7: Display\t\t8: Display Reverse\n");
        printf("9: Count\t\t0: Exit\n");
        printf("-----------------------------------------------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &iChoice);

        if (iChoice == 0)
        {
            printf("Thank You For Using The Application\n");
            break;
        }
        else if (iChoice == 1)
        {
            printf("Enter data to insert at First: ");
            scanf("%d", &iValue);
            InsertFirst(&head, &tail, iValue);
        }
        else if (iChoice == 2)
        {
            printf("Enter data to insert at Last: ");
            scanf("%d", &iValue);
            InsertLast(&head, &tail, iValue);
        }
        else if (iChoice == 3)
        {
            printf("Enter data: ");
            scanf("%d", &iValue);
            printf("Enter Position: ");
            scanf("%d", &iPos);
            InsertAtPos(&head, &tail, iPos, iValue);
        }
        else if (iChoice == 4)
        {
            DeleteFirst(&head, &tail);
        }
        else if (iChoice == 5)
        {
            DeleteLast(&head, &tail);
        }
        else if (iChoice == 6)
        {
            printf("Enter Position to Delete: ");
            scanf("%d", &iPos);
            DeleteAtPos(&head, &tail, iPos);
        }
        else if (iChoice == 7)
        {
            printf("List: ");
            Display(head, tail);
            printf("\n");
        }
        else if (iChoice == 8)
        {
            printf("List in Reverse: ");
            DisplayRev(head, tail);
        }
        else if (iChoice == 9)
        {
            iRet = Count(head, tail);
            printf("Total Elements: %d\n", iRet);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
