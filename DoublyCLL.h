#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T Data;
    struct node<T> *next;
    struct node<T> *prev;
};

template <class T>
class DoublyCLL
{
    public:
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int); 

        void Display();
        int CountNode();        
};
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL; 
    newn = new node<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->Data = no;
    if(Head==NULL && Tail==NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL; 
    newn = new node<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->Data = no; 
    if(Head==NULL && Tail==NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else{
        newn->prev = Tail;
        Tail = newn;
    }
    Tail->next = Head;
    Count++;       
}

template <class T>
void DoublyCLL<T>::Display()
{
    cout<<"Element From Linked-List: "<<endl;
    struct node<T> *temp = Head;
    while(temp->next!=Head)
    {
        cout<<temp->Data<<" ";
         temp = temp->next;
    }       
    cout<<endl;
}

template <class T>
int DoublyCLL<T>::CountNode()
{
    return Count;
}