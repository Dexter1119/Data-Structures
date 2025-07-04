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
        SinglyCLL()
        {
            this -> first = NULL;
            this -> last = NULL;
            this -> iCount = 0;
        }
        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);  

};

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

int SinglyCLL::Count()
{
    return iCount;   
}
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

void SinglyCLL::DeleteFirst()
{   PNODE target =NULL;

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
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;

    sobj.InsertAtPos(105,3);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;

    sobj.DeleteAtPos(3);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"\n The number of elements in linked list are:"<<iRet<<endl;




    return 0;
}