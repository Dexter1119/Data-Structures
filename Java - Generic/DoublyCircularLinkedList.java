////////////////////////////////////////////////////////////////////
//
// File Name :   DoublyCircularLinkedList.java
// Description : Menu-Driven Program for Doubly Circular Linked List (DCLL)
// Author :      Pradhumnya Changdev Kalsait
// Date :        08/07/25
//
////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class node<T>
{
    public T data;
    public node<T> next;
    public node<T> prev;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : node<T> (Constructor)
    // Description   : Initializes node with data, next & prev set to null
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public node(T no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public node(T no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCLL<T>
{
    private node<T> first;
    private node<T> last;
    private int iCount;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DoublyCLL (Constructor)
    // Description   : Initializes Doubly Circular Linked List
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public DoublyCLL()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public DoublyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertFirst
    // Description   : Inserts a node at the beginning
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertFirst(T no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertFirst(T no)
    {
        node<T> newn = new node<T>(no);

        if (first == null && last == null)
        {
            first = newn;
            last = newn;
            last.next = first;
            first.prev = last;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
            last.next = first;
            first.prev = last;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertLast
    // Description   : Inserts a node<T> at the end
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertLast(T no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertLast(T no)
    {
        node<T> newn = new node<T>(no);

        if (first == null && last == null)
        {
            first = newn;
            last = newn;
            last.next = first;
            first.prev = last;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
            last.next = first;
            first.prev = last;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertAtPos
    // Description   : Inserts a node<T> at given position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertAtPos(T no, int pos)
    // Input Output  : (2 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertAtPos(T no, int pos)
    {
        if (pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }
        else if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            node<T> newn = new node<T>(no);
            node<T> temp = first;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
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
    // Description   : Deletes the first node<T>
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteFirst()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteFirst()
    {
        if (first == null && last == null)
        {
            return;
        }
        else if (first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteLast
    // Description   : Deletes the last node<T>
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteLast()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        if (first == null && last == null)
        {
            return;
        }
        else if (first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteAtPos
    // Description   : Deletes node<T> at a specific position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteAtPos(int pos)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteAtPos(int pos)
    {
        if (pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
            return;
        }
        else if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            node<T> temp = first;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Displays the list in forward direction
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void Display()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void Display()
    {
        if (first == null)
        {
            System.out.println("List is empty.");
            return;
        }

        node<T> temp = first;
        do
        {
            System.out.print("|" + temp.data + "|<->");
            temp = temp.next;
        } while (temp != first);
        System.out.println();
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Returns number of node<T>s in list
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
// Description   : Entry point of the program (DCLL Menu)
// Author        : Pradhumnya Changdev Kalsait
// Date          : 08/07/25
// Prototype     : public static void main(String[] args)
// Input Output  : (0 input, 0 output)
//
// Menu Driven Program
//
////////////////////////////////////////////////////////////////////

public class DoublyCircularLinkedList
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        DoublyCLL<Integer> dobj = new DoublyCLL<>();
        int iChoice = 0, iValue = 0, iPos = 0, iRet = 0;

        System.out.println("-----------------------------------------------------------");
        System.out.println("---- Menu-Driven Program for Doubly Circular Linked List ---");
        System.out.println("-----------------------------------------------------------");

        while (true)
        {
            System.out.println("\n-----------------------------------------------------------");
            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display Elements");
            System.out.println("8 : Count Elements");
            System.out.println("0 : Exit");
            System.out.println("-----------------------------------------------------------");
            System.out.print("Enter your choice: ");
            iChoice = sc.nextInt();

            switch (iChoice)
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
                    System.out.println("First node<T> deleted.");
                    break;

                case 5:
                    dobj.DeleteLast();
                    System.out.println("Last node<T> deleted.");
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
                    System.out.println("Total node<T>s: " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application.");
                    sc.close();
                    dobj = null;
                    System.gc();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
