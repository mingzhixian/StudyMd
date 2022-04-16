#include <iostream>
namespace std
{
    void func1()
    {
        cout << "此处是调用了std空间中的cout" << endl;
    }
}
using namespace std;
int main()
{
    func1();
    return 0;
}