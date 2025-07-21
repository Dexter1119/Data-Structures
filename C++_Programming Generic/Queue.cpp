////////////////////////////////////////////////////////////////////////
//
//  Name:        Queue.cpp 
//  Description: Problems On Data Structures- Queue generic
//  Author:      Pradhumnya Changdev Kalsait.
//  Date:        12-07-25
//
////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class Queue
{
    private:

        struct node<T>* first;
        int iCount ;

    public:
        
        Queue();
        void enqueue(T no);
        T dequeue();
        void Display();
        int Count();

};
template<class T>
Queue<T> :: Queue():first(NULL),iCount(0)
        {

        }

template<class T>
void Queue<T>::enqueue(T no)    // InsertLast
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;
    newn = new node<T>;

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
template<class T>
T Queue<T>::dequeue()        // Deletefirst
{
    
    struct node<T> * temp = NULL;
    T iValue;


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
template<class T>
void Queue<T>::Display()
{
    struct node<T> * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|-";
        temp = temp-> next;
    }

}
template<class T>
int Queue<T>::Count()
{
    return this->iCount;

}

int main()
{
    Queue<int> *sobj = new Queue<int>();
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