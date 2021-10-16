#include <iostream>
using namespace std;
/*
Linked List consists of element value and pointer to the next element. Must create a user defined data type

Use a class(user defined data type ) to represent an element of a linked list often named Node

Node element of a linked list
(->) used to access 

*/
class Node { //User defined data type Node
public:
    int Value;
    Node* Next;
};
// By passing the first element(head) we can access all other elements until it returns null
void printList(Node*n) { //recieves a node pointer(Node*)
    while (n!=NULL)
    {
        cout << n->Value <<  endl;
        n = n->Next;
    }
    

}

int main()
{
    Node* head = new Node(); //Standard name for first element of linked list
    Node* second = new Node();
    Node* third = new Node();
    
    head->Value = 1; //value of element
    head->Next = second; //pointer to the next element

    second->Value = 2;
    second->Next = third;

    third->Value = 3;
    third->Next = NULL;

    printList(second); // pass in head(node pointer)

    system("pause>0");
}