////////////////////////////////////////////////////////////////////////
//
//  Name:        Stack.java 
//  Description: Problems On Data Structures- Stack
//  Author:      Pradhumnya Changdev Kalsait.
//  Date:        12/07/2025
//
////////////////////////////////////////////////////////////////////////

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class StackX
{
    private node first;
    int iCount ;
    StackX()
    {
        this.first = null;
        this.iCount =  0;
    }

    public void push(int no)      //InsertFirst
    {
        node newn = null;
        newn = new node(no);
        
        newn.next = first;
        first = newn;

        this.iCount++;
    }

    public int pop()            //Deletefirst
    {
        node temp = null;
        temp = this.first;

        if(temp == null)        //stack is empty
        {
            System.out.println("Unable to POP as stack is empty");
            return -1;
        }
        else
        {
            first = first.next;
            iCount--;

            return temp.data;
        }

       
    }
    public void Display()
    {
        node temp = null;
        temp = this.first;
        while(temp != null)
        {
            System.out.println("|"+temp.data+"|");
            temp = temp.next;
        }

    }
    public int Count()
    {
        return iCount;
    }


}
public class Stack {
    public static void main(String A[])
    {
        StackX sobj = new StackX();
        int iRet = 0;

        sobj.push(10);
        sobj.push(20);
        sobj.push(30);
        sobj.push(40);
        sobj.push(50);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("The number of elements in stack are :"+iRet);

        iRet = sobj.pop();
        System.out.println("The poped element in stack is :"+iRet);

        iRet = sobj.pop();
        System.out.println("The poped element in stack is :"+iRet);

        iRet = sobj.pop();
        System.out.println("The poped element in stack is :"+iRet);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("The number of elements in stack are :"+iRet);


    }
}
