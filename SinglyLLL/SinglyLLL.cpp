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