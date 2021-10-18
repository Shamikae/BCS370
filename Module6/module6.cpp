/*
Shamika Earle
BCS 370
Module 6 
Unsorted Singly nexted List
*/

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
    Node(T data, Node *p)
    { //Note, this constructor combines both default and parameterized constructors. You may modify the contructor to your needs
        this->data = data;
        next = p;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head, *current;

public:
    //default constructor
    LinkedList()
    {
        head = NULL;    //the head pointer
        current = NULL; //acts as the tail of the list
    }

    //destructor - IMPORTANT
    ~LinkedList()
    {
        current = head;
        while (current != NULL)
        { //the loop stops when both current and head are NULL
            head = head->next;
            delete current;
            current = head;
        }
    }

    void addLast(int n)
    { // to add a node at the end of the list
        if (head == NULL)
        {
            head = new Node<T>(n);
            current = head;
        }
        else
        {
            while (current->next != NULL)
                current = current->next;
            current->next = new Node<T>(n);
            current = current->next; //You may decide whether to keep this line or not for the function
        }
    }

    void print()
    { // to display all nodes in the list
        Node<T> *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << "\n";
            tmp = tmp->next;
        }
    }

    // addFirst (T data)
    // New Node is add at the front and becomes the head
    //1. Prepare new Node and allocate memory for it
    void addFirst(T data)
    {
        Node<T>* tmp = new Node<T>(data);
        tmp->next = head;
        head = tmp;
        if (current == NULL)
            current = head;
    }

    // pop()
    // Create (initialize) temporary node for head
    //Move head to next node
    // Delete temporary node
    T pop()
    {
        if (head == NULL)
            return 0;
        Node<T>* tmp = head;
        head = head->next;
        cout<<"Element to be removed is : "<<tmp->data << "\n";
        if (head == NULL) // if there is no node remaining
            current = NULL;
        T data = tmp->data;
        delete tmp;
        return data;
    }

    // contains(T data)
    // create a node pointer
    // While not NULL if data == data return true
        //else next
    // return false
    bool contains(T data)
    {
        Node<T> *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == data)
                {return true;}
            tmp = tmp->next;
        }
        return false;
    }

    // update(T oldData, T newData)
    // initialize temporary node as head
    // find old data
    // replace with new
    void update(T oldData, T newData)
    {
        Node<T> *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == oldData)
            {
                tmp->data = newData;
                break;
            }
            tmp = tmp->next;
        }
    }

    // size()
    // Initialize a temporary node pointer
    // Initialize count at 0
    // While not NULL 
        //count++
        //tmp = tmp->next
    //return count

    int size()
    {
        Node<T> *tmp = head;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    // remove(T data)
    // Check for node
    // Find node that is before node being removed
    // Change next of the node before 
    // delete temp node

    void remove(T data)
    {
        if (contains(data))
        {
            Node<T> *tmp = head, *pre = NULL;
            while (tmp != NULL)
            {
                if (tmp->data == data)
                    break;
                pre = tmp;
                tmp = tmp->next;
            }
            if (pre == NULL) {
                pop();
            }else
            {
                pre->next = tmp->next;
                delete tmp;
            }
        }
    }

    // Insert after(int n, T data) 
    // Check for node by finding the previous
    // If not add to end
    void insertAfter(int n, T data)
    {
        Node<T> *node = new Node<T>(data);
        if (size() <= n)
            addLast(data);
        else
        {
            Node<T> *tmp = head, *pre;
            while (n > 0)
            {
                n--;
                pre = tmp;
                tmp = tmp->next;
            }
            pre->next = node;
            node->next = tmp;
        }
    }

    //merge(const linkedList &linklist)
    //
    void merge(const LinkedList &linkedlist)
    {
        
        if (head == NULL)
            head = linkedlist.head;
        else
        {
            Node<T> *tmp = head;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = linkedlist.head;
        }
    }
};

int main()
{
    LinkedList<int> a;
    a.addLast(1);
    a.addLast(2);
    
    a.print();
    a.addFirst(0);
    cout << "List after add is :" << "\n";
    a.print();
    a.pop();
    cout << "List after pop() is :  "<< "\n";
    a.print();
    cout << "Does List contains(1) :  " << a.contains(1)<< "\n";
    a.print();
    cout << "Does List contains(3) :  " << a.contains(3)<< "\n";
    a.print();
    a.addLast(3);
    a.addLast(4);
    cout << "List after add is :" << "\n";
    a.print();
    a.update(1,5);
    cout << "List after update is :" << "\n";
    a.print();
    a.update(5,1);
    cout << "List after update is :" << "\n";
    a.print();
    cout << "List count is :  " << a.size() << "\n";
    a.insertAfter(3, 3);
    cout << "List using insertAfter() is :  \n";
    a.print();
    a.remove(3);
    cout << "List after remove(3) is :  \n";
    a.print();
    
    LinkedList<int> b;
    b.addLast(5);
    b.addLast(6);
    b.addLast(7);
    cout << "List B:\n";
    b.print();
    a.merge(b);
    cout << "list after merging: \n";
    a.print();
    return 0;
}