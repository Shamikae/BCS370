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
class linked_list
{
    Node<T> *head, *current;

public:
    //default constructor
    linked_list()
    {
        head = NULL;    //the head pointer
        current = NULL; //acts as the tail of the list
    }

    //destructor - IMPORTANT
    ~linked_list()
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

    // addFirst
    void addFirst(T data)
    {
        Node<T> *tmp = new Node<T>(data);
        tmp->next = head;
        head = tmp;
        if (current == NULL)
            current = head;
    }

    // pop
    T pop()
    {
        if (head == NULL)
            return NULL;
        Node<T> *tmp = head;
        head = head->next;
        if (head == NULL) // if there is now node remaining
            current = NULL;
        T data = tmp->data;
        delete tmp;
        return data;
    }

    // contains()
    bool contains(T data)
    {
        Node<T> *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->data == data)
                return true;
            tmp = tmp->next;
        }
        return false;
    }

    // update()
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

    // remove method

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
            if (pre == NULL) // remove head
                pop();
            else
            {
                pre->next = tmp->next;
                delete tmp;
            }
        }
    }

    //insert after n
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
    void merge(const linked_list &linkedlist)
    {
        // first list is empty
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
    linked_list<int> a;
    a.addLast(1);
    a.addLast(2);
    cout << "\nList is :  \n";
    a.print();
    a.addFirst(3);
    cout << "\nList after addFirst() is : \n ";
    a.print();
    a.pop();
    cout << "\nList after pop() is :  \n";
    a.print();
    cout << "\nSize of List is :  " << a.size();
    a.insertAfter(2, 5);
    cout << "\nList after insertAfter() is :  \n";
    a.print();
    a.remove(5);
    cout << "\nList after remove(5) is :  \n";
    a.print();
    cout << "\nIs List contains(5) :  " << a.contains(5);
    linked_list<int> b;
    b.addLast(10);
    b.addLast(20);
    cout << "List b is:\n";
    b.print();
    a.merge(b);
    cout << "list after merging a and b is :\n";
    a.print();
    return 0;
}