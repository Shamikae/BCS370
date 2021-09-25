//template two template datatypes
//2/24/19 gz
#include <iostream>

template<class T, class U>
void switchDT(T t, U u) {
    T t1 = t;
    t = (T)u;
    u = (U)t1;
    
    std::cout << "t: " << t << " and " << u << std::endl;
}

int main()
{
    switchDT<double, int>(10.5, 10);
    switchDT<char, int>('a',99);

    return 0;
}
