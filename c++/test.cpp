#include "stdio.h"
int f1(int const *i)
{
    //*i=5;会报错
    int a=9;
    i=&a;
    return 1;
}
int f2(const int *i)
{
    //*i=5;会报错
    int a=9;
    i=&a;
    return 1;
}
int f3(int * const i)
{
    *i=5;
    int a=9;
    //i=&a;会报错
    return 1;
}
int f4(const int * const i)
{
    //*i=5;会报错
    int a=9;
    //i=&a;会报错
    return 1;
}
int f5(const int * i)
{
    int *a;
    i=a;
    //a=i;会报错
    return 1;
}
int main(int argc, char const *argv[])
{
    int a = 1, b = 2;
    int &c = a; //引用，此后无法再次修改&c为其他变量的别名
    f1(&a);
    printf("%d,\n",c);
    return 0;
}