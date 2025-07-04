////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLLL.cpp
// Description : Buidling Singly Linear Linked List in OOP
// Author :      Pradhumnya Changdev Kalsait   
// Date :        02/07/25
//
////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node * next;

}NODE,*PNODE,**PPNODE;

class SinglyLLL
{
    private:
        int iCount;
        PNODE first;

    public:
    SinglyLLL()
    {
        this -> iCount = 0;
        this -> first = NULL;
    }

    void Display()
    {
        PNODE temp = first;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
        }
        cout<<"NULL";

    }
    int Count()
    {
        return iCount;
    }
    
    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        newn = new NODE;
        if(NULL == newn )
        {
            cout<<"Unable to allocate the memory for new node";
            return;
        }

        newn -> data = iNo;
        newn -> next = NULL;
        if(NULL == first)
        {
            first = newn;
        }
        else
        {
            newn -> next = first;
            first = newn;
        }
        iCount++;
    }
    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = new NODE;
        if(NULL == newn )
        {
            cout<<"Unable to allocate the memory for new node";
            return;
        }


        newn -> data = iNo;
        newn -> next = NULL;

        if(NULL == first)
        {
            first = newn;
        }
        else
        {
           temp = first;
           while(temp -> next != NULL)
           {
                temp = temp -> next;
           }
           temp -> next = newn;
        }
        iCount++;

    }
    void DeleteFirst()
    {
        PNODE temp = NULL;
        if(first == NULL)
        {
            return;
        }
        else
        {
            temp = first;
            first = temp -> next;
            delete temp;
            iCount--;
        }
        
    }
    void DeleteLast()
    {
        PNODE temp = NULL;
        if(first == NULL)
        {
            return;
        }
        else
        {

            temp = first;
            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            
            delete temp -> next;
            temp -> next = NULL;
            iCount--;

        }

    }
    void InsertAtPos(int iNo,int iPos)
    {
        if(iPos > iCount+1 || iPos < 1 )
        {
            cout<<"Invalid Position";
            return;
        }
        else if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if( iPos == iCount+1)
        {
            InsertLast(iNo);
        }
        else
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int iCnt = 0;

            newn = new NODE;
            if(NULL == newn)
            {
                cout<<"Unable to allocate the memory for newn node";
                return;
            }

            newn -> data = iNo;
            newn -> next = NULL;
            
            temp = first;
            for(iCnt = 1; iCnt < iPos-1; iCnt++)
            {
                temp = temp -> next;
            }
            newn -> next = temp -> next;
            temp -> next = newn ;

        }
        iCount++;

    }
    void DeleteAtPos(int iPos)
    {
        PNODE temp = NULL;
        PNODE target = NULL;

         if(iPos > iCount+1 || iPos < 1 )
        {
            cout<<"Invalid Position";
            return;
        }
        else if(iPos == 1)
        {
            DeleteFirst();
        }
        else if( iPos == iCount+1)
        {
            DeleteLast();
        }
        else
        {
            
            int iCnt = 0;

            temp = first;
            for(iCnt = 1; iCnt< iPos-1; iCnt++)
            {
                temp = temp -> next;
            }
            target = temp -> next;
            temp -> next = target -> next;
            delete target;
        }
        iCount--;
    }
};
int main()
{
    SinglyLLL sobj;
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
            sobj.InsertFirst( iValue);
            printf("Element inserted at first position successfully\n");
        }
        else if(iChoice == 2)
        {
            printf("Enter The data that you wanna insert last: ");
            scanf("%d", &iValue);
            sobj.InsertLast( iValue);
            printf("Element inserted at last position successfully\n");
        }
        else if(iChoice == 3)
        {
            printf("Enter The data that you wanna insert: ");
            scanf("%d", &iValue);
            printf("Enter The Position That you wanna insert at: ");
            scanf("%d", &iPos);
            sobj.InsertAtPos( iValue, iPos);
            printf("Element inserted at %d Position successfully\n", iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element...\n");
            sobj.DeleteFirst();
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element...\n");
            sobj.DeleteLast();
        }
        else if(iChoice == 6)
        {
            printf("Enter The Position That you wanna delete: ");
            scanf("%d", &iPos);
            sobj.DeleteAtPos(iPos);
            printf("Element deleted at %d Position successfully\n", iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements in Linked List are:\n");
            sobj.Display();
            printf("\n");
        }
        else if(iChoice == 8)
        {
            iRet = sobj.Count();
            printf("No of Elements in the Linked List are : %d\n", iRet);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
