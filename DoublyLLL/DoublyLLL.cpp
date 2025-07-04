////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLLL.cpp
// Description : Buidling Singly Linear Linked List
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
    struct node * prev;
   

}NODE,*PNODE;

class DoublyLLL
{
    private:
        PNODE first;
        
        int count;
    public :
        DoublyLLL()
        {
            this -> first = NULL;
            this -> count = 0;
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

void DoublyLLL::Display()
{
    PNODE temp = first;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int DoublyLLL::Count()
{
    return count;
}

void DoublyLLL::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    if(NULL == newn)
    {
        cout<<"Unable to allocate the memory"<<endl;
        return;
    }

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(NULL == first)
    {
        first = newn;
        count++;
    }
    else
    {
        newn -> next = first;

        first = newn;

        newn -> next -> prev = first;
        count++;
    }

}

void DoublyLLL::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;
    if(NULL == newn)
    {
        cout<<"Unable to allocate the memory"<<endl;
        return;
    }

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(NULL == first)
    {
        first = newn;
        count++;
    }
    else
    {
        temp = first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
        count++;

    }
}


void DoublyLLL::DeleteFirst()
{
    PNODE temp = NULL;
    if(NULL == first)
    {
        return;
    }
    else
    {
        temp = first;
        first = temp -> next;
        first -> next -> prev = first;

        delete temp;
        count--;
    }
}
void DoublyLLL::DeleteLast()
{
    PNODE temp = NULL;
    PNODE target = NULL;
    if(NULL == first)
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
        target = temp -> next;
        temp -> next = NULL;

        delete target;
        count--;

    }

}
void DoublyLLL::InsertAtPos(int no,int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
 

    
    if(iPos < 1 || iPos > count+1)
    {
        printf("Invalid Position");
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;
        if(NULL == newn)
        {
            cout<<"Unable to allocate the memory"<<endl;
            return;
        }

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;


        temp = first;

        for(iCnt = 1; iCnt< iPos -1;iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        temp -> next = newn;
        count++;
    }
}

void DoublyLLL::DeleteAtPos(int iPos)
{
    PNODE target = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
 

    
    if(iPos < 1 || iPos > count)
    {
        printf("Invalid Position");
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == count)
    {
        DeleteLast();
    }
    else
    {
        
        temp = first;
        for(iCnt = 1; iCnt< iPos -1;iCnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        target -> next -> prev = temp;
        delete target;
        count--;
    }
}
int main()
{
    DoublyLLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;


    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;

    dobj.InsertAtPos(105,3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;

    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"the number of elements in doubly linked list are:"<<iRet<<endl;



    return 0;
}