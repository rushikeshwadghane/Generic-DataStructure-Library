#include<iostream>
using namespace std;

// Singly Linear Linked_List


template<class T>
struct node1
{
    T data;
    struct node1 *next;
};
template<class T>
class SinglyLL
{
    public:
        struct node1<T> *Head;
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
    struct node1<T> *newn = NULL;
    newn = new node1<T>;

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
    struct node1<T> *newn = NULL;
    newn = new node1<T>;
    newn->data  =No;
    newn->next = NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node1<T> *temp = Head;
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
    struct node1 <T> *newn  = NULL;
    newn = new node1<T>;
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
        struct node1<T> *temp = Head;
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
    struct node1 <T> *temp  = Head;
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
    struct node1<T> *temp = Head;
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
            struct node1<T> *temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < iPos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node1<T> *temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
            Count--;
    }
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elelment from Singly Linear Linked List Are: "<<endl;
    struct node1 <T> *temp = Head;
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


// Doubly Linear Linked_List

template <class T>
struct node2 
{
    T data;
    struct node2<T> *next;
    struct node2<T> *prev;
};
template <class T>
class DoublyLL
{
    public:
        struct node2<T> *Head;
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
    struct node2 <T> *newn  =NULL;
    newn = new node2<T>;
    newn->data = no;
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
    struct node2<T> *newn = NULL;
    newn = new node2<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    struct node2<T> *temp = Head;
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
        struct node2<T> *temp = Head;
        struct node2 <T> *newn = NULL;
        newn = new node2<T>;
        newn->next = NULL;
        newn->data = no;
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
    struct node2<T> *temp = Head;
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
    struct node2 <T> *temp = NULL;

    int size = CountNode();

    if((pos < 1) || (pos > size+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos ==1)
    {
        DeleteFirst();
    }
    else if(pos == size)
    {
        DeleteLast();
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
    cout<<"Elelment from Dubly Linear Linked List Are: "<<endl;
    struct node2<T> *temp = Head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}


// Singly Circular Linked_List

template<class T>
struct node3 
{
    T data;
    struct node3<T> * next;

};
template<class T>
class SinglyCLL
{
    public:
        struct node3<T> *Head;
        struct node3<T> *Tail;
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
    struct node3<T> *newn = NULL;
    newn = new node3<T>;
    newn->data = no;
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
    struct node3<T> *newn =NULL;
    newn = new node3<T>;
    newn->data = no;
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
    struct node3<T> *newn =NULL;
    newn = new node3<T>;
    newn->data = no;
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
            struct node3<T> *temp = Head;
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
    struct node3<T>*temp=Head;
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
            struct node3<T> *temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node3<T>  *temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
            Count--;
    }    

}

template<class T>
void SinglyCLL<T>::Display()
{
    cout<<"Element from Singly Circular Linked-List:"<<endl;
    struct node3<T> *temp = Head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp!=Head); 
    cout<<endl;
}

template <class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}


//Doubly Circular Linked_List

#include<iostream>
using namespace std;

template <class T>
struct node4 
{
    T data;
    struct node4<T> *next;
    struct node4<T> * prev;
};

template <class T>
class DoublyCLL
{
    public:
        struct node4<T> *Head;
        struct node4<T> *Tail;
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
    struct node4<T> *newn = NULL; 
    newn = new node4<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;
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
    struct node4<T> *newn = NULL; 
    newn = new node4<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no; 
    if(Head==NULL && Tail==NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else{

         Tail->next = newn;
         newn->prev = Tail;
      
         Tail=newn;
    }
    Tail->next = Head;
    Count++;       
}
template <class T>
void DoublyCLL<T>::InsertAtPos(T no,int Pos)
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
    else if(Pos==(Size+1))
    {
        InsertLast(no);
    }
    else
    {
        struct node4<T> *temp = Head;
        struct node4 <T> *newn = NULL;
        newn = new node4<T>;
        newn->next = NULL;
        newn->data = no;
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
void DoublyCLL<T>::DeleteFirst()
{   
    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head= NULL;

    }
    else
    {
        Head = Head->next;
        delete(Tail->next);
        Tail->next = Head;
        Head->prev = Tail;
    }
    Count--;
}
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head= NULL;

    }
    else
    {
        Tail = Tail->prev;
        delete Head->prev;
        Head->prev = Tail;
        Tail->next = Head;
    }    
    Count--;
}
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    struct node4<T> *temp = NULL;

    int Size = CountNode();

    if((pos < 1) || (pos > Size+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos ==1)
    {
        DeleteFirst();
    }
    else if(pos == Size)
    {
        DeleteLast();
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
void DoublyCLL<T>::Display()
{
    cout<<"Element From Doubly Circular Linked-List: "<<endl;
    struct node4<T> *temp = Head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=Head);     
    cout<<endl;
}

template <class T>
int DoublyCLL<T>::CountNode()
{
    return Count;
}


