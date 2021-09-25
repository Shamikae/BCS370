// class templates
// http://www.cplusplus.com/doc/oldtutorial/templates/
// updated 9/15/2020

#include <iostream>
using std::cout;

template <class T>
class MyPair {
    T a, b;
  public:
    MyPair (T, T);
    T getmax ();
};
template <class T>
MyPair<T>::MyPair (T first, T second):a(first),b(second){}

template <class T>
T MyPair<T>::getmax () {
  return a>b? a : b;
}

int main () {
  MyPair <char> myobject ('z', '-');
  cout << myobject.getmax();
  return 0;
}
