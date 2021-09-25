// function template
// 2/9/2019 gz All right reserved.
#include <iostream>

template <class T>
T getSum (T a, T b) {
  T result;
  result = a+b;
  return (result);
}

int main () {
  int i=5, j=6, intTotal;
  float l=10.5f, m=5.4f, floatTotal;
  
  intTotal=getSum<int>(i,j);
  floatTotal=getSum<float>(l,m);
    
  std::cout << intTotal << std::endl
            << floatTotal << std::endl;
  return 0;
}
