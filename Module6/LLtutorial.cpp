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

void addFirst(Node**head, int newVal) { //recieves a pointer to a pointer(Node**)
    //1. Prepare new Node
    Node* newNode = new  Node(); //Create new Node and allocate memory for it
    newNode->Value = newVal;
    //2. Put it in front of the current head
    newNode->Next = *head; //assigning a pointer(Next) to a pointer(*head)current
    //3. Move head of the list to point to the newNode
    *head = newNode;
}

void addLast(Node**head, int newVal) {
    //1. Prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newVal;
    newNode->Next = NULL;
    //2. If Linked list is empty, newNode will be a head node
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    //3. Find the last node
    Node* last = *head;
    while (last->Next!=NULL)
    {
        last = last->Next;
    }
    //4. Insert newNode after last node (at the end)
    last->Next =  newNode;
}

void addInAfter(Node*previous, int newVal) {
    //1. Check if previous node is NULL
    if(previous==NULL) {
        cout << "Previous can not be NULL";
        return;
    }
    //2. Prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newVal;
    //3. Insert newNode after previous
    newNode->Next = previous->Next;
    previous->Next = newNode;
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

    addFirst(&head, -1); //pass in address of the head(address of a pointer) and the value to be added
    addFirst(&head, -2);
    addLast(&head, 4);
    addLast(&head, 5);
    addInAfter(second, 0);
    printList(head); // pass in head(node pointer)

    system("pause>0");
}