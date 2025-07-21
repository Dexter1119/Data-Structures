////////////////////////////////////////////////////////////////////////
//
//  Name:        Queue.cpp 
//  Description: Problems On Data Structures- Queue
//  Author:      Pradhumnya Changdev Kalsait.
//  Date:        29-06-2025
//
////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};


class Queue
{
    private:

        struct node* first;
        int iCount ;

    public:
        
        Queue();
        void enqueue(int no);
        int dequeue();
        void Display();
        int Count();

};

Queue :: Queue():first(NULL),iCount(0)
        {

        }
void Queue::enqueue(int no)    // InsertLast
{
    struct node * newn = NULL;
    struct node * temp = NULL;
    newn = new node;

    newn-> data = no;
    newn -> next = NULL;

    if(NULL == this->first)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    

    this->iCount++;
}

int Queue::dequeue()        // Deletefirst
{
    
    struct node * temp = NULL;
    int iValue = 0;


    if(this->first == NULL)
    {
        cout<<"Queue is Empty..."<<endl;
        return NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        iCount--;
        iValue = temp->data;
        delete temp;
        return iValue;
        
        

    }



}

void Queue::Display()
{
    struct node * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|-";
        temp = temp-> next;
    }

}

int Queue::Count()
{
    return this->iCount;

}

int main()
{
    Queue *sobj = new Queue();
    int iRet = 0;
   

    sobj->enqueue(111);
    sobj->enqueue(101);
    sobj->enqueue(51);
    sobj->enqueue(21);
    sobj->enqueue(11);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"The number of elements in Queue are:"<<iRet;


    iRet = sobj->dequeue();
    cout<<"\ndequeueed element is :"<<iRet;

    iRet = sobj->dequeue();
    cout<<"\ndequeueed element is :"<<iRet;

    iRet = sobj->dequeue();
    cout<<"\ndequeueed element is :"<<iRet<<endl;

    sobj->Display();
    iRet = sobj->Count();
    cout<<"The number of elements in Queue are:"<<iRet;



    



    return 0;
}