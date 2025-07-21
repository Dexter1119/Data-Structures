////////////////////////////////////////////////////////////////////////
//
//  Name:        program390.cpp 
//  Description: Problems On Data Structures- Stack generic
//  Author:      Pradhumnya Changdev Kalsait.
//  Date:        29-06-2025
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
class Stack
{
    private:

        struct node<T> * first;
        int iCount ;

    public:
        
        Stack();
        void push(T no);
        T pop();
        void Display();
        int Count();

};
template<class T>
Stack<T> :: Stack():first(NULL),iCount(0)
        {

        }

template<class T>
void Stack<T>::push(T no)    // InsertFirst
{
    struct node<T> * newn = NULL;
    newn = new node<T>;

    newn-> data = no;
    newn -> next = NULL;

    newn-> next = this->first;
    this->first = newn;

    this->iCount++;
}

template<class T>
T Stack<T>::pop()        // Deletefirst
{
    
    struct node<T> * temp = NULL;
    T iValue = 0;


    if(this->first == NULL)
    {
        cout<<"STack is Empty..."<<endl;
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
void Stack<T>::Display()
{
    struct node<T> * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|\n";
        temp = temp-> next;
    }

}
template<class T>
int Stack<T>::Count()
{
    return this->iCount;

}

int main()
{
    Stack<int> *sobj = new Stack<int>();
    int iRet = 0;
   

    sobj->push(111);
    sobj->push(101);
    sobj->push(51);
    sobj->push(21);
    sobj->push(11);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"The number of elements in stack are:"<<iRet;


    iRet = sobj->pop();
    cout<<"\nPoped element is :"<<iRet;

    iRet = sobj->pop();
    cout<<"\nPoped element is :"<<iRet;

    iRet = sobj->pop();
    cout<<"\nPoped element is :"<<iRet<<endl;

    sobj->Display();
    iRet = sobj->Count();
    cout<<"The number of elements in stack are:"<<iRet;



    



    return 0;
}