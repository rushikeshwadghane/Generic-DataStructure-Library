#include<iostream>

#include"Linked_List.h"
using namespace std;

int main()
{
    SinglyLL<int> sll;
    int isll=0;

    sll.InsertFirst(11);
    sll.InsertLast(21);
    sll.InsertLast(51); 
    sll.InsertLast(101);
    sll.InsertLast(111);
    sll.InsertLast(151);
    sll.Display();
    isll = sll.CountNode();
    cout<<"Number of Element in LL:"<<isll<<endl;


    sll.DeleteFirst();
    sll.DeleteLast();
    sll.Display();
    isll = sll.CountNode();
    cout<<"Number of Element in LL:"<<isll<<endl;

    
    sll.InsertAtPos(75,3);
    sll.InsertAtPos(55,5);
    sll.Display();
    isll = sll.CountNode();
    cout<<"Number of Element in LL:"<<isll<<endl;      

    sll.DeleteAtPos(3);
    sll.DeleteAtPos(4);
    sll.Display();
    isll = sll.CountNode();
    cout<<"Number of Element in LL:"<<isll<<endl;   

//////////////////////////////////////////////////////// 


    SinglyCLL<int> scl;
    int iscl=0;

    scl.InsertFirst(11);
    scl.InsertLast(21);
    scl.InsertLast(51); 
    scl.InsertLast(101);
    scl.InsertLast(111);
    scl.InsertLast(151);
    scl.Display();
    iscl = scl.CountNode();
    cout<<"Number of Element in LL:"<<iscl<<endl;


    scl.DeleteFirst();
    scl.DeleteLast();
    scl.Display();
    iscl = scl.CountNode();
    cout<<"Number of Element in LL:"<<iscl<<endl;

    
    scl.InsertAtPos(75,3);
    scl.InsertAtPos(55,5);
    scl.Display();
    iscl = scl.CountNode();
    cout<<"Number of Element in LL:"<<iscl<<endl;      

    scl.DeleteAtPos(3);
    scl.DeleteAtPos(4);
    scl.Display();
    iscl = scl.CountNode();
    cout<<"Number of Element in LL:"<<iscl<<endl; 

/////////////////////////////////////////////////////

  

    DoublyLL<int> dll;
    int idll=0;

    dll.InsertFirst(11);
    dll.InsertLast(21);
    dll.InsertLast(51); 
    dll.InsertLast(101);
    dll.InsertLast(111);
    dll.InsertLast(151);
    dll.Display();
    idll = dll.CountNode();
    cout<<"Number of Element in LL:"<<idll<<endl;


    dll.DeleteFirst();
    dll.DeleteLast();
    dll.Display();
    idll = dll.CountNode();
    cout<<"Number of Element in LL:"<<idll<<endl;

    
    dll.InsertAtPos(75,3);
    dll.InsertAtPos(55,5);
    dll.Display();
    idll = dll.CountNode();
    cout<<"Number of Element in LL:"<<idll<<endl;      

    dll.DeleteAtPos(3);
    dll.DeleteAtPos(4);
    dll.Display();
    idll = dll.CountNode();
    cout<<"Number of Element in LL:"<<idll<<endl; 

///////////////////////////////////////////////////////////

    DoublyCLL<int> dcl;
    int idcl=0;

    dcl.InsertFirst(11);
    dcl.InsertLast(21);
    dcl.InsertLast(51); 
    dcl.InsertLast(101);
    dcl.InsertLast(111);
    dcl.InsertLast(151);
    dcl.Display();
    idcl = dcl.CountNode();
    cout<<"Number of Element in LL:"<<idcl<<endl;


    dcl.DeleteFirst();
    dcl.DeleteLast();
    dcl.Display();
    idcl = dcl.CountNode();
    cout<<"Number of Element in LL:"<<idcl<<endl;

    
    dcl.InsertAtPos(75,3);
    dcl.InsertAtPos(55,5);
    dcl.Display();
    idcl = dcl.CountNode();
    cout<<"Number of Element in LL:"<<idcl<<endl;      

    dcl.DeleteAtPos(3);
    dcl.DeleteAtPos(4);
    dcl.Display();
    idcl = dcl.CountNode();
    cout<<"Number of Element in LL:"<<idcl<<endl; 
   
//////////////////////////////////////////////////////


    return 0;    
}

