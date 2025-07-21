////////////////////////////////////////////////////////////////////
//
// File Name :   SinglyLinearLinkedList.java
// Description : Menu-Driven Program for Singly Linear Linked List
// Author :      Pradhumnya Changdev Kalsait
// Date :        08/07/25
//
////////////////////////////////////////////////////////////////////

import java.util.Scanner;

////////////////////////////////////////////////////////////////////
//
// Class Name : Node<T>
// Description : Defines structure of a Node<T>
// Author     : Pradhumnya Changdev Kalsait
// Date       : 08/07/25
//
////////////////////////////////////////////////////////////////////
class Node<T>
{
    public T data;
    public Node<T> next;

    public Node(T no)
    {
        this.data = no;
        this.next = null;
    }

    protected void finalize()
    {
        System.out.println("Inside Finalize");
    }
}

////////////////////////////////////////////////////////////////////
//
// Class Name : SinglyLL
// Description : Defines Singly Linear Linked List operations
// Author     : Pradhumnya Changdev Kalsait
// Date       : 08/07/25
//
////////////////////////////////////////////////////////////////////
class SinglyLL<T>
{
    private Node<T> first;
    private int iCount;

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : SinglyLL (Constructor)
    // Description   : Initializes the linked list
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public SinglyLL()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertFirst
    // Description   : Inserts element at the beginning
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertFirst(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertFirst(T no)
    {
        Node<T> newn = new Node<T>(no);
        if (first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertLast
    // Description   : Inserts element at the end
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertLast(int no)
    // Input Output  : (1 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void InsertLast(T no)
    {
        Node<T> newn = new Node<T>(no);
        if (first == null)
        {
            first = newn;
        }
        else
        {
            Node<T> temp = first;
            while (temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteFirst
    // Description   : Deletes element from the beginning
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteFirst()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteFirst()
    {
        if (first == null)
        {
            return;
        }
        else if (first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : DeleteLast
    // Description   : Deletes element from the end
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void DeleteLast()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        if (first == null)
        {
            return;
        }
        else if (first.next == null)
        {
            first = null;
        }
        else
        {
            Node<T> temp = first;
            while (temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : InsertAtPos
    // Description   : Inserts element at a given position
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void InsertAtPos(int no, int pos)
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
            Node<T> newn = new Node<T>(no);
            Node<T> temp = first;
            for (int i = 1; i < pos - 1; i++)
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
    // Function Name : DeleteAtPos
    // Description   : Deletes element at a given position
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
            Node<T> temp = first;
            for (int i = 1; i < pos - 1; i++)
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
    // Description   : Displays all elements
    // Author        : Pradhumnya Changdev Kalsait
    // Date          : 08/07/25
    // Prototype     : public void Display()
    // Input Output  : (0 input, 0 output)
    //
    ////////////////////////////////////////////////////////////////////
    public void Display()
    {
        Node<T> temp = first;
        while (temp != null)
        {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    ////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Returns number of elements
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
// Description   : Entry point of the program
// Author        : Pradhumnya Changdev Kalsait
// Date          : 08/07/25
// Prototype     : public static void main(String[] args)
// Input Output  : (0 input, 0 output)
//
// Menu Driven Program
//
////////////////////////////////////////////////////////////////////
public class SinglyLinearLinkedList
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        SinglyLL<Integer> sobj = new SinglyLL<>();
        int iValue, iChoice, iPos, iRet;

        System.out.println("-----------------------------------------------------------------");
        System.out.println("-------------------Singly Linear Linked List---------------------");
        System.out.println("-----------------------------------------------------------------");

        while (true)
        {
            System.out.println("-----------------------------------------------------------------");
            System.out.println("-------------Please Select The Option----------------------------");
            System.out.println("-----------------------------------------------------------------");
            System.out.println("1: Insert First");
            System.out.println("2: Insert Last");
            System.out.println("3: Insert At Position");
            System.out.println("4: Delete First");
            System.out.println("5: Delete Last");
            System.out.println("6: Delete At Position");
            System.out.println("7: Display Elements");
            System.out.println("8: Count Elements");
            System.out.println("0: Exit");
            System.out.println("-----------------------------------------------------------------");
            System.out.print("Enter Your Choice: ");
            iChoice = sc.nextInt();

            switch (iChoice)
            {
                case 0:
                    System.out.println("Thank You For Using The Application");
                    return;

                case 1:
                    System.out.print("Enter Data to Insert First: ");
                    iValue = sc.nextInt();
                    sobj.InsertFirst(iValue);
                    break;

                case 2:
                    System.out.print("Enter Data to Insert Last: ");
                    iValue = sc.nextInt();
                    sobj.InsertLast(iValue);
                    break;

                case 3:
                    System.out.print("Enter Data: ");
                    iValue = sc.nextInt();
                    System.out.print("Enter Position: ");
                    iPos = sc.nextInt();
                    sobj.InsertAtPos(iValue, iPos);
                    break;

                case 4:
                    System.out.println("Deleting First Element...");
                    sobj.DeleteFirst();
                    break;

                case 5:
                    System.out.println("Deleting Last Element...");
                    sobj.DeleteLast();
                    break;

                case 6:
                    System.out.print("Enter Position to Delete: ");
                    iPos = sc.nextInt();
                    sobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    System.out.println("Elements in Linked List:");
                    sobj.Display();
                    break;

                case 8:
                    iRet = sobj.Count();
                    System.out.println("Number of Elements: " + iRet);
                    sc.close();
                    break;

                default:
                    System.out.println("Invalid Choice");
                    sc.close();
                    break;
            }

        }
        
    }
}
