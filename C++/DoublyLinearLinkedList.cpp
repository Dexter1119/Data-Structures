////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLinearLinkedList.cpp
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

} NODE, *PNODE;

class DoublyLLL
{
    private:
        PNODE first;
        int count;

    public:
        DoublyLLL();
        void Display();
        int Count();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
};

DoublyLLL::DoublyLLL()
{
    this->first = NULL;
    this->count = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays the elements of the doubly linked list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void Display()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns the number of elements in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int Count()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int DoublyLLL::Count()
{
    return count;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a node at the beginning of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertFirst(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    if(newn == NULL)
    {
        cout << "Unable to allocate memory" << endl;
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    count++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a node at the end of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertLast(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    if(newn == NULL)
    {
        cout << "Unable to allocate memory" << endl;
        return;
    }

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        PNODE temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    count++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteFirst()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }

    PNODE temp = first;
    first = first->next;

    if(first != NULL)
    {
        first->prev = NULL;
    }

    delete temp;
    count--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteLast()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }

    PNODE temp = first;

    if(temp->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        delete target;
        temp->next = NULL;
    }
    count--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at a given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void InsertAtPos(int no, int pos)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::InsertAtPos(int no, int pos)
{
    if(pos < 1 || pos > count + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == count + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        if(newn == NULL)
        {
            cout << "Unable to allocate memory" << endl;
            return;
        }

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        count++;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes the node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : void DeleteAtPos(int pos)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyLLL::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > count)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == count)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        PNODE target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        count--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point of the program for testing DLL operations
// Author        : Pradhumnya Changdev Kalsait
// Date          : 02/07/25
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    DoublyLLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    dobj.InsertAtPos(105, 3);
    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet = dobj.Count();
    cout << "The number of elements in doubly linked list are: " << iRet << endl;

    return 0;
}
