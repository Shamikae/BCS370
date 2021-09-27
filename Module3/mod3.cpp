#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
};

class Class
{
private:
    int classSize;
    Student* students;

public:
    Class(int x) //Parameterized constructor taking int argument to be passed in and assigned to the member variable  classSize
    {
        
        classSize = x;//assigning x to the private member variable classSize
        students = new Student[x];//Using the new operator, initialize dynamic array students with classSize elements
        
        for (int i = 0; i < x; i++)//For the value of x(classSize) loop through the array
        {
            //Use pointer arithmetic to assign name and age 
            (*(students + i)).name = "";
            (*(students + i)).age = 0;
        }
    }
    //Destructor
    ~Class()
    {
        delete[] students;//Use delete to de-allocate(delete) dynamic variable/array
    }
};

int main()
{
    
    Class bcs(9); //Instantiating an object of Class named bcs with 9 students.
    
    return 0;
}