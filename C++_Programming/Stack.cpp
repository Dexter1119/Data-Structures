////////////////////////////////////////////////////////////////////////
//
//  Name:        Stack.cpp 
//  Description: Problems On Data Structures- Stack
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


class Stack
{
    private:

        struct node* first;
        int iCount ;

    public:
        
        Stack();
        void push(int no);
        int pop();
        void Display();
        int Count();

};

Stack :: Stack():first(NULL),iCount(0)
        {

        }
void Stack::push(int no)    // InsertFirst
{
    struct node * newn = NULL;
    newn = new node;

    newn-> data = no;
    newn -> next = NULL;

    newn-> next = this->first;
    this->first = newn;

    this->iCount++;
}

int Stack::pop()        // Deletefirst
{
    
    struct node * temp = NULL;
    int iValue = 0;


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

void Stack::Display()
{
    struct node * temp = NULL;
    temp = this->first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|\n";
        temp = temp-> next;
    }

}

int Stack::Count()
{
    return this->iCount;

}

int main()
{
    Stack *sobj = new Stack();
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