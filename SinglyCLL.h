#include<iostream>
using namespace std;
template<class T>
struct node 
{
    T Data;
    struct node * next;

};
template<class T>
class SinglyCLL
{
    public:
        struct node<T> *Head;
        struct node<T> *Tail;
        int Count;

        SinglyCLL();
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
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->Data = no;
    newn->next = NULL;

    if(Head == NULL && Tail==NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else{
        newn->next = Head;
        Head = newn;
        Tail->next = Head;
    }
    Count++;    
}
template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn =NULL;
    newn = new node<T>;
    newn->Data = no;
    newn->next = NULL;    
    if(Head==NULL && Tail==NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next  =newn;
        Tail = newn;
        newn->next= Head;
    }
    Count++;    
}
template<class T>
void SinglyCLL<T>::InsertAtPos(T no,int Pos)
{
    struct node<T> *newn =NULL;
    newn = new node<T>;
    newn->Data = no;
    newn->next = NULL;    
    int Size = CountNode();
    if(Pos<1 || Pos>(Size+1))
    {
        printf("Invallid Position");
        return;
    }
    if(Pos==1)
    {
        InsertFirst(no);
    }
    else if(Pos==(Size+1))
    {
        InsertLast(no);
    }
    else
    {
            struct node<T> *temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < Pos-1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;
            Count++;
    }    
}
template<class T> 
void SinglyCLL<T>::DeleteFirst()
{
    if((Head==NULL) && (Tail==NULL))
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else{
        
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }
    Count--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct node<T>*temp=Head;
    if((Head==NULL) && (Tail==NULL))
    {
        return;
    }
    else if(Head==Tail)
    {
        delete Head;
    }
    else
    {
        while(temp->next!=Tail)
        {
           temp =  temp->next; 
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
    Count--;    
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
    int iSize = CountNode();

    if((ipos < 1) || (ipos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
            struct node<T> *temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node<T>  *temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
            Count--;
    }    

}

template<class T>
void SinglyCLL<T>::Display()
{
    cout<<"Element from Singly Circular Linked-List:"<<endl;
    struct node<T> *temp = Head;
    do
    {
        cout<<temp->Data<<" ";
        temp = temp->next;
    } while (temp!=Head); 
    cout<<endl;
}

template <class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}
