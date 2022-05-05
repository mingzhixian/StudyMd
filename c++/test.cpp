#include <iostream>

using namespace std;

// 基类1
class A
{
public:
    virtual void prt1()
    {
        cout << "A1" << endl;
    }
    virtual void prt2()
    {
        cout << "A2" << endl;
    }
};

class B : A
{
public:
    void prt1()
    {
        cout << "B1" << endl;
    }
    void prt2()
    {
        cout << "B2" << endl;
    }
    void prtB()
    {
        cout << "BBBBBB" << endl;
    }
};

class C : A
{
public:
    void prt1()
    {
        cout << "C1" << endl;
    }
    void prt2()
    {
        cout << "C2" << endl;
    }
    void prtC()
    {
        cout << "CCCCCC" << endl;
    }
};
int main(void)
{
    A *b = (A *)new B;
    A *c = (A *)new C;
    b->prt1();
    b->prt2();
    // b->prtB();找不到
    c->prt1();
    c->prt2();
    // c->prtC();找不到
    return 0;
}