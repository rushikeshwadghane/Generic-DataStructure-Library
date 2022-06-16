#include<iostream>
using namespace std;
template<class T>
struct node
{
    T data;
    struct node *next;
};
template<class T>
class SinglyLL
{
    public:
        struct node<T> *Head;
        int Count;

    SinglyLL();    
    void  InsertFirst(T);
    void  InsertLast(T);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T,int);
    void DeleteAtPos(int); 

};
template<class T>
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;

    newn->data  =No;
    newn->next = NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next = Head;
        Head= newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data  =No;
    newn->next = NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = newn;
    }
    Count++;    
}
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int Pos)
{
    struct node <T> *newn  = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    int size = CountNode();
    if(Pos<1 || Pos==(size+1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(Pos==1)
    {
        InsertFirst(no);
    }
    else if (Pos==(size+1))
    {
        InsertLast(no);
    }
    else{
        struct node<T> *temp = Head;
        for(int i=1;i<(Pos-1);i++)
        {
            temp = temp->next;
        }

            newn->next=temp->next;
            temp->next = newn;
        Count++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node <T> *temp  = Head;
    if(Head==NULL)
    {
        return;
    }
    else{
        temp = Head;
        Head = Head->next;
        delete(temp);
        Count--;
    }
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next ==NULL)
    {
        delete(Head);
        Head=NULL;
    }
    else
    {
        while (temp->next->next !=NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    Count--;
}
template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iSize = CountNode();

    if((iPos < 1) || (iPos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
            struct node<T> *temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < iPos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node<T> *temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
            Count--;
    }
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elelment from Linked List Are: "<<endl;
    struct node <T> *temp = Head;
    while(temp!=NULL)
    {
        cout<<temp->data <<" ";
        temp= temp->next;
    }
    cout<<endl;
}
template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}