#include <iostream>
using namespace std;

namespace first_space
{
    void func1()
    {
        cout << "命名空间1中的函数1" << endl;
    }
    namespace second_space
    {
        void func1()
    {
        cout << "命名空间2中的函数1" << endl;
    }
        void func2()
        {
            func1();
            cout << "命名空间2中的函数2" << endl;
        }
    }
}
using namespace first_space::second_space;
int main()
{
    func2();
    return 0;
}