////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyCircularLinkedList.java
// Description : Menu-Driven Program for Singly Circular Linked List (SCLL)
// Author :      Pradhumnya Changdev Kalsait
// Date :        08/07/25
//
////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class node
{
    public int data;
    public node next;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : node (Constructor)
    // Description   : Initializes node with data and sets next to null
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
    }
}

class SinglyCLL
{
    private node first;
    private node last;
    private int iCount;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : SinglyCLL (Constructor)
    // Description   : Initializes the singly circular linked list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public SinglyCLL()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public SinglyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertFirst
    // Description   : Inserts node at the beginning of the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertFirst(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if (first == null && last == null)
        {
            first = newn;
            last = newn;
            last.next = first;
        }
        else
        {
            newn.next = first;
            first = newn;
            last.next = first;
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

        if (first == null && last == null)
        {
            first = newn;
            last = newn;
            last.next = first;
        }
        else
        {
            last.next = newn;
            last = newn;
            last.next = first;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertAtPos
    // Description   : Inserts node at a specific position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertAtPos(int no, int pos)
    // Input Output  : (2 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertAtPos(int no, int pos)
    {
        if (pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
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
            node newn = new node(no);
            node temp = first;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteFirst
    // Description   : Deletes the first node in the list
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
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteLast
    // Description   : Deletes the last node in the list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteLast()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        node temp = null;

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
            temp = first;

            while (temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteAtPos
    // Description   : Deletes node at a specific position
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
            node temp = first;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            iCount--;
        }
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Displays all elements in the list
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

        node temp = first;

        do
        {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        } while (temp != first);

        System.out.println();
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Returns number of nodes in the list
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
// Description   : Entry point of the program (Singly Circular LL demo)
// Author        : Pradhumnya Changdev Kalsait
// Date          : 08/07/25
// Prototype     : public static void main(String[] args)
// Input Output  : (0 input, 0 output)
//
// Menu Driven Program
//
////////////////////////////////////////////////////////////////////

public class SinglyCircularLinkedList
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        SinglyCLL sobj = new SinglyCLL();
        int iChoice = 0, iValue = 0, iPos = 0, iRet = 0;

        System.out.println("-------------------------------------------------------------");
        System.out.println("-------- Menu-Driven Program For Singly Circular LL --------");
        System.out.println("-------------------------------------------------------------");

        while (true)
        {
            System.out.println("\n-------------------------------------------------------------");
            System.out.println("1 : Insert First");
            System.out.println("2 : Insert Last");
            System.out.println("3 : Insert At Position");
            System.out.println("4 : Delete First");
            System.out.println("5 : Delete Last");
            System.out.println("6 : Delete At Position");
            System.out.println("7 : Display Elements");
            System.out.println("8 : Count Elements");
            System.out.println("0 : Exit");
            System.out.println("-------------------------------------------------------------");
            System.out.print("Enter your choice: ");
            iChoice = sc.nextInt();

            switch (iChoice)
            {
                case 1:
                    System.out.print("Enter data to insert first: ");
                    iValue = sc.nextInt();
                    sobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter data to insert last: ");
                    iValue = sc.nextInt();
                    sobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter data: ");
                    iValue = sc.nextInt();
                    System.out.print("Enter position: ");
                    iPos = sc.nextInt();
                    sobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    sobj.DeleteFirst();
                    System.out.println("First element deleted.");
                    break;

                case 5:
                    sobj.DeleteLast();
                    System.out.println("Last element deleted.");
                    break;

                case 6:
                    System.out.print("Enter position to delete: ");
                    iPos = sc.nextInt();
                    sobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    System.out.println("Elements in Linked List:");
                    sobj.Display();
                    break;

                case 8:
                    iRet = sobj.Count();
                    System.out.println("Number of elements: " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application.");
                    sc.close();
                    sobj = null;
                    System.gc();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
