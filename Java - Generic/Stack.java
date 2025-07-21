////////////////////////////////////////////////////////////////////////
//
//  Name:        Stack.java 
//  Description: Problems On Data Structures- Stack
//  Author:      Pradhumnya Changdev Kalsait.
//  Date:        14/07/2025
//
////////////////////////////////////////////////////////////////////////

class node<T>
{
    public T data;
    public node<T> next;

    node(T no)
    {
        this.data = no;
        this.next = null;
    }
}

class StackX<T>
{
    private node<T> first;
    int iCount ;
    StackX()
    {
        this.first = null;
        this.iCount =  0;
    }

    public void push(T no)      //InsertFirst
    {
        node<T> newn = null;
        newn = new node<T>(no);
        
        newn.next = first;
        first = newn;

        this.iCount++;
    }

    public T pop()               //Deletefirst
    {
        node<T> temp = null;
        temp = this.first;

        if(temp == null)        //stack is empty
        {
            System.out.println("Unable to POP as stack is empty");
            return null;
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
        node<T> temp = null;
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
public class Stack
{
    public static void main(String A[])
    {
        StackX<Integer> sobj = new StackX<>();
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
