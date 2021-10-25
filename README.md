# BCS 370 Data Structures

## Module 1:

## Module 2:

## Module 3: 
Given the Student struct definition as follows:
struct Student {
    std::string name;
      int age;
};
2. Create a class  Class that has int classSize and Student* students as its  private member variables.
1) Create a parameterized  constructor that takes an  int argument to be passed in and assigned to the member variable  classSize. The constructor creates a  dynamic array of Student objects with   classSize elements.The function uses  pointer arithmetic to assign default values  (such as name="", age=0) to each object.
2) Also, construct the destructor, ~Student(), for the class.
3. In main(), simply instantiate an object to ensure the program works.

//note: *(students+i) will return the Student object at index i
            //on students array.

## Module 8:
– Stack
You will be creating a stroke-based sketch book app, using stack data structure.
The app menu items include the following actions (methods):
draw();
erase();
undo();
redo();
A drawing is made of strokes. When draw() is called, a new stroke is made; when erase() gets
called, the latest stroke is deleted from the screen; when undo() is called, the latest stroke is
removed, but the record is saved; when redo() is called, the last undo() action (stroke) is recalled
back.
For example:
1) draw (stroke 1)
2) draw (stroke 2)
3) undo(): remove stroke 2 and saved to an undo list
4) draw (stroke 3)
5) redo(): put stroke 2 back to the drawing list
6) redo(): redo list is empty, nothing to be put back
7) draw (stroke 4)
8) erase(): stroke 4 is permanently removed from drawing list and is not saved in the undo
list
The final drawing list should be: stroke1->stroke3->stroke2
Can you design and implement the program, including the above methods, using stack data
structure?
You may directly use C++ library <stack> or <vector> for this assignment. 
 