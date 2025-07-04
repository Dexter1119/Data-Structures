////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLinearLinkedListMenu.c
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


////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays the elements of the doubly linked list
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
        first = first -> next;
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
        first = first -> next;
    }
    while(first  != NULL)
    {
        printf("|%d|<=>", first->data);
        first = first -> prev;
    }
    printf("NULL");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Counts the number of elements in the list
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
        first = first -> next;
    }
    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts new node at first position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertFirst(PPNODE first,int iNo)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts new node at last position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertLast(PPNODE first, int iNo)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteFirst(PPNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteLast(PPNODE first)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts node at given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertAtPos(PPNODE first, int iNo, int iPos)
// Input Output  : (3 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes node at given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteAtPos(PPNODE first, int iPos)
// Input Output  : (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point function for the application
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
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
    printf("-------------------Doubly Linear Linked List---------------------\n");
    printf("-----------------------------------------------------------------\n");
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
        printf("8: Display All Elements in Linked List in reverse order\n");
        printf("9: Count All Elements in Linked List\n");
        printf("0: To Exit from Application\n");
        printf("-----------------------------------------------------------------\n"); 

        printf("Enter Your Choice:");
        scanf("%d",&iChoice);
        if(iChoice == 0)
        {
            printf("Thank You For Using The Application\n");
            printf("\n-----------------------------------------------------------------\n"); 
            break;


        }
        else if(iChoice == 1)
        {
            printf("Enter The data that you wanna insert First:");
            scanf("%d",&iValue);
            InsertFirst(&head,iValue);
            printf("element inserted at first position successfully\n",iPos);
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last:");
            scanf("%d",&iValue);
            InsertLast(&head,iValue);

        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert :");
            scanf("%d",&iValue);
            printf("Enter The Position That you wanna enter:");
            scanf("%d",&iPos);
            InsertAtPos(&head,iValue,iPos);
            printf("element inserted at %d Position successfully\n",iPos);

        }
        else if(iChoice == 4)
        {
            printf("Deleting the first Element");
            DeleteLast(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the Last Element");
            DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete:");
            scanf("%d",&iPos);
            DeleteAtPos(&head,iPos);
            printf("element deleted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 7)
        {
            printf("ELements in Linked List are:\n");
            Display(head);
        }
        else if(iChoice == 8)
        {
            printf("ELements in Linked List in reverse order are:\n");
            DisplayRev(head);
        }
        else if(iChoice == 9)
        {
            iRet = Count(head);
            printf("No of Elements in the Linked List are :%d\n",iRet);
        }
        else
        {
            printf("Invalid Choice");
        }

    }

    return 0;
}