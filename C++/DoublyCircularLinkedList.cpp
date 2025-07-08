////////////////////////////////////////////////////////////////////////
//
//  File Name    : program365.c 
//  Description  : Menu-Driven Program for Doubly Circular Linked List
//  Author       : Pradhumnya Changdev Kalsait
//  Date         : 06/07/2025
//
////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;

} NODE, *PNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCLL();
        void Display();
        int Count();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////
//
// Function Name : DoublyCLL
// Description   : Constructor to initialize the circular doubly linked list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : DoublyCLL()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
DoublyCLL::DoublyCLL()
{
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns the number of nodes in the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : int Count()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int DoublyCLL::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays the elements of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void Display()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::Display()
{
    if (first == NULL && last == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }

    PNODE temp = first;
    cout << "Elements of Linked List are:\n";
    do
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    } while (temp != first);
    cout << "\n";
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a node at the beginning of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void InsertFirst(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if (first == NULL && last == NULL)
    {   
        first = newn;
        last = newn;    
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a node at the end of the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void InsertLast(int no)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void DeleteFirst()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::DeleteFirst()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the list
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void DeleteLast()
// Input Output  : (0 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::DeleteLast()
{
    if (first == NULL && last == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void InsertAtPos(int no, int pos)
// Input Output  : (2 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::InsertAtPos(int no, int pos)
{
    if (pos < 1 || pos > iCount + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        PNODE temp = first;
        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes the node at the given position
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : void DeleteAtPos(int pos)
// Input Output  : (1 input, 0 output)
//
////////////////////////////////////////////////////////////////////
void DoublyCLL::DeleteAtPos(int pos)
{
    if (pos < 1 || pos > iCount)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Menu-driven interface to test all operations
// Author        : Pradhumnya Changdev Kalsait
// Date          : 06/07/2025
// Prototype     : int main()
// Input Output  : (0 input, 1 output)
//
////////////////////////////////////////////////////////////////////
int main()
{
    DoublyCLL dobj;
    int choice = 0, value = 0, pos = 0;

    while (true)
    {
        cout << "\n---------------------------\n";
        cout << " DOUBLY CIRCULAR LINKED LIST MENU \n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At Position\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete At Position\n";
        cout << "7. Display\n";
        cout << "8. Count\n";
        cout << "9. Exit\n";
        cout << "---------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dobj.InsertFirst(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dobj.InsertLast(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                dobj.InsertAtPos(value, pos);
                break;

            case 4:
                dobj.DeleteFirst();
                break;

            case 5:
                dobj.DeleteLast();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                dobj.DeleteAtPos(pos);
                break;

            case 7:
                dobj.Display();
                break;

            case 8:
                cout << "Total nodes: " << dobj.Count() << endl;
                break;

            case 9:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}
