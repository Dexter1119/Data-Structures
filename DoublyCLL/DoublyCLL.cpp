////////////////////////////////////////////////////////////////////
//
// File Name   : DoublyCLL.cpp
// Description : Buidling Doubly Circular Linked List->OOP design
// Author      : Pradhumnya Changdev Kalsait   
// Date        : 03/07/25
// 
////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE, *PNODE, **PPNODE;

class DoublyCLL
{   
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCLL()
    {
        this -> first = NULL;
        this -> last = NULL;
        this -> iCount = 0;
    }
    int Count();
    void Display();
    void DisplayRev();

    void InsertFirst(int no);
    void InsertLast(int no);
    void DeleteFirst();
    void DeleteLast();
    
   
    void InsertAtPos(int iPos, int no);
    void DeleteAtPos(int iPos);
};

int DoublyCLL::Count()
{
    return iCount;
    
}


int main()
{
    DoublyCLL dobj;
    int iValue = 0;
    int iChoice = 0;
    int iPos = 0;
    int iRet = 0;

    cout << "-----------------------------------------------------------------\n";
    cout << "-------------------Doubly Circular Linked List-------------------\n";
    cout << "-----------------------------------------------------------------\n";

    while (1)
    {
        cout << "-----------------------------------------------------------------\n";
        cout << "------------------Please Select The Option-----------------------\n";
        cout << "-----------------------------------------------------------------\n"; 
        cout << "1: Insert New Node At First Position\n";
        cout << "2: Insert New Node At Last Position\n";
        cout << "3: Insert New Node At Given Position\n";
        cout << "4: Delete Node At First Position\n";
        cout << "5: Delete Node At Last Position\n";
        cout << "6: Delete Node At Given Position\n";
        cout << "7: Display All Elements in Linked List\n";
        cout << "8: Display All Elements in Linked List in reverse order\n";
        cout << "9: Count All Elements in Linked List\n";
        cout << "0: To Exit from Application\n";
        cout << "-----------------------------------------------------------------\n"; 

        cout << "Enter Your Choice:";
        cin >> iChoice;
        
        if (iChoice == 0)
        {
            cout << "Thank You For Using The Application\n";
            break;
        }
        
        switch (iChoice)
        {
            case 1:
                cout << "Enter The data that you wanna insert First:";
                cin >> iValue;
                dobj.InsertFirst(iValue);
                break;

            case 2:
                cout << "Enter The data that you wanna insert Last:";
                cin >> iValue;
                dobj.InsertLast(iValue);
                break;

            case 3:
                cout << "Enter The position and data to insert at that position:";
                cin >> iPos >> iValue;
                dobj.InsertAtPos(iPos, iValue);
                break;

            case 4:
                dobj.DeleteFirst();
                break;

            case 5:
                dobj.DeleteLast();
                break;

            case 6:
                cout << "Enter the position to delete node at that position:";
                cin >> iPos;
                dobj.DeleteAtPos(iPos);
                break;

            case 7:
                dobj.Display();
                break;

            case 8:
                dobj.DisplayRev();
                break;
            case 9:
                iRet = dobj.Count();
                cout << "Total Elements: " << iRet << endl;
                break;

        }
    }
}