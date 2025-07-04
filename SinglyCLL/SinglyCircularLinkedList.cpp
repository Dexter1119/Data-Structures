////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyCLL.cpp
// Description : Buidling Singly Circular Linked List - OOP Design
// Author :      Pradhumnya Changdev Kalsait   
// Date :        03/07/25
//
////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;
    public:
        SinglyCLL();

        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);  
};

////////////////////////////////////////////////////////////////////
//
// Function Name : SinglyCLL
// Description   : Constructor to initialize data members
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : SinglyCLL::SinglyCLL()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
SinglyCLL::SinglyCLL()
{
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::Display()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::Display()
{
    PNODE temp = NULL;
    temp = first;
    do
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp -> next;

    } while (temp != first);
    cout<<"NULL"<<endl;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns number of elements in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : int SinglyCLL::Count()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int SinglyCLL::Count()
{
    return iCount;   
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts new node at the beginning
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::InsertFirst(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(NULL == newn)
    {
        cout<<"Unable to allocate the memory for new node\n";
        return;
    }

    newn -> data = no;
    newn -> next = NULL;

    if((NULL == first)&& (NULL == last))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
        last -> next = first; 
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts new node at the end
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::InsertLast(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(NULL == newn)
    {
        cout<<"Unable to allocate the memory for new node\n";
        return;
    }

    newn -> data = no;
    newn -> next = NULL;

    if((NULL == first)&& (NULL == last))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        last = newn;
        last -> next = first;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes first node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::DeleteFirst()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::DeleteFirst()
{
    PNODE target =NULL;

    if(first == NULL && NULL == last)
    {
        return;
    }
    else
    {
        target = first;
        first = target -> next;
        last -> next = first;
        delete target;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes last node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::DeleteLast()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::DeleteLast()
{
    PNODE target =NULL;
    PNODE temp = NULL;

    if(first == NULL && NULL == last)
    {
        return;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        last = temp;
        last -> next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts new node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::InsertAtPos(int no, int pos)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::InsertAtPos(int no,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position";
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        if(NULL == newn)
        {
            cout<<"Unable to allocate the memory for new node\n";
            return;
        }

        newn -> data = no;
        newn -> next = NULL;

        temp = first;
        for(iCnt = 1;iCnt < pos -1 ; iCnt++ )
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes node at given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 03/07/25
// Prototype     : void SinglyCLL::DeleteAtPos(int pos)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void SinglyCLL::DeleteAtPos(int pos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position";
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1 ; iCnt < pos-1 ; iCnt++ )
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        delete target;
        iCount--;
    }
}

int main()
{
    SinglyCLL sobj;
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
            sobj.InsertFirst(iValue);
            printf("element inserted at first position successfully\n");
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last:");
            scanf("%d",&iValue);
            sobj.InsertLast(iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert :");
            scanf("%d",&iValue);
            printf("Enter The Position That you wanna enter:");
            scanf("%d",&iPos);
            sobj.InsertAtPos(iValue,iPos);
            printf("element inserted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first Element");
            sobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            printf("Deleting the Last Element");
            sobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete:");
            scanf("%d",&iPos);
            sobj.DeleteAtPos(iPos);
            printf("element deleted at %d Position successfully\n",iPos);
        }
        else if(iChoice == 7)
        {
            printf("ELements in Linked List are:\n");
            sobj.Display();
        }
        else if(iChoice == 8)
        {
            iRet = sobj.Count();
            printf("No of Elements in the Linked List are :%d\n",iRet);
        }
        else
        {
            printf("Invalid Choice");
        }
    }

    return 0;
}
