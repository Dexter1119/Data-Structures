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

void DisplayRev(PNODE first,PNODE last)
{
    if (first == NULL && last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    PNODE temp = last;

    do
    {
        printf("|%d|<=>",temp->data);
        temp = temp-> prev;

    } while (temp != last-> prev);
    
    printf("\n");
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
            InsertFirst(&head,&tail,iValue);
            printf("element inserted at first position successfully\n",iPos);
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last:");
            scanf("%d",&iValue);
            InsertLast(&head,&tail,iValue);

        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert :");
            scanf("%d",&iValue);
            printf("Enter The Position That you wanna enter:");
            scanf("%d",&iPos);
            InsertAtPos(&head,&tail,iValue,iPos);
            printf("element inserted at %d Position successfully\n",iPos);

        }
        else if(iChoice == 4)
        {
            printf("Deleting the first Element");
            DeleteLast(&head,&tail);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the Last Element");
            DeleteLast(&head,&tail);
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete:");
            scanf("%d",&iPos);
            DeleteAtPos(&head,&tail,iPos);
            printf("element deleted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 7)
        {
            printf("ELements in Linked List are:\n");
            Display(head,tail);
        }
        else if(iChoice == 8)
        {
            printf("ELements in Linked List in reverse order are:\n");
            DisplayRev(head,tail);
        }
        else if(iChoice == 9)
        {
            iRet = Count(head,tail);
            printf("No of Elements in the Linked List are :%d\n",iRet);
        }
        else
        {
            printf("Invalid Choice");
        }

    }

    return 0;
}