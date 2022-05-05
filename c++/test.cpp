#include <iostream>

using namespace std;

// 基类1
class A
{
public:
    void inc()
    {
        n++;
    }
    static void prt()
    {
        cout << n << endl;
    }
    static int n;
};
int A::n = 0;
// 基类2
class B : public A
{
};

int main(void)
{
    B b;
    b.prt();
    b.inc();
    b.inc();
    b.prt();
    return 0;
}