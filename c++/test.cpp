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

class C : public B
{
public:
 void prt()
 {
  cout << "打印C" << endl;
 }
};

int main(void)
{
 A* a=(A*)new B();
 a->prt();
 C* c=(C*)new B();
 c->prt();
 return 0;
}