//相当于#include <iostream>
namespace a
{
    extern void func1();
}
//相当于using namespace std;
using namespace a;
int main()
{
    func1();
    return 0;
}