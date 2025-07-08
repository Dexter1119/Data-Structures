////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLLLMenu.c
// Description : Buidling Singly Linear Linked List with Menu
// Author     :   Pradhumnya Changdev Kalsait   
// Date       :   02/07/25
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
// Description   :   Displays the elements of the linked list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
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
// Description   :   Counts and returns the number of nodes
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
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
// Description   :   Inserts a new node at the beginning
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertFirst(PPNODE first, int iNo)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("Unable to allocate the memory");
        return;
    }

    newn->data = iNo;
    newn->next = *first;
    *first = newn;
}

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Description   :   Inserts a new node at the end
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertLast(PPNODE first, int iNo)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("Unable to allocate the memory");
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
// Description   :   Inserts a node at a specified position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertAtPos(PPNODE first, int iNo, int iPos)
// Input Output  :   (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first , int iNo, int iPos)
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
    else if(iPos == iCount+1)
    {
        InsertLast(first, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        if(NULL == newn)
        {
            printf("Unable to allocate the memory");
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
// Description   :   Deletes the first node of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
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
// Description   :   Deletes the last node of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
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
// Description   :   Deletes the node at a specified position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
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
// Description   :   Entry point and menu for linked list operations
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   int main()
// Input Output  :   (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    int iValue = 0;
    int iChoice = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-----------------------------------------------------------------\n");
    printf("-------------------Singly Linear Linked List---------------------\n");

    while(1)
    {
        printf("-----------------------------------------------------------------\n");
        printf("------------------Please Select The Option-----------------------\n");
        printf("-----------------------------------------------------------------\n"); 
        printf("1: Insert New Node At First Position\n");
        printf("2: Insert New Node At Last Position\n");
        printf("3: Insert New Node At Given Position\n");
        printf("4: Delete Node At First Position\n");
        printf("5: Delete Node At Last Position\n");
        printf("6: Delete Node At Given Position\n");
        printf("7: Display All Elements in Linked List\n");
        printf("8: Count All Elements in Linked List\n");
        printf("0: To Exit from Application\n");
        printf("-----------------------------------------------------------------\n"); 

        printf("Enter Your Choice:");
        scanf("%d", &iChoice);

        if(iChoice == 0)
        {
            printf("Thank You For Using The Application\n");
            printf("\n-----------------------------------------------------------------\n"); 
            break;
        }
        else if(iChoice == 1)
        {
            printf("Enter The data that you wanna insert First: ");
            scanf("%d", &iValue);
            InsertFirst(&head, iValue);
            printf("Element inserted at first position successfully\n");
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last: ");
            scanf("%d", &iValue);
            InsertLast(&head, iValue);
            printf("Element inserted at last position successfully\n");
        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert: ");
            scanf("%d", &iValue);
            printf("Enter The Position That you wanna insert at: ");
            scanf("%d", &iPos);
            InsertAtPos(&head, iValue, iPos);
            printf("Element inserted at %d Position successfully\n", iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element...\n");
            DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element...\n");
            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete: ");
            scanf("%d", &iPos);
            DeleteAtPos(&head, iPos);
            printf("Element deleted at %d Position successfully\n", iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements in Linked List are:\n");
            Display(head);
            printf("\n");
        }
        else if(iChoice == 8)
        {
            iRet = Count(head);
            printf("No of Elements in the Linked List are : %d\n", iRet);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
