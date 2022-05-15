#include <iostream>

using namespace std;

class A
{
public:
    void virtual prt()
    {
        cout << "打印A" << endl;
    }
};

class B : public A
{
public:
    void prt()
    {
        cout << "打印B" << endl;
    }
};

int main(void)
{
    // static_cast不安全，转换后在进行读取派生类的东西会导致越界，因为实际对象中没有派生类的东西。类似于c中的强制转换，且一般更多使用c的强制转换。
    B *a = static_cast<B *>(new A());
    a->prt();
    // const_cast转换为非静态
    const int i = 2;
    const int *p = &i;
    // int *q=p;报错
    int *q = (int *)p;
    // int *q = const_cast<int *>(p);
    cout << *q << "   ";
    *q = 32;
    cout << *q << endl;
    // dynamic_cast是在运行时转换，如果不成功会返回null.
    cout << dynamic_cast<B *>(new A()) << endl;
    cout << dynamic_cast<A *>(new B()) << endl;
    return 0;
}