////////////////////////////////////////////////////////////////////
//
// File Name   :  SinglyLinearLinkedList.cpp
// Description :  Buidling Singly Linear Linked List in OOP
// Author      :  Pradhumnya Changdev Kalsait   
// Date        :  14/07/25
//
////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
template<class T>
struct node
{
    T data;
    struct node<T>* next;

};

template<class T>
class SinglyLLL
{
    private:
        int iCount;
        struct node<T>* first;

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
        struct node<T>* temp = first;
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
// Description   :   Inserts a node<T>at the beginning of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertFirst(int iNo)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    void InsertFirst(T iNo)
    {
        struct node<T>* newn = NULL;
        newn = new node<T>;
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
// Description   :   Inserts a node<T>at the end of the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertLast(int iNo)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    void InsertLast(T iNo)
    {
        struct node<T>* newn = NULL;
        struct node<T>* temp = NULL;

        newn = new node<T>;
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
// Description   :   Deletes the first node<T>from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteFirst()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    void DeleteFirst()
    {
        struct node<T>* temp = NULL;
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
// Description   :   Deletes the last node<T>from the list
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteLast()
// Input Output  :   (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    void DeleteLast()
    {
        struct node<T>* temp = NULL;
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
// Description   :   Inserts a node<T>at the given position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void InsertAtPos(int iNo, int iPos)
// Input Output  :   (2 inputs, 0 output)
//
////////////////////////////////////////////////////////////////////
    void InsertAtPos(T iNo,int iPos)
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
            struct node<T>* newn = NULL;
            struct node<T>* temp = NULL;
            int iCnt = 0;

            newn = new node<T>;
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
// Description   :   Deletes the node<T>at the given position
// Author        :   Pradhumnya Changdev Kalsait
// Date          :   02/07/25
// Prototype     :   void DeleteAtPos(int iPos)
// Input Output  :   (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
    void DeleteAtPos(int iPos)
    {
        struct node<T>* temp = NULL;
        struct node<T>* target = NULL;

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

    SinglyLLL<int> sobj;
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

    cout<<"__________________________________________________________________________-"<<endl;
    SinglyLLL<double> sobj1;
    sobj1.InsertFirst(51.0);
    sobj1.InsertFirst(21);
    sobj1.InsertFirst(11);

    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj1.InsertLast(101);
    sobj1.InsertLast(111);

    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj1.DeleteFirst();
    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj1.DeleteLast();
    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj1.InsertAtPos(105,3);
    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    sobj1.DeleteAtPos(3);
    sobj1.Display();
    iRet = sobj1.Count();
    cout<<"\nThe number of elements in Linked List are:"<<iRet<<endl;

    return 0;

}
