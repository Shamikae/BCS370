#include <iostream>
using namespace std;

template <class T>
class Circle {

    private:
    T radius;

    double area(){
        return 3.14*radius*radius;
    }

    public:
    Circle& operator+(int a){
        radius = radius + a;
        return *this;
    }
    Circle& operator++(){
        radius += 1;
        return *this;
    }

    friend ostream& operator<< (ostream& out, Circle& obj) {
        cout <<"Radius: ";
        cout<< obj.radius<<endl;
        cout<<"Circle area: ";
        cout<< obj.area()<<endl;

        return (out);
    }

    friend istream& operator>>(istream& in, Circle& obj){
        cout<<"Enter circle radius: ";
        cin>> obj.radius;

        return (in);
    }
};

int main() {
    
    Circle<int> circle1;
    cin>> circle1;
    cout<< circle1<<endl;
    cout<< circle1 + 5 << endl;
    cout << ++circle1<< endl;
    
    return 0;
}