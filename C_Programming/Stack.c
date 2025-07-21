////////////////////////////////////////////////////////////////////
//
// File Name :    Stack.c
// Description :  Buidling Stack Data Structure
// Author     :   Pradhumnya Changdev Kalsait   
// Date       :   14/07/25
//
////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>



typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;


void push(PPNODE first,int no) // InsertFirst
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(NULL == newn )
    {
        printf("UNable to allocate the memory for the new node");
        return;
    }
    
    newn -> data = no;
    newn -> next = NULL;

    newn -> next = *first;
    *first = newn;

}

int pop(PPNODE first)  //DeleteFirst
{
    PNODE temp = NULL;
    int iValue = 0;

    temp = *first;
    *first = (*first) -> next;
    iValue = temp -> data;

    free(temp);
    return iValue;

}

void Display(PNODE first)
{
   while (first != NULL)
    {
        printf("|%d|\n",first->data);
        first = first -> next;
    }
    printf("\n");
    

}

int Count(PNODE first)
{
    int iCOunt = 0;
    while (first != NULL)
    {
        iCOunt++;
        first = first -> next;
    }
    return iCOunt;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    push(&head,11);
    push(&head,21);
    push(&head,51);
    push(&head,101);

    Display(head);
    iRet = Count(head);
    printf("The Number of elements is Stack Are: %d\n",iRet);

    iRet = pop(&head);
    printf("The poped element is :%d\n",iRet);
     Display(head);
    iRet = Count(head);
    printf("The Number of elements is Stack Are: %d\n",iRet);


    iRet = pop(&head);
    printf("The poped element is :%d\n",iRet);
     Display(head);
    iRet = Count(head);
    printf("The Number of elements is Stack Are: %d\n",iRet);


    iRet = pop(&head);
    printf("The poped element is :%d\n",iRet);
     Display(head);
    iRet = Count(head);
    printf("The Number of elements is Stack Are: %d\n",iRet);


    iRet = pop(&head);
    printf("The poped element is :%d\n",iRet);
     Display(head);
    iRet = Count(head);
    printf("The Number of elements is Stack Are: %d\n",iRet);




    



    return 0;
}