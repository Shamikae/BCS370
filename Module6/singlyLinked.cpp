//Shamika Earle
//BCS 370 Module 6 Unsorted Singly Linked List 

#include <iostream>
using std::cout;


template <typename T>
struct Node {
    T data;
    Node *link;
  
	Node(T data, Node *p  = nullptr) { //Note, this constructor combines both default and parameterized constructors. You may modify the contructor to your needs
        this->data = data;
		link = p;
    }
};

template <typename T>
class linked_list
{
    Node<T> *head,*current;
  public:
    //default constructor
    linked_list() {
        head = nullptr;//the head pointer
        current = nullptr;//acts as the tail of the list
    }

    //destructor - IMPORTANT
    ~linked_list() {
		current = head;
		while( current != nullptr ) {//the loop stops when both current and head are NULL
    		head  = head->link;
    		delete current;
    		current = head;
		}
    }

    void addLast(int n) {// to add a node at the end of the list
        if(head == nullptr){
            head = new Node<T>(n);
            current = head;
        } else {
			while( current->link != nullptr)
				current = current->link;
            current->link = new Node<T>(n);
            current = current->link;//You may decide whether to keep this line or not for the function
        }
    }
    
    void print() { // to display all nodes in the list
        Node<T> *tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << "\n";
            tmp = tmp->link;
        }
    }
};

int main() {
    linked_list<int> a;
    a.addLast(1);
    a.addLast(2);
    
    //add your test code here

	a.print();
    
    return 0;
}




