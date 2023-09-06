#include<iostream>
//#include "func.h"
// we can use nstrucktures instedd of class and in this case
// we do not need public because element of a structurs are public by default 
class Node{
    public:
    int value;
    Node* next;
    Node* previous;
}; 
// this function starting from the head and and continue to the rest of the element
void printForward(Node* head){
Node* traverses = head;           // creating a Node* and put a head in it 
while (traverses!= nullptr)         // read the head and from there go to the next element
{
    std::cout<<traverses->value<<std::endl;
    traverses = traverses->next;
}

}

// same process bout only start from tail
void printBackward(Node* tail){
Node* traverses = tail;
while (traverses!= nullptr)
{
    std::cout<<traverses->value<<std::endl;
    traverses = traverses->previous;
}

}


int main(){

Node* head;
Node* tail;
//node number 1
// step number 4 is to say that this node here is our head and tail of out list
Node* node = new Node(); // step one create node
node->value = 1;          // step two set a value to 
node->next = nullptr;     // step tree set pointer to head and tail the element
node->previous = nullptr;
    
head = node;
tail = node;



// node number 2
node = new Node(); // step one  
node->value = 2; // set the value
node->next = nullptr;
node->previous = tail;
tail->next = node; // here we tell the tail that now you have a successor/efterträdare 
tail = node; // here now we say that this node is the tail 



// nod number 3
node = new Node(); // step one  
node->value = 3; // set the value
node->next = nullptr;
node->previous = tail;
tail->next = node;
tail = node;



// node number 4
node = new Node(); // step one  
node->value = 4; // set the value
node->next = nullptr;
node->previous = tail;
tail->next = node;
tail = node;

// node number 5
node = new Node(); // step one  
node->value = 5; // set the value
node->next = nullptr;
node->previous = tail;
tail->next = node;
tail = node;

printForward(head);
std::cout<<"---------------"<<std::endl;;
printBackward(tail);



    return 0;
}


/*
// in this class we put two things one is the value of the node and the second is pointer of the node
// all of the member of the class is private by default. 
class func
{
public:
    int value;
    func* Next; 

};

// so this functions purpos is to enter the alla element of the link list and print them out.
void printList(func*n){ 
    while (n!=NULL)
    {
        std::cout<<n->value<<std::endl; // using this operator to access the element
        //and the second part is to move to the next node 
        // so in here i'm saying that my n is equel to what ever the next is,
        n = n->Next;
    }
    
}

int main(){

func* Head = new func();
func* second = new func();
func* thired = new func();

Head->value = 1;
Head->Next= second;
second->value = 2;
second->Next=thired; 
thired->value = 3;
thired->Next=NULL;

// to print out the content of alla element we can print the first element then the
// second and the third will follow. 
printList(Head);    // in here we are passing the node pointer therfor we have to recieve a node pointe as parameter in print function.


    return 0;
}
*/
/*
int a = 5;
int *ptr = &a;

//one importent think is that the pointer has to be the 
//type of the varible for exemple char pointer can only point to char
//and float can only point to float and so on

std::cout<< ptr <<std::endl; // print the address of the index

std::cout<< *ptr <<std::endl; // print the contant of the index
*ptr = 33; // this is how to change the the value of the ( a )
std::cout<<*ptr<<std::endl; // chande the content of the 
std::cout<< a <<std::endl;
*/