////////////////////////////////////////////////////////////////////////
//
//  Name:        Queue.java 
//  Description: Problems On Data Structures- Queue
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

class QueueX
{
    private node first;
    int iCount ;
    QueueX()
    {
        this.first = null;
        this.iCount =  0;
    }

    public void enqueue(int no)      //InsertLast
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
        }

        else
        {
            temp = first;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        iCount++;
    }

    public int dequeue()            //Deletefirst
    {
        node temp = null;
        temp = this.first;

        if(temp == null)        //Queue is empty
        {
            System.out.println("Unable to remove as Queue is empty");
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
            System.out.print("|"+temp.data+"|-");
            temp = temp.next;
        }

    }
    public int Count()
    {
        return iCount;
    }


}
public class Queue
{
    public static void main(String A[])
    {
        QueueX sobj = new QueueX();
        int iRet = 0;

        sobj.enqueue(10);
        sobj.enqueue(20);
        sobj.enqueue(30);
        sobj.enqueue(40);
        sobj.enqueue(50);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("\nNo of elements in queue are :"+iRet);

        iRet = sobj.dequeue();
        System.out.println("removed elemet from queue is :"+iRet);

        iRet = sobj.dequeue();
        System.out.println("removed elemet from queue is :"+iRet);

        iRet = sobj.dequeue();
        System.out.println("removed elemet from queue is :"+iRet);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("\nNo of elements in queue are :"+iRet);


    }
}
