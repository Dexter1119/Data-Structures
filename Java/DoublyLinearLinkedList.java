////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyLinearLinkedList.java
// Description : Menu-Driven Program for Doubly Linear Linked List (DoublyLLL)
// Author :      Pradhumnya Changdev Kalsait
// Date :        08/07/25
//
////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class node
{
    public int data;
    public node next;
    public node prev;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : node (Constructor)
    // Description   : Initializes node with data, next & prev as null
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public node(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLLL
{
    private node first;
    private int iCount;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DoublyLLL (Constructor)
    // Description   : Initializes the Doubly Linear Linked List
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public DoublyLLL()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertFirst
    // Description   : Inserts node at the beginning of list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertFirst(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertLast
    // Description   : Inserts node at the end of the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertLast(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.prev = temp;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertAtPos
    // Description   : Inserts node at a given position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertAtPos(int no, int pos)
    // Input Output  : (2 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node(no);
            node temp = first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;
            temp.next.prev = newn;
            temp.next = newn;

            iCount++;
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteFirst
    // Description   : Deletes first node in the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteFirst()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else
        {
            first = first.next;
            if(first != null)
            {
                first.prev = null;
            }
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteLast
    // Description   : Deletes last node in the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteLast()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            node temp = first;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteAtPos
    // Description   : Deletes node at a given position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteAtPos(int pos)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            node temp = first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            if(temp.next != null)
            {
                temp.next.prev = temp;
            }

            iCount--;
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Displays all elements of the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void Display()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("|" + temp.data + "|<=>");
            temp = temp.next;
        }
        System.out.println("null");
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Returns the number of nodes in list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public int Count()
    // Input Output  : (0 input, 1 output)
    //
    ////////////////////////////////////////////////////////////////////
    public int Count()
    {
        return iCount;
    }
}

////////////////////////////////////////////////////////////////////
//
// Function Name : main
// Description   : Entry point of the program (DoublyLLL Menu)
// Author        : Pradhumnya Changdev Kalsait
// Date          : 08/07/25
// Prototype     : public static void main(String[] args)
// Input Output  : (0 input, 0 output)
//
// Menu-Driven Program
//
////////////////////////////////////////////////////////////////////

public class DoublyLinearLinkedList
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        DoublyLLL dobj = new DoublyLLL();
        int iChoice = 0, iValue = 0, iPos = 0, iRet = 0;

        System.out.println("--------------------------------------------------------------");
        System.out.println("--- Menu-Driven Program for Doubly Linear Linked List (DLL) ---");
        System.out.println("--------------------------------------------------------------");

        while(true)
        {
            System.out.println("\n--------------------------------------------------------------");
            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display Elements");
            System.out.println("8 : Count Elements");
            System.out.println("0 : Exit");
            System.out.println("--------------------------------------------------------------");
            System.out.print("Enter your choice: ");
            iChoice = sc.nextInt();

            switch(iChoice)
            {
                case 1:
                    System.out.print("Enter data: ");
                    iValue = sc.nextInt();
                    dobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data: ");
                    iValue = sc.nextInt();
                    dobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data: ");
                    iValue = sc.nextInt();
                    System.out.print("Enter position: ");
                    iPos = sc.nextInt();
                    dobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    dobj.DeleteFirst();
                    System.out.println("First node deleted.");
                    break;

                case 5:
                    dobj.DeleteLast();
                    System.out.println("Last node deleted.");
                    break;

                case 6:
                    System.out.print("Enter position to delete: ");
                    iPos = sc.nextInt();
                    dobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    System.out.println("Elements in the list:");
                    dobj.Display();
                    break;

                case 8:
                    iRet = dobj.Count();
                    System.out.println("Total number of elements: " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application.");
                    sc.close();
                    dobj = null;
                    System.gc();
                    return;

                default:
                    System.out.println("Invalid choice. Try again.");
                    break;
            }
        }
    }
}
