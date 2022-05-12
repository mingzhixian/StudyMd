#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
template <>
class A<double, int>
{
public:
    double t1;
    int t2;
};

template <class T1>
class A<double, T1>
{
public:
    double t1;
    T1 t2;
};

int main(void)
{
    A a;
    a.t1 = 3.45;
    a.t2 = 6;
    cout << a.t1 << "  " << a.t2 << endl;
    return 0;
}