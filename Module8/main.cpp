/*
The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 

What is Stack in C++ STL?
Stacks are the data structure which stores the data in LIFO (Last In First Out) where we do insertion and deletion from the top of the last element inserted. 
Like a stack of plates, if we want to push a new plate into the stack we insert on the top and if we want to remove the plate from the stack we then also remove it from the top.

What is stack::push()?
stack::push() function is an inbuilt function in C++ STL, 
which is defined in <stack>header file. push() is used to push or insert an element at the top of the stack container. 
The content of the new element is copied and initialized.
Syntax
stack_name.push(value_type& val);

What is stack::pop()?
stack::pop() function is an inbuilt function in C++ STL, 
which is defined in <stack>header file. pop() is used to pop or remove an element from the top of the stack container. 
The content from the top is removed and the size of the container is reduced by 1.
Syntax
stack_name.pop();

What is stack::top()?
stack::top() function is an inbuilt function in C++ STL, 
which is defined in <stack> header file. top() is used to access the element at the top of the stack container. 
In a stack, the top element is the element that is inserted at the last or most recently inserted element.
Syntax
stack_name.top();

What is stack::empty()?
stack::empty() function is an inbuilt function in C++ STL, 
which is defined in <stack>header file. empty() is used to check whether the associated container is empty or not and return true or false accordingly.
The function checks the container should be empty means the size of the container should be 0.
Syntax
stack_name.empty();
*/

#include <iostream>
#include <stack>
using namespace std;

class Stroke
{
    stack<char> firstStack;
    stack<char> secStack;

public:
    void display_screen()
    {
        stack<char> temp;
        while (!firstStack.empty())
        {
            temp.push(firstStack.top());
            firstStack.pop();
        }
        cout << "---> ";
        while (!temp.empty())
        {
            cout << temp.top();
            firstStack.push(temp.top());
            temp.pop();
        }
        cout << " <---\n\n";
    }
    void draw()
    {
        cout << "Enter sketch character\n";
        char x;
        cin >> x;
        firstStack.push(x); //Add to the end
        display_screen();
    }
    void erase()
    {
        firstStack.pop();  //Remove from end
        display_screen();
    }
    void undo()
    {
        secStack.push(firstStack.top()); 
        firstStack.pop();
        display_screen();
    }
    void redo()
    {
        if (!secStack.empty())
        {
            firstStack.push(secStack.top());
            secStack.pop();
        }
        display_screen();
    }
    void play()
    {
        int flag = 1;
        while (flag)
        {
            char val;
            cout << "Sketch options\n\n";
            cout << "1 for draw\n";
            cout << "2 for erase\n";
            cout << "3 for undo\n";
            cout << "4 for redo\n";
            cout << "Enter option\n\n";
            cin >> val;
            switch (val)
            {
            case '1':
                this->draw();
                break;
            case '2':
                this->erase();
                break;
            case '3':
                this->undo();
                break;
            case '4':
                this->redo();
                break;
            default:
                cout << "Invalid Option \n";
                break;
            }
        }
    }
};
int main()
{
    class Stroke artist1; 
    artist1.play();
}