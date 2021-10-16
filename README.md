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