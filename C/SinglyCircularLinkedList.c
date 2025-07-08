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

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements in the circular list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void Display(PNODE first, PNODE last)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void Display(PNODE first,PNODE last)
{
    do
    {
        printf("|%d|->",first->data);
        first = first-> next;
    }while(first != (last-> next));
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Counts number of nodes in the circular list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int Count(PNODE first, PNODE last)
// Input Output  : (2 input, 1 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertFirst(PPNODE first, PPNODE last, int no)
// Input Output  : (3 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertLast(PPNODE first, PPNODE last, int no)
// Input Output  : (3 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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
        temp = *last;
        temp -> next = newn;
        *last = newn;
        (*last) -> next = *first;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFrist
// Description   : Deletes the first node in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteFrist(PPNODE first, PPNODE last)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteLast(PPNODE first, PPNODE last)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at a specific position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertAtPos(PPNODE first, PPNODE last, int no, int iPos)
// Input Output  : (4 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from a specific position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
// Input Output  : (3 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point of the program with menu-driven logic
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    PNODE last = NULL;

    int iValue = 0;
    int iChoice = 0;
    int iPos = 0;
    int iRet = 0;

    printf("-----------------------------------------------------------------\n");
    printf("------------------Singly Circular Linked List--------------------\n");

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
            InsertFirst(&head,&last,iValue);
            printf("element inserted at first position successfully\n",iPos);
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last:");
            scanf("%d",&iValue);
            InsertLast(&head,&last,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert :");
            scanf("%d",&iValue);
            printf("Enter The Position That you wanna enter:");
            scanf("%d",&iPos);
            InsertAtPos(&head,&last,iValue,iPos);
            printf("element inserted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first Element");
            DeleteLast(&head,&last);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the Last Element");
            DeleteLast(&head,&last);
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete:");
            scanf("%d",&iPos);
            DeleteAtPos(&head,&last,iPos);
            printf("element deleted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 7)
        {
            printf("ELements in Linked List are:\n");
            Display(head,last);
        }
        else if(iChoice == 8)
        {
            iRet = Count(head,last);
            printf("No of Elements in the Linked List are :%d\n",iRet);
        }
        else
        {
            printf("Invalid Choice");
        }
    }

    return 0;
}
