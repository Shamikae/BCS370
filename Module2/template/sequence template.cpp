// sequence template
// templates can also have regular typed parameters (non-type parameters)
#include <iostream>
using namespace std;

template <class T, int N>
class MySequence {
    T members [N];
  public:
    void setmember (int, T);
    T getmember (int);
};

template <class T, int N>
void MySequence<T,N>::setmember (int index, T value) {
  members[index]=value;
}

template <class T, int N>
T MySequence<T,N>::getmember (int index) {
  return members[index];
}

int main () {
  MySequence <int,5> myints;
  MySequence <double,5> myfloats;
  myints.setmember (0,100);
  myfloats.setmember (3,3.1416);
  cout << myints.getmember(0) << '\n';
  cout << myfloats.getmember(3) << '\n';
  return 0;
}
