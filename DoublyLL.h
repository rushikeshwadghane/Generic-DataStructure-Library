#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T Data;
    struct node<T> *next;
    struct node<T> *prev:
};
template <class T>
class DoublyLL
{
    public:
        struct node<T> *Head;
        int Count = 0;
    DoublyLL();
    void  InsertFirst(T);
    void  InsertLast(T);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T,int);
    void DeleteAtPos(int);         
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count= 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node <T> *newn  =NULL;
    newn = new node<T>;
    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(Head==NULL)
    {
        Head= newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->Data = no;
    newn->next = NULL;
    newn->prev = NULL;
    struct node<T> *temp = Head;
    if(Head==NULL)
    {
        Head= newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = NULL;
    }
    Count++;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T no,int Pos)
{
    int Size  = CountNode();
    if((Pos<1)||(Pos>Size+1))
    {
        cout<<"Invalid Position"<<endl;
    }
    if(Pos==1)
    {
        InsertFirst(no);
    }
    else if(Pos==(Size))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *temp = Head;
        struct node <T> *newn = NULL;
        newn = new node<T>;
        newn->next = NULL;
        newn->Data = no;
        newn->prev = NULL;
        for(int i=1;i<Pos-1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        newn->next->prev = newn;
        Count++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        delete Head;
    }
    else
    {
        Head = Head->next;
        delete (Head->prev);
        Head->prev = NULL;
    }
    Count--;
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
    }
    else{
       while (temp->next->next!=NULL)
       {
           temp = temp->next;
       }
        delete (temp->next);
        temp->next=NULL;
    } 
    Count--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    struct node <T> *temp = NULL

    int size = CountNode();

    if((pos < 1) || (pos > size))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos ==1)
    {
        DeleteFirst(head);
    }
    else if(pos == size)
    {
        DeleteLast(head);
    }
    else
    {
        temp = Head;

        for( int iCnt =1; iCnt < (pos-1) ;iCnt++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;
        Count--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> *temp = Head;
    while(temp!=0)
    {
        cout<<temp->Data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}