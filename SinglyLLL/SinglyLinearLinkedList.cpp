////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLLL.cpp
// Description : Buidling Singly Linear Linked List in OOP
// Author     :   Pradhumnya Changdev Kalsait   
// Date       :   02/07/25
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   SinglyLLL
// Description   :   Constructor to initialize the linked list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   SinglyLLL()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    SinglyLLL()
    {
        this -> iCount = 0;
        this -> first = NULL;
    }

////////////////////////////////////////////////////////////////////
//
// Function Name :   Display
// Description   :   Displays the elements of the linked list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void Display()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   Count
// Description   :   Returns the number of nodes in the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   int Count()
// Input Output  :   (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
    int Count()
    {
        return iCount;
    }

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertFirst
// Description   :   Inserts a node at the beginning of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertFirst(int iNo)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertLast
// Description   :   Inserts a node at the end of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertLast(int iNo)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteFirst
// Description   :   Deletes the first node from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteFirst()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteLast
// Description   :   Deletes the last node from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteLast()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name :   InsertAtPos
// Description   :   Inserts a node at the given position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertAtPos(int iNo, int iPos)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
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
            temp -> next = newn;
        }
        iCount++;
    }

////////////////////////////////////////////////////////////////////
//
// Function Name :   DeleteAtPos
// Description   :   Deletes the node at the given position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteAtPos(int iPos)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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
    int iRet = 0;

    SinglyLLL sobj;
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj.InsertAtPos(105,3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj.DeleteAtPos(3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    return 0;
}
